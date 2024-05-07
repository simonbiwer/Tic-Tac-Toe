//*******************************************************************
/*!
\file   SPImaster_MCU.cpp
\author Thomas Breuer
\date   02.03.2011
*/

//*******************************************************************
// Bits im Statusregister SR
#define SPI3_TNF  (1<<0)
#define SPI3_RNE  (1<<2)
#define SPI3_BSY  (1<<4)

// Bits im Statusregister SPSR
#define SPI0_SPIF  (1<<7)

//*******************************************************************
// 
// cHwSPImaster_0
//
//*******************************************************************
//-------------------------------------------------------------------
#if ( system_PCLK_SPI != 25000000 )
  #error "system_PCLK_SPI not defined or wrong value"
#endif

//-------------------------------------------------------------------
cHwSPImaster_0::cHwSPImaster_0( MODE        mode,
                                ClockPolPha clockPolPhaIn )

: cHwSPImaster()

{
  cHwPinConfig::set( cHwPinConfig::SCK0  );
  cHwPinConfig::set( cHwPinConfig::MISO0 );
  cHwPinConfig::set( cHwPinConfig::MOSI0 );

  LPC_SC->PCONP |= 0x00000100;  // Enable clock for SPI
  
  switch( mode )
  {
    default:
    case CR_250kHz:  LPC_SPI->SPCCR = system_PCLK_SPI / (1000 *  250); break;
    case CR_500kHz:  LPC_SPI->SPCCR = system_PCLK_SPI / (1000 *  500); break;
    case CR_1000kHz: LPC_SPI->SPCCR = system_PCLK_SPI / (1000 * 1000); break;
    case CR_2000kHz: LPC_SPI->SPCCR = system_PCLK_SPI / (1000 * 2000); break;
    case CR_4000kHz: LPC_SPI->SPCCR = system_PCLK_SPI / (1000 * 4000); break;
    case CR_8000kHz: LPC_SPI->SPCCR = system_PCLK_SPI / (1000 * 8000); break;
  } 

  LPC_SPI->SPCR |=  (((clockPolPhaIn&0x01)?1:0)<<3)  // CPHA
                   |(((clockPolPhaIn&0x10)?1:0)<<4)  // CPOL
                   |(1<<5);                          // Master Mode enable
}

//-------------------------------------------------------------------
BYTE cHwSPImaster_0::transceiveByte( BYTE value )
{
  BYTE x=0;

  LPC_SPI->SPDR = value;                  // This write starts the SPI data transfer
  
  while( !(LPC_SPI->SPSR & SPI0_SPIF) );  // wait for last cycle of SPI data transfer

  x = LPC_SPI->SPDR;                      // read the received data (optional)

  return( x );
}

//-------------------------------------------------------------------
BYTE cHwSPImaster_0::transceiveByteExt( BYTE bit, BYTE data )
{
  LPC_SPI->SPCR |= (9<<8)     // 9 bit transfer
                  |(1<<2);    // BitEnable: use BITS
 
  WORD x = 0;

  LPC_SPI->SPDR = ((WORD)bit<<8)|data;     // Start SPI data transfer
  
  while( !(LPC_SPI->SPSR & SPI0_SPIF) );   // Wait for last cycle of SPI data transfer

  x = LPC_SPI->SPDR;                       // Read the received data (optional)

  LPC_SPI->SPCR &= ~( (9<<8)
                     |(1<<2)); //Bit enable: 8 Bit

  return( x );
}

//*******************************************************************
// 
// cHwSPImaster_1
//
//*******************************************************************
//-------------------------------------------------------------------
cHwSPImaster_1::cHwSPImaster_1( MODE        mode,
                                ClockPolPha clockPolPhaIn )

: cHwSPImaster()

{
  BYTE scr = 0;

  cHwPinConfig::set( cHwPinConfig::SCK1  );
  cHwPinConfig::set( cHwPinConfig::MISO1 );
  cHwPinConfig::set( cHwPinConfig::MOSI1 );
  
  LPC_SC->PCONP |= 0x00000400;  // Enable clock for SSP1

  switch( mode )
  {
    // prescaler CPSR = 2
    default:
    case CR_250kHz:  scr = system_PCLK_SPI / (2000 *  250) - 1; break;
    case CR_500kHz:  scr = system_PCLK_SPI / (2000 *  500) - 1; break;
    case CR_1000kHz: scr = system_PCLK_SPI / (2000 * 1000) - 1; break;
    case CR_2000kHz: scr = system_PCLK_SPI / (2000 * 2000) - 1; break;
    case CR_4000kHz: scr = system_PCLK_SPI / (2000 * 4000) - 1; break;
    case CR_8000kHz: scr = system_PCLK_SPI / (2000 * 8000) - 1; break;
  } 

  LPC_SSP1->CR0 =  (7<<0)                          // Data size select: 8bit
                  |(0<<4)                          // Frame format: SPI
                  |(((clockPolPhaIn&0x10)?1:0)<<6) // CPOL
                  |(((clockPolPhaIn&0x01)?1:0)<<7) // CPHA
                  |(scr<<8);                       // Serial clock rate (SCR)
                                                   // clock rate = PCLK/(CPSR*(SCR+1))

  LPC_SSP1->CPSR = 0x02;
  
  LPC_SSP1->CR1  =  (0<<0) // Loop back mode: off
                   |(1<<1) // SSP enable
                   |(0<<2) // Master/slave mode: master
                   |(0<<3);// Slave output disable
}

//-------------------------------------------------------------------
BYTE cHwSPImaster_1::transceiveByte( BYTE data )
{
  BYTE x=0;
  
  // wait until transmission buffer not full 
  while( !(LPC_SSP1->SR & SPI3_TNF) );

  // start transmission
  LPC_SSP1->DR = data;

  // wait until transmission completed
  while( (LPC_SSP1->SR & SPI3_BSY) );

  // wait until data received 
  while( (LPC_SSP1->SR & SPI3_RNE) )
  {
     x = LPC_SSP1->DR;
  }
  return( x );
}

//-------------------------------------------------------------------
BYTE cHwSPImaster_1::transceiveByteExt( BYTE bit, BYTE data )
{
  WORD x = 0;

  // wait until transmission buffer not full 
  while( !(LPC_SSP1->SR & SPI3_TNF) );
  
  LPC_SSP1->CR0 = (LPC_SSP1->CR0 & ~(0xF<<0)) | (9<<0); // DSS: 9-bit transfer
   
  LPC_SSP1->DR = ((WORD)bit<<8)|data;     // Start SPI data transfer
    
   // wait until transmission completed
  while( (LPC_SSP1->SR & SPI3_BSY) );

  // wait until data received 
  while( (LPC_SSP1->SR & SPI3_RNE) )
  {
     x = LPC_SSP1->DR;
  }
  
  LPC_SSP1->CR0 = (LPC_SSP1->CR0 & ~(0xF<<0)) | (8<<0); // DSS: 8-bit transfer
  
  return( x );
}

//EOF
