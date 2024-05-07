//*******************************************************************
/*!
\file   devMotorDirection.cpp
\author Thomas Breuer
\date   22.02.2019
*/

//*******************************************************************
//
// cDevMotorDirection
//
//*******************************************************************
//-------------------------------------------------------------------
cDevMotorDirection::cDevMotorDirection( cDevDigital    &cwIn,
                                        cDevDigital    &ccwIn,
                                        cDevAnalogOut  &pwmIn )
  : cw ( cwIn  ),
    ccw( ccwIn ),
    pwm( pwmIn )
{
}

//-------------------------------------------------------------------
void cDevMotorDirection::run( float speed )
{
  if( speed > 0 )
  {
    ccw.clr();
    cw.set();
    pwm = speed;
  }
  else if( speed < 0 )
  {
    cw.clr();
    ccw.set();
    pwm = -speed;
  }
  else
  {
    ccw.clr();
    cw.clr();
    pwm = 0;
  }  
}

//-----------------------------------------------------------------
void cDevMotorDirection::brake( void )
{
  cw.set();
  ccw.set();
  pwm = 0;
}

//EOF
