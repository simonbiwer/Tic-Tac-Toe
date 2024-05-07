//*******************************************************************
/*!
\file   Port_MCU.cpp
\author Thomas Breuer
\date   27.02.2013
*/

//*******************************************************************
// 
// cHwPort_N
//
//*******************************************************************
//-------------------------------------------------------------------
cHwPort_N::cHwPort_N( PortId portId ) 

: cHwPort() 

{
  switch( portId )
  {
    default:
    case 0: portID = 0; break;
    case 1: portID = 1; break;
  }
}

//-------------------------------------------------------------------
void cHwPort_N::setMode( MTYPE mask, Mode mode )
{
  for( BYTE i = 0; i < 24; i++, mask >>= 1 )
  {
    if( mask & 0x01 )
    {
      setPinMode( i, mode );
    }
  }
}

//-------------------------------------------------------------------
void cHwPort_N::setPinMode( BYTE pinId, Mode mode )
{

#warning "PINMODE fehlt!"
// siehe: cHwPinConfig::set()

  if( mode & Out )
  {
    LPC_GPIO->DIR[portID] |= ((MTYPE)0x01 << pinId);
  }
  else
  {
    LPC_GPIO->DIR[portID] &= ~((MTYPE)0x01 << pinId);
  }
}
// EOF
