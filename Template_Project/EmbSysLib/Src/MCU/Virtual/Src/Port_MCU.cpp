//*******************************************************************
/*!
\file   Port_Virtual.cpp
\author Thomas Breuer
\date   10.11.2016
*/

//*******************************************************************
//
// cHwPort_Virtual
//
//*******************************************************************
//-------------------------------------------------------------------
cHwPort_Virtual::cHwPort_Virtual( cNetAddr<4> addr, WORD port )

: cHwPort(),
  client( addr, port )

{
  valueDir = 0;
  valueOut = 0;
  valueIn  = 0;
}

//-------------------------------------------------------------------
void cHwPort_Virtual::setMode( MTYPE mask, Mode mode )
{
  if( mode & Out )
  {
    valueDir |= mask;
  }
  else
  {
    valueDir &= ~mask;
  }

  transceive();
}

//-------------------------------------------------------------------
void cHwPort_Virtual::setPinMode( BYTE pinId, Mode modeIn )
{
  setMode( 1<< pinId, modeIn );
}

//-------------------------------------------------------------------
void cHwPort_Virtual::set( MTYPE mask )
{
  char dataStr[32]; //!< \todo use a string-object

  valueOut |= mask;

  transceive();
}

//-------------------------------------------------------------------
void cHwPort_Virtual::set( MTYPE mask, MTYPE value )
{
  set( mask & value );
  clr( mask & (~value) );
}

//-------------------------------------------------------------------
void cHwPort_Virtual::clr( MTYPE mask )
{
  valueOut &= ~mask;

  transceive();
}

//-------------------------------------------------------------------
MTYPE cHwPort_Virtual::get( void )
{
  transceive();
  return( valueIn );
}

//-------------------------------------------------------------------
void cHwPort_Virtual::transceive( )
{
  Data data;

  data.dir = valueDir;
  data.value = valueOut;

  client.transceive( (BYTE*)&data, sizeof(Data), (BYTE*)&data, sizeof(Data));

  valueIn = data.value;
}

//EOF
