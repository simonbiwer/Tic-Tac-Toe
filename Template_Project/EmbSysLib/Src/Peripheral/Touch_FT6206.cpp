//*******************************************************************
/*!
\file   Touch_FT6206.cpp
\author Thomas Breuer
\date   03.04.2019

\see 
*/

//*******************************************************************
#include "lib.h"
#include "Peripheral/Touch_FT6206.h"

//*******************************************************************
//
// cHwTouch_FT6206
//
//*******************************************************************
//-------------------------------------------------------------------
cHwTouch_FT6206::cHwTouch_FT6206( cHwI2Cmaster &i2cIn )

: cHwTouch( WIDTH, HEIGHT ), 
  i2c( i2cIn, hwAddr )
{
}

//-------------------------------------------------------------------
void cHwTouch_FT6206::update( void )
{
	BYTE data[4];
	
	i2c.read( (BYTE)0x03, data, 4 );
	if( !i2c.isError() )
  {
		if( ( data[0] & 0xC0 ) == 0x80 )
    {
      xPos =           ((WORD)(data[2]&0x0F)<<8) | data[3];
      yPos = height - (((WORD)(data[0]&0x0F)<<8) | data[1]);
      isTouchedFlag = true;
    }
    else
    {
      isTouchedFlag = false;
    } 	
	}
}

//EOF
