//*******************************************************************
/*!
\file   RAM_MCU.cpp
\author Thomas Breuer
\date   25.02.2011
*/

//*******************************************************************
// 
// cHwMemory_RAM
//
//*******************************************************************
//-------------------------------------------------------------------
cHwMemory_RAM::cHwMemory_RAM( void )

: cHwMemory( 20,    // size
             0xFF ) // default value

{
  ptr = (DWORD*)(&LPC_RTC->GPREG0);
}

//-------------------------------------------------------------------
inline void cHwMemory_RAM::writeByte( WORD addr, BYTE data )
{
  // write a single byte within a DWORD-Array
  //
  DWORD *tmp  = ptr + (addr>>2);
  BYTE   offs = (addr&0x03)<<3;

  *tmp &= ~(0xFF<<offs); 
  *tmp |=  (data<<offs);
}

//-------------------------------------------------------------------
inline BYTE cHwMemory_RAM::readByte( WORD addr )
{
  // read a single byte within a DWORD-Array
  //
  DWORD *tmp  = ptr + (addr>>2);
  BYTE   offs = (addr&0x03)<<3;

  return( ((*tmp)>>offs) & 0xFF );
}

//EOF
