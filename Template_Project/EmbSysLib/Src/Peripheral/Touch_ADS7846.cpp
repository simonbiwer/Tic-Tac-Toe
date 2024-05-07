//*******************************************************************
/*!
\file   Touch_ADS7846.cpp
\author Thomas Breuer
\date   11.03.2013
*/

//*******************************************************************
#include "Peripheral/Touch_ADS7846.h"

//*******************************************************************
//
// cHwTouch_ADS7846
//
//*******************************************************************
//-------------------------------------------------------------------
cHwTouch_ADS7846::cHwTouch_ADS7846( cHwSPImaster::Device &spiIn, 
                                    WORD                  width,
                                    WORD                  height )

: cHwTouch( width, height),
  spi( spiIn )
{
}

//-------------------------------------------------------------------
void cHwTouch_ADS7846::update( void )
{
  xPos = (DWORD)width  * (0x0FFF - readData(1)) / 0x1000;
  yPos = (DWORD)height * (         readData(5)) / 0x1000;

  isTouchedFlag = ( readData(3) > 0x50 ) ? true : false;  
}

//-------------------------------------------------------------------
int cHwTouch_ADS7846::readData( BYTE ch )
{
  BYTE data[3] = {0,0,0};
  int  res;

  data[0] =   ( 1<<7)  // S:         ON
             |(ch<<4)  // Channel
             |( 0<<3)  // MODE:      12bit
             |( 0<<2)  // SER/#DFR:  Differential;
             |( 3<<0); // PowerDown: Disable

  spi.transceive( data, 3 );

  res = ( (((WORD)data[1]<<8) | data[2]) >> 3 ) & 0xFFF;
 
  return( res );
}

//EOF
