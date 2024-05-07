//*******************************************************************
/*!
\file   Module/ISC_USBdevice.h
\author Thomas Breuer
\date   11.12.2014, 17.03.2016
*/

//*******************************************************************
#ifndef _ISC_USB_DEVICE_H
#define _ISC_USB_DEVICE_H

//*******************************************************************
#include "Module/ISC.h"
#include "Module/USB/USBinterfClassVSC.h"

//*******************************************************************
/*!
\class cISC_USBdevice

\brief ISC transport class with USB hardware

\remark The length of the payload is limited to 60 bytes

\example cISC.cpp
*/
class cISC_USBdevice : public cISC,
                       public cUSBinterfClassVSC< cISC::DATA,
                                                  cISC::DATA >
{
  public:
    //---------------------------------------------------------------
    /*! Instantiate an ISC transport object with USB interface

        \param uart Reference to USB hardware
        \param interfId USB interface ID
        \param crcMode Select CRC calculation mode (FAST or SMALL)
    */
    cISC_USBdevice( cHwUSB    &usb,
                    BYTE       interfId,
                    cCRC::MODE crcMode = cCRC::SMALL );

    //---------------------------------------------------------------
    /*! Update the ISC transport object

        NOT required with USB
    */
     virtual void update( void );

   private:
    //---------------------------------------------------------------
    virtual void writeStream( BYTE  id,
                              BYTE *data,
                              BYTE  size,
                              WORD  crc );

    //---------------------------------------------------------------
    virtual int onTransmit( cISC::DATA &data );

    //---------------------------------------------------------------
    virtual int onReceive( cISC::DATA &data );

  private:
    //---------------------------------------------------------------
    cHwUSB &usb;

    cFifo<cISC::DATA> fifo;

}; //cISC_USBdevice

#endif
