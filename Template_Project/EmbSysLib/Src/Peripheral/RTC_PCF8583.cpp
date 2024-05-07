//*******************************************************************
/*!
\file   RTC_PCF8583.cpp
\author Thomas Breuer
\date   11.03.2011
*/

//*******************************************************************
//
// cHwRTC_PCF8583
//
//*******************************************************************
//-------------------------------------------------------------------
cHwRTC_PCF8583::cHwRTC_PCF8583( cHwI2Cmaster &i2cIn, BYTE hwAddrIn )

: i2c(i2cIn,  baseAdr | ((hwAddrIn&maskAdr)<<1))

{
}

//-------------------------------------------------------------------
void cHwRTC_PCF8583::set( const cHwRTC::Properties &clock )
{
  // Konfiguration
  i2c.write(  (BYTE)0x00, // Control/status register
                    (0x00<<7)    // stop flag: count pulses
                   |(0x00<<6)    // hold flag: count
                   |(0x00<<4)    // fuction mode: clock mode 32.768kHz)
                   |(0x00<<3)    // mask flag: read locations 05 to 06 unmasked
                   |(0x00<<2)    // alarm enable: alarm disabled
                   |(0x00<<1)    // alarm flag: ---
                   |(0x00<<0));  // timer flag: ---

  i2c.write(  (BYTE)0x02, 
                     Dual_2_BCD( clock.second) );

  i2c.write(  (BYTE)0x03, 
                     Dual_2_BCD( clock.minute) );

  i2c.write(  (BYTE)0x04, 
                     Dual_2_BCD( clock.hour  ) |(0x00<<6)   // AM
                                               |(0x00<<7) );// 24h-format);

  i2c.write(  (BYTE)0x05, 
                     Dual_2_BCD( clock.day   ) |((clock.year%4)<<6) );

  i2c.write(  (BYTE)0x06, 
                     Dual_2_BCD( clock.month ) );
}

//-------------------------------------------------------------------
BYTE cHwRTC_PCF8583::get( cHwRTC::Properties &clock )
{
  BYTE sec;
  
  clock.second = BCD_2_Dual( i2c.read(  (BYTE)0x02 )        );
  clock.minute = BCD_2_Dual( i2c.read(  (BYTE)0x03 )        );
  clock.hour   = BCD_2_Dual( i2c.read(  (BYTE)0x04 ) & 0x3F );
  clock.year   = BCD_2_Dual( i2c.read(  (BYTE)0x05 ) >> 6   );
  clock.month  = BCD_2_Dual( i2c.read(  (BYTE)0x06 ) & 0x1F );
  clock.day    = BCD_2_Dual( i2c.read(  (BYTE)0x05 ) & 0x3F );

  // reread sec to check overflow
  sec          = BCD_2_Dual( i2c.read(  (BYTE)0x02 )        );
  
  return( (clock.second <= sec) ? true : false );
}

//-------------------------------------------------------------------
inline BYTE cHwRTC_PCF8583::BCD_2_Dual( BYTE bcd )
{
  return( 10*((bcd>>4)&0x0F) + (bcd&0x0F) );
}

//-------------------------------------------------------------------
inline BYTE cHwRTC_PCF8583::Dual_2_BCD( BYTE dual )
{
  return( ((dual/10)<<4) | (dual%10) );
}

//EOF
