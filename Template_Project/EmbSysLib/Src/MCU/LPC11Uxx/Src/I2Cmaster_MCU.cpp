//*******************************************************************
/*!
\file   I2Cmaster_MCU.cpp
\author Thomas Breuer
\date   02.03.2011
*/

//*******************************************************************
// Bits in I2CON:
#define I2CON_AA      (1<<2)
#define I2CON_SI      (1<<3)
#define I2CON_STO     (1<<4)
#define I2CON_STA     (1<<5)
#define I2CON_I2EN    (1<<6)

// Status in I2CSTAT
#define I2STAT_START_TRANSMITTED     0x08
#define I2STAT_SLA_W_TRANSMITTED_ACK 0x18
#define I2STAT_SLA_R_TRANSMITTED_ACK 0x40
#define I2STAT_DATA_TRANSMITTED_ACK  0x28
#define I2STAT_DATA_RECEIVED_ACK     0x50
#define I2STAT_DATA_RECEIVED_NACK    0x58

//*******************************************************************
// 
// cHwI2Cmaster_0
//
//*******************************************************************
//-------------------------------------------------------------------
#if ( system_PCLK_I2C != 48000000 )
  #error "system_PCLK_I2C not defined or wrong value"
#endif

//-------------------------------------------------------------------
cHwI2Cmaster_0::cHwI2Cmaster_0( MODE   mode,
                                BYTE   maskIntr )

: cHwI2Cmaster( maskIntr )

{
  uint32_t pmode = cHwPinConfig::NOPUPD | cHwPinConfig::OD;

  cHwPinConfig::set( cHwPinConfig::SCL, pmode );
  cHwPinConfig::set( cHwPinConfig::SDA, pmode );
  
  LPC_SYSCON->SYSAHBCLKCTRL |= (1<<5);
  LPC_SYSCON->PRESETCTRL    |= (1<<1);

  DWORD scl;
  
  switch( mode )
  {
    // High/low time of master clock: ClockRate =  PCLK_I2C / (2*scl)
    default:
    case CR_10kHz:   scl = WORD( system_PCLK_I2C / (2*  10E3) ); break;
    case CR_100kHz:  scl = WORD( system_PCLK_I2C / (2* 100E3) ); break;
    case CR_400kHz:  scl = WORD( system_PCLK_I2C / (2* 400E3) ); break;
    case CR_1000kHz: scl = WORD( system_PCLK_I2C / (2*1000E3) ); break;
  } 

  LPC_I2C->SCLL = scl;
  LPC_I2C->SCLH = scl;
 
  LPC_I2C->CONSET = I2CON_I2EN;
}

//-------------------------------------------------------------------
inline void cHwI2Cmaster_0::waitForAckn( BYTE state )
{
  WORD i= 0xFFF;

  if( isHardwareOK )
  {
    while( (--i) && ((LPC_I2C->STAT & 0xFC) != state) );    // wait for ACK
  }

  if( i == 0 ) 
  {
    isHardwareOK = false; 
    stop();
  }

  if( 0 )
  {
    stop();
  }
}

//-------------------------------------------------------------------
inline void cHwI2Cmaster_0::start( void )
{
  isHardwareOK = true;
  
  stop();
  WORD i=0x6FF;

  while( --i ); 
  
  LPC_I2C->CONSET = I2CON_STA;
  waitForAckn( I2STAT_START_TRANSMITTED );
}

//-------------------------------------------------------------------
inline void cHwI2Cmaster_0::stop( void )
{
  LPC_I2C->CONSET = I2CON_STO;
  LPC_I2C->CONCLR = I2CON_SI;
}

//-------------------------------------------------------------------
inline void cHwI2Cmaster_0::sendAddr( BYTE addr )
{
  LPC_I2C->DAT = addr;   
  
  LPC_I2C->CONCLR = I2CON_SI | I2CON_STA;

  if(addr & 0x01) // Slave transmitter
  {
    waitForAckn( I2STAT_SLA_R_TRANSMITTED_ACK );
  }
  else // Master transmitter
  {
    waitForAckn( I2STAT_SLA_W_TRANSMITTED_ACK );
  }
}

//-------------------------------------------------------------------
inline void cHwI2Cmaster_0::writeByte( BYTE byte )
{
  LPC_I2C->DAT = byte;

  LPC_I2C->CONCLR = I2CON_SI;

  waitForAckn( I2STAT_DATA_TRANSMITTED_ACK );
}

//-------------------------------------------------------------------
inline BYTE cHwI2Cmaster_0::readByteAck( void )
{
  LPC_I2C->CONSET = I2CON_AA;
  LPC_I2C->CONCLR = I2CON_SI;

  waitForAckn( I2STAT_DATA_RECEIVED_ACK ); 
  
  return( LPC_I2C->DAT );
}

//-------------------------------------------------------------------
inline BYTE cHwI2Cmaster_0::readByteNack( void )
{
  LPC_I2C->CONCLR = I2CON_SI|I2CON_AA;











  waitForAckn( I2STAT_DATA_RECEIVED_NACK ); 
  
  return( LPC_I2C->DAT );
}

//EOF
