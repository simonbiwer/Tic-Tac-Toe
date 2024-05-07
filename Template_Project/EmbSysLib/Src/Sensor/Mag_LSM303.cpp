//*******************************************************************
/*!
\file   Mag_LSM303.cpp
\author Thomas Breuer
\date   21.11.2012
*/

//*******************************************************************
#include "lib.h"
#include "Mag_LSM303.h"

// TODO: Unterschied LM303 und LM303D ???
//*******************************************************************
// 
// cHwSensMag_LSM303
//
//*******************************************************************
//-------------------------------------------------------------------
cHwSensMag_LSM303::cHwSensMag_LSM303( cHwI2Cmaster &i2cIn )

: i2c( i2cIn, hwAddr )

{
  // Control Register 1 (CTRL_REG1_A)            
  i2c.write(  (BYTE)0x20,  (0x5<<4)  // Data rate selection:   100Hz
                           |(  0<<3)  // Low-power mode enable: OFF (normal mode)
                           |(  1<<2)  // Z axis enable:         ON
                           |(  1<<1)  // Y axis enable:         ON
                           |(  1<<0));// X axis enable:         ON

  // Control Register 2 (CTRL_REG2_A), High pass filter ...
  i2c.write(  (BYTE)0x21,  (0<<6)  //  ... mode:                        Normal
                           |(0<<4)  //  ... cut-off frequency:           ???
                           |(0<<3)  //  ... data selection:              OFF
                           |(0<<2)  //  ... enabled for CLICK function:  OFF
                           |(0<<1)  //  ... enabled for AOI Interrupt 2: OFF
                           |(0<<0));//  ... enabled for AOI Interrupt 1: OFF
                           
  // Control Register 3 (CTRL_REG3_A)
  i2c.write(  (BYTE)0x22,  0); // all interrupts off

  // Control Register A (CRA_REG_M)
  i2c.write(  (BYTE)0x24,  (1<<7)  // Temperature Sensor enable: ON 
                                 |(6<<2));// Data output rate:          75Hz

  // Control Register B (CRB_REG_M)
  i2c.write(  (BYTE)0x25, (0<<5)); // Gain setting: 1.3 Gauss

  // Mode Register
  i2c.write(  (BYTE)0x26, (0<<0)); // Operating mode: continuous conversion

}

//-------------------------------------------------------------------
inline WORD cHwSensMag_LSM303::readWord( BYTE addr )
{
  WORD data;
  
  data  =        i2c.read(  (BYTE)(addr) );
  data |= ((WORD)i2c.read(  (BYTE)(addr+1) )) << 8;
  
  return( data );
}

//-------------------------------------------------------------------
inline WORD cHwSensMag_LSM303::getX( void )
{
  return( readWord( 0x08 ) );
}

//-------------------------------------------------------------------
inline WORD cHwSensMag_LSM303::getY( void )
{
  return( readWord( 0x0A ) );
}

//-------------------------------------------------------------------
inline WORD cHwSensMag_LSM303::getZ( void )
{
  return( readWord( 0x0C ) );
}

// EOF
