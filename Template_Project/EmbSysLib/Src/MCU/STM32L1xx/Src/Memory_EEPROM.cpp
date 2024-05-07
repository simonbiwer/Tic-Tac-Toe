//*******************************************************************
/*!
\file   Memory_EEPROM.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "Memory_EEPROM.h"

//*******************************************************************
//
// cHwMemory_EEPROM
//
//*******************************************************************
//-------------------------------------------------------------------
cHwMemory_EEPROM::cHwMemory_EEPROM( DWORD offset, DWORD size )

: cHwMemory( size, // size
             0x00 )  // default value

{
  ptr = (BYTE*)(0x08080000+offset); // see Datasheet, Table 8 to 11
}

//-------------------------------------------------------------------
void cHwMemory_EEPROM::unlock( void )
{
  if( FLASH->PECR & FLASH_PECR_PELOCK )
  {
    FLASH->PEKEYR = 0x89ABCDEF;
    FLASH->PEKEYR = 0x02030405;
  }
}
    
//-------------------------------------------------------------------
void cHwMemory_EEPROM::lock( void )
{
  FLASH->PECR |= FLASH_PECR_PELOCK;
}

//-------------------------------------------------------------------
void cHwMemory_EEPROM::writeByte( DWORD addr, BYTE data )
{
  
  FLASH->PECR &= ~FLASH_PECR_FTDW;
  while( FLASH->SR & FLASH_SR_BSY );
  ptr[addr] = data;
  
  FLASH->PECR |= FLASH_PECR_PRGLOCK;
}

//-------------------------------------------------------------------
BYTE cHwMemory_EEPROM::readByte( DWORD addr )
{
  return( ptr[addr] );
}

//EOF
