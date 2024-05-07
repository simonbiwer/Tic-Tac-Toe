//*******************************************************************
/*!
\file   devAnalogIn.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "devAnalogIn.h"

//*******************************************************************
//
// cDevAnalogIn
//
//*******************************************************************
//-------------------------------------------------------------------
cDevAnalogIn::cDevAnalogIn( BYTE  channel,
                            float max,
                            float min )

: cDevAnalog( channel,
              (max-min)/(float)0xFFFF,
               min )

{
}

//-------------------------------------------------------------------
inline float cDevAnalogIn::get( void )
{
  return( gain*getRaw() + offs );
}

//-------------------------------------------------------------------
inline cDevAnalogIn::operator float( void )
{
  return( get() );
}

//-------------------------------------------------------------------
void cDevAnalogIn::calibrate( float x1, 
                              float y1,
                              float x2,
                              float y2
                            )
{
  if( x1 != x2 ) 
  {
    gain = (y2-y1)/(x2-x1);
    offs = y1 - gain*x1;
  }
}

//EOF
