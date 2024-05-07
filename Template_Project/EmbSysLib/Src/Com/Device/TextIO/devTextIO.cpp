//*******************************************************************
/*!
\file   devTextIO.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

//*******************************************************************
#include "devTextIO.h"

//*******************************************************************
//
// cDevTextIO
//
//*******************************************************************
//-------------------------------------------------------------------
cDevTextIO::cDevTextIO( BYTE        inBufSizeIn,
                        BYTE        outBufSizeIn,
                        const char *eosIn,
                        const char *keyIn )
{
  inBufSize  = inBufSizeIn;
  outBufSize = outBufSizeIn;
  strIn      = new char[ inBufSize + 1];
  strOut     = new char[outBufSize + 1];
  idx        = 0;
  eos        = eosIn;
  key        = keyIn;
  escape     = 0;
  last       = 0;
}

//-------------------------------------------------------------------
char* cDevTextIO::getString( void )
{
	BYTE c        = 0;
  BYTE complete = 0;

  while( get( &c ) && !complete )
  {
    switch( escape )
    {
      case 0: // we are not in an escape sequence
        switch( c )
        {
          case 27  : escape = 1;          break; // start of esc sequence
          case 224 : escape = 2;          break; // function key
          default  : last = c;
                     strIn[idx++] = last; break; // normal
        }
        break;

      case 1: // last character was an escape / function key
        switch( c )
        {
          case '[': escape = 2;          break; // sequence completed
          case 27:  strIn[idx++] = last;        // add repeated key
                    escape = 0;          break;
          default:  escape = 0;          break; // unvalid sequence
        }
        break;

      case 2: // we have received ('ESC' and '[') or '\224'
        last = c | 0x80;
        strIn[idx++] = last;
        escape = 0;
        break;
    }

    // check end of string condition
    if(    (idx >= inBufSize-2)           // buffer full
                                          // OR
        || (   (idx == 1 )                // first character and ...
            && (   (last&0x80)            //   ... esc sequence or function key
                || strchr( key, last )) ) //   OR  single key
                                          // OR
        || (strchr( eos, last ))          // end of string character
      )
    {
      complete   = 1;
      strIn[idx] = 0;
      idx        = 0;
      return( strIn );
    }
  }
  return( NULL );
}

//-------------------------------------------------------------------
void cDevTextIO::printf( const char *format, ... )
{
  va_list argzeiger;

  va_start ( argzeiger, format );
  vsnprintf( strOut, outBufSize, format, argzeiger );
  va_end   ( argzeiger );

  // Set output
  set( (BYTE*)strOut, strlen(strOut) );
}

//EOF
