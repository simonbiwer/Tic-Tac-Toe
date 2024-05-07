//*******************************************************************
/*!
\file   Timer_MCU.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "Timer_MCU.h"
#include "../Sys/PinConfig.h"

//*******************************************************************
//
// cHwTimer_N
//
//*******************************************************************
//-------------------------------------------------------------------
#if ( system_PCLK_TIM != 32000000 )
  #error "system_PCLK_TIM not defined or wrong value"
#endif

//-------------------------------------------------------------------
cHwTimer_N *cHwTimer_N::timerPtr_2 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_3 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_4 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_5 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_6 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_7 = 0;

//-------------------------------------------------------------------
cHwTimer_N::cHwTimer_N( TimerId timerIdIn,
                        DWORD   cycleTimeIn )

: cHwTimer()

{
  timerId = timerIdIn;

  switch( timerId )
  {
    default:
      // error!
      break;

    case TIM_2:
      ptr           = (TIM_TypeDef*)TIM2_BASE;
      timerPtr_2    = this;
      RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
      NVIC_EnableIRQ( TIM2_IRQn );
      break;

    case TIM_3:
      ptr           = (TIM_TypeDef*)TIM3_BASE;
      timerPtr_3    = this;
      RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
      NVIC_EnableIRQ( TIM3_IRQn );
      break;

    case TIM_4:
      ptr           = (TIM_TypeDef*)TIM4_BASE;
      timerPtr_4    = this;
      RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
      NVIC_EnableIRQ( TIM4_IRQn );
      break;

    case TIM_5:
      ptr           = (TIM_TypeDef*)TIM5_BASE;
      timerPtr_5    = this;
      RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
      NVIC_EnableIRQ( TIM5_IRQn );
      break;

    case TIM_6:
      ptr           = (TIM_TypeDef*)TIM6_BASE;
      timerPtr_6    = this;
      RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
      NVIC_EnableIRQ( TIM6_IRQn );
      break;

    case TIM_7:
      ptr           = (TIM_TypeDef*)TIM7_BASE;
      timerPtr_7    = this;
      RCC->APB1ENR |= RCC_APB1ENR_TIM7EN;
      NVIC_EnableIRQ( TIM7_IRQn );
      break;
  }

// calculate tics and prescaler
  float rawTics = (float)system_PCLK_TIM * cycleTimeIn * 1E-6f;
  DWORD ps      = 1;
  while( rawTics > 0xFFFF ) // tics must be < 16Bits
  {
    ps      *= 10;
    rawTics /= 10;
  }

  tics      = (DWORD)rawTics;
  cycleTime = (DWORD)(1E6 * tics * ps / (float)system_PCLK_TIM);

  ptr->CR1  = TIM_CR1_CEN;  // counter enable
  ptr->DIER = TIM_DIER_UIE; // update interrupt enable
  ptr->EGR  = TIM_EGR_UG;   // re-initialize timer
  ptr->PSC  = ps - 1;
  ptr->ARR  = tics;
}

//-------------------------------------------------------------------
void cHwTimer_N::enablePWM( BYTE channel, Mode polarity )
{
  switch( timerId )
  {
    case TIM_2:
      switch( channel )
      {
        case 0: cHwPinConfig::set( cHwPinConfig::TIM2_CH1_ETR ); break;
        case 1: cHwPinConfig::set( cHwPinConfig::TIM2_CH2     ); break;
        case 2: cHwPinConfig::set( cHwPinConfig::TIM2_CH3     ); break;
        case 3: cHwPinConfig::set( cHwPinConfig::TIM2_CH4     ); break;
      }
      break;

    case TIM_3:
      switch( channel )
      {
        case 0: cHwPinConfig::set( cHwPinConfig::TIM3_CH1     ); break;
        case 1: cHwPinConfig::set( cHwPinConfig::TIM3_CH2     ); break;
        case 2: cHwPinConfig::set( cHwPinConfig::TIM3_CH3     ); break;
        case 3: cHwPinConfig::set( cHwPinConfig::TIM3_CH4     ); break;
      }
      break;

    case TIM_4:
      switch( channel )
      {
        case 0: cHwPinConfig::set( cHwPinConfig::TIM4_CH1     ); break;
        case 1: cHwPinConfig::set( cHwPinConfig::TIM4_CH2     ); break;
        case 2: cHwPinConfig::set( cHwPinConfig::TIM4_CH3     ); break;
        case 3: cHwPinConfig::set( cHwPinConfig::TIM4_CH4     ); break;
      }
      break;

//    case TIM_5:
//      switch( channel )
//      {
//        case 0: cHwPinConfig::set( cHwPinConfig::TIM5_CH1     ); break;
//        case 1: cHwPinConfig::set( cHwPinConfig::TIM5_CH2     ); break;
//        case 2: cHwPinConfig::set( cHwPinConfig::TIM5_CH3     ); break;
//        case 3: cHwPinConfig::set( cHwPinConfig::TIM5_CH4     ); break;
//      }
//      break;

    default:
      // no PWM support
      break;
  }

  WORD ccmr =  (7<<4)  // OCxM: PWM-mode 2
              |(0<<3); // OCxPE: preload enable

  WORD ccer =  (1<<0)             // CCxE: enable
              |(((polarity==NORMAL)?1:0)<<1); 
                                  // CCxP: polarity 
                                  //       invers: active high
                                  //       normal: active low


  switch( channel )
  {
    case 0:
      ptr->CCMR1 |= ccmr;
      ptr->CCER  |= ccer;
      break;

    case 1:
      ptr->CCMR1 |= ccmr<<8;
      ptr->CCER  |= ccer<<4;
      break;

    case 2:
      ptr->CCMR2 |= ccmr;
      ptr->CCER  |= ccer<<8;
      break;

    case 3:
      ptr->CCMR2 |= ccmr<<8;
      ptr->CCER  |= ccer<<12;
      break;
  }
}

//-------------------------------------------------------------------
void cHwTimer_N::setPWM( WORD value, BYTE ch )
{
  value = (WORD)((DWORD)value*tics >> 16);

  switch( ch )
  {
    case 0: ptr->CCR1 = value; break;
    case 1: ptr->CCR2 = value; break;
    case 2: ptr->CCR3 = value; break;
    case 3: ptr->CCR4 = value; break;
  }
}

//-------------------------------------------------------------------
void cHwTimer_N::isr(void)
{
  ptr->SR = !TIM_SR_TIF;
  isrHandler();
}

//-------------------------------------------------------------------
extern "C" {
  void TIM2_IRQHandler(void)
  {
    cHwTimer_N::timerPtr_2->isr();
  }
}

//-------------------------------------------------------------------
extern "C" {
  void TIM3_IRQHandler(void)
  {
    cHwTimer_N::timerPtr_3->isr();
  }
}

//-------------------------------------------------------------------
extern "C" {
  void TIM4_IRQHandler(void)
  {
    cHwTimer_N::timerPtr_4->isr();
  }
}

//-------------------------------------------------------------------
extern "C" {
  void TIM5_IRQHandler(void)
  {
    cHwTimer_N::timerPtr_5->isr();
  }
}

//-------------------------------------------------------------------
extern "C" {
  void TIM6_IRQHandler(void)
  {
    cHwTimer_N::timerPtr_6->isr();
  }
}

//-------------------------------------------------------------------
extern "C" {
  void TIM7_IRQHandler(void)
  {
    cHwTimer_N::timerPtr_7->isr();
  }
}

//EOF
