//*******************************************************************
/*!
\file   Memory_BKPRAM.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "Memory_BKPRAM.h"

//*******************************************************************
// 
// cHwMemory_BKPRAM
//
//*******************************************************************
//-------------------------------------------------------------------
cHwMemory_BKPRAM::cHwMemory_BKPRAM( void )

: cHwMemory( 80,    // size
             0xFF ) // default value

{
  RCC->APB1ENR |= RCC_APB1ENR_PWREN;
  PWR->CR |= PWR_CR_DBP;
  RCC->AHB1ENR |= RCC_AHB1ENR_BKPSRAMEN;
  ptr = (DWORD*)(&RTC->BKP0R);
}

//-------------------------------------------------------------------
inline void cHwMemory_BKPRAM::writeByte( DWORD addr, BYTE data )
{
  // write a single byte within a DWORD-Array
  //
  DWORD *tmp  = ptr + (addr>>2);
  BYTE   offs = (addr&0x03)<<3;

  *tmp &= ~(0xFF<<offs); 
  *tmp |=  (data<<offs);
}

//-------------------------------------------------------------------
inline BYTE cHwMemory_BKPRAM::readByte( DWORD addr )
{
  // read a single byte within a DWORD-Array
  //
  DWORD *tmp  = ptr + (addr>>2);
  BYTE   offs = (addr&0x03)<<3;

  return( ((*tmp)>>offs) & 0xFF );
}

//EOF
