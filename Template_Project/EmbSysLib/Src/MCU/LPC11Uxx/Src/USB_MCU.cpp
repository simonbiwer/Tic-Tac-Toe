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
#define DEV_INT          0x80000000
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
// NEW LPC11Uxx
//*******************************************************************
/* USB Device Command Status */
#define USB_EN              (0x1<<7)  /* Device Enable */
#define USB_SETUP_RCVD      (0x1<<8)  /* SETUP token received */
#define USB_PLL_ON          (0x1<<9)  /* PLL is always ON */
#define USB_LPM             (0x1<<11) /* LPM is supported */
#define USB_IntOnNAK_AO     (0x1<<12) /* Device Interrupt on NAK BULK OUT */
#define USB_IntOnNAK_AI     (0x1<<13) /* Device Interrupt on NAK BULK IN */
#define USB_IntOnNAK_CO     (0x1<<14) /* Device Interrupt on NAK CTRL OUT */
#define USB_IntOnNAK_CI     (0x1<<15) /* Device Interrupt on NAK CTRL IN */
#define USB_DCON            (0x1<<16) /* Device connect */
#define USB_DSUS            (0x1<<17) /* Device Suspend */
#define USB_LPM_SUS         (0x1<<19) /* LPM suspend */
#define USB_REMOTE_WAKE     (0x1<<20) /* LPM Remote Wakeup */
#define USB_DCON_C          (0x1<<24) /* Device connection change */
#define USB_DSUS_C          (0x1<<25) /* Device SUSPEND change */
#define USB_DRESET_C        (0x1<<26) /* Device RESET */
#define USB_VBUS_DBOUNCE    (0x1<<28) /* Device VBUS detect */

typedef struct _EP_LIST {
  uint32_t  buf_ptr;
  uint32_t  buf_length;
} EP_LIST;

#define USB_EPLIST_ADDR		0x20004000
#define USB_EPDATA_ADDR		(USB_EPLIST_ADDR + 0x100)
#define USB_EPDATA_PAGE		(USB_EPDATA_ADDR&0xFFC00000)	/* Bit 22~31 is the page */
#define USB_RAM_LIMIT		0x800		/* maximum USB RAM size is 2K */

#define USB_POWER             0
#define USB_IF_NUM            1
#define USB_EP_NUM            10
#define USB_SETUP_PACKET_SIZE 8
#define USB_MAX_PACKET0       64
#define USB_MAX_NON_ISO_SIZE  64
#define USB_MAX_ISO_SIZE      1023
#define USB_LOGIC_EP_NUM      5

/* EP buffer address and length default setting */
volatile EP_LIST EPList[USB_EP_NUM*2]; /* Consider double buffer for non zero EPs */

#define BUF_ACTIVE			(0x1U<<31)
#define EP_DISABLED			(0x1<<30)
#define EP_STALL			(0x1<<29)
#define EP_RESET			(0x1<<28)
#define EP_ISO_TYPE			(0x1<<26)


/* tmp */
int debugcnt = 0;

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

  /* Initialize clock and I/O pins for USB. */
  //USBIOClkConfig();
  /* Enable AHB clock to the GPIO domain. */
  LPC_SYSCON->SYSAHBCLKCTRL |= (1<<6);

  /* Enable AHB clock to the USB block and USB RAM. */
  LPC_SYSCON->SYSAHBCLKCTRL |= ((0x1<<14)|(0x1<<27));

  /* Pull-down is needed, or internally, VBUS will be floating. This is to
  address the wrong status in VBUSDebouncing bit in CmdStatus register. It
  happens on the NXP Validation Board only that a wrong ESD protection chip is used. */
  LPC_IOCON->PIO0_3   &= ~0x1F;
  LPC_IOCON->PIO0_3   |= ((0x1<<3)|(0x01<<0));	/* Secondary function VBUS */

  //  LPC_IOCON->PIO0_3   |= (0x01<<0);			/* Secondary function VBUS */
  LPC_IOCON->PIO0_6   &= ~0x07;
  LPC_IOCON->PIO0_6   |= (0x01<<0);			/* Secondary function SoftConn */


  /* Enable the USB Interrupt */
  NVIC_EnableIRQ(USB_IRQn);

  reset();
}

