//*******************************************************************
/*!
\file   devAnalogOut.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _DEV_ANALOG_OUT_H
#define _DEV_ANALOG_OUT_H

//*******************************************************************
#include "devAnalog.h"

//*******************************************************************
/*!
\class cDevAnalogOut

\brief Abstract class for analog output devices

Uses the conversion
 - raw = gain*(x - min)

with
 - gain = 0xFFFF/(max - min)
*/
class cDevAnalogOut : public cDevAnalog
{
  protected:
    //---------------------------------------------------------------
    // Instatiate a analog output device
    // channel: Device output channel
    // max:     Analog value corresponding to maximum raw value
    // min:     Analog value corresponding to minimum raw value
    cDevAnalogOut( BYTE  channel,
                   float max,
                   float min = 0.0f );

  public:
    //---------------------------------------------------------------
    /*! Set the physical quantity
        \param value Value to set
    */
    virtual void set( float value );

    //---------------------------------------------------------------
    /*! Set the physical quantity
        \param value Value to set
        \return value
    */
    virtual float operator=( float value );

    //---------------------------------------------------------------
    /*! Set the raw output value [0,..,0xFFFF]
        \param value Value to set
    */
    virtual void setRaw( WORD value ) = 0;

}; //cDevAnalogOut

#endif
