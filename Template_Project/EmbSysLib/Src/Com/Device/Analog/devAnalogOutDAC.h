//*******************************************************************
/*!
\file   devAnalogOutDAC.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.

*/

//*******************************************************************
#ifndef _DEV_ANALOG_OUT_DAC_H
#define _DEV_ANALOG_OUT_DAC_H

//*******************************************************************
#include "devAnalogOut.h"
#include "Com/Hardware/Analog/DAC.h"

//*******************************************************************
/*!
\class cDevAnalogOutDAC

\brief Analog input device, using cHwDAC

\example cDevAnalog.cpp
*/
class cDevAnalogOutDAC : public cDevAnalogOut
{
  public:
    //---------------------------------------------------------------
    /*! Instatiate a analog output device
        \param dac     Reference to DAC hardware
        \param channel Channel ID
        \param max     Analog value corresponding to maximum raw value
        \param min     Analog value corresponding to minimum raw value
    */
    cDevAnalogOutDAC( cHwDAC &dac,
                      BYTE    channel = 0,
                      float   max     = 1.0f,
                      float   min     = 0.0f );

  public:
    //---------------------------------------------------------------
    /*! Set the raw output value [0,..,0xFFFF]
        \param value Value to set
    */
    virtual void setRaw( WORD value );

  private:
    //---------------------------------------------------------------
    cHwDAC &dac;

  public:
    //---------------------------------------------------------------
    using cDevAnalogOut::operator=;

}; //cDevAnalogOutDAC

#endif
