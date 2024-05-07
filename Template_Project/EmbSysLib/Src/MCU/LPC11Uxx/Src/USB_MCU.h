//*******************************************************************
/*!
\file   USB_MCU.h
\author Thomas Breuer
\date   01.06.02012
*/

//*******************************************************************
#ifndef _HW_USB_MCU_H
#define _HW_USB_MCU_H

#include "Com/Hardware/USB/USB.h"
//*******************************************************************
// Konfiguration

//*******************************************************************
/*! 
\class cHwUSB

\brief 


\example cHwUSB.cpp
*/
class cHwUSB_0 : public cHwUSB
{
  public:
    //---------------------------------------------------------------
    /*! 
    */
   cHwUSB_0( cHwUSBdesc &desc );
    
    //---------------------------------------------------------------
    // 
    virtual void isr( void );

    //---------------------------------------------------------------
    // 
    virtual void start( void );
 
  private:
    //---------------------------------------------------------------
    //
    virtual void reset (void);
 
    //---------------------------------------------------------------
    //
    virtual void configure (BYTE flag);

    //-------------------------------------------------------------------
    //
    virtual void setAddress( BYTE adr = 0 );

    //---------------------------------------------------------------
    //
    virtual void configEP( BYTE epAddress, 
                           WORD epMaxPacketSize, 
                           BYTE epType );

    //---------------------------------------------------------------
    //
    virtual void setStallEP( BYTE epAddr );

    //---------------------------------------------------------------
    //
    virtual void clrStallEP( BYTE epAddr );

    //---------------------------------------------------------------
    // 
    virtual WORD readEP( BYTE  epAddr, 
                         BYTE *dataPtr, 
                         WORD  len);

    //---------------------------------------------------------------
    // 
    virtual WORD writeEP( BYTE  epAddr, 
                          BYTE *pData,
                          WORD  cnt );

  private:
    //---------------------------------------------------------------
    BYTE epAddr2Index( BYTE epAddr )
    {
      return( ((epAddr & 0x0F) << 1) | ((epAddr & 0x80)?0x01:0x00) );
    }
  
    //-------------------------------------------------------------------
    virtual void WrCmd( DWORD data );

    //---------------------------------------------------------------
    virtual void WrCmdDat( DWORD cmd, 
                           DWORD val);

    //---------------------------------------------------------------
    virtual DWORD RdCmdDat( DWORD cmd );

  public:
    //---------------------------------------------------------------
    static cHwUSB_0 *usbPtr;

  private:
    //---------------------------------------------------------------
    static const WORD USB_EP_NUM  = 10;
  
  BYTE isSetup;
  BYTE deviceAddress;
 
}; //cHwUSB

#endif
