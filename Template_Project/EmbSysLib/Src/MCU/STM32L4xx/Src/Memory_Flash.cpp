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
cHwMemory_Flash::cHwMemory_Flash( Sector sector )

: cHwMemory( (sector&0x0F)*0x4000, 
             0xFF ) // default value

{
  ptr            = (BYTE*)( (sector>>8)*0x4000 + 0x08000000 );
  sectorID       = (sector>>4)&0x0F;
  dataDoubleWord = 0;
  isFlashFlag    = true;
}

//-------------------------------------------------------------------
void cHwMemory_Flash::clear( DWORD offset )
{
  while( FLASH->SR & FLASH_SR_BSY );
  
  FLASH->KEYR = 0x45670123;
  FLASH->KEYR = 0xCDEF89AB;
  
  FLASH->CR &= ~(FLASH_CR_STRT | FLASH_CR_SER | (0xf<<3)); // set SER-bit
  FLASH->CR |=   FLASH_CR_SER | (sectorID<<3); 
  
  FLASH->CR |= FLASH_CR_STRT;// set STRT-bit
  
  while( FLASH->SR & FLASH_SR_BSY );
  
  FLASH->CR &= ~(FLASH_CR_STRT | FLASH_CR_SER | (0xf<<3)); // clr SER-bit
  
  FLASH->CR |= FLASH_CR_LOCK;
  
  while( FLASH->SR & FLASH_SR_BSY );
}

//-------------------------------------------------------------------
void cHwMemory_Flash::writeByte( DWORD addr, BYTE data )
{
  while( FLASH->SR & FLASH_SR_BSY );
  
  FLASH->KEYR = 0x45670123;
  FLASH->KEYR = 0xCDEF89AB;
  
  while( FLASH->SR & FLASH_SR_BSY );
  
  FLASH->CR |= FLASH_CR_PG;
  
  ptr[addr] = data;
  
  while( FLASH->SR & FLASH_SR_BSY );

  FLASH->CR &= ~FLASH_CR_PG;
  
  FLASH->CR |= FLASH_CR_LOCK;

  while( FLASH->SR & FLASH_SR_BSY );
}

//-------------------------------------------------------------------
BYTE cHwMemory_Flash::readByte( DWORD addr )
{
  return( ptr[addr] );
}

//EOF
