//*******************************************************************
/*!
\file   DisplayFont.cpp
\author Thomas Breuer
\date   21.03.2012
*/

//*******************************************************************
#include "DisplayFont.h"

//*******************************************************************
//
// cHwDisplayFont
//
//*******************************************************************
//-------------------------------------------------------------------
cHwDisplayFont::cHwDisplayFont( const cHwDisplayFontProperties *propIn,
                                const BYTE                     *dataIn )
{
  prop     = propIn;
  data     = dataIn;
  selected = data;  // default is first character
}

//-------------------------------------------------------------------
 BYTE cHwDisplayFont::getCharWidth( void ) const
{
  return( GET_BYTE_PROGMEM(prop->charWidth) );
}

//-------------------------------------------------------------------
BYTE cHwDisplayFont::getCharHeight( void ) const
{
  return( GET_BYTE_PROGMEM(prop->charHeight) );
}

//-------------------------------------------------------------------
void cHwDisplayFont::setChar( BYTE c )
{
  BYTE id = 0;

  if( GET_BYTE_PROGMEM(prop->firstId) <= c && c <= GET_BYTE_PROGMEM(prop->lastId) ) // is char c defined?
  {
    id = c - GET_BYTE_PROGMEM(prop->firstId);
  }
  selected = data + (WORD)id * GET_BYTE_PROGMEM(prop->bytePerChar);
}

//-------------------------------------------------------------------
BYTE cHwDisplayFont::getPixel( BYTE x, BYTE y )
{
                                                 // calc pixel number
  WORD pixel  = ( (WORD)x + (WORD)y * getCharWidth() );

                                                // get pixel value
  BYTE ret = GET_BYTE_PROGMEM_PTR(selected+(pixel>>3)) & ( 0x80>>(pixel&0x07) );

  return( ret ? true : false );
}

//EOF
