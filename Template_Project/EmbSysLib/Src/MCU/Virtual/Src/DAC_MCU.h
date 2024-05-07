//*******************************************************************
/*!
\file   DAC_Virtual.h
\author Thomas Breuer
\date   21.01.2013
*/

//*******************************************************************
#ifndef _HW_DAC_VIRTUAL_H
#define _HW_DAC_VIRTUAL_H
//*******************************************************************
#include "Com/Hardware/Analog/DAC.h"
#include "MCU/Virtual/Sys/UDPclient.h"

//*******************************************************************
/*!
\class cHwDAC_Virtual

\brief Implementation of the digital to analog converter (DAC)

\example cHwDAC.cpp
*/
class cHwDAC_Virtual : public cHwDAC
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
    /*! Initialize the DAC hardware
        \param client Reference to a client
    */
    cHwDAC_Virtual( cNetAddr<4> addr, WORD port );

    //---------------------------------------------------------------
    virtual void set( WORD value,
                      BYTE ch = 0 );

    //---------------------------------------------------------------
    virtual void enable( BYTE ch = 0 ) { /* nothing to do */ }

  private:
    //---------------------------------------------------------------
    UDPclient   client;

}; // cHwDAC_Virtual

#endif