//-------------------------------------------------------------------
inline void cHwUSB_0::isr(void)
{
  DWORD intstat = LPC_USB->INTSTAT;
  LPC_USB->INTSTAT = intstat; // clear all interrupts
  //
  // Device status interrupt
  //
  if( intstat & DEV_INT )
  {
    if( LPC_USB->DEVCMDSTAT & USB_DRESET_C )
    {
      reset();
      return;
    }
  }

  //
  // Error interrupt
  //
  /*
  if( LPC_USB->INTSTAT & ERR_INT )
  {
    WrCmd(CMD_RD_ERR_STAT);
    val = RdCmdDat(DAT_RD_ERR_STAT);
    // handle error ...
  }
  */
  //
  // Endpoint interrupt
  //

  WORD n    = 0;
  WORD mask = 0x01;
  while( n < USB_EP_NUM && (intstat & 0x3FF) )
  {
    if( intstat & mask )
    {
      intstat &= ~mask; // clear interrupt flag

 if( deviceAddress )
 {
   debugcnt++;
 }
      if( (n == 0) && (LPC_USB->DEVCMDSTAT & USB_SETUP_RCVD) ) // setup ?
      {
        /* Check/Clear STALL on both EP0 IN and OUT when SETUP is received. */
        DWORD *addr = (DWORD*)USB_EPLIST_ADDR;
        //if ( (*addr & EP_STALL) || ((*addr+2) & EP_STALL) )
        //{
          *addr     &= ~(BUF_ACTIVE);
          *addr     &= ~(EP_STALL);
          *(addr+2) &= ~(BUF_ACTIVE);
          *(addr+2) &= ~(EP_STALL);
        //}
         LPC_USB->DEVCMDSTAT |= USB_SETUP_RCVD;
        isSetup = true;
        eventHandler( 0, true );

      }
      else
      {
        //LPC_USB->DEVCMDSTAT |= USB_SETUP_RCVD;
        isSetup = false;
        eventHandler( (n>>1)|((n&0x01)<<7), // calc EP address
                      false );
      }
    }
    n++;
    mask <<= 1;
  }
}

//-------------------------------------------------------------------
void cHwUSB_0::start(void)
{
//x  LPC_USB->USBClkCtrl = 0x12;                /* Dev, AHB clock enable */
//x  while ((LPC_USB->USBClkSt & 0x12) != 0x12);

  reset();
  NVIC_EnableIRQ(USB_IRQn);               /* enable USB interrupt */
  LPC_USB->DEVCMDSTAT |= (USB_DCON|USB_PLL_ON);

  // some problems within startup can be avoided with this:
  cSystem::delayMilliSec( 3000 );
}

