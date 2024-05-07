//*******************************************************************
/*!
\file   ADC_Virtual.h
\author Thomas Breuer
\date   15.10.2013
*/

//*******************************************************************
#ifndef _HW_ADC_VIRTUAL_H
#define _HW_ADC_VIRTUAL_H

//*******************************************************************
#include "Com/Hardware/Analog/ADC.h"
//#include "Hardware/Virtual/Client/Client.h"
#include "MCU/Virtual/Sys/UDPclient.h"


//*******************************************************************
/*!
\class cHwADC_Virtual

\brief Implementation of the analg to digital converter (ADC)

\example cHwADC_Virtual.cpp
*/
class cHwADC_Virtual : public cHwADC
{
  public:
    //---------------------------------------------------------------
    class Data
    {
      public:
        BYTE      cmd;
        BYTE      ch;
        cNetWORD  value;
    };

  public:
    //---------------------------------------------------------------
    /*! Initialize the ADC hardware
        \param client Reference to a client
        \param tPtr   Reference to a timer object (option). If
                      declared, auto trigger conversion is used.
                      Otherwise the update() function must be called
                      explicit
    */
    cHwADC_Virtual( cNetAddr<4> addr, WORD port,

                    cHwTimer  *tPtr = 0 );

  private:
    //----------------------------------------
    virtual WORD getResult( void );

    //----------------------------------------
    virtual void startCh( BYTE ch );

    //----------------------------------------
    virtual void configCh( BYTE ch, BYTE para = 0 );

  private:
    //----------------------------------------
    //cHwClient &client;
    UDPclient   client;
    WORD       currentValue;

}; //cHwADC_Virtual

#endif
