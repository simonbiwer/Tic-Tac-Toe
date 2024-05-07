//*******************************************************************
/*!
\file   ExtInt_MCU.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "ExtInt_MCU.h"

//*******************************************************************
//
// cHwExtInt_N
//
//*******************************************************************

cHwExtInt_N *cHwExtInt_N::extIntPtr[16] = {0};


//-------------------------------------------------------------------
cHwExtInt_N::cHwExtInt_N( cHwExtInt_N::PortId portId_In, BYTE pinId_In )
{
    pinId  = pinId_In % 16;
    portId = portId_In % 8;

    cHwExtInt_N::extIntPtr[pinId] = this;
    switch( pinId )
    {
      case 0: irqNumber = EXTI0_IRQn;   break;
      case 1: irqNumber = EXTI1_IRQn;   break;
      case 2: irqNumber = EXTI2_IRQn;   break;
      case 3: irqNumber = EXTI3_IRQn;   break;
      case 4: irqNumber = EXTI4_IRQn;   break;
      case 5:
      case 6:
      case 7:
      case 8:
      case 9: irqNumber = EXTI9_5_IRQn; break;
      case 10:
      case 11:
      case 12:
      case 13:
      case 14:
      case 15: irqNumber = EXTI15_10_IRQn; break;
    }

}

void cHwExtInt_N::enable()
{

  RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

  SYSCFG->EXTICR[pinId/4] |= ( portId << 4*(pinId%4) );
  EXTI->IMR  |= (1 << pinId);
 // EXTI->FTSR |= (1 << pinId);

  NVIC_EnableIRQ( irqNumber );
}

void cHwExtInt_N::disable()
{
  // TODO: check, if sufficient to disable interrupt
  SYSCFG->EXTICR[pinId/4] &= ~( portId << 4*(pinId%4) );
}

void cHwExtInt_N::setEdge( Edge edge)
{
  switch( edge )
  {
    case FALLING:  EXTI->FTSR |=  (1 << pinId);
                   EXTI->RTSR &= ~(1 << pinId);
                   break;
    case RISING:   EXTI->FTSR &= ~(1 << pinId);
                   EXTI->RTSR |=  (1 << pinId);
                   break;

    case BOTH:     EXTI->FTSR |= (1 << pinId);
                   EXTI->RTSR |= (1 << pinId);
                   break;

    default:       EXTI->FTSR &= ~(1 << pinId);
                   EXTI->RTSR &= ~(1 << pinId);
                   break;
  }
}


//-------------------------------------------------------------------
void cHwExtInt_N::isr_N(void)
{

  isrHandler();
}


extern "C" {
    void EXTI_X_IRQHandler( BYTE id )
    {
          EXTI->PR |= 1<<id;
          cHwExtInt_N::extIntPtr[id] -> isr_N();
    }
}



extern "C" {
    void EXTI0_IRQHandler( void )
    {
      EXTI_X_IRQHandler(0);
    }
}

extern "C" {
    void EXTI1_IRQHandler( void )
    {
      EXTI_X_IRQHandler(1);
    }
}

extern "C" {
    void EXTI2_IRQHandler( void )
    {
      EXTI_X_IRQHandler(2);
    }
}

extern "C" {
    void EXTI3_IRQHandler( void )
    {
      EXTI_X_IRQHandler(3);
    }
}

extern "C" {
    void EXTI4_IRQHandler( void )
    {
      EXTI_X_IRQHandler(4);
    }
}

extern "C" {
    void EXTI9_5_IRQHandler( void )
    {
        for(int i=5;i<=9;i++)
            if( EXTI->PR & (1<<i) )
            {
                EXTI_X_IRQHandler(i);
            }
    }
}

extern "C" {
    void EXTI15_10_IRQHandler( void )
    {
        for(int i=10;i<=15;i++)
            if( EXTI->PR & (1<<i) )
            {
                EXTI_X_IRQHandler(i);
            }
    }
}


// EOF