//-------------------------------------------------------------------
void cHwUSB_0::reset (void)
{
  /* Initialize EP Command/Status List. */
 ////// USB_EPInit();
 ////// void USB_EPInit( void ) {
  uint32_t *addr, data_ptr;
  uint32_t i, j = 0;

  addr = (uint32_t *)USB_EPLIST_ADDR;
  LPC_USB->EPLISTSTART = USB_EPLIST_ADDR;
  data_ptr = USB_EPDATA_ADDR;
  LPC_USB->DATABUFSTART = USB_EPDATA_PAGE;

  /* CTRL, BULK or Interrupt IN/OUT EPs, max EP size is 64 */
  /* For EP0, double buffer doesn't apply to CTRL EPs, but, EP0OUTBuf0 is
  for EP0OUT, EP0OUTBuf1 is for SETUP, EP0INBuf0 is for EP0IN, EP0INTBuf1 is
  reserved. Also note: ACTIVE bit doesn't apply to SETUP and Reserved EP buffer. */
  *addr++ = (USB_MAX_PACKET0<<16)|((uint16_t)(data_ptr>>6));
  EPList[j].buf_ptr = data_ptr;
  EPList[j++].buf_length = USB_MAX_PACKET0;
  data_ptr += USB_MAX_PACKET0;
  *addr++ = ((uint16_t)(data_ptr>>6));		/* No length field for SETUP */
  EPList[j].buf_ptr = data_ptr;
  EPList[j++].buf_length = USB_SETUP_PACKET_SIZE;
  /* For easier alignment, the data field is aligned to 64 bytes for all EPs. */
  data_ptr += USB_MAX_PACKET0;

  *addr++ = (USB_MAX_PACKET0<<16)|((uint16_t)(data_ptr>>6));
  EPList[j].buf_ptr = data_ptr;
  EPList[j++].buf_length = USB_MAX_PACKET0;
  data_ptr += USB_MAX_PACKET0;
#if 0
  /* EP0 IN second buffer(buffer1) is reserved. */
  *addr++ = (USB_MAX_PACKET0<<16)|((uint16_t)(data_ptr>>6));
#else
  addr++;
#endif
  EPList[j].buf_ptr = data_ptr;
  EPList[j++].buf_length = USB_MAX_PACKET0;
  data_ptr += USB_MAX_PACKET0;

  for ( i = 2; i < USB_EP_NUM; i++ )
  {
	/* Buffer 0 */
#if USB_ISO_COMMUNICATION
	*addr++ = EP_DISABLED|EP_ISO_TYPE|(USB_MAX_ISO_SIZE<<16)|((uint16_t)(data_ptr>>6));
	EPList[j].buf_ptr = data_ptr;
	EPList[j++].buf_length = USB_MAX_ISO_SIZE;
	data_ptr += USB_MAX_ISO_SIZE;
#else
	*addr++ = EP_DISABLED|(USB_MAX_NON_ISO_SIZE<<16)|((uint16_t)(data_ptr>>6));
	EPList[j].buf_ptr = data_ptr;
	EPList[j++].buf_length = USB_MAX_NON_ISO_SIZE;
	data_ptr += USB_MAX_NON_ISO_SIZE;
#endif
	/* Buffer 1 */
#if USB_ISO_COMMUNICATION
	*addr++ = EP_DISABLED|EP_ISO_TYPE|(USB_MAX_ISO_SIZE<<16)|((uint16_t)(data_ptr>>6));
	EPList[j].buf_ptr = data_ptr;
	EPList[j++].buf_length = USB_MAX_ISO_SIZE;
	data_ptr += USB_MAX_ISO_SIZE;
#else
	*addr++ = EP_DISABLED|(USB_MAX_NON_ISO_SIZE<<16)|((uint16_t)(data_ptr>>6));
	EPList[j].buf_ptr = data_ptr;
	EPList[j++].buf_length = USB_MAX_NON_ISO_SIZE;
	data_ptr += USB_MAX_NON_ISO_SIZE;
#endif
  }

  LPC_USB->DEVCMDSTAT |= USB_EN;
 /*??*/ LPC_USB->DEVCMDSTAT &= ~USB_LPM;

  /* Clear all EP interrupts, device status, and SOF interrupts. */
  LPC_USB->INTSTAT = 0xC00003FF;
  /* Enable all ten(10) EPs interrupts including EP0, note: EP won't be
  ready until it's configured/enabled when device sending SetEPStatus command
  to the command engine. */
  LPC_USB->INTEN  = DEV_INT | 0x3FF ; ///x| (USB_SOF_EVENT ? FRAME_INT : 0);


//x  LPC_USB->USBEpInd = 0;
//x  LPC_USB->USBMaxPSize = USB_MAX_PACKET0;
//x  LPC_USB->USBEpInd = 1;
//x  LPC_USB->USBMaxPSize = USB_MAX_PACKET0;
//x  while ((LPC_USB->USBDevIntSt & EP_RLZED_INT) == 0);

//x  LPC_USB->USBEpIntClr  = 0xFFFFFFFF;
//x  LPC_USB->USBEpIntEn   = 0xFFFFFFFF; // no DMA,was: 0xFF..FF ^ USB_DMA_EP;
//x  LPC_USB->USBDevIntClr = 0xFFFFFFFF;
//x  LPC_USB->USBDevIntEn  = DEV_STAT_INT
//x                        | EP_SLOW_INT
//x                        // no SOF, was:         | (USB_SOF_EVENT   ? FRAME_INT : 0)
//x                        // no error event, was: | (USB_ERROR_EVENT ? ERR_INT   : 0)
//x                        ;
//x  WrCmdDat(CMD_SET_DEV_STAT,DAT_WR_BYTE((0<<0)));
//x  WrCmdDat(CMD_SET_DEV_STAT,DAT_WR_BYTE((1<<0)));

  //setAddress( 0 );

  deviceAddress = 0;
}

