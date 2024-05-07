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
cHwUSB_0 *cHwUSB_0::usbPtr = 0;

//-------------------------------------------------------------------
cHwUSB_0::cHwUSB_0( cHwUSBdesc &desc )
: cHwUSB( desc )
{
  usbPtr = this;

//  for(BYTE i=0;i< USB_EP_NUM;i++)
//  {
//     ep[i]=0;
//  }

//  registerEP( 0x00, &epCtrl.epOUT );
//  registerEP( 0x80, &epCtrl.epIN );


  // USB_Init()
  cHwPinConfig::set( cHwPinConfig::USB_Dm      );
  cHwPinConfig::set( cHwPinConfig::USB_Dp      );
  cHwPinConfig::set( cHwPinConfig::USB_UP_LED  );
  cHwPinConfig::set( cHwPinConfig::VBUS        );
  cHwPinConfig::set( cHwPinConfig::USB_CONNECT );

  LPC_SC->PCONP |= (1UL<<31);  // USB PCLK -> enable USB Per.
}

//-------------------------------------------------------------------
inline void cHwUSB_0::isr(void)
{
  DWORD  val;
  DWORD  disr = LPC_USB->USBDevIntSt; // Device Interrupt Status

  // Device status interrupt
  if( disr & DEV_STAT_INT )
  {
    LPC_USB->USBDevIntClr = DEV_STAT_INT;
    WrCmd(CMD_GET_DEV_STAT);
    val = RdCmdDat(DAT_GET_DEV_STAT); // get device status

    if( val & DEV_RST ) // Reset
    {
      reset();
    }
    return;
  }

  // Error interrupt
  if( disr & ERR_INT )
  {
    WrCmd(CMD_RD_ERR_STAT);
    val = RdCmdDat(DAT_RD_ERR_STAT);
    // handle error ...
    LPC_USB->USBDevIntClr = ERR_INT;
  }

  // Endpoint interrupt
  if( disr & EP_SLOW_INT )
  {
    DWORD epIntSt = LPC_USB->USBEpIntSt;
    DWORD mask    = 0x01;

    // for all endpoints
    for( BYTE n = 0; n < USB_EP_NUM && epIntSt; n++, mask <<= 1 )
    {
      if( epIntSt & mask )
      {
        epIntSt &= ~mask;

        LPC_USB->USBEpIntClr = mask;
        while ((LPC_USB->USBDevIntSt & CDFULL_INT) == 0);

        val = LPC_USB->USBCmdData;

        eventHandler( (n>>1)|((n&0x01)<<7),          // calc EP address
                      (val&EP_SEL_STP)?true:false ); // Setup?
      }
    }
    LPC_USB->USBDevIntClr = EP_SLOW_INT;
  }
}

//-------------------------------------------------------------------
void cHwUSB_0::start(void)
{
  LPC_USB->USBClkCtrl = 0x12;            // Dev, AHB clock enable
  while ((LPC_USB->USBClkSt & 0x12) != 0x12);

  reset();
  NVIC_EnableIRQ(USB_IRQn);             // enable USB interrupt

  // some problems within startup can be avoided with this:
  cSystem::delayMilliSec( 100 );
}

//-------------------------------------------------------------------
void cHwUSB_0::reset (void)
{
  WrCmdDat(CMD_SET_DEV_STAT,DAT_WR_BYTE((1<<4))); // RST

  LPC_USB->USBDevIntClr = 0xFFFF;
  LPC_USB->USBReEp = 0;
  while ((LPC_USB->USBDevIntSt & EP_RLZED_INT) == 0);
  LPC_USB->USBDevIntClr =  EP_RLZED_INT;

  LPC_USB->USBReEp |= (1<<0);
  LPC_USB->USBEpInd = 0;
  LPC_USB->USBMaxPSize = desc.getMaxPacketSize0();

  while ((LPC_USB->USBDevIntSt & EP_RLZED_INT) == 0);
  LPC_USB->USBDevIntClr =  EP_RLZED_INT;

  LPC_USB->USBReEp |= (1<<1);
  LPC_USB->USBEpInd = 1;
  LPC_USB->USBMaxPSize = desc.getMaxPacketSize0();
  while ((LPC_USB->USBDevIntSt & EP_RLZED_INT) == 0);
  LPC_USB->USBDevIntClr = EP_RLZED_INT;

  LPC_USB->USBEpIntClr  = 0xFFFFFFFF;
  LPC_USB->USBEpIntEn   = 0xFFFFFFFF; // no DMA,was: 0xFF..FF ^ USB_DMA_EP;
  LPC_USB->USBDevIntClr = 0xFFFFFFFF;
  LPC_USB->USBDevIntEn  = DEV_STAT_INT
                        | EP_SLOW_INT
                        // no SOF, was:         | (USB_SOF_EVENT   ? FRAME_INT : 0)
                        // no error event, was: | (USB_ERROR_EVENT ? ERR_INT   : 0)
                        ;

  WrCmdDat(CMD_SET_MODE,DAT_WR_BYTE((1<<3))); //INAK_II

  WrCmdDat(CMD_SET_DEV_STAT,DAT_WR_BYTE((0<<0)));
  WrCmdDat(CMD_SET_DEV_STAT,DAT_WR_BYTE((1<<0)));

  setAddress(0);
}

//---------------------------------------------------------------
/*!
*/
void cHwUSB_0::configure (BYTE flag)
{
    for (DWORD num = 2; num < USB_EP_NUM; num++)
    //               ^--- execpt control EP
    {
      // disable EP
      WrCmdDat(CMD_SET_EP_STAT(num), DAT_WR_BYTE(EP_STAT_DA));
    }

  WrCmdDat(CMD_CFG_DEV, DAT_WR_BYTE(flag ? CONF_DVICE : 0));
}

