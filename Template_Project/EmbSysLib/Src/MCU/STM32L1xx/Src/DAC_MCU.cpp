//*******************************************************************
/*!
\file   DAC_MCU.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "DAC_MCU.h"
#include "../Sys/PinConfig.h"

//*******************************************************************
// 
// cHwDAC_0
//
//*******************************************************************
//-------------------------------------------------------------------
cHwDAC_0::cHwDAC_0( void )

: cHwDAC( 2 )

{
  RCC->APB1ENR |= RCC_APB1ENR_DACEN;
}

//-------------------------------------------------------------------
inline void cHwDAC_0::set( WORD value, BYTE ch )
{
  switch( ch )
  {
    default:
      // error
      break;
    case 0: DAC->DHR12L1 = value & 0xFFF0; break;
    case 1: DAC->DHR12L2 = value & 0xFFF0; break;
  }
}

//-------------------------------------------------------------------
inline void cHwDAC_0::enable( BYTE ch )
{
  switch( ch )
  {
    default:
      // error!
      break;
    
    case 0: 
      cHwPinConfig::set( cHwPinConfig::DAC_OUT1, cHwPinConfig::ANALOG );
      DAC->CR |=   DAC_CR_EN1
                 | DAC_CR_BOFF1;
      break;
    
    case 1:
      cHwPinConfig::set( cHwPinConfig::DAC_OUT2, cHwPinConfig::ANALOG );
      DAC->CR |=   DAC_CR_EN2
                 | DAC_CR_BOFF2; 
      break;
  }
}

//EOF
