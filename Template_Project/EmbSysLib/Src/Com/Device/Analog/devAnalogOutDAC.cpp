//*******************************************************************
/*!
\file   devAnalogOutDAC.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "devAnalogOutDAC.h"

//*******************************************************************
//
// cDevAnalogOutDAC
//
//*******************************************************************
//-------------------------------------------------------------------
cDevAnalogOutDAC::cDevAnalogOutDAC( cHwDAC &dacIn,
                                    BYTE    channel,
                                    float   max,
                                    float   min )

:cDevAnalogOut( channel, max, min ),
 dac          ( dacIn )

{
  dac.enable( channel );
}

//-------------------------------------------------------------------
void cDevAnalogOutDAC::setRaw( WORD value )
{
  dac.set( value, channel );
}

//EOF
