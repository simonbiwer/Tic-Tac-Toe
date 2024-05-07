//*******************************************************************
/*!
\file   devAnalogInADC.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "devAnalogInADC.h"

//*******************************************************************
//
// cDevAnalogInADC
//
//*******************************************************************
//-------------------------------------------------------------------
cDevAnalogInADC::cDevAnalogInADC( cHwADC &adcIn,
                                  BYTE    channel,
                                  float   max,
                                  float   min,
                                  BYTE    para )

: cDevAnalogIn( channel, max, min ),
  adc         ( adcIn )

{
  adc.enable( channel, para );
}

//-------------------------------------------------------------------
WORD cDevAnalogInADC::getRaw( void )
{
  return( adc.get( channel ) );
}

void cDevAnalogInADC::enable()
{
    adc.enable( channel, 0 );
}
//EOF
