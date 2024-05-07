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
// cHwI2Cmaster_N
//
//*******************************************************************
//-------------------------------------------------------------------
#if ( system_PCLK_I2C != 25000000 )
  #error "system_PCLK_I2C not defined or wrong value"
#endif

//-------------------------------------------------------------------
cHwI2Cmaster_N::cHwI2Cmaster_N( I2C_ID id,
                                MODE   mode,
                                BYTE   maskIntr )

: cHwI2Cmaster( maskIntr )

{
  uint32_t pmode = cHwPinConfig::NOPUPD | cHwPinConfig::OD;
  
  switch( id )
  {
    default:
      // error!
    case I2C_1:
      ptr = LPC_I2C1;
      cHwPinConfig::set( cHwPinConfig::SDA1, pmode );
      cHwPinConfig::set( cHwPinConfig::SCL1, pmode );
      break;
    
    case I2C_2:
      ptr = LPC_I2C2;
      cHwPinConfig::set( cHwPinConfig::SDA2, pmode );
      cHwPinConfig::set( cHwPinConfig::SCL2, pmode );
    break;
  }
  
  WORD scl;
  
  switch( mode )
  {
    // High/low time of master clock: ClockRate =  PCLK_I2C / (2*scl)
    default:
    case CR_10kHz:   scl = WORD( system_PCLK_I2C / (2*  10E3) ); break;
    case CR_100kHz:  scl = WORD( system_PCLK_I2C / (2* 100E3) ); break;
    case CR_400kHz:  scl = WORD( system_PCLK_I2C / (2* 400E3) ); break;
    case CR_1000kHz: scl = WORD( system_PCLK_I2C / (2*1000E3) ); break;
  } 

  ptr->I2SCLL = scl;
  ptr->I2SCLH = scl;

  ptr->I2CONSET = I2CON_I2EN;
}

//-------------------------------------------------------------------
inline void cHwI2Cmaster_N::waitForAckn( BYTE state )
{
  WORD i= 0xFFFF;

  if( isHardwareOK )
  {
    while( (--i) && ((ptr->I2STAT & 0xFC) != state) );    // wait for ACK
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
inline void cHwI2Cmaster_N::start( void )
{
  isHardwareOK = true;
  
  stop();
  WORD i=0x6FF;

  while( --i ); 
  
  ptr->I2CONSET = I2CON_STA;
  waitForAckn( I2STAT_START_TRANSMITTED );
}

//-------------------------------------------------------------------
inline void cHwI2Cmaster_N::stop( void )
{
  ptr->I2CONSET = I2CON_STO;
  ptr->I2CONCLR = I2CON_SI;
}

//-------------------------------------------------------------------
inline void cHwI2Cmaster_N::sendAddr( BYTE addr )
{
  ptr->I2DAT = addr;   
  
  ptr->I2CONCLR = I2CON_SI | I2CON_STA;

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
inline void cHwI2Cmaster_N::writeByte( BYTE byte )
{
  ptr->I2DAT = byte;

  ptr->I2CONCLR = I2CON_SI;

  waitForAckn( I2STAT_DATA_TRANSMITTED_ACK );
}

//-------------------------------------------------------------------
inline BYTE cHwI2Cmaster_N::readByteAck( void )
{
  ptr->I2CONSET = I2CON_AA;
  ptr->I2CONCLR = I2CON_SI;

  waitForAckn( I2STAT_DATA_RECEIVED_ACK ); 
  
  return( ptr->I2DAT );
}

//-------------------------------------------------------------------
inline BYTE cHwI2Cmaster_N::readByteNack( void )
{
  ptr->I2CONCLR = I2CON_SI|I2CON_AA;

  waitForAckn( I2STAT_DATA_RECEIVED_NACK ); 
  
  return( ptr->I2DAT );
}

//EOF