//---------------------------------------------------------------
void cHwUSB_0::configure (BYTE flag)
{
uint32_t data_ptr;
uint32_t j = 0;

DWORD *addr = (DWORD*)(USB_EPLIST_ADDR + (1<<3));
data_ptr = USB_EPDATA_ADDR+4*USB_MAX_NON_ISO_SIZE;
  for (DWORD num = 2; num < USB_EP_NUM; num++)
  //               ^--- execpt control EP
  {
        // disable EP
      /* Buffer 0 */
      *addr++ = EP_DISABLED|(USB_MAX_NON_ISO_SIZE<<16)|((uint16_t)(data_ptr>>6));
      EPList[j].buf_ptr = data_ptr;
      EPList[j++].buf_length = USB_MAX_NON_ISO_SIZE;
      data_ptr += USB_MAX_NON_ISO_SIZE;

        /* Buffer 1 */
      *addr++ = EP_DISABLED|(USB_MAX_NON_ISO_SIZE<<16)|((uint16_t)(data_ptr>>6));
      EPList[j].buf_ptr = data_ptr;
      EPList[j++].buf_length = USB_MAX_NON_ISO_SIZE;
      data_ptr += USB_MAX_NON_ISO_SIZE;
      }

  LPC_USB->DEVCMDSTAT |= USB_EN;
}

DWORD tmp=0;

//-------------------------------------------------------------------
void cHwUSB_0::setAddress (BYTE adr)
{
//  LPC_USB->DEVCMDSTAT |= USB_SETUP_RCVD;
//
//

  deviceAddress = 0x80 | adr;
     if( deviceAddress & 0x80 )
      {
        LPC_USB->DEVCMDSTAT &= ~0x7F;
        LPC_USB->DEVCMDSTAT |= (USB_EN|deviceAddress);
        LPC_USB->DEVCMDSTAT |= (USB_EN|deviceAddress);
        deviceAddress &= 0x7F;
      }

  writeEP( 0x80, NULL, 0 );  // Write ackn

// cSystem::delayMilliSec(1);
////  LPC_USB->DEVCMDSTAT &= ~0x7F;
////  LPC_USB->DEVCMDSTAT |= (USB_EN|adr);
////  cSystem::delayMilliSec(1);
 //
 //


//  if( adr )
//  {
//    DeviceAddress = 0x80 | adr;
//  }
//  else if( DeviceAddress )
//  {
//    WrCmdDat(CMD_SET_ADDR, DAT_WR_BYTE(DEV_EN | DeviceAddress)); /* Don't wait for next */
//    WrCmdDat(CMD_SET_ADDR, DAT_WR_BYTE(DEV_EN | DeviceAddress)); /*  Setup Status Phase */
//    DeviceAddress = 0;
//  }
}

//-------------------------------------------------------------------
void cHwUSB_0::configEP (BYTE epAddr, WORD epMaxPacketSize, BYTE epType)
{
  uint32_t epIdx = epAddr2Index(epAddr);
  DWORD *addr = (DWORD*)(USB_EPLIST_ADDR + (epIdx<<3));

  *addr &= ~EP_DISABLED;
  if ( epAddr & 0x0F )	/* Non-zero EPs */
  {
    if ( epAddr & 0x80 )		/* For non-zero IN */
    {
      *addr &= ~0x3FFFFFFF;
      *addr |= BUF_ACTIVE;
    }
    else
    {
      /* For non-zero EP OUT, in addition to clear EP_DISABLED bits,
      set the ACTIVE bit indicating that EP is ready to read. For
      double buffered EPs, set ACTIVE bit and clear EP_DISABLED bit
      for both buffer0 and 1. */
      *addr |= BUF_ACTIVE;

    }
  }
  return;
}

//---------------------------------------------------------------
void cHwUSB_0::setStallEP (BYTE epAddr)
{
  uint32_t epIdx = epAddr2Index(epAddr);

  WrCmdDat(CMD_SET_EP_STAT(epIdx), DAT_WR_BYTE(EP_STAT_ST));

//  WrCmdDat(CMD_SET_EP_STAT(EPAdr(EPNum)), DAT_WR_BYTE(EP_STAT_ST));
//  setHalt(EPAdr(EPNum));
}

