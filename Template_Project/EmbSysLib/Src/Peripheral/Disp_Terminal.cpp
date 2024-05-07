//*******************************************************************
/*!
\file   Disp_Terminal.cpp
\author Thomas Breuer
\date   10.03.2011
*/

//*******************************************************************
#include <stdio.h>

#include "Disp_Terminal.h"

//*******************************************************************
// 
// cHwDisp_Terminal
//
//*******************************************************************
//-------------------------------------------------------------------
cHwDisp_Terminal::cHwDisp_Terminal( cHwUART &uartIn )

: cHwDisplay( NUM_OF_LINE, NUM_OF_COLUM ), 
  uart(uartIn)

{
  clear();
}

//-------------------------------------------------------------------
inline void cHwDisp_Terminal::clear( void )
{
  sendESC("[2J");
}

//-------------------------------------------------------------------
inline void cHwDisp_Terminal::refresh( void )
{
}

//-------------------------------------------------------------------
inline void cHwDisp_Terminal::gotoTextPos( BYTE lineIn, BYTE columIn )
{
  char str[12];
  line  = lineIn;
  colum = columIn;

  // Startadresse fuer Display-Speicher schreiben
  if( line < NUM_OF_LINE && colum < NUM_OF_COLUM )
  {
    uart.set( '\r' ); 
    uart.set( '\n' ); 
    sprintf( str, "[%02d;%02df", (WORD)line  + 1,
                                 (WORD)colum + 1 );
    sendESC( str );
  }
}

//-------------------------------------------------------------------
inline void cHwDisp_Terminal::putChar( char c )
{
  if( line < NUM_OF_LINE && colum < NUM_OF_COLUM )
  {
    uart.set( c ); // putchar at current pos
    colum++;       // emulate cursor increment
  }
}

//-------------------------------------------------------------------
void cHwDisp_Terminal::sendESC( const char *seq )
{
  uart.set( 27 );
  for( BYTE i = 0; seq[i] != 0; i++ )
  {
    uart.set( seq[i] );
  }
}
       
//EOF
