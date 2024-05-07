//*******************************************************************
/*!
\file   PinConfig.cpp
\author Thomas Breuer
\date   08.10.2014
*/

//*******************************************************************
//
// cPinConfig
//
//*******************************************************************
//-------------------------------------------------------------------
void cHwPinConfig::set( Function func, DWORD mode )
{
  uint32_t  port;
  uint32_t  pin;
  uint32_t  af;
  uint32_t  pin2;
  uint32_t  offs;
  uint32_t *ptr;

  for( uint32_t i = 0; table[i] != END_OF_TABLE; i++ )
  {
     if( (table[i] >> 16) == func )
     {
       port = (table[i]>>12)&0x0F;
       pin  = (table[i]>> 4)&0xFF;
       af   = (table[i]>> 0)&0x0F;

       pin2 = 2*(pin&0x0F);
       offs = 2*port + (pin>>4);

       ptr = (uint32_t*)(&LPC_PINCON->PINSEL0) + offs;
       *ptr &= ~(3  << pin2);
       *ptr |=  (af << pin2);

       ptr = (uint32_t*)(&LPC_PINCON->PINMODE0) + offs;
       *ptr &= ~(      0x03 <<pin2);
       *ptr |=  ((mode&0x03)<<pin2);

       ptr = (uint32_t*)(&LPC_PINCON->PINMODE_OD0) + port;
       *ptr &= ~(           0x01 <<pin);
       *ptr |=  (((mode>>4)&0x01)<<pin);

       return;
     }
  }
  // error!
  // -> The table does not contain the func
  // while(1);
}

// EOF
