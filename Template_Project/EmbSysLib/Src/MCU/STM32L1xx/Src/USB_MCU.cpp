//*******************************************************************
/*!
\file   USB_MCU.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.

\todo   Implementierung überarbeiten
*/

//*******************************************************************
#include "USB_MCU.h"

//*******************************************************************
typedef struct
{
  __IO uint32_t EP[8];        // Endpoint register
  __IO uint32_t reserved[8];  // Reserved Address
  __IO uint32_t CNTR;         // Control register
  __IO uint32_t ISTR;         // Interrupt status register
  __IO uint32_t FNR;          // Frame number register
  __IO uint32_t DADDR;        // Device address register
  __IO uint32_t BTABLE;       // Buffer table register

} USB_TypeDef;

//*******************************************************************
#pragma pack(1)
typedef struct
{
    struct
    {
      WORD addr;
      WORD reserved2;
      WORD count;
      WORD reserved1;
    } bufDesc[16];

} USB_BufferDescriptionTable;
#pragma pack()

//*******************************************************************
#define USB_BASE             (APB1PERIPH_BASE + 0x5C00)
#define USB                  ((USB_TypeDef *) USB_BASE)

#define USB_BUF_BASE         (APB1PERIPH_BASE + 0x6000)
#define USB_BUF             ((USB_BufferDescriptionTable *) USB_BUF_BASE)


//*******************************************************************
//
// cHwUSB
//
//*******************************************************************
//-------------------------------------------------------------------
cHwUSB_0 *cHwUSB_0::usbPtr = 0;
WORD      cHwUSB_0::EPconfig::offset = sizeof(USB_BufferDescriptionTable);

//-------------------------------------------------------------------
cHwUSB_0::cHwUSB_0( cHwUSBdesc &desc )
: cHwUSB( desc )
{
  usbPtr = this;
}

//-------------------------------------------------------------------
inline void cHwUSB_0::isr(void)
{
  DWORD istr = USB->ISTR;

  if( istr & USB_ISTR_RESET )
  {
    reset();
    USB->ISTR = ~USB_ISTR_RESET;
  }

  if( istr & USB_ISTR_CTR )
  {
    for( BYTE num=0; num<8;num++)
    {
      if( USB->EP[num]&USB_EP0R_CTR_RX )
      {
        EP[num].clrCTR_RX();
        eventHandler( num|0x00,          // calc EP address
                      (USB->EP[num]&USB_EP0R_SETUP)?true:false ); // Setup?
      }

      if( USB->EP[num]&USB_EP0R_CTR_TX )
      {
        EP[num].clrCTR_TX();
        eventHandler( num|0x80,          // calc EP address
                      false ); // no Setup
      }
      USB->ISTR = ~USB_ISTR_CTR;
    }
  }
}

//-------------------------------------------------------------------
void cHwUSB_0::start(void)
{
  reset();

  setAddress(0);

  NVIC_EnableIRQ(USB_LP_IRQn);             // enable USB interrupt
  SYSCFG->PMC |= SYSCFG_PMC_USB_PU; // switch on PU
}

//-------------------------------------------------------------------
void cHwUSB_0::reset (void)
{
  RCC->APB1ENR |= RCC_APB1ENR_USBEN;
  RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

  // power on
  // --------
  USB->CNTR = USB_CNTR_FRES;

  cSystem::delayMicroSec(10);

  USB->CNTR = 0;


  USB->ISTR = 0; // Clear pending interrupts

  DWORD *ptr = (DWORD*)USB_BUF_BASE;
  for(int i=0;i<256;i++)
  {
    *(ptr++)=0;
  }

  setAddress(0);

  EPconfig::offset = sizeof(USB_BufferDescriptionTable);

  EP[0].init(  0x80/*addr*/, 1/*type*/, 0/*kind*/, 64/*size*/);
  EP[0].init(  0x00/*addr*/, 1/*type*/, 0/*kind*/, 64/*size*/);
  EP[0].setSTAT_RX( 3 );
  EP[0].setSTAT_TX( 2 );

  USB->CNTR =  // set interrupts mask
                  USB_CNTR_CTRM
               | !USB_CNTR_WKUPM
               | !USB_CNTR_SUSPM
               | !USB_CNTR_ERRM
               | !USB_CNTR_SOFM
               | !USB_CNTR_ESOFM
               |  USB_CNTR_RESETM;

  SYSCFG->PMC |= SYSCFG_PMC_USB_PU; // switch on PU
}

//-------------------------------------------------------------------
void cHwUSB_0::configure (BYTE flag)
{
}

//-------------------------------------------------------------------
void cHwUSB_0::setAddress( BYTE adr )
{
  writeEP( 0x80, NULL, 0 );

  cSystem::delayMilliSec(1);

  USB->DADDR =   adr             // address
               | USB_DADDR_EF;

  EP[0].setSTAT_RX(3);
}

