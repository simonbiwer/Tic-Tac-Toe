//*******************************************************************
/*!
\file   PinConfig.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
//
// cHwPinConfig
//
//*******************************************************************
//-------------------------------------------------------------------
void cHwPinConfig::set( GPIO_TypeDef *gpio, BYTE pinId, DWORD mode, BYTE af )
{
  BYTE pin2 = 2*pinId;
  BYTE pin3 = pinId>>3;

  MTYPE bitmask1 = ~((MTYPE)0x01 <<     pinId    );
  MTYPE bitmask2 = ~((MTYPE)0x03 <<     pin2     );
  MTYPE bitmask3 = ~((MTYPE)0x0F << (4*(pinId%8)));

  MTYPE moder   = (MTYPE)((mode    )&0x03) << pin2;
  MTYPE pupdr   = (MTYPE)((mode>> 8)&0x03) << pin2;
  MTYPE otyper  = (MTYPE)((mode>> 4)&0x01) << pinId;
  MTYPE ospeedr = (MTYPE)((mode>>12)&0x03) << pin2;
  MTYPE afr     = (MTYPE)((af      )&0x0F) << (4*(pinId%8));

  cSystem::disableInterrupt();
  gpio->MODER     = ( gpio->MODER     & bitmask2 ) | moder;
  gpio->PUPDR     = ( gpio->PUPDR     & bitmask2 ) | pupdr;
  gpio->OTYPER    = ( gpio->OTYPER    & bitmask1 ) | otyper;
  gpio->OSPEEDR   = ( gpio->OSPEEDR   & bitmask2 ) | ospeedr;
  gpio->AFR[pin3] = ( gpio->AFR[pin3] & bitmask3 ) | afr;
  cSystem::enableInterrupt();
}

//-------------------------------------------------------------------
bool cHwPinConfig::set( Function func, DWORD mode )
{
  BYTE port;
  BYTE pin;
  BYTE af;

  GPIO_TypeDef *gpio;

  for( WORD i = 0; table[i] != END_OF_TABLE; i++ )
  {
    if( (table[i] >> 16) == func )
    {
      port = (table[i]>>12)&0x0F;
      pin  = (table[i]>> 4)&0x0F;
      af   = (table[i]>> 0)&0x0F;

      if( (mode & 0x0F) != ANALOG )
      {
        mode |= ALTERNATE_FUNC;
      }

      RCC->AHB1ENR |= ((1UL << port) );

      gpio = (GPIO_TypeDef *)(GPIOA_BASE + (0x400*port));
      set( gpio, pin, mode, af );
      return( true );
    }
  }
  // Error: The table does not contain the func
  return( false );
}

// EOF