//-------------------------------------------------------------------
void cHwUSB_0::setAddress( BYTE adr )
{
  WrCmdDat(CMD_SET_ADDR, DAT_WR_BYTE(DEV_EN | adr));

  writeEP( 0x80, NULL, 0 );  // Write ackn
}

//-------------------------------------------------------------------
void cHwUSB_0::configEP (BYTE epAddr, WORD epMaxPacketSize, BYTE epType)
{
  uint32_t epIdx = epAddr2Index( epAddr );

  LPC_USB->USBDevIntClr = EP_RLZED_INT;
  LPC_USB->USBReEp |= ((DWORD)1 << epIdx);
  LPC_USB->USBEpInd = epIdx;
  LPC_USB->USBMaxPSize = epMaxPacketSize;
  while ((LPC_USB->USBDevIntSt & EP_RLZED_INT) == 0);
  LPC_USB->USBDevIntClr = EP_RLZED_INT;

  // Enable EP
  WrCmdDat(CMD_SET_EP_STAT(epIdx), DAT_WR_BYTE(0));

  //Reset EP
  WrCmdDat(CMD_SET_EP_STAT(epIdx), DAT_WR_BYTE(0));

//  if( (epIdx & 0x01) && epType != USB_ENDPOINT_TYPE_BULK )
//  {
//    LPC_USB->USBCtrl = ((epAddr & 0x0F) << 2) | CTRL_WR_EN;
//    LPC_USB->USBTxPLen = 0;
//    LPC_USB->USBCtrl   = 0;
//    WrCmdDat( CMD_SEL_EP(epIdx), CMD_VALID_BUF );
//  }
}

//---------------------------------------------------------------
void cHwUSB_0::setStallEP (BYTE epAddr)
{
  uint32_t epIdx = epAddr2Index(epAddr);

  WrCmdDat(CMD_SET_EP_STAT(epIdx), DAT_WR_BYTE(EP_STAT_ST));
}

//---------------------------------------------------------------
void cHwUSB_0::clrStallEP (BYTE epAddr)
{
  uint32_t epIdx = epAddr2Index(epAddr);

  WrCmdDat(CMD_SET_EP_STAT(epIdx), DAT_WR_BYTE(0));
}

//-------------------------------------------------------------------
WORD cHwUSB_0::readEP( BYTE  epAddr,
                       BYTE *dataPtr,
                       WORD  len )
{
  uint32_t cnt=0;
  uint32_t epIdx = epAddr2Index(epAddr);

  if( !(epAddr & 0x80) )
  {
    LPC_USB->USBCtrl = ((epAddr & 0x0F) << 2) | CTRL_RD_EN;

    do
    {
      cnt = LPC_USB->USBRxPLen;
    } while ((cnt & PKT_RDY) == 0);
    cnt &= PKT_LNGTH_MASK;

    cnt = (cnt<len)?cnt:len;

    for( DWORD n = 0; n < (cnt + 3) / 4; n++ )
    {
      *((__packed DWORD *)dataPtr) = LPC_USB->USBRxData;
      dataPtr += 4;
    }
    LPC_USB->USBCtrl = 0;

    if (((EP_MSK_ISO >> epAddr) & 1) == 0) // Non-Isochronous Endpoint
    {
      WrCmdDat( CMD_SEL_EP(epIdx), CMD_CLR_BUF );
    }
    return (cnt);
  }
  return( 0 );
}

//-------------------------------------------------------------------
WORD cHwUSB_0::writeEP( BYTE  epAddr,
                        BYTE *pData,
                        WORD  cnt )
{
  uint32_t epIdx = epAddr2Index(epAddr);

  if( epAddr & 0x80 )
  {
    LPC_USB->USBCtrl = ((epAddr & 0x0F) << 2) | CTRL_WR_EN;

    LPC_USB->USBTxPLen = cnt;

    for( DWORD n = 0; n < (cnt + 3) / 4; n++ )
    {
      LPC_USB->USBTxData = *((__packed DWORD *)pData);
      pData += 4;
    }
    LPC_USB->USBCtrl = 0;
    WrCmdDat( CMD_SEL_EP(epIdx), CMD_VALID_BUF);
    return (cnt);
  }
  return( 0 );
}

//-------------------------------------------------------------------
//-------------------------------------------------------------------
void cHwUSB_0::WrCmd(DWORD data)
{
  LPC_USB->USBDevIntClr = CCEMTY_INT;
  LPC_USB->USBCmdCode = data;
  while ((LPC_USB->USBDevIntSt & CCEMTY_INT) == 0);
}

//-------------------------------------------------------------------
void cHwUSB_0::WrCmdDat (DWORD cmd, DWORD val)
{
  WrCmd(cmd);
  WrCmd(val);
}

//-------------------------------------------------------------------
DWORD cHwUSB_0::RdCmdDat (DWORD cmd)
{

  LPC_USB->USBDevIntClr = CCEMTY_INT | CDFULL_INT;
  LPC_USB->USBCmdCode = cmd;
  while ((LPC_USB->USBDevIntSt & CDFULL_INT) == 0);

  return (LPC_USB->USBCmdData);
}

//-------------------------------------------------------------------
extern "C"
{
  void USB_IRQHandler(void)
  {
    cHwUSB_0::usbPtr->isr();
  }
}

//EOF