//-------------------------------------------------------------------
void cHwUSB_0::configEP (BYTE epAddr, WORD epMaxPacketSize, BYTE epType)
{
  BYTE num = epAddr&0x07;
  BYTE type[] = { 1/*CTRL*/, 2/*ISO*/, 0/*BULK*/, 3/*INT*/};
  if( epAddr & 0x80 ) // IN=TX
  {
    EP[num].init(  epAddr, type[epType&0x3]/*type*/, 0/*kind*/, epMaxPacketSize);
    EP[num].setSTAT_TX( (epType==2)?2:3 );
    //                              ^^^  Bulk:2, Interrupt 3
    //<! \todo anders loesen!!!
  }
  else
  {
    EP[num].init(  epAddr, type[epType&0x3]/*type*/, 0/*kind*/, epMaxPacketSize);
    EP[num].setSTAT_RX( 3 );
  }
}

//---------------------------------------------------------------
void cHwUSB_0::setStallEP (BYTE epAddr)
{
if( epAddr & 0x80 ) // IN, RX
  EP[0].setSTAT_RX(1);
else
  EP[0].setSTAT_TX(1);
}

//---------------------------------------------------------------
void cHwUSB_0::clrStallEP (BYTE epAddr)
{
}

//-------------------------------------------------------------------
WORD cHwUSB_0::readEP( BYTE  epAddr,
                       BYTE *dataPtr,
                       WORD  len )
{
  BYTE  num = epAddr & 0x07;
  WORD *ptr = EP[num].rxPtr;

  if( !(epAddr & 0x80) && ptr )
  {
    WORD cnt = USB_BUF->bufDesc[2*num+1].count & 0x3FF; // count lesen
    cnt = (cnt<len)?cnt:len;

    for( WORD n = 0; n < (cnt + 1) / 2; n++ )
    {
      *((__packed WORD *)dataPtr) = *ptr;
      dataPtr += 2;
      ptr     += 2;
    }
    EP[num].setSTAT_RX(3);

    return( cnt );
  }

  return( 0 );
}

//-------------------------------------------------------------------
WORD cHwUSB_0::writeEP( BYTE  epAddr,
                        BYTE *pData,
                        WORD  cnt )
{
  BYTE  num = epAddr & 0x07;
  WORD *ptr = EP[num].txPtr;

  cnt = (cnt<64)?cnt:64;
    if( (epAddr & 0x80) && ptr)
  {
    for( WORD n = 0; n < (cnt + 1) / 2; n++ )
    {
      *ptr = *((WORD *)pData);
      pData += 2;
      ptr     += 2;
    }
    USB_BUF->bufDesc[2*num].count = cnt & 0x3FF; // count lesen

    EP[num].setSTAT_TX(3);
    return( cnt );
  }
  return( 0 );
}

//-------------------------------------------------------------------
//-------------------------------------------------------------------
WORD *cHwUSB_0::EPconfig::bdt_init(BYTE num, BYTE isRX, WORD size)
{
  WORD *ret = NULL;
  offset &= (~0x01);
  if(isRX)
  {
    if( size <= 62 )
    {
      USB_BUF->bufDesc[2*num+1].count =  (       0 <<15)
                                        |((size>>1)<<10);
    }
    else
    {
      USB_BUF->bufDesc[2*num+1].count =  (       1 <<15)
                                        |((size>>6)<<10);
    }
    USB_BUF->bufDesc[2*num+1].addr  = offset;
  }
  else
  {
    USB_BUF->bufDesc[2*num].count = 0;
    USB_BUF->bufDesc[2*num].addr  = offset;
  }
  ret = (WORD*)USB_BUF+offset;
  offset += size;

  return( ret );
}

//-------------------------------------------------------------------
void cHwUSB_0::EPconfig::init( DWORD addrIn, DWORD type, DWORD kind, WORD sizeIn)
{
  addr     = addrIn&0x07;

  regPtr   = (DWORD*)&(USB->EP[addr&0x07]);

  if( addrIn & 0x80 ) // IN=TX
  {
    txSize   = sizeIn;
    txPtr = bdt_init(addr,0, txSize );//TX
  }
  else
  {
    rxSize   = sizeIn;
    rxPtr = bdt_init(addr,1, rxSize );//OUT=RX

  }

  config   = (addr<<0)
            |(type<<9)
            |(kind<<8)
            |(1<<15) // CTR_RX
            |(1<<7) // CTR_TX
            |(1<<11);// SETUP

  *regPtr = config;
}

//-------------------------------------------------------------------
void cHwUSB_0::EPconfig::clrCTR_RX()
{
  *regPtr = config & ~(1<<15);//tmp;
}

//-------------------------------------------------------------------
void cHwUSB_0::EPconfig::clrCTR_TX( )
{
  *regPtr = config & ~(1<<7);
}

//-------------------------------------------------------------------
void cHwUSB_0::EPconfig::setSTAT_RX( DWORD stat)
{
  *regPtr = (((*regPtr)&(3<<12))^(stat<<12)) | config;
}

//-------------------------------------------------------------------
void cHwUSB_0::EPconfig::setSTAT_TX(DWORD stat)
{
  *regPtr = (((*regPtr)&(3<<4))^(stat<<4)) | config;
}

//-------------------------------------------------------------------
extern "C"
{
  void USB_LP_IRQHandler(void)
  {
    cHwUSB_0::usbPtr->isr();
  }
}

//EOF
