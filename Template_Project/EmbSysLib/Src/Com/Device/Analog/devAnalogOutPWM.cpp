//*******************************************************************
/*!
\file   devAnalogOutPWM.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.

*/

//*******************************************************************
#include "devAnalogOutPWM.h"

//*******************************************************************
//
// cDevAnalogOutPWM
//
//*******************************************************************
//-------------------------------------------------------------------
cDevAnalogOutPWM::cDevAnalogOutPWM( cHwTimer       &timerIn,
                                    cHwTimer::Mode  mode,
                                    BYTE            channel,
                                    float           max,
                                    float           min )

: cDevAnalogOut( channel, max, min ),
  timer        ( timerIn )

{
  timer.enablePWM( channel, mode );
}

//-------------------------------------------------------------------
void cDevAnalogOutPWM::setRaw( WORD value )
{
  timer.setPWM( value, channel );
}

//*******************************************************************
//
// cDevAnalogOutPWMemul
//
//*******************************************************************
//-------------------------------------------------------------------
cDevAnalogOutPWMemul::cDevAnalogOutPWMemul( cHwTimer    &timerIn,
                                            cDevDigital &portIn,
                                            BYTE         resIn,
                                            float        maxIn,
                                            float        minIn )
: cDevAnalogOut( 0, maxIn, minIn ),
  timer        ( timerIn         ),
  port         ( portIn          )

{
  shift = 16 - resIn;
  max   = (WORD)(0x0001L << resIn) - 1;
  t     = 0;
  timer.add(this);
}

//-------------------------------------------------------------------
void cDevAnalogOutPWMemul::setRaw( WORD value )
{
  limitBuf << (WORD)(value>>shift);
}

//-------------------------------------------------------------------
void cDevAnalogOutPWMemul::update( void )
{
  if( t >= max )
  {
    t = 0;
    port.set();
    limitBuf >> limit;
  }
  if( t == limit )
  {
    port.clr();
  }
  t++;
}

//EOF
