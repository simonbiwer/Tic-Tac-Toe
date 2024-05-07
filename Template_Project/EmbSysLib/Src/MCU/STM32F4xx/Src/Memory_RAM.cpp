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

: cHwMemory( 0x1000,    // size = 4K
             0xFF ) // default value

{
  RCC->APB1ENR |= RCC_APB1ENR_PWREN;
  PWR->CR |= PWR_CR_DBP;
  RCC->AHB1ENR |= RCC_AHB1ENR_BKPSRAMEN;

  ptr = (BYTE*)(0x40024000);
  
PWR->CSR |= PWR_CSR_BRE;
while( !(PWR->CSR&PWR_CSR_BRR) );
//   dataDoubleWord = 0; 
// isFlashFlag    = true;
}

//-------------------------------------------------------------------
//void cHwMemory_RAM::clear( DWORD offset )
//{
//  while( FLASH->SR & FLASH_SR_BSY );
//  
//  FLASH->KEYR = 0x45670123;
//  FLASH->KEYR = 0xCDEF89AB;
//  
//  FLASH->CR &= ~(FLASH_CR_STRT | FLASH_CR_SER | (0xf<<3)); // set SER-bit
//  FLASH->CR |=   FLASH_CR_SER | (sectorID<<3); 
//  
//  FLASH->CR |= FLASH_CR_STRT;// set STRT-bit
//  
//  while( FLASH->SR & FLASH_SR_BSY );
//  
//  FLASH->CR &= ~(FLASH_CR_STRT | FLASH_CR_SER | (0xf<<3)); // clr SER-bit
//  
//  FLASH->CR |= FLASH_CR_LOCK;
//  
//  while( FLASH->SR & FLASH_SR_BSY );
//}

//-------------------------------------------------------------------
void cHwMemory_RAM::writeByte( DWORD addr, BYTE data )
{
  ptr[addr] = data;
//  while( FLASH->SR & FLASH_SR_BSY );
//  
//  FLASH->KEYR = 0x45670123;
//  FLASH->KEYR = 0xCDEF89AB;
//  
//  while( FLASH->SR & FLASH_SR_BSY );
//  
//  FLASH->CR |= FLASH_CR_PG;
//  
//  ptr[addr] = data;
//  
//  while( FLASH->SR & FLASH_SR_BSY );

//  FLASH->CR &= ~FLASH_CR_PG;
//  
//  FLASH->CR |= FLASH_CR_LOCK;

//  while( FLASH->SR & FLASH_SR_BSY );
}

//-------------------------------------------------------------------
BYTE cHwMemory_RAM::readByte( DWORD addr )
{
  return( ptr[addr] );
}

//EOF
