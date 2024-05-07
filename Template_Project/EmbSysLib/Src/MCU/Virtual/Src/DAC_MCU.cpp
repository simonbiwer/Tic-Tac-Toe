//*******************************************************************
/*!
\file   DAC_Virtual.cpp
\author Thomas Breuer
\date   21.01.2013
*/

//*******************************************************************
//
// cHwDAC_Virtual
//
//*******************************************************************
//-------------------------------------------------------------------
cHwDAC_Virtual::cHwDAC_Virtual(  cNetAddr<4> addr, WORD port )

: cHwDAC( 8 ),
 client( addr, port )

{
}

//-------------------------------------------------------------------
inline void cHwDAC_Virtual::set( WORD value,
                                 BYTE ch )
{
//  client.poke( "O", ch ); // DAC channel
//  client.poke( "D", value );
Data data;
data.cmd = 1;
data.ch = ch;
data.value = value;
client.transceive((BYTE*)&data, sizeof(Data),(BYTE*)&data, sizeof(Data));


}

//EOF
