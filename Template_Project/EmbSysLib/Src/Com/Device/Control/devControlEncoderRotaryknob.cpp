//*******************************************************************
/*!
\file   devControlEncoderRotaryKnob.cpp
\author Thomas Breuer
\date   12.04.2011
*/


//*******************************************************************
//
// cDevControlEncoderRotaryKnob
//
//*******************************************************************
//-------------------------------------------------------------------
cDevControlEncoderRotaryKnob::cDevControlEncoderRotaryKnob( cDevDigital *btnLeftIn,
                                              cDevDigital *btnRightIn,
                                              cDevDigital *btnCtrlIn,
                                              cHwTimer    *timerPtr )
: cDevControlEncoder( btnCtrlIn, timerPtr ),
  btnLeft    ( btnLeftIn ),
  btnRight   ( btnRightIn )

{
}

//-------------------------------------------------------------------
cDevControlEncoder::tEvent cDevControlEncoderRotaryKnob::getIncrement( void )
{
  if( btnLeft && btnRight )
  {
    switch( btnLeft->getEvent() )
    {
      case cDevDigital::ACTIVATED:
          return( btnRight->get()?NONE:LEFT );

      case cDevDigital::RELEASED:
          return( btnRight->get()?LEFT:NONE );
    }

    switch( btnRight->getEvent() )
    {
      case cDevDigital::ACTIVATED:
          return( btnLeft->get()?NONE:RIGHT );

      case cDevDigital::RELEASED:
          return( btnLeft->get()?RIGHT:NONE );
    }
  }
  return( NONE );
}

//EOF