//---------------------------------------------------------------
void cHwUSB_0::clrStallEP (BYTE epAddr)
{
  uint32_t epIdx = epAddr2Index(epAddr);

  WrCmdDat(CMD_SET_EP_STAT(epIdx), DAT_WR_BYTE(0));

//  WrCmdDat(CMD_SET_EP_STAT(EPAdr(EPNum)), DAT_WR_BYTE(0));
//  clrHalt(EPAdr(EPNum));
}

//-------------------------------------------------------------------
WORD cHwUSB_0::readEP( BYTE  epAddr,
                       BYTE *dataPtr,
                       WORD  len )
{
  uint32_t cnt=0;
  uint32_t epIdx = epAddr2Index(epAddr);
  DWORD *addr = (DWORD*)(USB_EPLIST_ADDR + (epIdx<<3));
  DWORD *ptr;

  if( !(epAddr & 0x80) )
  {
    if( (epIdx == 0) && isSetup ) // setup ?
    {
      addr++;
      cnt = USB_SETUP_PACKET_SIZE;
      ptr = (DWORD *)EPList[1].buf_ptr;
    }
    else
    {
      cnt = (*addr >> 16) & PKT_LNGTH_MASK;
      /* The NBytes field decrements by H/W with the packet byte each time. */
      cnt = EPList[epIdx*2].buf_length - cnt;
      ptr = (DWORD *)EPList[epIdx*2].buf_ptr;
    }

    cnt = (cnt<len)?cnt:len;

    memcpy (dataPtr, ptr, cnt);

    /* Clear buffer after EP read, reset EP length and buffer pointer field */
    if( (epIdx == 0) && isSetup ) // setup ?
    {
      *addr &= ~0x3FFFFFF;
      *addr |= (uint16_t)((EPList[1].buf_ptr)>>6);
    }
    else
    {
      *addr &= ~0x3FFFFFF;
      *addr |=   ((EPList[epIdx*2].buf_length<<16)
               | (uint16_t)((EPList[epIdx*2].buf_ptr)>>6) | BUF_ACTIVE);
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
  DWORD *addr = (DWORD*)(USB_EPLIST_ADDR + (epIdx<<3));
  DWORD *ptr;

  if( epAddr & 0x80 )
  {
//    while( (*addr) & BUF_ACTIVE );

    /* Get EP command/status List, update the length field and data pointer. */
    *addr &= ~0x3FFFFFF;
    cnt &= PKT_LNGTH_MASK;
    *addr |= (cnt<<16)|(uint16_t)((EPList[epIdx*2].buf_ptr)>>6);

    ptr = (DWORD *)EPList[epIdx*2].buf_ptr;

    memcpy (ptr, pData, cnt);

    if ( (*addr & EP_STALL) && (epAddr & 0x0F) )
    {
      /* This is for MSC class when STALL occurs and non-zero EPs,
      set the ACTIVE flag, but don't do anything until ClearFeature
      to clear STALL, then tranfer the data. */
      //??? EPActiveFlag |= (0x1U << EPAdr(EPNum));
      return (cnt);
    }
    *addr |= BUF_ACTIVE;

    if( epIdx == 1 ) //&& isSetup)
    {
      /* When EP0 IN is received, set ACTIVE bit on both EP0 IN
      and OUT. */
      *(addr-2) |= BUF_ACTIVE;	/* Set ACTIVE bit on EP0 OUT */
    }
    if( deviceAddress && cnt==0x19 )
    {
      debugcnt++;
    }
    return (cnt);
  }
  return( 0 );
}

//-------------------------------------------------------------------
void cHwUSB_0::WrCmd(DWORD data)
{
//x  LPC_USB->USBDevIntClr = CCEMTY_INT;
//x  LPC_USB->USBCmdCode = data;
//x  while ((LPC_USB->USBDevIntSt & CCEMTY_INT) == 0);
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

//x  LPC_USB->USBDevIntClr = CCEMTY_INT | CDFULL_INT;
//x  LPC_USB->USBCmdCode = cmd;
//x  while ((LPC_USB->USBDevIntSt & CDFULL_INT) == 0);

//x  return (LPC_USB->USBCmdData);
  return( 0 );
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
