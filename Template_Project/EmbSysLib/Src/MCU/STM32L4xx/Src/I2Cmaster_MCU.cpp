//*******************************************************************
/*!
\file   I2Cmaster_MCU.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "I2Cmaster_MCU.h"

//*******************************************************************
// 
// cHwI2Cmaster_N
//
//*******************************************************************
//-------------------------------------------------------------------
#if ( system_PCLK_I2C != 42000000 )
  #error "system_PCLK_I2C not defined or wrong value"
#endif

//-------------------------------------------------------------------
cHwI2Cmaster_N::cHwI2Cmaster_N( I2C_ID id, 
                                MODE   mode,
                                BYTE   maskIntr )

: cHwI2Cmaster( maskIntr )

{
  switch( id )
  {  
    default:
      // error!
      break;
      
    case I2C_1: 
      ptrBase       = (I2C_TypeDef*)I2C1_BASE; 
      RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
      cHwPinConfig::set( cHwPinConfig::I2C1_SCL, cHwPinConfig::OPEN_DRAIN );
      cHwPinConfig::set( cHwPinConfig::I2C1_SDA, cHwPinConfig::OPEN_DRAIN );
      break;
            
    case I2C_2: 
      ptrBase       = (I2C_TypeDef*)I2C2_BASE; 
      RCC->APB1ENR |= RCC_APB1ENR_I2C2EN;
      cHwPinConfig::set( cHwPinConfig::I2C2_SCL, cHwPinConfig::OPEN_DRAIN );
      cHwPinConfig::set( cHwPinConfig::I2C2_SDA, cHwPinConfig::OPEN_DRAIN );
      break;
  }

  WORD ccr;
  
  switch( mode )
  {
    // High/low time of master clock: ClockRate = PCLK_I2C / (2*ccr)
    default:
    case CR_10kHz:   ccr = WORD( (float)system_PCLK_I2C /   20E3F ); break;
    case CR_100kHz:  ccr = WORD( (float)system_PCLK_I2C /  200E3F ); break;
    case CR_400kHz:  ccr = WORD( (float)system_PCLK_I2C /  800E3F ); break;
    case CR_1000kHz: ccr = WORD( (float)system_PCLK_I2C / 2000E3F ); break;
  } 

  ptrBase->CR2 &= ~0x3F; 
  ptrBase->CR2 |= RANGE( system_PCLK_I2C/1000000, 2, 42 ); // peripheral input clock
  
  ptrBase->CCR =  I2C_CCR_FS     // Fast mode enable
                |!I2C_CCR_DUTY   // Fast mode tlow/thigh = 2
                | ccr; 
  
  ptrBase->TRISE = (WORD)(0.1e-6 * system_PCLK_I2C) + 1; // Trise = 0.1µs
  
  ptrBase->CR1 |= I2C_CR1_PE; // enable
}

//-------------------------------------------------------------------
inline void cHwI2Cmaster_N::waitForAckn( MTYPE state )
{
  WORD i= 0xFFFF;

  if( isHardwareOK )
  {
    while( (--i) && !(ptrBase->SR1 & state)  );    // wait for ACK
  }

  if( i == 0 ) 
  {
    isHardwareOK = false; 
    stop();
  }
}

//-------------------------------------------------------------------
inline void cHwI2Cmaster_N::start( void )
{
  if( isHardwareOK )
  {
    ptrBase->CR1 &= ~(I2C_CR1_STOP | I2C_CR1_START);
    ptrBase->CR1 |=  (               I2C_CR1_START);
    waitForAckn( I2C_SR1_SB );
  }
}

//-------------------------------------------------------------------
inline void cHwI2Cmaster_N::stop( void )
{
  ptrBase->CR1 |=  (I2C_CR1_STOP                );
}

//-------------------------------------------------------------------
inline void cHwI2Cmaster_N::sendAddr( BYTE addr )
{
  if( isHardwareOK )
  {
    volatile BYTE tmp = ptrBase->SR1;
    ptrBase->DR = addr;   
    if( addr & 0x01 ) // master read
      ptrBase->CR1 |= (I2C_CR1_ACK );
    waitForAckn( I2C_SR1_ADDR | I2C_SR1_TXE );

    tmp = ptrBase->SR2;
  }
}

//-------------------------------------------------------------------
inline void cHwI2Cmaster_N::writeByte( BYTE byte )
{
  if( isHardwareOK )
  {
    ptrBase->DR = byte; 
 
    waitForAckn( I2C_SR1_TXE );
 
    volatile BYTE tmp = ptrBase->SR2;
  }
}

//-------------------------------------------------------------------
inline BYTE cHwI2Cmaster_N::readByteAck( void )
{
  if( isHardwareOK )
  {
    ptrBase->CR1 |= (I2C_CR1_ACK );

    waitForAckn( I2C_SR1_RXNE ); 
    return( ptrBase->DR );
  }
  return( 0 );
}

//-------------------------------------------------------------------
inline BYTE cHwI2Cmaster_N::readByteNack( void )
{
  if( isHardwareOK )
  {
    ptrBase->CR1 &= ~(I2C_CR1_ACK );

    waitForAckn( I2C_SR1_RXNE ); 
    return( ptrBase->DR );
  }
  return( 0 );
}

//EOF
