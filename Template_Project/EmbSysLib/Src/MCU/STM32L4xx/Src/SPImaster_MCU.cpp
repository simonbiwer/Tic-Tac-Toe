//*******************************************************************
/*!
\file   SPImaster_MCU.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.

\warning transceiveByteExt() not implermented
*/

//*******************************************************************
#include "SPImaster_MCU.h"

//*******************************************************************
//
// cHwSPImaster_N
//
//*******************************************************************
//-------------------------------------------------------------------
#if ( system_PCLK_SPI != 84000000 )
  #error "system_PCLK_SPI not defined or wrong value"
#endif

//-------------------------------------------------------------------
cHwSPImaster_N::cHwSPImaster_N( SPI_ID       id, 
                                MODE         mode,
                                ClockPolPha  clockPolPhaIn )

: cHwSPImaster()

{
  switch( id )
  {
    default:
      // error!
      break;
      
    case SPI_1:
      ptr           = SPI1;
      RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
      cHwPinConfig::set( cHwPinConfig::SPI1_SCK  );
      cHwPinConfig::set( cHwPinConfig::SPI1_MISO );
      cHwPinConfig::set( cHwPinConfig::SPI1_MOSI );
//      cHwPinConfig::set( cHwPinConfig::SPI1_NSS  );
      break;

//    case SPI_2:
//      ptr           = SPI2;
//      RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;
//      cHwPinConfig::set( cHwPinConfig::SPI2_SCK  );
//      cHwPinConfig::set( cHwPinConfig::SPI2_MISO );
//      cHwPinConfig::set( cHwPinConfig::SPI2_MOSI );
////      cHwPinConfig::set( cHwPinConfig::SPI2_NSS  );
//      break;

    case SPI_3:
      ptr           = SPI3;
      RCC->APB1ENR1 |= RCC_APB1ENR1_SPI3EN;
      cHwPinConfig::set( cHwPinConfig::SPI3_SCK  );
      cHwPinConfig::set( cHwPinConfig::SPI3_MISO );
      cHwPinConfig::set( cHwPinConfig::SPI3_MOSI );
//      cHwPinConfig::set( cHwPinConfig::SPI3_NSS  );
      break;
  }

  WORD br;
  
  switch( mode )
  {
    default:
    // Baud rate control, prescaler: clock rate = PCLK_SPI / 2^(br+1)
    // Valid for PCLK_SPI = 32MHz
    case CR_250kHz:  br = 6; /* 32MHz/128 */ break;
    case CR_500kHz:  br = 5; /* 32MHz/64  */ break;
    case CR_1000kHz: br = 4; /* 32MHz/32  */ break;
    case CR_2000kHz: br = 3; /* 32MHz/16  */ break;
    case CR_4000kHz: br = 2; /* 32MHz/8   */ break;
    case CR_8000kHz: br = 1; /* 32MHz/4   */ break;
  } 

  cr1  =   !SPI_CR1_DFF       // Data frame format: 8-bit
         |  SPI_CR1_SSM       // Slave management: SW
         |  SPI_CR1_SSI       //
         |  SPI_CR1_LSBFIRST  // LSB first: disable
         |  SPI_CR1_SPE       // SPI enable
         |  (br<<3)           // Baud rate
         |  SPI_CR1_MSTR      // Master mode
         |  ((clockPolPhaIn&0x01)?SPI_CR1_CPOL:0)
         |  ((clockPolPhaIn&0x10)?SPI_CR1_CPHA:0);

  ptr->CR1 = cr1 & (~SPI_CR1_SPE);

  ptr->CR1 |= SPI_CR1_SPE;

  // Dummy-Read to push SCK to high
  transceiveByte( 0x00 );
}

//-------------------------------------------------------------------
BYTE cHwSPImaster_N::transceiveByte( BYTE data )
{
  BYTE x=0;

  // wait until transmission buffer empty
  while( !(ptr->SR & SPI_SR_TXE) );

  // start transmission
  ptr->DR = data;
  
  // wait until transmission buffer empty
  while( !(ptr->SR & SPI_SR_TXE) );

  // wait until transmission completed
  while( (ptr->SR & SPI_SR_BSY) );

  // wait until data received
  while( (ptr->SR & SPI_SR_RXNE) )
  {
     x = ptr->DR;
  }

  return( x );
}

//-------------------------------------------------------------------
BYTE cHwSPImaster_N::transceiveByteExt( BYTE bit, BYTE data )
{
  return( 0 );
  /*! \todo cHwSPImaster_N::transceiveByteExt() implementieren */
}

//EOF
