//*******************************************************************
/*!
\file   Touch.cpp
\author Thomas Breuer
\date   11.03.2013
*/

//*******************************************************************
#include "Touch.h"

//*******************************************************************
//
// cHwTouch
//
//*******************************************************************
//-------------------------------------------------------------------
cHwTouch::cHwTouch( WORD widthIn, 
                    WORD heightIn )
{
  width  = widthIn;
  height = heightIn;
  xPos   = 0;
  yPos   = 0;
  isTouchedFlag = false;
}

//-------------------------------------------------------------------
inline WORD cHwTouch::getPosX( void )
{
  return( xPos );
}

//-------------------------------------------------------------------
inline WORD cHwTouch::getPosY( void )
{
  return( yPos );
}

//-------------------------------------------------------------------
inline BYTE cHwTouch::isTouched( void )
{
  return( isTouchedFlag );
}

//EOF
