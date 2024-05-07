//*******************************************************************
/*!
\file   Gyro_L3GD20.cpp
\author Thomas Breuer
\date   21.11.2012
*/

//*******************************************************************
// 
// cHwSensGyro_L3GD20
//
//*******************************************************************
//-------------------------------------------------------------------
cHwSensGyro_L3GD20::cHwSensGyro_L3GD20( cHwI2Cmaster &i2cIn,
                                BYTE          hwAddrIn )

: i2c(i2cIn, baseAdr | ( (hwAddrIn&0x01) << 1 ) )

{
    i2c.write((BYTE)0x20,  (3<<4)
                                 |(0xf<<0));

    i2c.write((BYTE)0x21,  (1<<4)
                                 |(3<<0));

    i2c.write((BYTE)0x23,  (3<<4));

}

//-------------------------------------------------------------------
inline WORD cHwSensGyro_L3GD20::readWord( BYTE addr )
{
  WORD data;
  
  data  =        i2c.read( (BYTE)(addr  )   );
  data |= ((WORD)i2c.read( (BYTE)(addr+1) )) << 8;
  
  return( data );
}

//-------------------------------------------------------------------
inline WORD cHwSensGyro_L3GD20::getX( void )
{
  return( readWord( 0x28 ) );
}

//-------------------------------------------------------------------
inline WORD cHwSensGyro_L3GD20::getY( void )
{
  return( readWord( 0x2A ) );
}

//-------------------------------------------------------------------
inline WORD cHwSensGyro_L3GD20::getZ( void )
{
  return( readWord( 0x2C ) );
}

// EOF
