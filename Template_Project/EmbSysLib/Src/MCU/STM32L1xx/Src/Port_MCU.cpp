//*******************************************************************
/*!
\file   Port_MCU.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "Port_MCU.h"
#include "../Sys/PinConfig.h"

//*******************************************************************
// 
// cHwPort_N
//
//*******************************************************************
//-------------------------------------------------------------------
cHwPort_N::cHwPort_N( PortId portId ) 

: cHwPort() 

{
  switch( portId )
  {
    default:
      // error
      break;
    case PA: ptr = (GPIO_TypeDef *)(GPIOA_BASE); RCC->AHBENR |= ((1UL << 0) ); break;
    case PB: ptr = (GPIO_TypeDef *)(GPIOB_BASE); RCC->AHBENR |= ((1UL << 1) ); break;
    case PC: ptr = (GPIO_TypeDef *)(GPIOC_BASE); RCC->AHBENR |= ((1UL << 2) ); break;
    case PD: ptr = (GPIO_TypeDef *)(GPIOD_BASE); RCC->AHBENR |= ((1UL << 3) ); break;
    case PE: ptr = (GPIO_TypeDef *)(GPIOE_BASE); RCC->AHBENR |= ((1UL << 4) ); break;
    case PF: ptr = (GPIO_TypeDef *)(GPIOF_BASE); RCC->AHBENR |= ((1UL << 5) ); break;
    case PG: ptr = (GPIO_TypeDef *)(GPIOG_BASE); RCC->AHBENR |= ((1UL << 6) ); break;
    case PH: ptr = (GPIO_TypeDef *)(GPIOH_BASE); RCC->AHBENR |= ((1UL << 7) ); break;
  }
}

//-------------------------------------------------------------------
void cHwPort_N::setMode( MTYPE mask, Mode mode )
{
  for( BYTE i = 0; i < 16; i++, mask >>= 1 )
  {
    if( mask & 0x01 )
    {
      setPinMode( i, mode );
    }
  }
}

//-------------------------------------------------------------------
void cHwPort_N::setPinMode( BYTE pinId, Mode mode )
{
  BYTE  pinId2 = pinId << 1;

  MTYPE bitmask  = ~((MTYPE)0x01 << pinId  );
  MTYPE bitmask2 = ~((MTYPE)0x03 << pinId2 );

  MTYPE moder  = 0;
  MTYPE pupdr  = 0;
  MTYPE otyper = 0;
  
  if( mode & Out ) moder   = (MTYPE)0x01<< pinId2;
  if( mode & PU  ) pupdr  |= (MTYPE)0x01<< pinId2;
  if( mode & PD  ) pupdr  |= (MTYPE)0x02<< pinId2;
  if( mode & OD  ) otyper  = (MTYPE)0x01<< pinId;

  cSystem::disableInterrupt();
  ptr->MODER     = ( ptr->MODER     & bitmask2 ) | moder;
  ptr->PUPDR     = ( ptr->PUPDR     & bitmask2 ) | pupdr;
  ptr->OTYPER    = ( ptr->OTYPER    & bitmask  ) | otyper;
  cSystem::enableInterrupt();
}

// EOF
