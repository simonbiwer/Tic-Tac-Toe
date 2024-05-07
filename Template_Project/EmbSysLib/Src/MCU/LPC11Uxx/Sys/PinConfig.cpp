//*******************************************************************
/*!
\file   PinConfig.cpp
\author Thomas Breuer
\date   08.10.2014
*/

//*******************************************************************
//
// cHwPinConfig
//
//*******************************************************************
//-------------------------------------------------------------------
void cHwPinConfig::set( Function func, DWORD mode )
{
  uint32_t  port;
  uint32_t  pin;
  uint32_t  af;

  uint32_t *ptr;

  for( uint32_t i = 0; table[i] != END_OF_TABLE; i++ )
  {
     if( (table[i] >> 16) == func )
     {
       port = (table[i]>>12)&0x0F;
       pin  = (table[i]>> 4)&0xFF;
       af   = (table[i]>> 0)&0x07;

       mode = mode ^ AD; // Toggle AD mode bit: 
                         //  0 = enable AD mode 
                         //  1 = disable AD mode
       
       ptr = (uint32_t*)(&LPC_IOCON->RESET_PIO0_0) + 24*port + pin;
       *ptr = ( ((mode&0xFF)<<3) | (af<<0) );

       return;
     }
  }
  // error!
  // -> The table does not contain the func
  // while(1);
}

// EOF
