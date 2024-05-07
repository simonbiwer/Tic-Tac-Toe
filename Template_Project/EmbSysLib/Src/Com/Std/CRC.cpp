//*******************************************************************
/*!
\file   CRC.cpp
\author Thomas Breuer
\date   11.03.2011
*/

//*******************************************************************
#include "CRC.h"

//*******************************************************************
//
// cCRC
//
//*******************************************************************
//-------------------------------------------------------------------
cCRC::cCRC( MODE mode,
            WORD startCRC_In,
            WORD generatorPolynomIn )
{
  startCRC         = startCRC_In;
  crc              = startCRC;
  generatorPolynom = generatorPolynomIn;

  if( mode == FAST )
  {
    tabArray = new WORD[256];

    for( WORD i = 0; i < 256 && tabArray; i++ )
    {
      tabArray[i] = tabMethod( i );
    }
  }
  else
  {
    tabArray = NULL;
  }
}

//-------------------------------------------------------------------
cCRC::~cCRC( void )
{
  if( tabArray )
  {
    delete tabArray;
  }
}

//-------------------------------------------------------------------
WORD cCRC::operator()( const BYTE  *ptr,
                       const DWORD  size )
{
  WORD crcLoc = startCRC;

  for( DWORD i = 0; i < size; i++ )
  {
    BYTE idx = ( *(ptr++) ) ^ crcLoc;

    if( tabArray )
    {
      crcLoc = (crcLoc>>8) ^ tabArray[idx];
    }
    else
    {
      crcLoc = (crcLoc>>8) ^ tabMethod( idx );
    }
  }
  return( crcLoc );
}

//-------------------------------------------------------------------
void cCRC::operator()( const BYTE data )
{
  BYTE idx = data ^ crc;

  if( tabArray )
  {
    crc = (crc>>8) ^ tabArray[idx];
  }
  else
  {
    crc = (crc>>8) ^ tabMethod( idx );
  }
  //return( crc );
}

//-------------------------------------------------------------------
inline WORD cCRC::tabMethod( BYTE idx )
{
  WORD crcLoc = 0;

  for( BYTE bit = 0; bit < 8; bit++ )
  {
    if( (crcLoc^idx) & 0x01 )
    {
      crcLoc = (crcLoc>>1) ^ generatorPolynom;
    }
    else
    {
      crcLoc = (crcLoc>>1);
    }
    idx = (idx>>1);
  }
  return( crcLoc );
}

// EOF
