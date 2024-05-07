//*******************************************************************
/*!
\file   USBhardware.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//#include "USBctrl.h"
//#include "USBdesc.h"
//*******************************************************************
#ifndef _HW_USB_HARDWARE_H
#define _HW_USB_HARDWARE_H

//*******************************************************************
/*!
\class cHwUSB

\brief Abstract interface to USB hardware

\example cHwUSB.cpp
*/
class cHwUSB
{
  protected:
    //---------------------------------------------------------------
    cHwUSB( cHwUSBdesc &desc );

    //---------------------------------------------------------------
    virtual void eventHandler( BYTE EPnum,
                               BYTE isSetup );
  public:
    //---------------------------------------------------------------
    /*! Start USB
    */
    virtual void start( void ) = 0;

  protected:
    //---------------------------------------------------------------
    virtual void reset( void ) = 0;

    //---------------------------------------------------------------
    virtual void configure( BYTE flag ) = 0;

    //-------------------------------------------------------------------
    virtual void setAddress( BYTE addr ) = 0;

    //---------------------------------------------------------------
    virtual void configEP( BYTE epAddr,
                           WORD epMaxPacketSize,
                           BYTE epType          ) = 0;

    //---------------------------------------------------------------
    virtual void setStallEP( BYTE epAddr ) = 0;

    //---------------------------------------------------------------
    virtual void clrStallEP( BYTE epAddr ) = 0;

    //---------------------------------------------------------------
    virtual WORD readEP( BYTE  epAddr,
                         BYTE *dataPtr,
                         WORD  len     ) = 0;

    //---------------------------------------------------------------
    virtual WORD writeEP( BYTE  epAddr,
                          BYTE *dataPtr,
                          WORD  len     ) = 0;

  protected:
    //---------------------------------------------------------------
    cHwUSBdesc   &desc;   // must be the first one
    cHwUSBctrl    epCtrl;

  //-----------------------------------------------------------------
  friend class cHwUSBctrl;
  friend class cHwUSBendpoint;
  friend class cHwUSBinterf;

}; //cHwUSB

#endif
