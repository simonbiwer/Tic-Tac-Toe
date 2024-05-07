//*******************************************************************
/*!
\file   devAnalog.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _DEV_ANALOG_H
#define _DEV_ANALOG_H

//*******************************************************************
/*!
\class cDevAnalog

\brief Access to analog I/O devices

This class is an interface to analog I/O devices.
It supports also a linear conversion between raw value and physical
quantity

\example cDevAnalog.cpp
*/
class cDevAnalog
{
  protected:
    //---------------------------------------------------------------
    // Instatiate an analog device
    // channel: Device input or output channel
    // gain:    Conversion factor
    // offset:  Conversion offset
    cDevAnalog( BYTE  channel,
                float gain,
                float offset );

  protected:
    //---------------------------------------------------------------
    BYTE  channel;
    float gain;
    float offs;

}; //cDevAnalog

#endif
