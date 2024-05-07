//*******************************************************************
/*!
\file   USBendpoint.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_USB_ENDPOINT_H
#define _HW_USB_ENDPOINT_H

//*******************************************************************
#include "Com/Std/DataPointer.h"

//*******************************************************************
class cHwUSB;

//*******************************************************************
/*!
\class cHwUSBendpoint

\brief Endpoint
*/
class cHwUSBendpoint
{
  private:
    //---------------------------------------------------------------
    // non-control endpoint:
    cHwUSBendpoint( cHwUSB       &usb,
                    cHwUSBinterf *interfIn,
                    BYTE          id,
                    WORD          maxPacketSize,
                    BYTE          attributes  );

    //---------------------------------------------------------------
    // control endpoint:
    cHwUSBendpoint( cHwUSB       &usb,
                    BYTE          id,
                    WORD          maxPacketSize );

    //---------------------------------------------------------------
    void in( void );

    //---------------------------------------------------------------
    void inCtrl( void );

    //---------------------------------------------------------------
    void out( void );

    //---------------------------------------------------------------
    void outCtrl( void );

    //---------------------------------------------------------------
    WORD readData( void );

    //---------------------------------------------------------------
    void writeData( void );

    //---------------------------------------------------------------
  public: // \todo check public
    void writeData( const cDataPointer &epDataIn );

  private:
    //---------------------------------------------------------------
    void writeDataLen( const cDataPointer &epDataIn,
                       WORD                maxLen );

    //---------------------------------------------------------------
    void writeAcknowledge( void );

    //---------------------------------------------------------------
    void readAcknowledge( void );

    //-------------------------------------------------------------------
    void stall( void );

    //-------------------------------------------------------------------
    void clrStall( void );

    //-------------------------------------------------------------------
    void clrFeature( void );

    //---------------------------------------------------------------
    void setConfiguration( void );

  private:
    //-------------------------------------------------------------------
    cHwUSB        &usb;
    cHwUSBinterf  *interf;
    cDataPointer   epData;
    BYTE           id;
    WORD           maxPacketSize;
    BYTE           attributes;

  //---------------------------------------------------------------------
  friend class cHwUSB;
  friend class cHwUSBctrl;
  friend class cHwUSBinterf;

}; //cHwUSBendpoint

#endif
