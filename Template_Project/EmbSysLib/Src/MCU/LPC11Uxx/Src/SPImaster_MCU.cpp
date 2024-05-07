//*******************************************************************
/*!
\file   SPImaster_MCU.cpp
\author Thomas Breuer
\date   28.03.2013
*/

//*******************************************************************
// Bits im Statusregister SR
#define SPI_TFE  (1<<0)
#define SPI_RNE  (1<<2)
#define SPI_BSY  (1<<4)

//*******************************************************************
// 
// cHwSPImaster_N
//
//*******************************************************************
//-------------------------------------------------------------------
#if ( system_PCLK_SPI != 48000000 )
  #error "system_PCLK_SPI not defined or wrong value"
#endif

//-------------------------------------------------------------------
cHwSPImaster_N::cHwSPImaster_N( SPI_ID       id, 
                                MODE         mode,
                                ClockPolPha  clockPolPhaIn )

: cHwSPImaster()
                                   
{
  BYTE scr = 0;

  switch( id )
  {
    default:
      // error!
      break;
    case SPI0:
      ptr = LPC_SSP0;
      cHwPinConfig::set( cHwPinConfig::SCK0 );
      cHwPinConfig::set( cHwPinConfig::MOSI0 );
      cHwPinConfig::set( cHwPinConfig::MISO0 );
      LPC_SYSCON->SYSAHBCLKCTRL |= (1<<11);
      LPC_SYSCON->PRESETCTRL    |= (1<<0);
      break;
    
    case SPI1:
      ptr = LPC_SSP1;
      cHwPinConfig::set( cHwPinConfig::SCK1 );
      cHwPinConfig::set( cHwPinConfig::MOSI1 );
      cHwPinConfig::set( cHwPinConfig::MISO1 );
      LPC_SYSCON->SYSAHBCLKCTRL |= (1<<18);
      LPC_SYSCON->PRESETCTRL    |= (1<<2);
    break;
  }
  
  switch( mode )
  {
    // prescaler CPSR = 4
    default:
    case CR_250kHz:  scr = system_PCLK_SPI / (4000L *  250) - 1; break;
    case CR_500kHz:  scr = system_PCLK_SPI / (4000L *  500) - 1; break;
    case CR_1000kHz: scr = system_PCLK_SPI / (4000L * 1000) - 1; break;
    case CR_2000kHz: scr = system_PCLK_SPI / (4000L * 2000) - 1; break;
    case CR_4000kHz: scr = system_PCLK_SPI / (4000L * 4000) - 1; break;
    case CR_8000kHz: scr = system_PCLK_SPI / (4000L * 8000) - 1; break;
  } 

  cr0 =  (0<<4)                          // Frame format: SPI
        |(((clockPolPhaIn&0x10)?1:0)<<6) // CPOL
        |(((clockPolPhaIn&0x01)?1:0)<<7) // CPHA
        |(scr<<8);                       // Serial clock rate (SCR)

  ptr->CR0  =  (0x7<<0) // DSS: 8-bit transfer
              |cr0;
                        
  ptr->CPSR = 0x04;
  
  ptr->CR1  = (0<<0) // Loop back mode: off
             |(1<<1) // SSP enable
             |(0<<2) // Master/slave mode: master
             |(0<<3);// Slave output disable

  // Dummy-Read to push SCK to high
  transceiveByte( 0x00 );
}

//-------------------------------------------------------------------
BYTE cHwSPImaster_N::transceiveByte( BYTE data )
{
  BYTE x=0;

  // wait until transmission buffer empty 
  while( !(ptr->SR & SPI_TFE) );

  // start transmission
  ptr->DR = data;

  // wait until transmission completed
  while( (ptr->SR & SPI_BSY) );
 
  // wait until data received 

// TODO Variante KNX:
/*
while( !(ptr->SR & SPI_RNE) );
x = ptr->DR;
return( x );
*/

  while( (ptr->SR & SPI_RNE) )
  {
     x = ptr->DR;
  }
  return( x );
}

//-------------------------------------------------------------------
BYTE cHwSPImaster_N::transceiveByteExt( BYTE bit, BYTE data )
{
  BYTE x=0;

  // wait until transmission buffer not full 
  while( !(ptr->SR & SPI_TFE) );

  ptr->CR0 = (0x8<<0) // DSS: 9-bit transfer
                 |cr0;

  // start transmission
  ptr->DR = ((WORD)bit << 8)|data;

  // wait until transmission completed
  while( (ptr->SR & SPI_BSY) );

  // wait until data received 
  while( (ptr->SR & SPI_RNE) )
  {
     x = ptr->DR;
  }
  
  ptr->CR0 = (0x7<<0)// DSS: 8-bit transfer
            |cr0;

  return( x );
}

//EOF
