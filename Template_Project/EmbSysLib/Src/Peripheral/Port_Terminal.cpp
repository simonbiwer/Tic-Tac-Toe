//*******************************************************************
/*!
\file   Port_Terminal.cpp
\author Thomas Breuer
\date   08.03.2011
*/

//*******************************************************************
#include "lib.h"
#include "Port_Terminal.h"

//*******************************************************************
//
// cHwPort_Terminal
//
//*******************************************************************
//-------------------------------------------------------------------
cHwPort_Terminal::cHwPort_Terminal( cHwUART  &uartIn,
                                    MTYPE     lockIn,
                                    cHwTimer *tPtrIn )

: cHwPort() , uart(uartIn)

{
  lock = lockIn;
  tPtr = tPtrIn;
  if( tPtr )
  {
    tPtr->add( this ); // register object at timer
  }

  escape = 0;
  latch  = 0;
  out    = 0;
  dir    = 0;
  last   = 0;
}

//---------------------------------------------------------------
void cHwPort_Terminal::setMode( MTYPE mask, Mode mode )
{
  if( mode & cHwPort::Out )
  {
    dir |= mask; 
  }
  else
  {
    dir &= ~mask;
  }
}

//---------------------------------------------------------------
void cHwPort_Terminal::setPinMode( BYTE pinId, Mode modeIn )
{
  setMode( (MTYPE)0x01 << pinId, modeIn );
}

//-------------------------------------------------------------------
void cHwPort_Terminal::set( MTYPE mask )
{
  out |= mask;
  if( tPtr == 0 )
  {
    update();
  }
}

//-------------------------------------------------------------------
void cHwPort_Terminal::set( MTYPE mask, MTYPE value )
{
  out |=  (mask&value);
  out &= ~(mask&value);
  if( tPtr == 0 )
  {
    update();
  }
}

//-------------------------------------------------------------------
void cHwPort_Terminal::clr( MTYPE mask )
{
  out &= ~mask;
  if( tPtr == 0 )
  {
    update();
  }
}

//-------------------------------------------------------------------
MTYPE cHwPort_Terminal::get( void )
{
  if( tPtr == 0 )
  {
    update();
  }

  MTYPE ret = latch;
  return(ret);
}

//-------------------------------------------------------------------
void cHwPort_Terminal::update( void )
{
  BYTE c=0;
  MTYPE tmpLatch = 0;

  latch = latch & lock; // clear bit, if lock is not set

  //
  // parsing keyboard stream
  //
  while( uart.get(&c) && c != 0 ) // read character from terminal
  {
    switch( escape )
    {
      case 0: // we are not in an escape sequence
        switch( c )
        {

          case '1': tmpLatch |= NUM_1; break;
          case '2': tmpLatch |= NUM_2; break;
          case '3': tmpLatch |= NUM_3; break;
          case '4': tmpLatch |= NUM_4; break;
          case '5': tmpLatch |= NUM_5; break;
          case '6': tmpLatch |= NUM_6; break;
          case '7': tmpLatch |= NUM_7; break;
          case '8': tmpLatch |= NUM_8; break;

          case '+': tmpLatch |= PLUS;  break;
          case '-': tmpLatch |= MINUS; break;
          case ' ': tmpLatch |= BLANK; break;
          case '\r':tmpLatch |= ENTER; break;
          case 27  :escape = 1;        break;
          case 224 :escape = 2;        break;
        }
        break;

      case 1: // last character was an escape
        switch( c )
        {
          case '[': escape = 2; break; // sequence completed
          case 27:  tmpLatch |= last;  // repeated key
                    escape = 0;break;
          default:  escape = 0; break; // unvalid sequence
        }
        break;

      case 2: // we have received 'ESC' and '['
        switch( c )
        {
          case 'A':
          case 72:  last = UP;    break;
          case 'B':
          case 80:  last = DOWN;  break;
          case 'C':
          case 77:  last = RIGHT; break;
          case 'D':
          case 75:  last = LEFT;  break;
          default:  last = 0;     break;
        }
        tmpLatch |= last;
        escape = 0;
        break;
      }
  }

  //
  // calculate latch
  //
  cSystem::disableInterrupt();
  latch |= tmpLatch & ~lock;
  latch ^= tmpLatch &  lock;
  cSystem::enableInterrupt();

  //
  // diplay port's output
  //
  if( dir ) // has port any output?
  {
    for( BYTE i = 0; i < 8*sizeof(MTYPE); i++ )
    {
      MTYPE mask = (0x01 << (8*sizeof(MTYPE) - i - 1) );
      if( dir & mask )
      {
        uart.set( (out&mask) ? 'X' : '.' );
      }
      else
      {
        uart.set('-');
      }
    }
    uart.set('\r');
  }
}

// EOF
