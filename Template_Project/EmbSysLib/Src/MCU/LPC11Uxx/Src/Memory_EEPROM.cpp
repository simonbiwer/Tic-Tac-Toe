//*******************************************************************
/*!
\file   Memory_EEPROM.cpp
\author Thomas Breuer
\date   25.03.2013

Implementation: see AN11073, July 2012, NXP
*/

//*******************************************************************
// 
// cHwMemory_EEPROM
//
//*******************************************************************

#define IAP_LOCATION 0x1FFF1FF1
typedef void (*IAP)(unsigned int command[],unsigned int result[]);
static const IAP iap_entry = (IAP) IAP_LOCATION;

//-------------------------------------------------------------------
cHwMemory_EEPROM::cHwMemory_EEPROM( void )

: cHwMemory( 4032,  // size, see AN11073, NXP
             0xFF ) // default value

{
}

//-------------------------------------------------------------------
inline void cHwMemory_EEPROM::writeByte( DWORD addr, BYTE data )
{
  // write a single byte 
  //
  unsigned int command[] =
    {
      61, // write command
      addr,
      (unsigned int) &data,
      1, // size
      48000 // SystemCoreClock/1000;
    };
  unsigned int result[4];

  // Invoke IAP call...
  iap_entry( command, result );
  if( 0 != result[0] ) 
  {
    //Trap error
    while(1);
  } 
}

//-------------------------------------------------------------------
inline BYTE cHwMemory_EEPROM::readByte( DWORD addr )
{
  // read a single byte
  //
  BYTE buf = 0;
  unsigned int command[] = 
    {
      62,   // read command
      addr,
      (unsigned int) &buf,
      1,    // size
      48000 // SystemCoreClock/1000;
    };
  unsigned int result[4];

  // Invoke IAP call...
  iap_entry( command, result );
  if( 0 != result[0] )
  {
    //Trap error
    while(1);
  }

  return( buf );
}

//EOF
