//*******************************************************************
/*!
\file   EEPROM_24C256.cpp
\author Thomas Breuer
\date   25.08.2014
*/

//*******************************************************************
#include "EEPROM_24C256.h"

//*******************************************************************
//
// cHwEEPROM_24C256
//
//*******************************************************************
//-------------------------------------------------------------------
cHwEEPROM_24C256::cHwEEPROM_24C256( cHwI2Cmaster &i2cIn, BYTE hwAddrIn )

: cHwMemory( 0x8000, 0x00 ) , i2c(i2cIn, baseAdr | ( (hwAddrIn&maskAdr) << 1 )) 
  // Memory size is 256Kbit = 32KByte (0x8000)
{
}

//--------------------------------------------
void cHwEEPROM_24C256::unlock( void )
{
}

//--------------------------------------------
void cHwEEPROM_24C256::lock( void )
{
}

//--------------------------------------------
void cHwEEPROM_24C256::writeByte( DWORD addr, BYTE data )
{
  // ACKNOWLEDGE POLLING, see datasheet page 9
  BYTE i    = 20;
  BYTE test = 0;
  
  i2c.write( (WORD)addr, data );
  
  while( i-- )
  {
    cSystem::delayMilliSec( 1 );
    i2c.read( (WORD)addr, &test, sizeof(test) );
    
    if( !i2c.isError() && test == data )
    {
      break;
    }   
  }   
}

//--------------------------------------------
BYTE cHwEEPROM_24C256::readByte( DWORD addr )
{
  BYTE ret=0;  
  i2c.read( (WORD)addr, &ret, sizeof(ret) );
  return( ret );
}

//EOF
