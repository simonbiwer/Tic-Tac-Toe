//*******************************************************************
/*!
\file   DAC_MCU.cpp
\author Thomas Breuer
\date   14.02.2011
*/

//*******************************************************************
// 
// cHwDAC_0
//
//*******************************************************************
//-------------------------------------------------------------------
cHwDAC_0::cHwDAC_0( void )

: cHwDAC( 1 )

{
  cHwPinConfig::set( cHwPinConfig::AOUT, cHwPinConfig::NOPUPD );

  LPC_SC->PCLKSEL0     &=~(3<<22); // Set PCLK_DAC = CCLK/4
  LPC_SC->PCLKSEL0     |= (0<<22); //

  LPC_DAC->DACCNTVAL    = 25;      // Divider: 25Mhz -> 1MHz

  LPC_DAC->DACCTRL      =  (1<<1)  // DBLBUF_ENA: double buffering enable
                          |(1<<2); // CNT_ENA:    time-out counter enable
}

//-------------------------------------------------------------------
inline void cHwDAC_0::set( WORD value, BYTE ch )
{
  if( ch == 0 )
  {
    // 16 Bit -> 10 Bit, Register erwartet Value in Bit 15:6
    LPC_DAC->DACR = value & (0x3FF<<6);
  }
}

//EOF
