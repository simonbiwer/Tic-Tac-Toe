//*******************************************************************
/*!
\file   USB_MCU.cpp
\author Thomas Breuer
\date   01.06.2012
*/

//*******************************************************************
//#define EP_MSK_CTRL 0x0001      /* Control Endpoint Logical Address Mask */
//#define EP_MSK_BULK 0xC924      /* Bulk Endpoint Logical Address Mask */
//#define EP_MSK_INT  0x4492      /* Interrupt Endpoint Logical Address Mask */
#define EP_MSK_ISO  0x1248      /* Isochronous Endpoint Logical Address Mask */

/* Device Interrupt Bit Definitions */
//#define FRAME_INT           0x00000001
#define EP_FAST_INT         0x00000002
#define EP_SLOW_INT         0x00000004
#define DEV_STAT_INT        0x00000008
#define CCEMTY_INT          0x00000010
#define CDFULL_INT          0x00000020
#define RxENDPKT_INT        0x00000040
#define TxENDPKT_INT        0x00000080
#define EP_RLZED_INT        0x00000100
#define ERR_INT             0x00000200

/* Rx & Tx Packet Length Definitions */
#define PKT_LNGTH_MASK      0x000003FF
#define PKT_DV              0x00000400
#define PKT_RDY             0x00000800

/* USB Control Definitions */
#define CTRL_RD_EN          0x00000001
#define CTRL_WR_EN          0x00000002

/* Command Codes */
#define CMD_SET_ADDR        0x00D00500
#define CMD_CFG_DEV         0x00D80500
#define CMD_SET_MODE        0x00F30500
#define CMD_RD_FRAME        0x00F50500
#define DAT_RD_FRAME        0x00F50200
#define CMD_RD_TEST         0x00FD0500
#define DAT_RD_TEST         0x00FD0200
#define CMD_SET_DEV_STAT    0x00FE0500
#define CMD_GET_DEV_STAT    0x00FE0500
#define DAT_GET_DEV_STAT    0x00FE0200
#define CMD_GET_ERR_CODE    0x00FF0500
#define DAT_GET_ERR_CODE    0x00FF0200
#define CMD_RD_ERR_STAT     0x00FB0500
#define DAT_RD_ERR_STAT     0x00FB0200
#define DAT_WR_BYTE(x)     (0x00000100 | ((x) << 16))
#define CMD_SEL_EP(x)      (0x00000500 | ((x) << 16))
#define DAT_SEL_EP(x)      (0x00000200 | ((x) << 16))
#define CMD_SEL_EP_CLRI(x) (0x00400500 | ((x) << 16))
#define DAT_SEL_EP_CLRI(x) (0x00400200 | ((x) << 16))
#define CMD_SET_EP_STAT(x) (0x00400500 | ((x) << 16))
#define CMD_CLR_BUF         0x00F20500
#define DAT_CLR_BUF         0x00F20200
#define CMD_VALID_BUF       0x00FA0500

/* Device Address Register Definitions */
#define DEV_ADDR_MASK       0x7F
#define DEV_EN              0x80

/* Device Configure Register Definitions */
#define CONF_DVICE          0x01


/* Device Status Register Definitions */
//#define DEV_CON             0x01
//#define DEV_CON_CH          0x02
//#define DEV_SUS             0x04
//#define DEV_SUS_CH          0x08
#define DEV_RST             0x10
 
/* Endpoint Select Register Definitions */
#define EP_SEL_F            0x01
#define EP_SEL_ST           0x02
#define EP_SEL_STP          0x04
#define EP_SEL_PO           0x08
#define EP_SEL_EPN          0x10
#define EP_SEL_B_1_FULL     0x20
#define EP_SEL_B_2_FULL     0x40

/* Endpoint Status Register Definitions */
#define EP_STAT_ST          0x01
#define EP_STAT_DA          0x20
#define EP_STAT_RF_MO       0x40
#define EP_STAT_CND_ST      0x80

//*******************************************************************
// 
// cHwUSB
//
//*******************************************************************
//-------------------------------------------------------------------
cHwUSB *cHwUSB_0::usbPtr = 0;

