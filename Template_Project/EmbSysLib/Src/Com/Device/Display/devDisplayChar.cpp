//*******************************************************************
/*!
\file   devDisplayChar.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   25.04.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include <stdio.h>
#include <stdarg.h>

//*******************************************************************
//
// cDevDisplayChar
//
//*******************************************************************
//-------------------------------------------------------------------
cDevDisplayChar::cDevDisplayChar( cHwDisplay &displayIn )

: display( displayIn )

{
  display.clear();
}

//-------------------------------------------------------------------
void cDevDisplayChar::clear(void)
{
  display.clear();
}

//-------------------------------------------------------------------
void cDevDisplayChar::refresh(void)
{
  display.refresh();
}

//-------------------------------------------------------------------
void cDevDisplayChar::printf( BYTE        line,
                              BYTE        column,
                              BYTE        minLen,
                              const char *format,
                              ... )
{
  BYTE i;

  //! \todo: string-klasse verwenden oder string-Groesse als Parameter/Template?
  char str[32]; // ein paar Zeichen als Reserve

  va_list argzeiger;
  va_start ( argzeiger, format );
  vsnprintf( str, 31, format, argzeiger );
  va_end   ( argzeiger );

  display.gotoTextPos( line, column );

  // Zeichenweise an Display uebertragen
  for( i = 0; str[i] != 0 && i<30; i++ )
  {
    display.putChar( str[i] );
  }

  // Rest mit Leerzeichen ueberschreiben
  for( /* no init*/ ; i < minLen; i++)
  {
    display.putChar( ' ' );
  }
}

//-------------------------------------------------------------------
void cDevDisplayChar::printf( BYTE        line,
                              BYTE        column,
                              const char *str )
{
  BYTE i;

  display.gotoTextPos( line, column );

  // Zeichenweise an Display uebertragen
  for( i = 0; str[i] != 0; i++ )
  {
    display.putChar( str[i] );
  }
}

//EOF
