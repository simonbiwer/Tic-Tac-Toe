//*******************************************************************
/*!
\file   ADC_MCU.cpp
\author Thomas Breuer
\date   02.05.2012
*/

//*******************************************************************
//
// cHwADC_0
//
//*******************************************************************
//-------------------------------------------------------------------
#define ADC_CLK_MAX (13000000) // max ADC-clock,
                               // see User Manual Ch. 29.5.1

//-------------------------------------------------------------------
#if ( system_PCLK_ADC != 25000000 )
  #error "system_PCLK_ADC not defined or wrong value"
#endif

//-------------------------------------------------------------------
cHwADC *cHwADC_0::adcPtr = 0;

//-------------------------------------------------------------------
cHwADC_0::cHwADC_0( cHwTimer *tPtrIn )

: cHwADC( 8, tPtrIn )

{
  adcPtr = this;

  // Power Control for Peripherals
  LPC_SC->PCONP |= (1<<12);// PCADC - A/D converter (ADC)
                           //   power/clock control bit: ON

  // A/D Control Register (AD0CR)
  LPC_ADC->ADCR |= (1<<21);// PDN - The A/D converter is operational: ON

  // A/D Status register (AD0INTEN)
  LPC_ADC->ADINTEN  = (0<<0) // ADINTENx: no interrupt
                     |(1<<8);// ADGINTEN: global DONE flag generates interrupt

  // A/D Control Register (AD0CR)
  adcr =  ( 0<< 0)                            // SEL: none
         |((system_PCLK_ADC/ADC_CLK_MAX)<< 8) // CLKDIV: 1+1
         |( 0<<16)                            // BURST: software controlled
         |( 1<<21)                            // PDN: enable ADC
         |( 0<<24);                           // START: no start

  LPC_ADC->ADCR = adcr;

  NVIC_EnableIRQ( ADC_IRQn );
}

//-------------------------------------------------------------------
void cHwADC_0::configCh( BYTE ch, BYTE para )
{
  switch( ch )
  {
    default:
    case 0: cHwPinConfig::set( cHwPinConfig::AD0_0, cHwPinConfig::NOPUPD ); break;
    case 1: cHwPinConfig::set( cHwPinConfig::AD0_1, cHwPinConfig::NOPUPD ); break;
    case 2: cHwPinConfig::set( cHwPinConfig::AD0_2, cHwPinConfig::NOPUPD ); break;
    case 3: cHwPinConfig::set( cHwPinConfig::AD0_3, cHwPinConfig::NOPUPD ); break;
    case 4: cHwPinConfig::set( cHwPinConfig::AD0_4, cHwPinConfig::NOPUPD ); break;
    case 5: cHwPinConfig::set( cHwPinConfig::AD0_5, cHwPinConfig::NOPUPD ); break;
    case 6: cHwPinConfig::set( cHwPinConfig::AD0_6, cHwPinConfig::NOPUPD ); break;
    case 7: cHwPinConfig::set( cHwPinConfig::AD0_7, cHwPinConfig::NOPUPD ); break;
  }
}

//-------------------------------------------------------------------
inline WORD cHwADC_0::getResult( void )
{
  return( (LPC_ADC->ADGDR) & 0xFFFF );
}

//-------------------------------------------------------------------
inline void cHwADC_0::startCh( BYTE ch )
{
  // A/D Control Register (AD0CR)
  LPC_ADC->ADCR =  adcr
                  |( 1<<ch) // SEL: ch
                  |( 1<<24);// START: conversion now
}

//-------------------------------------------------------------------
extern "C"
{
  void ADC_IRQHandler(void)
  {
    // A/D Status register (AD0STAT)
    LPC_ADC->ADSTAT = (1<<16); //ADINT: reset

    cHwADC_0::adcPtr->isr();
  }
}

//EOF
