//*******************************************************************
/*!
\file   DAC_MAX5308.cpp
\author Thomas Breuer
\date   24.03.2011
*/

//*******************************************************************
#include "Peripheral/DAC_MAX5308.h"

//*******************************************************************
// 
// cHwDAC_MAX5308
//
//*******************************************************************
//-------------------------------------------------------------------
cHwDAC_MAX5308::cHwDAC_MAX5308( cHwSPImaster::Device &spiIn )

: cHwDAC( 8 ),
  spi( spiIn )

{
  spi.write( (WORD)0x1000 ); // Reset
  spi.write( (WORD)0xFFFF ); // Power-Up all DAC's
}

//-------------------------------------------------------------------
void cHwDAC_MAX5308::set( WORD value, BYTE ch )
{
  WORD data = (value >> 4) & 0x0FF3; // shift to 10 bit (data bit 0..9 => output bit 2..11)
  WORD ctrl = (ch&0x07)+2;           // 3 bit with offset

  spi.write( (WORD)(  (ctrl<<12)     // control bits = channel select
                     |(data<< 0) )); // data bits
}

//EOF
