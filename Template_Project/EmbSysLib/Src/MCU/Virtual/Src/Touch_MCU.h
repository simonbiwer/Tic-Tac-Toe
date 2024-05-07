//*******************************************************************
/*!
\file   Touch_Virtual.h
\author Thomas Breuer
\date   10.03.2013
*/

//*******************************************************************
#ifndef _HW_TOUCH_VIRTUAL_H
#define _HW_TOUCH_VIRTUAL_H

//*******************************************************************
#include "Com/Hardware/Display/Touch.h"
#include "MCU/Virtual/Sys/UDPclient.h"

//*******************************************************************
/*!
\class cHwTouch_Virtual

\brief Abstract class supporting touch sensor of graphic displays

\example cHwTouch.cpp
*/
class cHwTouch_Virtual : public cHwTouch
{
  public:
    //---------------------------------------------------------------
    class Data
    {
      public:
        BYTE      cmd;
        cNetWORD  x;
        cNetWORD  y;
        cNetWORD  c;
        cNetWORD  d;
        cNetWORD  color;
    };
  public:
    //---------------------------------------------------------------
    /*! Initialize virtual touch sensor
        \param client Reference to a client
        \param width  Touch area width
        \param height Touch area height
    */
    cHwTouch_Virtual( cNetAddr<4> addr, WORD port,
                      WORD       width,
                      WORD       height );

  public:
    /*! Update coordinates and flags. This method must be called to
        read new data from the touch controller
    */
    virtual void update( void );

  private:
    //---------------------------------------------------------------
   /// cHwClient &client;
UDPclient   client;
}; //cHwTouch_Virtual;

#endif
