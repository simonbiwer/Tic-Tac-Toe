//*******************************************************************
/*!
\file   Timer_MCU.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "Timer_MCU.h"

//*******************************************************************
//
// cHwTimer_N
//
//*******************************************************************
//-------------------------------------------------------------------
#if ( system_PCLK_TIM != 72000000 )
  #error "system_PCLK_TIM not defined or wrong value"
#endif

//-------------------------------------------------------------------
cHwTimer_N *cHwTimer_N::timerPtr_1 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_2 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_3 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_4 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_5 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_7 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_8 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_9 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_10 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_11 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_12 = 0;
cHwTimer_N *cHwTimer_N::timerPtr_14 = 0;

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

//   case TIM_1:
//      ptr           = (TIM_TypeDef*)TIM1_BASE;
//      timerPtr_1    = this;
//      RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
//      NVIC_EnableIRQ( TIM1_UP_TIM10_IRQn );
//      break;

    case TIM_2:
      ptr           = (TIM_TypeDef*)TIM2_BASE;
      timerPtr_2    = this;
      RCC->APB1ENR1 |= RCC_APB1ENR1_TIM2EN;
      NVIC_EnableIRQ( TIM2_IRQn );
      break;

//    case TIM_3:
//      ptr           = (TIM_TypeDef*)TIM3_BASE;
//      timerPtr_3    = this;
//      RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
//      NVIC_EnableIRQ( TIM3_IRQn );
//      break;

//    case TIM_4:
//      ptr           = (TIM_TypeDef*)TIM4_BASE;
//      timerPtr_4    = this;
//      RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
//      NVIC_EnableIRQ( TIM4_IRQn );
//      break;

//    case TIM_5:
//      ptr           = (TIM_TypeDef*)TIM5_BASE;
//      timerPtr_5    = this;
//      RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
//      NVIC_EnableIRQ( TIM5_IRQn );
//      break;

    case TIM_7:
      ptr           = (TIM_TypeDef*)TIM7_BASE;
      timerPtr_7    = this;
      RCC->APB1ENR1 |= RCC_APB1ENR1_TIM7EN;
      NVIC_EnableIRQ( TIM7_IRQn );
      break;

//    case TIM_8:
//      ptr           = (TIM_TypeDef*)TIM8_BASE;
//      timerPtr_8    = this;
//      RCC->APB2ENR |= RCC_APB2ENR_TIM8EN;
//      NVIC_EnableIRQ( TIM8_CC_IRQn );
//      break;

//    case TIM_9:
//      ptr           = (TIM_TypeDef*)TIM9_BASE;
//      timerPtr_9    = this;
//      RCC->APB2ENR |= RCC_APB2ENR_TIM9EN;
//      //<! todo 
//      // NVIC_EnableIRQ( TIM9_IRQn );
//      break;

//    case TIM_10:
//      ptr           = (TIM_TypeDef*)TIM10_BASE;
//      timerPtr_10    = this;
//      RCC->APB2ENR |= RCC_APB2ENR_TIM10EN;
//      //<! todo 
//      // NVIC_EnableIRQ( TIM10_IRQn );
//      break;

//    case TIM_11:
//      ptr           = (TIM_TypeDef*)TIM11_BASE;
//      timerPtr_11    = this;
//      RCC->APB2ENR |= RCC_APB2ENR_TIM11EN;
//      //<! todo 
//      // NVIC_EnableIRQ( TIM11_IRQn );
//      break;

//   case TIM_12:
//      ptr           = (TIM_TypeDef*)TIM12_BASE;
//      timerPtr_12    = this;
//      RCC->APB1ENR |= RCC_APB1ENR_TIM12EN;
//      //<! todo
//      // NVIC_EnableIRQ( TIM11_IRQn );
//      break;

//    case TIM_14:
//      ptr           = (TIM_TypeDef*)TIM14_BASE;
//      timerPtr_14    = this;
//      RCC->APB1ENR |= RCC_APB1ENR_TIM14EN;
//      //<! todo 
//      // NVIC_EnableIRQ( TIM14_IRQn );
//      break;
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
////    case TIM_1:
////      switch( channel )
////      {
////        case 0: cHwPinConfig::set( cHwPinConfig::TIM1_CH1     ); break;
////        case 1: cHwPinConfig::set( cHwPinConfig::TIM1_CH2     ); break;
////        case 2: cHwPinConfig::set( cHwPinConfig::TIM1_CH3     ); break;
////        case 3: cHwPinConfig::set( cHwPinConfig::TIM1_CH4     ); break;
////      }
////      TIM1->BDTR |= (1<<15); // MOE Master Output Enable
////      break;

////    case TIM_2:
////      switch( channel )
////      {
////        case 0: cHwPinConfig::set( cHwPinConfig::TIM2_CH1     ); break;
////        case 1: cHwPinConfig::set( cHwPinConfig::TIM2_CH2     ); break;
////        case 2: cHwPinConfig::set( cHwPinConfig::TIM2_CH3     ); break;
////        case 3: cHwPinConfig::set( cHwPinConfig::TIM2_CH4     ); break;
////      }
////      break;

////    case TIM_3:
////      switch( channel )
////      {
////        case 0: cHwPinConfig::set( cHwPinConfig::TIM3_CH1     ); break;
////        case 1: cHwPinConfig::set( cHwPinConfig::TIM3_CH2     ); break;
////        case 2: cHwPinConfig::set( cHwPinConfig::TIM3_CH3     ); break;
////        case 3: cHwPinConfig::set( cHwPinConfig::TIM3_CH4     ); break;
////      }
////      break;

////    case TIM_4:
////      switch( channel )
////      {
////        case 0: cHwPinConfig::set( cHwPinConfig::TIM4_CH1     ); break;
////        case 1: cHwPinConfig::set( cHwPinConfig::TIM4_CH2     ); break;
////        case 2: cHwPinConfig::set( cHwPinConfig::TIM4_CH3     ); break;
////        case 3: cHwPinConfig::set( cHwPinConfig::TIM4_CH4     ); break;
////      }
////      break;

////    case TIM_5:
////      switch( channel )
////      {
////        case 0: cHwPinConfig::set( cHwPinConfig::TIM5_CH1     ); break;
////        case 1: cHwPinConfig::set( cHwPinConfig::TIM5_CH2     ); break;
////        case 2: cHwPinConfig::set( cHwPinConfig::TIM5_CH3     ); break;
////        case 3: cHwPinConfig::set( cHwPinConfig::TIM5_CH4     ); break;
////      }
////      break;

////    case TIM_7:
////      switch( channel )
////      {
//////        case 0: cHwPinConfig::set( cHwPinConfig::TIM5_CH1     ); break;
//////        case 1: cHwPinConfig::set( cHwPinConfig::TIM5_CH2     ); break;
//////        case 2: cHwPinConfig::set( cHwPinConfig::TIM5_CH3     ); break;
//////        case 3: cHwPinConfig::set( cHwPinConfig::TIM5_CH4     ); break;
////      }
////      break;

//////    case TIM_8:
//////      switch( channel )
//////      {
//////        case 0: cHwPinConfig::set( cHwPinConfig::TIM8_CH1     ); break;
//////        case 1: cHwPinConfig::set( cHwPinConfig::TIM8_CH2     ); break;
//////        case 2: cHwPinConfig::set( cHwPinConfig::TIM8_CH3     ); break;
//////        case 3: cHwPinConfig::set( cHwPinConfig::TIM8_CH4     ); break;
//////      }
//////      TIM8->BDTR |= (1<<15); // MOE Master Output Enable
//////      break;

////    case TIM_9:
////      switch( channel )
////      {
////        case 0: cHwPinConfig::set( cHwPinConfig::TIM9_CH1     ); break;
////        case 1: cHwPinConfig::set( cHwPinConfig::TIM9_CH2     ); break;
////      }
////      break;

//////    case TIM_10:
//////      switch( channel )
//////      {
//////        case 0: cHwPinConfig::set( cHwPinConfig::TIM10_CH1     ); break;
//////      }
//////      TIM10->BDTR |= (1<<15); // MOE Master Output Enable
//////      break;

//////    case TIM_11:
//////      switch( channel )
//////      {
//////        case 0: cHwPinConfig::set( cHwPinConfig::TIM11_CH1     ); break;
//////      }
//////      TIM11->BDTR |= (1<<15); // MOE Master Output Enable
//////      break;

//////    case TIM_12:
//////      switch( channel )
//////      {
//////        case 0: cHwPinConfig::set( cHwPinConfig::TIM12_CH1     ); break;
//////        case 1: cHwPinConfig::set( cHwPinConfig::TIM12_CH2     ); break;
//////      }
//////      TIM12->BDTR |= (1<<15); // MOE Master Output Enable
//////      break;

//////    case TIM_14:
//////      switch( channel )
//////      {
//////        case 0: cHwPinConfig::set( cHwPinConfig::TIM14_CH1     ); break;
//////      }
//////      break;

    default:
      // no PWM support
      break;
  }

  WORD ccmr =  (7<<4)  // OCxM: PWM-mode 2
              |(1<<3); // OCxPE: preload enable

  WORD ccer = 0;
  if( polarity )
  {
   ccer =  (1<<2)  // CCxNE: enable
              |(1<<3); // CCxNP: polarity active low
  }
  else
  {
   ccer =  (1<<0)  // CCxE: enable
              |(1<<1); // CCxP: polarity active low
  }
  switch( channel )
  {
    case 0:
      ptr->CCMR1 |=  ccmr;
      ptr->CCER  |=  ccer;
      break;

    case 1:
      ptr->CCMR1 |=  ccmr<<8;
      ptr->CCER  |=  ccer<<4;
      break;

    case 2:
      ptr->CCMR2 |=  ccmr;
      ptr->CCER  |=  ccer<<8;
      break;

    case 3:
      ptr->CCMR2 |=  ccmr<<8;
      ptr->CCER  |=  ccer<<12;
      break;
  }
}

//-------------------------------------------------------------------
void cHwTimer_N::setPWM( WORD value, BYTE ch )
{
  value = (WORD)((DWORD)value*tics >> 16);

  switch( ch )
  {
    case 0: ptr->CCR1  = value; break;
    case 1: ptr->CCR2  = value; break;
    case 2: ptr->CCR3  = value; break;
    case 3: ptr->CCR4  = value; break;
  }
}

//-------------------------------------------------------------------
void cHwTimer_N::isr_N(void)
{
  ptr->SR = !TIM_SR_TIF;
  ptr->SR = !TIM_SR_UIF;
  isrHandler();
}

//-------------------------------------------------------------------
extern "C" {
  void TIM1_UP_TIM10_IRQHandler(void)
		// todo: dieser interrupt auch fuer Tim10???
  {
    if( TIM1->SR & TIM_SR_UIF )
		{
			cHwTimer_N::timerPtr_1->isr_N();
			TIM1->SR = 0;
		}
//		else if( TIM10->SR )
//		{
//			TIM10->SR=0;
//		}
  }
}

//-------------------------------------------------------------------
extern "C" {
  void TIM2_IRQHandler(void)
  {
    cHwTimer_N::timerPtr_2->isr_N();
  }
}

//-------------------------------------------------------------------
extern "C" {
  void TIM3_IRQHandler(void)
  {
    cHwTimer_N::timerPtr_3->isr_N();
  }
}

//-------------------------------------------------------------------
extern "C" {
  void TIM4_IRQHandler(void)
  {
    cHwTimer_N::timerPtr_4->isr_N();
  }
}

//-------------------------------------------------------------------
extern "C" {
  void TIM5_IRQHandler(void)
  {
    cHwTimer_N::timerPtr_5->isr_N();
  }
}

//-------------------------------------------------------------------
extern "C" {
  void TIM7_IRQHandler(void)
  {
    cHwTimer_N::timerPtr_7->isr_N();
  }
}

//-------------------------------------------------------------------
extern "C" {
  void TIM8_CC_IRQHandler(void)
  {
    cHwTimer_N::timerPtr_8->isr_N();
  }
}

// No IRQ handler iomplemented for TIM9, TIM10, TIM11 and TIM14

//EOF
