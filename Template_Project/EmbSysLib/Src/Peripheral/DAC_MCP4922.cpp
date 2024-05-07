//*******************************************************************
/*!
\file   DAC_MCP4922.cpp
\author Thomas Breuer
\date   30.03.2011
*/

//*******************************************************************
#include "Peripheral/DAC_MCP4922.h"

//*******************************************************************
//
// cHwDAC_MCP4922
//
//*******************************************************************
//-------------------------------------------------------------------
cHwDAC_MCP4922::cHwDAC_MCP4922( cHwSPImaster::Device &spiIn,
                                BYTE                  gainIn )

: cHwDAC( 2 ),
  spi( spiIn )

{
  ga = gainIn?0:1;
}

//-------------------------------------------------------------------
void cHwDAC_MCP4922::set( WORD value, BYTE ch )
{
  BYTE ctrl = (ch<<7)   // channel select, 0:A, 1:B
             |( 0<<6)   // BUF: Vref Input unbuffered
             |(ga<<5)   // GA:  Gain control, 1: Vmax = Vreff, 0:Vmax=2*Vreff
             |( 1<<4);  // SHDN:Output Power Down: normal Output

  spi.write( (WORD)(   ((WORD)ctrl<<8)
                     | (value     >>4) ));
}

//EOF
