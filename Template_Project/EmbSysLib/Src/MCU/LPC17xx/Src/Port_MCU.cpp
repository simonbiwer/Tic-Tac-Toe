//*******************************************************************
/*!
\file   Port_MCU.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   08.09.2016

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
    case P0: ptr = (LPC_GPIO_TypeDef *)(LPC_GPIO0_BASE); break;
    case P1: ptr = (LPC_GPIO_TypeDef *)(LPC_GPIO1_BASE); break;
    case P2: ptr = (LPC_GPIO_TypeDef *)(LPC_GPIO2_BASE); break;
    case P3: ptr = (LPC_GPIO_TypeDef *)(LPC_GPIO3_BASE); break;
    case P4: ptr = (LPC_GPIO_TypeDef *)(LPC_GPIO4_BASE); break;
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
#warning "PINMODE fehlt!"
// siehe: cHwPinConfig::set()

  if( mode & Out )
  {
    ptr->FIODIR |= ((MTYPE)0x01 << pinId);
  }
  else
  {
    ptr->FIODIR &= ~((MTYPE)0x01 << pinId);
  }
/*
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
*/
}

// EOF
