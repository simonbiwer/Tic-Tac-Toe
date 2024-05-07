//*******************************************************************
/*!
\file   Acc_ADXL345.cpp
\author Thomas Breuer
\date   21.11.2012
*/

//*******************************************************************
#include "lib.h"
#include "Com/Hardware/I2C/I2Cmaster.h"
#include "Acc_ADXL345.h"

//*******************************************************************
// 
// cHwSensAcc_ADXL345
//
//*******************************************************************
//-------------------------------------------------------------------
cHwSensAcc_ADXL345::cHwSensAcc_ADXL345( cHwI2Cmaster &i2cIn )

: i2c( i2cIn, hwAddr )

{
  // Control Register 1 (CTRL_REG1_A)            
  i2c.write(  (BYTE)0x2D,  (1<<3) );  // Measure
                          

 
  
}

//-------------------------------------------------------------------
inline WORD cHwSensAcc_ADXL345::readWord( BYTE addr )
{
  WORD data;
  
  data  =        i2c.read(  (BYTE)(addr  ) );
  data |= ((WORD)i2c.read(  (BYTE)(addr+1) )) << 8;
  
  return( data );
}

//-------------------------------------------------------------------
inline WORD cHwSensAcc_ADXL345::getX( void )
{
  return( readWord( 0x32 ) );
}

//-------------------------------------------------------------------
inline WORD cHwSensAcc_ADXL345::getY( void )
{
  return( readWord( 0x34 ) );
}

//-------------------------------------------------------------------
inline WORD cHwSensAcc_ADXL345::getZ( void )
{
  return( readWord( 0x36 ) );
}

// EOF
