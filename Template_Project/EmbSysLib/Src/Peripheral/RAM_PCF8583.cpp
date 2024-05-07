//*******************************************************************
/*!
\file   RAM_PCF8583.cpp
\author Thomas Breuer
\date   11.03.2011
*/

//*******************************************************************
//
// cHwRAM_PCF8583
//
//*******************************************************************
//-------------------------------------------------------------------
cHwRAM_PCF8583::cHwRAM_PCF8583( cHwI2Cmaster &i2cIn, BYTE hwAddrIn )

: cHwMemory(240, 0xFF) , i2c(i2cIn, baseAdr | ( (hwAddrIn&maskAdr) << 1 ))

{
}

//--------------------------------------------
void cHwRAM_PCF8583::writeByte( DWORD addr, BYTE data )
{
  i2c.write( (BYTE)(addr+16), data ); // offset due to RTC-data
}

//--------------------------------------------
BYTE cHwRAM_PCF8583::readByte( DWORD addr )
{
  return( i2c.read( (BYTE)(addr+16) ) ); // offset due to RTC-data
}

//EOF