//-------------------------------------------------------------------
cHwUSB_0::cHwUSB_0(void)
{
  usbPtr = this;

  for(BYTE i=0;i< USB_EP_NUM;i++)
    ep[i]=0;
  registerEP(0x00,&epCtrl);
  registerEP(0x80,&epCtrl);


  // USB_Init()
  LPC_PINCON->PINSEL1 &= ~((3<<26)|(3<<28));   /* P0.29 D+, P0.30 D- */
  LPC_PINCON->PINSEL1 |=  ((1<<26)|(1<<28));   /* PINSEL1 26.27, 28.29  = 01 */

  LPC_PINCON->PINSEL3 &= ~((3<< 4)|(3<<28));   /* P1.18 GoodLink, P1.30 VBUS */
  LPC_PINCON->PINSEL3 |=  ((1<< 4)|(2<<28));   /* PINSEL3 4.5 = 01, 28.29 = 10 */

  LPC_PINCON->PINSEL4 &= ~((3<<18)        );   /* P2.9 SoftConnect */
  LPC_PINCON->PINSEL4 |=  ((1<<18)        );   /* PINSEL4 18.19 = 01 */

  LPC_SC->PCONP |= (1UL<<31);                /* USB PCLK -> enable USB Per.       */

  EndPointMask  = 0x00000000;
  EndPointHalt  = 0x00000000;



}

//-------------------------------------------------------------------
void cHwUSB_0::start(void)
{
  LPC_USB->USBClkCtrl = 0x12;                /* Dev, AHB clock enable */
  while ((LPC_USB->USBClkSt & 0x12) != 0x12); 

  NVIC_EnableIRQ(USB_IRQn);               /* enable USB interrupt */

  Reset();
  setAddress(0);
}

//-------------------------------------------------------------------
void cHwUSB_0::Reset (void) 
{
  LPC_USB->USBEpInd = 0;
  LPC_USB->USBMaxPSize = USB_MAX_PACKET0;
  LPC_USB->USBEpInd = 1;
  LPC_USB->USBMaxPSize = USB_MAX_PACKET0;
  while ((LPC_USB->USBDevIntSt & EP_RLZED_INT) == 0);

  LPC_USB->USBEpIntClr  = 0xFFFFFFFF;
  LPC_USB->USBEpIntEn   = 0xFFFFFFFF; // no DMA,was: 0xFF..FF ^ USB_DMA_EP;
  LPC_USB->USBDevIntClr = 0xFFFFFFFF;
  LPC_USB->USBDevIntEn  = DEV_STAT_INT    
                        | EP_SLOW_INT    
                        // no SOF, was:         | (USB_SOF_EVENT   ? FRAME_INT : 0) 
                        // no error event, was: | (USB_ERROR_EVENT ? ERR_INT   : 0)
                        ;
  iWrCmdDat(CMD_SET_DEV_STAT,DAT_WR_BYTE((0<<0)));
  iWrCmdDat(CMD_SET_DEV_STAT,DAT_WR_BYTE((1<<0)));
}

//-------------------------------------------------------------------
void cHwUSB_0::setAddress (BYTE adr)
{
  if( adr )
  {
    DeviceAddress = 0x80 | adr;
  }
  else if( DeviceAddress )
  {
    iWrCmdDat(CMD_SET_ADDR, DAT_WR_BYTE(DEV_EN | DeviceAddress)); /* Don't wait for next */
    iWrCmdDat(CMD_SET_ADDR, DAT_WR_BYTE(DEV_EN | DeviceAddress)); /*  Setup Status Phase */
    DeviceAddress = 0;
  }
}

//-------------------------------------------------------------------
void cHwUSB_0::iWrCmd(DWORD data) 
{
  LPC_USB->USBDevIntClr = CCEMTY_INT;
  LPC_USB->USBCmdCode = data;
  while ((LPC_USB->USBDevIntSt & CCEMTY_INT) == 0);
}


