//*******************************************************************
/*!
\file   Acc_LSM303.cpp
\author Thomas Breuer
\date   21.11.2012
*/

//*******************************************************************
// 
// cHwSensAcc_LSM303
//
//*******************************************************************
//-------------------------------------------------------------------
cHwSensAcc_LSM303::cHwSensAcc_LSM303( cHwI2Cmaster &i2cIn )

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

// TODO Unterschied LM303 und LM303D ? 
//  // Control Register 4 (CTRL_REG4_A)
//  i2c.write(  (BYTE)0x23,  (1<<7)  // Block data update:      ON
//                           |(0<<6)  // Big/little endian data: LSB @ lower addr
//                           |(0<<4)  // Full-scale selection:   2G
//                           |(1<<3)  // High resolution output: ON
//                           |(0<<0));// SPI mode:               4-wire

//  // Control Register 5 (CTRL_REG5_A)
//  i2c.write(  (BYTE)0x24,  (0<<7)  // Reboot memory content:   OFF
//                           |(0<<6)  // FIFO enable:             OFF
//                           |(0<<3)  // Latch interrupt on INT1: OFF
//                           |(0<<2)  // 4D detection on INT1:    OFF
//                           |(0<<1)  // Latch interrupt on INT2: OFF
//                           |(0<<0));// 4D detection on INT2:    OFF

//  // Control Register 6 (CTRL_REG6_A)
//  i2c.write(  (BYTE)0x25,  0 );    // Interrupts and CLICK detection
//                                    // not used

}

//-------------------------------------------------------------------
inline WORD cHwSensAcc_LSM303::readWord( BYTE addr )
{
  WORD data;
  
  data  =        i2c.read(  (BYTE)(addr  ) );
  data |= ((WORD)i2c.read(  (BYTE)(addr+1) )) << 8;
  
  return( data );
}

//-------------------------------------------------------------------
inline WORD cHwSensAcc_LSM303::getX( void )
{
  return( readWord( 0x28 ) );
}

//-------------------------------------------------------------------
inline WORD cHwSensAcc_LSM303::getY( void )
{
  return( readWord( 0x2A ) );
}

//-------------------------------------------------------------------
inline WORD cHwSensAcc_LSM303::getZ( void )
{
  return( readWord( 0x2C ) );
}

// EOF
