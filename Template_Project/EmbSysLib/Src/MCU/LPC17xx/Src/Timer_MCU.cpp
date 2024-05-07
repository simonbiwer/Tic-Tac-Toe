//*******************************************************************
/*!
\file   Timer_MCU.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   08.09.2016

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
#if ( system_PCLK_TIM != 25000000 )
  #error "system_PCLK_TIM not defined or wrong value"
#endif

//-------------------------------------------------------------------
cHwTimer_N *cHwTimer_N::timerPtr_0   = 0;
cHwTimer_N *cHwTimer_N::timerPtr_1   = 0;
cHwTimer_N *cHwTimer_N::timerPtr_2   = 0;
cHwTimer_N *cHwTimer_N::timerPtr_3   = 0;
cHwTimer_N *cHwTimer_N::timerPtr_PWM = 0;

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
    case TIM_0:
      ptr        = LPC_TIM0;
      timerPtr_0 = this;
      NVIC_EnableIRQ( TIMER0_IRQn );
      break;

    case TIM_1:
      ptr        = LPC_TIM1;
      timerPtr_1 = this;
      NVIC_EnableIRQ( TIMER1_IRQn );
      break;

    case TIM_2:
      ptr        = LPC_TIM2;
      timerPtr_2 = this;
      NVIC_EnableIRQ( TIMER2_IRQn );
      break;

    case TIM_3:
      ptr        = LPC_TIM3;
      timerPtr_3 = this;
      NVIC_EnableIRQ( TIMER3_IRQn );
      break;

    case TIM_PWM:
      ptr          = (LPC_TIM_TypeDef*)LPC_PWM1;
      timerPtr_PWM = this;
      NVIC_EnableIRQ( PWM1_IRQn );
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

  ptr->PR  = ps - 1;    // Prescale Register

  ptr->MR0 = tics;      // match register 0

  ptr->MCR =  (1<<0)    // interrupt on match compare
             |(1<<1);   // reset timer on match compare

  if( timerId == TIM_PWM)
    ptr->TCR =  (1<<0)    // counter enable
               |(1<<3);   // PWM enable
 else
    ptr->TCR =  (1<<0);   // start timer

}

//-------------------------------------------------------------------
void cHwTimer_N::enablePWM( BYTE channel, Mode polarity )
{
  switch( timerId )
  {
    case TIM_PWM:
      switch( channel )
      {
        case 1: cHwPinConfig::set(cHwPinConfig::PWM1_1); LPC_PWM1->PCR |= (1<< 9); break;
        case 2: cHwPinConfig::set(cHwPinConfig::PWM1_2); LPC_PWM1->PCR |= (1<<10); break;
        case 3: cHwPinConfig::set(cHwPinConfig::PWM1_3); LPC_PWM1->PCR |= (1<<11); break;
        case 4: cHwPinConfig::set(cHwPinConfig::PWM1_4); LPC_PWM1->PCR |= (1<<12); break;
        case 5: cHwPinConfig::set(cHwPinConfig::PWM1_5); LPC_PWM1->PCR |= (1<<13); break;
        case 6: cHwPinConfig::set(cHwPinConfig::PWM1_6); LPC_PWM1->PCR |= (1<<14); break;
        default: break;
      }
    default:
      // no PWM support
      break;
  }
}

//-------------------------------------------------------------------
void cHwTimer_N::setPWM( WORD value, BYTE ch )
{
  value = (WORD)((DWORD)value*tics >> 16);

  switch( timerId )
  {
    case TIM_PWM:
      switch( ch )
      {
        case 1: LPC_PWM1->MR1 = value; LPC_PWM1->LER |= (1<<1); break;
        case 2: LPC_PWM1->MR2 = value; LPC_PWM1->LER |= (1<<2); break;
        case 3: LPC_PWM1->MR3 = value; LPC_PWM1->LER |= (1<<3); break;
        case 4: LPC_PWM1->MR4 = value; LPC_PWM1->LER |= (1<<4); break;
        case 5: LPC_PWM1->MR5 = value; LPC_PWM1->LER |= (1<<5); break;
        case 6: LPC_PWM1->MR6 = value; LPC_PWM1->LER |= (1<<6); break;
        default: break;
      }
    default:
      // no PWM support
      break;
  }
}

//-------------------------------------------------------------------
void cHwTimer_N::isr( void )
{
    // use IR to identify interrupt source
    if(ptr->IR & (1<<0))
    {
      ptr->IR = (1<<0); // clear request by writing a logic '1'(!!!)
      isrHandler();
    }
    else
    {
      ptr->IR = ptr->IR; // clear request by writing a logic '1'(!!!)
    }
}

//-------------------------------------------------------------------
extern "C" {
  void TIMER0_IRQHandler(void)
  {
    cHwTimer_N::timerPtr_0->isr();
  }
}

//-------------------------------------------------------------------
extern "C" {
  void TIMER1_IRQHandler(void)
  {
    cHwTimer_N::timerPtr_1->isr();
  }
}

//-------------------------------------------------------------------
extern "C" {
  void TIMER2_IRQHandler(void)
  {
    cHwTimer_N::timerPtr_2->isr();
  }
}

//-------------------------------------------------------------------
extern "C" {
  void TIMER3_IRQHandler(void)
  {
    cHwTimer_N::timerPtr_3->isr();
  }
}

//-------------------------------------------------------------------
extern "C" {
  void PWM1_IRQHandler(void)
  {
    cHwTimer_N::timerPtr_PWM->isr();
  }
}

//EOF
