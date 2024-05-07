//*******************************************************************
/*!
\file   Memory_RAM.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "Memory_RAM.h"

//*******************************************************************
// 
// cHwMemory_RAM
//
//*******************************************************************
//-------------------------------------------------------------------
cHwMemory_RAM::cHwMemory_RAM( void )

: cHwMemory( 80,    // size
             0xFF ) // default value

{
  ptr = (DWORD*)(&RTC->BKP0R);
  PWR->CR |= PWR_CR_DBP;
}

//-------------------------------------------------------------------
void cHwMemory_RAM::unlock( void )
{
}
    
//-------------------------------------------------------------------
void cHwMemory_RAM::lock( void )
{
}

//-------------------------------------------------------------------
inline void cHwMemory_RAM::writeByte( DWORD addr, BYTE data )
{
  // write a single byte within a DWORD-Array
  //
  DWORD *tmp  = ptr + (addr>>2);
  BYTE   offs = (addr&0x03)<<3;

  *tmp &= ~(0xFF<<offs); 
  *tmp |=  (data<<offs);
}

//-------------------------------------------------------------------
inline BYTE cHwMemory_RAM::readByte( DWORD addr )
{
  // read a single byte within a DWORD-Array
  //
  DWORD *tmp  = ptr + (addr>>2);
  BYTE   offs = (addr&0x03)<<3;

  return( ((*tmp)>>offs) & 0xFF );
}

//EOF
