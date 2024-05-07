//*******************************************************************
/*!
\file   ADC_MCU.cpp
\author Thomas Breuer
\date   28.03.2013
*/

//*******************************************************************
//
// cHwADC_0
//
//*******************************************************************
//-------------------------------------------------------------------
#define ADC_CLK_MAX (4500000) // max ADC-clock,
                              // see User Manual Ch. 29.5.1

//-------------------------------------------------------------------
#if ( system_PCLK_ADC != 48000000 )
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
  LPC_SYSCON->SYSAHBCLKCTRL |=  (1<<13); // PCADC - A/D converter (ADC)
  LPC_SYSCON->PDRUNCFG      &= ~(1<<4);  //   power/clock control bit: ON

  // A/D Status register (INTEN)
  LPC_ADC->INTEN  = (0<<0) // ADINTENx: no interrupt
                   |(1<<8);// ADGINTEN: global DONE flag generates interrupt

  // A/D Control Register (CR)
  cr =    ( 0<< 0)                            // SEL: none
         |((system_PCLK_ADC/ADC_CLK_MAX)<< 8) // CLKDIV: 1+1
         |( 0<<16)                            // BURST: software controlled
         |( 0<<17)                            // 10 bits
         |( 1<<21)                            // PDN: enable ADC
         |( 0<<24);                           // START: no start

  LPC_ADC->CR = cr;

  NVIC_EnableIRQ( ADC_IRQn );
}

//-------------------------------------------------------------------
void cHwADC_0::configCh( BYTE ch, BYTE para )
{
  switch( ch )
  {
    default:
      // error!
      break;
    case 0: cHwPinConfig::set( cHwPinConfig::AD0 ); break;
    case 1: cHwPinConfig::set( cHwPinConfig::AD1 ); break;
    case 2: cHwPinConfig::set( cHwPinConfig::AD2 ); break;
    case 3: cHwPinConfig::set( cHwPinConfig::AD3 ); break;
    case 4: cHwPinConfig::set( cHwPinConfig::AD4 ); break;
    case 5: cHwPinConfig::set( cHwPinConfig::AD5 ); break;
    case 6: cHwPinConfig::set( cHwPinConfig::AD6 ); break;
    case 7: cHwPinConfig::set( cHwPinConfig::AD7 ); break;
  }
}

//-------------------------------------------------------------------
inline WORD cHwADC_0::getResult( void )
{
  return( (LPC_ADC->GDR) & 0xFFFF );
}

//-------------------------------------------------------------------
inline void cHwADC_0::startCh( BYTE ch )
{
  // A/D Control Register (CR)
  LPC_ADC->CR =  cr
                |( 1<<ch) // SEL: ch
                |( 1<<24);// START: conversion now
}

//-------------------------------------------------------------------
extern "C"
{
  void ADC_IRQHandler(void)
  {
    // A/D Status register (STAT)
    LPC_ADC->STAT = (1<<16); //ADINT: reset

    cHwADC_0::adcPtr->isr();
  }
}

//EOF
