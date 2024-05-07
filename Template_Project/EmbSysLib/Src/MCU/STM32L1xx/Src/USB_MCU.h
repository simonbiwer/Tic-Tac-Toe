//*******************************************************************
/*!
\file   USB_MCU.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_USB_MCU_H
#define _HW_USB_MCU_H

//*******************************************************************
#include "Com/Hardware/USB/USB.h"

//*******************************************************************
/*!
\class cHwUSB

\brief

\example cHwUSB.cpp

// \todo Kommentare und Doku!
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
    void isr( void );

    //---------------------------------------------------------------
    virtual void start( void );

  private:
    //---------------------------------------------------------------
    class EPconfig
    {
      public:
        //-----------------------------------------------------------
        EPconfig()
        {
          regPtr = NULL;
          config = 0;
          rxPtr = NULL;
          txPtr = NULL;
        }

        //-----------------------------------------------------------
        void init( DWORD addrIn, DWORD type, DWORD kind, WORD sizeIn);

        //-----------------------------------------------------------
        WORD *bdt_init(BYTE num, BYTE isRX, WORD size);

        //-----------------------------------------------------------
        void clrCTR_RX();

        //-----------------------------------------------------------
        void clrCTR_TX( );

        //-----------------------------------------------------------
        void setSTAT_RX( DWORD stat);

        //-----------------------------------------------------------
        void setSTAT_TX(DWORD stat);

        //-----------------------------------------------------------
        DWORD config;
        DWORD *regPtr;
        DWORD addr;
        WORD  rxSize;
        WORD  txSize;
        WORD *txPtr;
        WORD *rxPtr;

        //------------------------------------------------------------
        static WORD offset;

    };  // class EPconfig


  private:
    //---------------------------------------------------------------
    virtual void reset( void );

    //---------------------------------------------------------------
    virtual void configure( BYTE flag );

    //---------------------------------------------------------------
    virtual void setAddress( BYTE adr = 0 );

    //---------------------------------------------------------------
    virtual void configEP( BYTE epAddr,
                           WORD epMaxPacketSize,
                           BYTE epType );

    //---------------------------------------------------------------
    virtual void setStallEP( BYTE epAddr );

    //---------------------------------------------------------------
    virtual void clrStallEP( BYTE epAddr );

    //---------------------------------------------------------------
    virtual WORD readEP( BYTE  epAddr,
                         BYTE *dataPtr,
                         WORD  len );

    //---------------------------------------------------------------
    virtual WORD writeEP( BYTE  epAddr,
                          BYTE *pData,
                          WORD  cnt );

    //---------------------------------------------------------------
    BYTE epAddr2Index( BYTE epAddr )
    {
      return( ((epAddr & 0x0F) << 1) | ((epAddr & 0x80)?0x01:0x00) );
    }

  public:
    //---------------------------------------------------------------
    static cHwUSB_0 *usbPtr;

  private:
    //---------------------------------------------------------------
    static const WORD USB_EP_NUM = 32;

    EPconfig    EP[8];


}; //cHwUSB_0

#endif
