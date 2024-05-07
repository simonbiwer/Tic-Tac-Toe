//*******************************************************************
/*!
\file   DAC_MCP4441.cpp
\author Thomas Breuer
\date   15.10.2012
*/

//*******************************************************************
//
// cHwDAC_MCP4441
//
//*******************************************************************
//-------------------------------------------------------------------
cHwDAC_MCP4441::cHwDAC_MCP4441( cHwI2Cmaster &i2cIn, BYTE hwAddrIn )

: cHwDAC( 4 ), i2c(i2cIn, baseAdr | ( (hwAddrIn&0x03) << 1 ))

{
}

//-------------------------------------------------------------------
void cHwDAC_MCP4441::set( WORD value, BYTE ch )
{
  BYTE commandByte;
  BYTE dataByte;
  BYTE memAddr;

  value = value >> 9; // 7 bit resolution resistor

  switch(ch)
  {
    default:
    case 0:  memAddr = 0x00; break;
    case 1:  memAddr = 0x01; break;
    case 2:  memAddr = 0x06; break;
    case 3:  memAddr = 0x07; break;
  };

  commandByte =   (memAddr<<4)        // Memory Address
                | (0x00   <<2)        // Command Operation bits = Write Data
                | ((value&0x0300)>>8);// Bit 9 and 8 of value

  dataByte = value&0x00FF;         // Bit 7 to 0 of value

  i2c.write( commandByte, dataByte );
}

//EOF
