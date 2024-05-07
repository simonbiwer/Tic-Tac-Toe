//*******************************************************************
/*!
\file   I2Cmaster_MCU.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.

\todo Timeout einbauen!
*/

//*******************************************************************
#include "I2Cmaster_MCU.h"

//*******************************************************************
// 
// cHwI2Cmaster_N
//
//*******************************************************************
//-------------------------------------------------------------------
#if ( system_PCLK_I2C != 50000000 )
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

    case I2C_3: 
      ptrBase       = (I2C_TypeDef*)I2C3_BASE; 
      RCC->APB1ENR |= RCC_APB1ENR_I2C3EN;
      cHwPinConfig::set( cHwPinConfig::I2C3_SCL, cHwPinConfig::OPEN_DRAIN );
      cHwPinConfig::set( cHwPinConfig::I2C3_SDA, cHwPinConfig::OPEN_DRAIN );
      break;

    case I2C_4: 
      ptrBase       = (I2C_TypeDef*)I2C4_BASE; 
      RCC->APB1ENR |= RCC_APB1ENR_I2C4EN;
      cHwPinConfig::set( cHwPinConfig::I2C4_SCL, cHwPinConfig::OPEN_DRAIN);
      cHwPinConfig::set( cHwPinConfig::I2C4_SDA, cHwPinConfig::OPEN_DRAIN);
      break;
  }

	WORD presc [] = {0x0B, 0x0B, 0x05, 0x05};
	WORD scll  [] = {0xC7, 0x13, 0x09, 0x03};
	WORD sclh  [] = {0xC3, 0x0F, 0x03, 0x01};
	WORD sdadel[] = {0x02, 0x02, 0x03, 0x00};
	WORD scldel[] = {0x04, 0x04, 0x03, 0x01};
		
	BYTE idx;
  
	// \see: Reference Manual RM0410, Table 208: Examples of timings settings for fI2CCLK = 48 MHz, www.st.com
  switch( mode )
  {
    default:
    case CR_10kHz:   idx = 0; break;
    case CR_100kHz:  idx = 1; break;
    case CR_400kHz:  idx = 2; break;
    case CR_1000kHz: idx = 3; break;
  } 
	ptrBase->TIMINGR =   (presc[idx] <<28)
	                   | (scldel[idx]<<20)
	                   | (sdadel[idx]<<16)
	                   | (sclh[idx]  << 8)
	                   | (scll[idx]  << 0);

  ptrBase->CR1 |= I2C_CR1_ANFOFF | I2C_CR1_PE; // enable
}

//-------------------------------------------------------------------
BYTE cHwI2Cmaster_N::write( BYTE  hwAddr,
                            BYTE *addr,
                            BYTE  sizeAddr,
                            BYTE *data,
                            BYTE  sizeData )
{
  BYTE i = 0;
  
  isHardwareOK = true;

  if( maskIntr )
    cSystem::disableInterrupt();
	
	if( sizeAddr )
	{
		// Transfer addr
		ptrBase->CR2 =   !I2C_CR2_AUTOEND
									 | !I2C_CR2_RELOAD
									 |  (sizeAddr+sizeData)<<16
									 | !I2C_CR2_ADD10	
									 | !I2C_CR2_RD_WRN
									 |  ((hwAddr & 0xFE) ); 

		ptrBase->CR2 |= I2C_CR2_START;
		
    for( i=0; i< sizeAddr; i++ )
    {
			while( !(ptrBase->ISR & I2C_ISR_TXIS) );
      ptrBase->TXDR = addr[i];
    }
    for( i=0; i< sizeData; i++ )
    {
			while( !(ptrBase->ISR & I2C_ISR_TXIS) );
      ptrBase->TXDR = data[i];
    }
		while( !(ptrBase->ISR & I2C_ISR_TC) );
	}
	
  ptrBase->CR2 |= I2C_CR2_STOP;

  if( maskIntr )
    cSystem::enableInterrupt();

  return( !isHardwareOK );
}

//-------------------------------------------------------------------
BYTE cHwI2Cmaster_N::read( BYTE  hwAddr,
                           BYTE *addr,
                           BYTE  sizeAddr,
                           BYTE *data,
                           BYTE  sizeData )
{
  BYTE i = 0;
  
  isHardwareOK = true;

  if( maskIntr )
    cSystem::disableInterrupt();
	
	if( sizeAddr )
	{
		// Transfer addr
		ptrBase->CR2 =   !I2C_CR2_AUTOEND
									 | !I2C_CR2_RELOAD
									 |  (sizeAddr)<<16
									 | !I2C_CR2_ADD10	
									 | !I2C_CR2_RD_WRN
									 |  ((hwAddr & 0xFE) ); 

		ptrBase->CR2 |= I2C_CR2_START;
		
    for( i=0; i< sizeAddr; i++ )
    {
			while( !(ptrBase->ISR & I2C_ISR_TXIS) );
      ptrBase->TXDR = addr[i];
    }
		while( !(ptrBase->ISR & I2C_ISR_TC) );
	}
	
	ptrBase->CR2 =     !I2C_CR2_AUTOEND
									 | !I2C_CR2_RELOAD
									 |  (sizeData)<<16
									 | !I2C_CR2_ADD10	
									 |  I2C_CR2_RD_WRN
									 |  ((hwAddr & 0xFE) ); 

  ptrBase->CR2 |= I2C_CR2_START;
	
	for( i=0; i< sizeData; i++ )
	{
		while( !(ptrBase->ISR & I2C_ISR_RXNE) );
		data[i] = ptrBase->RXDR;
	}
	while( !(ptrBase->ISR & I2C_ISR_TC) );

  ptrBase->CR2 |= I2C_CR2_STOP;
  
	if( maskIntr )
    cSystem::enableInterrupt();

  return( !isHardwareOK );
}

//EOF
