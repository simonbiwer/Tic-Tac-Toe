//*******************************************************************
/*!
\file   Port_MCU.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "Port_MCU.h"

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
    case PA: ptr = (GPIO_TypeDef *)(GPIOA_BASE); RCC->AHB1ENR |= ((1UL << 0) ); break;
    case PB: ptr = (GPIO_TypeDef *)(GPIOB_BASE); RCC->AHB1ENR |= ((1UL << 1) ); break;
    case PC: ptr = (GPIO_TypeDef *)(GPIOC_BASE); RCC->AHB1ENR |= ((1UL << 2) ); break;
    case PD: ptr = (GPIO_TypeDef *)(GPIOD_BASE); RCC->AHB1ENR |= ((1UL << 3) ); break;
    case PE: ptr = (GPIO_TypeDef *)(GPIOE_BASE); RCC->AHB1ENR |= ((1UL << 4) ); break;
    case PF: ptr = (GPIO_TypeDef *)(GPIOF_BASE); RCC->AHB1ENR |= ((1UL << 5) ); break;
    case PG: ptr = (GPIO_TypeDef *)(GPIOG_BASE); RCC->AHB1ENR |= ((1UL << 6) ); break;
    case PH: ptr = (GPIO_TypeDef *)(GPIOH_BASE); RCC->AHB1ENR |= ((1UL << 7) ); break;
    case PI: ptr = (GPIO_TypeDef *)(GPIOI_BASE); RCC->AHB1ENR |= ((1UL << 8) ); break;
    case PJ: ptr = (GPIO_TypeDef *)(GPIOJ_BASE); RCC->AHB1ENR |= ((1UL << 9) ); break;
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
  
  if( mode & cHwPort::Out ) moder   = (MTYPE)0x01<< pinId2;
  if( mode & cHwPort::PU  ) pupdr  |= (MTYPE)0x01<< pinId2;
  if( mode & cHwPort::PD  ) pupdr  |= (MTYPE)0x02<< pinId2;
  if( mode & cHwPort::OD  ) otyper  = (MTYPE)0x01<< pinId;

  cSystem::disableInterrupt();
  ptr->MODER     = ( ptr->MODER     & bitmask2 ) | moder;
  ptr->PUPDR     = ( ptr->PUPDR     & bitmask2 ) | pupdr;
  ptr->OTYPER    = ( ptr->OTYPER    & bitmask  ) | otyper;
  cSystem::enableInterrupt();
}

// EOF
