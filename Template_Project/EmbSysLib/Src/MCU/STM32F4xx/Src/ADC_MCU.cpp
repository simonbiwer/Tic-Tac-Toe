//*******************************************************************
/*!
\file   ADC_MCU.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "ADC_MCU.h"

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

  ADC->CCR |= (3<<16); // ???

  ADC1->CR2  =    ADC_CR2_ADON  // A/D Converter: ON
               | !ADC_CR2_CONT  // Continuous Conversion: OFF
               |  ADC_CR2_ALIGN;// Data alignment: left

  ADC1->CR1 =    ADC_CR1_EOCIE; // End of conversion interrupt: enable

//  while( !(ADC1->SR & ADC_SR_ADONS) );

  NVIC_EnableIRQ( ADC_IRQn );
}

//-------------------------------------------------------------------
void cHwADC_0::configCh( BYTE ch, BYTE para )
{

  DWORD paraLoc = para & 0x07; // see: Channel-wise programmable sampling time

  switch( ch )
  {
    default:
      // error!
      break;
    case  0: cHwPinConfig::set( cHwPinConfig::ADC123_IN0,  cHwPinConfig::ANALOG ); ADC1->SMPR2 |= (paraLoc<< 0); break;
    case  1: cHwPinConfig::set( cHwPinConfig::ADC123_IN1,  cHwPinConfig::ANALOG ); ADC1->SMPR2 |= (paraLoc<< 3); break;
    case  2: cHwPinConfig::set( cHwPinConfig::ADC123_IN2,  cHwPinConfig::ANALOG ); ADC1->SMPR2 |= (paraLoc<< 6); break;
    case  3: cHwPinConfig::set( cHwPinConfig::ADC123_IN3,  cHwPinConfig::ANALOG ); ADC1->SMPR2 |= (paraLoc<< 9); break;
    case  4: cHwPinConfig::set( cHwPinConfig::ADC12_IN4,   cHwPinConfig::ANALOG ); ADC1->SMPR2 |= (paraLoc<<12); break;
    case  5: cHwPinConfig::set( cHwPinConfig::ADC12_IN5,   cHwPinConfig::ANALOG ); ADC1->SMPR2 |= (paraLoc<<15); break;
    case  6: cHwPinConfig::set( cHwPinConfig::ADC12_IN6,   cHwPinConfig::ANALOG ); ADC1->SMPR2 |= (paraLoc<<18); break;
    case  7: cHwPinConfig::set( cHwPinConfig::ADC12_IN7,   cHwPinConfig::ANALOG ); ADC1->SMPR2 |= (paraLoc<<21); break;
    case  8: cHwPinConfig::set( cHwPinConfig::ADC12_IN8,   cHwPinConfig::ANALOG ); ADC1->SMPR2 |= (paraLoc<<24); break;
    case  9: cHwPinConfig::set( cHwPinConfig::ADC12_IN9,   cHwPinConfig::ANALOG ); ADC1->SMPR2 |= (paraLoc<<27); break;
    case 10: cHwPinConfig::set( cHwPinConfig::ADC123_IN10, cHwPinConfig::ANALOG ); ADC1->SMPR1 |= (paraLoc<< 0); break;
    case 11: cHwPinConfig::set( cHwPinConfig::ADC123_IN11, cHwPinConfig::ANALOG ); ADC1->SMPR1 |= (paraLoc<< 3); break;
    case 12: cHwPinConfig::set( cHwPinConfig::ADC123_IN12, cHwPinConfig::ANALOG ); ADC1->SMPR1 |= (paraLoc<< 6); break;
    case 13: cHwPinConfig::set( cHwPinConfig::ADC123_IN13, cHwPinConfig::ANALOG ); ADC1->SMPR1 |= (paraLoc<< 9); break;
    case 14: cHwPinConfig::set( cHwPinConfig::ADC3_IN14,   cHwPinConfig::ANALOG ); ADC1->SMPR1 |= (paraLoc<<12); break;
    case 15: cHwPinConfig::set( cHwPinConfig::ADC3_IN15,   cHwPinConfig::ANALOG ); ADC1->SMPR1 |= (paraLoc<<15); break;

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
  ADC1->SQR3 = ch & 0x1F;

  ADC1->CR2 |= ADC_CR2_SWSTART;
}

//-------------------------------------------------------------------
extern "C"
{
  void ADC_IRQHandler(void)
  {
    ADC1->SR &= ~ADC_SR_EOC;
    cHwADC_0::adcPtr->isr();
  }
}

//EOF
