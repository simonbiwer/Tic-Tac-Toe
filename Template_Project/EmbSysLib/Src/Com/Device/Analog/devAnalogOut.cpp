//*******************************************************************
/*!
\file   devAnalogOut.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "devAnalogOut.h"

//*******************************************************************
//
// cDevAnalogOut
//
//*******************************************************************
//-------------------------------------------------------------------
cDevAnalogOut::cDevAnalogOut( BYTE  channel,
                              float max,
                              float min )

: cDevAnalog( channel,
              (float)0xFFFF*( (max != min) ? 1.0F/(max-min) : 1.0F ),
              min )

{
}

//-------------------------------------------------------------------
void cDevAnalogOut::set( float value )
{
  setRaw( (WORD)RANGE( gain*(value - offs),
                      (float)0,
                      (float)0xFFFF) );
}

//-------------------------------------------------------------------
inline float cDevAnalogOut::operator=( float value )
{
  set( value );
  return( value );
}

//EOF
