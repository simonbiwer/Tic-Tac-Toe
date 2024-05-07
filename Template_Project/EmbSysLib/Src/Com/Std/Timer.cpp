//*******************************************************************
/*!
\file   Std/Timer.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
//
// cTimer
//
//*******************************************************************
//-------------------------------------------------------------------
cTimer::cTimer( void )

{
  running = false;
  timeToGo = 0;
}

//-------------------------------------------------------------------
void cTimer::start( WORD timeToWait_msec,
                    WORD timeToWait_usec )
{
  set( timeToWait_msec, timeToWait_usec );
  start();
}

//-------------------------------------------------------------------
void cTimer::start( void )
{
  startTime = getTics();
  running = true;
}

//-------------------------------------------------------------------
BYTE cTimer::timeout( WORD timeToWait_msec,
                      WORD timeToWait_usec )
{
  if( !running )
  {
    set( timeToWait_msec, timeToWait_usec );
  }
  return( timeout() );
}

//-------------------------------------------------------------------
BYTE cTimer::timeout( void )
{
  BYTE runState = false; // no timeout

  if( running )
  {
    if(getTics() - startTime >= timeToGo )
    {
      running = false;
    }
    runState = !running; // not running = timeout
  }

  if( !running )
  {
    start();
  }

  return( runState );
}

//-------------------------------------------------------------------
BYTE cTimer::isRunning( void )
{
  if( running && timeout() )
  {
    stop();
  }
  return( running );
}

//-------------------------------------------------------------------
void cTimer::stop( void )
{
  running = false;
}

//-------------------------------------------------------------------
void cTimer::set( WORD timeToWait_msec,
                  WORD timeToWait_usec )
{
  timeToGo =   ((DWORD)timeToWait_msec*1000L + timeToWait_usec)
             / getTimeOfTic();
}

// EOF