//-------------------------------------------------------------------
void cHwUSB_0::iWrCmdDat (DWORD cmd, DWORD val) 
{
  iWrCmd(cmd);
  iWrCmd(val);
}

//-------------------------------------------------------------------
DWORD cHwUSB_0::iRdCmdDat (DWORD cmd) 
{

  LPC_USB->USBDevIntClr = CCEMTY_INT | CDFULL_INT;
  LPC_USB->USBCmdCode = cmd;
  while ((LPC_USB->USBDevIntSt & CDFULL_INT) == 0);

  return (LPC_USB->USBCmdData);
}

//---------------------------------------------------------------
/*! 
*/
void cHwUSB_0::iWrCmdEP (DWORD EPphy, DWORD cmd)
{

  LPC_USB->USBDevIntClr = CCEMTY_INT;
  LPC_USB->USBCmdCode = CMD_SEL_EP(EPphy);
  while ((LPC_USB->USBDevIntSt & CCEMTY_INT) == 0);
  LPC_USB->USBDevIntClr = CCEMTY_INT;
  LPC_USB->USBCmdCode = cmd;
  while ((LPC_USB->USBDevIntSt & CCEMTY_INT) == 0);
}

//---------------------------------------------------------------
void cHwUSB_0::SetStallEP (BYTE epId) 
{
	BYTE EPphy = iEPAdr(epId);
	iWrCmdDat(CMD_SET_EP_STAT(epId), DAT_WR_BYTE(EP_STAT_ST));
	isetHalt(EPphy);
}

//---------------------------------------------------------------
void cHwUSB_0::ClrStallEP (BYTE epId) 
{
	BYTE EPphy = iEPAdr(epId);
	iWrCmdDat(CMD_SET_EP_STAT(epId), DAT_WR_BYTE(0));
	iclrHalt(EPphy);
}

//---------------------------------------------------------------
void cHwUSB_0::EnableEP (BYTE epId) 
{
	BYTE EPphy = iEPAdr(epId);
	iWrCmdDat(CMD_SET_EP_STAT(epId), DAT_WR_BYTE(0));
	isetMask(EPphy);
	iclrHalt(EPphy);
}

//---------------------------------------------------------------
void cHwUSB_0::DisableEP (BYTE epId) 
{
	BYTE EPphy = iEPAdr(epId);
	if( isMaskEP(epId) )
	{
		iWrCmdDat(CMD_SET_EP_STAT(epId), DAT_WR_BYTE(EP_STAT_DA));
		iclrMask(EPphy);
		iclrHalt(EPphy); 
	}
}

//---------------------------------------------------------------
void cHwUSB_0::ResetEP (BYTE epId) 
{
	BYTE EPphy = iEPAdr(epId);
	iWrCmdDat(CMD_SET_EP_STAT(epId), DAT_WR_BYTE(0));
}

//-------------------------------------------------------------------
void cHwUSB_0::ConfigEP (BYTE epId, WORD epMaxPacketSize, BYTE epType) 
{
  uint32_t epPhy = iEPAdr(epId);
  LPC_USB->USBReEp |= (1 << epPhy);
  LPC_USB->USBEpInd = epPhy;
  LPC_USB->USBMaxPSize = epMaxPacketSize;
  while ((LPC_USB->USBDevIntSt & EP_RLZED_INT) == 0);
  LPC_USB->USBDevIntClr = EP_RLZED_INT;

  EnableEP(epId);
  ResetEP(epId);

  iSetConfigurationEP(epPhy);

}

//---------------------------------------------------------------
/*! 
*/
void cHwUSB_0::Configure (BYTE flag) 
{

  iWrCmdDat(CMD_CFG_DEV, DAT_WR_BYTE(flag ? CONF_DVICE : 0));
/*
  LPC_USB->USBReEp = 0x00000003;
	//       --------------------
	//                      +---------- ist das so gewollt?
	//                                  
	//
  while ((LPC_USB->USBDevIntSt & EP_RLZED_INT) == 0);
  LPC_USB->USBDevIntClr = EP_RLZED_INT;
	*/
}

