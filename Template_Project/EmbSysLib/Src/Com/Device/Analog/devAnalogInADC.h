//*******************************************************************
/*!
\file   devAnalogInADC.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _DEV_ANALOG_IN_ADC_H
#define _DEV_ANALOG_IN_ADC_H

//*******************************************************************
#include "devAnalogIn.h"
#include "Com/Hardware/Analog/ADC.h"

//*******************************************************************
/*!
\class cDevAnalogInADC

\brief Analog input device, using cHwADC

\example cDevAnalog.cpp
*/
class cDevAnalogInADC : public cDevAnalogIn
{
  public:
    //---------------------------------------------------------------
    /*! Instatiate a analog input device
        \param adc     Reference to ADC hardware
        \param channel Channel ID
        \param max     Analog value corresponding to maximum raw value
        \param min     Analog value corresponding to minimum raw value
    */
    cDevAnalogInADC( cHwADC &adc,
                     BYTE    channel = 0,
                     float   max     = 1.0,
                     float   min     = 0.0,
                     BYTE    para    = 0 );

  public:
    //---------------------------------------------------------------
    /*! Get the raw input value
        \return Raw value in range of [0,..,0xFFFF]
    */
    virtual WORD getRaw( void );

    virtual void enable();

  private:
    //---------------------------------------------------------------
    cHwADC &adc;

}; //cDevAnalogInADC

#endif
