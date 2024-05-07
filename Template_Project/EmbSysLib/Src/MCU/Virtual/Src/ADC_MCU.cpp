//*******************************************************************
/*!
\file   ADC_Virtual.cpp
\author Thomas Breuer
\date   15.10.2013
*/

//*******************************************************************
//
// cHwADC_Virtual
//
//*******************************************************************
//-------------------------------------------------------------------
cHwADC_Virtual::cHwADC_Virtual( cNetAddr<4> addr, WORD port,
                                cHwTimer  *tPtrIn )

: cHwADC( 8, tPtrIn ),
  client( addr, port )

{
}

//-------------------------------------------------------------------
void cHwADC_Virtual::configCh( BYTE ch, BYTE para )
{
}

//-------------------------------------------------------------------
inline WORD cHwADC_Virtual::getResult( void )
{
  return( currentValue );
}

//-------------------------------------------------------------------
inline void cHwADC_Virtual::startCh( BYTE ch )
{
//  client.poke   ( "I", ch ); // ADC channel
//  client.request( "D", &currentValue );
Data data;
data.cmd = 0;
data.ch = ch;

client.transceive((BYTE*)&data, sizeof(Data),(BYTE*)&data, sizeof(Data));
currentValue = (WORD)data.value;
  // simulate interrupt:
  isr();
}

//EOF