//-------------------------------------------------------------------
WORD cHwUSB_0::read(BYTE epId, BYTE *dataPtr, WORD len)
{
	BYTE EPphy = iEPAdr(epId);
  uint32_t cnt, n;

  LPC_USB->USBCtrl = ((EPphy & 0x0F) << 2) | CTRL_RD_EN;

  do {
    cnt = LPC_USB->USBRxPLen;
  } while ((cnt & PKT_RDY) == 0);
  cnt &= PKT_LNGTH_MASK;

  
  cnt = (cnt<len)?cnt:len;
  
  for (n = 0; n < (cnt + 3) / 4; n++) {
    *((__packed DWORD *)dataPtr) = LPC_USB->USBRxData;
    dataPtr += 4;
  }
  LPC_USB->USBCtrl = 0;

  if (((EP_MSK_ISO >> EPphy) & 1) == 0) {   /* Non-Isochronous Endpoint */
    iWrCmdEP(epId, CMD_CLR_BUF);
  }
  return (cnt);
}

//-------------------------------------------------------------------
WORD cHwUSB_0::write(BYTE epId, BYTE *pData, WORD cnt) 
{
	BYTE EPphy = iEPAdr(epId);
  uint32_t n;

  LPC_USB->USBCtrl = ((EPphy & 0x0F) << 2) | CTRL_WR_EN;

  LPC_USB->USBTxPLen = cnt;

  for (n = 0; n < (cnt + 3) / 4; n++) {
    LPC_USB->USBTxData = *((__packed DWORD *)pData);
    pData += 4;
  }
  LPC_USB->USBCtrl = 0;
  iWrCmdEP(epId|0x80, CMD_VALID_BUF);
  return (cnt);
}



//-------------------------------------------------------------------
inline void cHwUSB_0::isr(void)
{
  uint32_t disr, 
           val, 
           n;
  DWORD epIntSt,
        mask = 0x01;

  disr = LPC_USB->USBDevIntSt;       /* Device Interrupt Status */

  //
  // Device status interrupt
  //
  if(disr & DEV_STAT_INT) 
  {
    LPC_USB->USBDevIntClr = DEV_STAT_INT;
    iWrCmd(CMD_GET_DEV_STAT);
    val = iRdCmdDat(DAT_GET_DEV_STAT); // get device status

    if( val & DEV_RST ) // Reset
    {                    
      Reset();
    }
    return;
  }

  //
  // Error interrupt
  //
  if( disr & ERR_INT ) 
  {
    iWrCmd(CMD_RD_ERR_STAT);
    val = iRdCmdDat(DAT_RD_ERR_STAT);
    // handle error ...
  }

  //
  // Endpoint interrupt
  //
  if( disr & EP_SLOW_INT )
  {
    epIntSt = LPC_USB->USBEpIntSt;
    mask    = 0x01;

    for( n = 0; n < USB_EP_NUM && epIntSt; n++, mask <<= 1 ) // for all endpoints, 
    {                                          // finish, when no more interr pending
      if( epIntSt & mask ) 
      {
        epIntSt &= ~mask;

        
        LPC_USB->USBEpIntClr = mask;
        while ((LPC_USB->USBDevIntSt & CDFULL_INT) == 0);

        val = LPC_USB->USBCmdData;
        if( ep[n] )
        {
          if( (n&0x01) == 0 ) // OUT endpoint
          {                 
            if( (n==0) && (val&EP_SEL_STP) ) // OUT ctrl endpoint with setup packet
            {         
              ep[0]->setup();
            }
            else  // OUT endpoint
            {
              ep[n]->out();
            }
          } 
          else  // IN endpoint
          {                            
            ep[n]->in();
          }
        } // if( ep[n] )

      }
    }
    LPC_USB->USBDevIntClr = EP_SLOW_INT;
  }
}

//-------------------------------------------------------------------
extern "C" 
{
  void USB_IRQHandler(void) __irq
  {
    cHwUSB_0::usbPtr->isr();
  }
}

//EOF
