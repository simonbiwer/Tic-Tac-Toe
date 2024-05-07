//*******************************************************************
/*!
\file   cDevDigitalIndicator.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "devDigitalIndicator.h"

//*******************************************************************
//
// cDevDigitalIndicator
//
//*******************************************************************
//-------------------------------------------------------------------
cDevDigitalIndicator::cDevDigitalIndicator( cDevDigital &devDigitalIn,
                                            cHwTimer    &timerIn )
: devDigital( devDigitalIn ),
  timer     ( timerIn      )
{
  timeout   = 0;
  cycleTime = timer.getCycleTime();
  clr();
  timer.add(this);

    limit = 0;
    maxi  = 1000;
    pwr   = 1;
    mean  = 0;
    t = 0;
    p = 0;
    G = 25E3/cycleTime; // Tics in 25ms (@40Hz)
    P=0;
    M=G;
    maxi = 1;
    limit = 0;
    pwr = 0;
    blink_flag=false;

}

//-------------------------------------------------------------------
void cDevDigitalIndicator::update( void )
{
  if( timeout > 0 )
  {
    timeout--;
    if( timeout == 0 )
    {
      clr();
    }
  }

  else if( blink_flag )
  {
    if( mean <= 0 )
    {
       devDigital.set(0);
       mean += P;
    }
    else
    {
       devDigital.set(1);
       mean -= M;
    }

    t++;
    if( t>=maxi)
    {
        P = pwr;
        M = G-pwr;
        t  = 0;
    }
    else if(t>limit)
    {
        P=0;
        M=G;
    }
  }
}

//EOF
