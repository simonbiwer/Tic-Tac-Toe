//*******************************************************************
/*!
\file   devControlEncoderJoystick.cpp
\author Thomas Breuer
\date   12.04.2011
*/

//*******************************************************************
//
// cDevControlEncoderJoystick
//
//*******************************************************************
//-------------------------------------------------------------------
cDevControlEncoderJoystick::cDevControlEncoderJoystick( cDevDigital *btnLeftIn,
                                          cDevDigital *btnRightIn,
                                          cDevDigital *btnCtrlIn,
                                          cHwTimer    *timerPtr,
                                          WORD         repeatTime )

: cDevControlEncoder( btnCtrlIn, timerPtr ),
  btnLeft    ( btnLeftIn ),
  btnRight   ( btnRightIn )
{
  if( timerPtr && timerPtr->getCycleTime() )
  {
    timerStart = 1000UL*repeatTime/timerPtr->getCycleTime();
    //           ------ ms to sec
  }
  else
  {
    timerStart = 0;
  }
  timerCnt = timerStart;
}

//-------------------------------------------------------------------
cDevControlEncoder::tEvent cDevControlEncoderJoystick::getIncrement( void )
{
  if( timerCnt )
  {
    timerCnt--;
  }

  if( btnLeft )
  {
    if(    btnLeft->getEvent() == cDevDigital::ACTIVATED
        || (!timerCnt && timerStart && btnLeft->get()) )
    {
      timerCnt = timerStart;
      return( LEFT );
    }
  }

  if( btnRight )
  {
    if(   btnRight->getEvent() == cDevDigital::ACTIVATED
       || (!timerCnt && timerStart && btnRight->get()) )
    {
      timerCnt = timerStart;
      return( RIGHT );
    }
  }
  return( NONE );
}

//EOF
