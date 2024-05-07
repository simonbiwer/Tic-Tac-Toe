//*******************************************************************
/*!
\file   ADC_MCU.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "ADC_MCU.h"
#include "../Sys/PinConfig.h"

//*******************************************************************
//
// cHwADC_0
//
//*******************************************************************
//-------------------------------------------------------------------
cHwADC *cHwADC_0::adcPtr = 0;

//-------------------------------------------------------------------
cHwADC_0::cHwADC_0( cHwTimer *tPtrIn )

: cHwADC( 16, tPtrIn )

{
  adcPtr = this;

  RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

  ADC1->CR2 |=    ADC_CR2_ADON  // A/D Converter: ON
               | !ADC_CR2_CONT  // Continuous Conversion: OFF
               |  ADC_CR2_ALIGN;// Data alignment: left

  ADC1->CR1 |=    ADC_CR1_EOCIE; // End of conversion interrupt: enable

  while( !(ADC1->SR & ADC_SR_ADONS) );

  NVIC_EnableIRQ( ADC1_IRQn );
}

//-------------------------------------------------------------------
void cHwADC_0::configCh( BYTE ch, BYTE para )
{
  switch( ch )
  {
    default:
      // error!
      break;
    case  2: cHwPinConfig::set( cHwPinConfig::ADC12_IN2,  cHwPinConfig::ANALOG ); break;
    case  3: cHwPinConfig::set( cHwPinConfig::ADC12_IN3,  cHwPinConfig::ANALOG ); break;
    case  6: cHwPinConfig::set( cHwPinConfig::ADC12_IN6,  cHwPinConfig::ANALOG ); break;
    case  7: cHwPinConfig::set( cHwPinConfig::ADC12_IN7,  cHwPinConfig::ANALOG ); break;
    case 12: cHwPinConfig::set( cHwPinConfig::ADC12_IN12, cHwPinConfig::ANALOG ); break;
    case 13: cHwPinConfig::set( cHwPinConfig::ADC12_IN13, cHwPinConfig::ANALOG ); break;
    case 14: cHwPinConfig::set( cHwPinConfig::ADC12_IN14, cHwPinConfig::ANALOG ); break;
    case 15: cHwPinConfig::set( cHwPinConfig::ADC12_IN15, cHwPinConfig::ANALOG ); break;

  }
}

//-------------------------------------------------------------------
inline WORD cHwADC_0::getResult( void )
{
  return( ADC1->DR & 0xFFFF );
}

//-------------------------------------------------------------------
inline void cHwADC_0::startCh( BYTE ch )
{
  // select channel
  ADC1->SQR5 = ch & 0x1F;

  ADC1->CR2 |= ADC_CR2_SWSTART;
}

//-------------------------------------------------------------------
extern "C"
{
  void ADC1_IRQHandler(void)
  {
    ADC1->SR &= ~ADC_SR_EOC;
    cHwADC_0::adcPtr->isr();
  }
}

//EOF
