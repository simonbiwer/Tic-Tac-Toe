//*******************************************************************
/*!
\file   Memory_Flash.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "Memory_Flash.h"

//*******************************************************************
//
// cHwMemory_Flash
//
//*******************************************************************
//-------------------------------------------------------------------
cHwMemory_Flash::cHwMemory_Flash(  DWORD *startAddress, DWORD size  )

: cHwMemory( size,
             0x00 ) // default value

{
  ptr            = startAddress;
  dataDoubleWord = 0;
}

//-------------------------------------------------------------------
void cHwMemory_Flash::unlock( void )
{
  if( FLASH->PECR & FLASH_PECR_PELOCK )
  {
    FLASH->PEKEYR = 0x89ABCDEF;
    FLASH->PEKEYR = 0x02030405;
  }
}
    
//-------------------------------------------------------------------
void cHwMemory_Flash::lock( void )
{
  FLASH->PECR |= FLASH_PECR_PELOCK;
}

//-------------------------------------------------------------------
void cHwMemory_Flash::clear( DWORD offset )
{
  FLASH->PRGKEYR = 0x8C9DAEBF;
  FLASH->PRGKEYR = 0x13141516;

  FLASH->PECR |= FLASH_PECR_ERASE;
  FLASH->PECR |= FLASH_PECR_PROG;

  while( FLASH->SR & FLASH_SR_BSY );

  ptr[(offset & ~(0xFF))>>2] = 0x00;  // round to page start address

  FLASH->PECR &= ~FLASH_PECR_ERASE;
  FLASH->PECR &= ~FLASH_PECR_PROG;

  while( FLASH->SR & FLASH_SR_BSY );

  FLASH->PECR |= FLASH_PECR_PRGLOCK;
}

//-------------------------------------------------------------------
void cHwMemory_Flash::writeByte( DWORD addr, BYTE data )
{

  BYTE shift = (8*(addr&0x3));

  if( (addr&0x03) == 0 )
  {
    dataDoubleWord = data;
  }
  else
  {
    dataDoubleWord |= ((DWORD)data<<shift);
  }

  if( (addr &0xFF) == 0 )
  {
    clear( addr );
  }

  if( (addr&0x03) == 0x03 )
  {
    FLASH->PRGKEYR = 0x8C9DAEBF;
    FLASH->PRGKEYR = 0x13141516;

    while( FLASH->SR & FLASH_SR_BSY );

    ptr[addr>>2] = dataDoubleWord ;
    while( FLASH->SR & FLASH_SR_BSY );

    FLASH->PECR |= FLASH_PECR_PRGLOCK;
  }
}

//-------------------------------------------------------------------
BYTE cHwMemory_Flash::readByte( DWORD addr )
{
  return( ptr[addr>>2] >> (8*(addr&0x3)) );
}

//EOF
