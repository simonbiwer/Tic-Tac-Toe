//*******************************************************************
/*!
\file   Module/RTOS/RTOS.cpp
\author Thomas Breuer
\date   14.02.2011, 09.03.2016
*/

//*******************************************************************
#include "RTOS.h"

//*******************************************************************
cRTOS *cRTOS::ptr = 0;

//*******************************************************************
//
// cRTOS::Task
//
//*******************************************************************
//-------------------------------------------------------------------
cRTOS::Task::Task( cRTOS    &rtosIn,
                   unsigned  stackSizeIn )

: rtos( rtosIn )
{
  stackSize = stackSizeIn;
  stackAddr = new char[stackSize];
  isActiveFlag = false;
}

//-------------------------------------------------------------------
cRTOS::Task::~Task( void )
{
   Stop();
   delete stackAddr;
   stackAddr = 0;
}

//-------------------------------------------------------------------
DWORD WINAPI cRTOS::Task::starter( void *ptr )
{
  ((Task*)ptr)->update();
  ((Task*)ptr)->Finish();
  return(0);
}

//-------------------------------------------------------------------
void cRTOS::Task::Finish( void )
{
  if( isActiveFlag )
  {
    isActiveFlag = false;
    OnStop();
    rtos.Stop( *this );

    // TODO: Vorlaeufige Loesung
    while(1);
  }
}

//-------------------------------------------------------------------
void cRTOS::Task::Stop( void )
{
  if( isActiveFlag )
  {
    isActiveFlag = false;
    rtos.Stop( *this );
    OnStop();
  }
}

//-------------------------------------------------------------------
void cRTOS::Task::Pause( WORD time /*ms*/)
{
  unsigned long timeToGo = cHwRTOS_MCU::getSysTime() + time;

  do
  {
    rtos.Pause( *this );
  } while( cHwRTOS_MCU::getSysTime() < timeToGo );

}

//-------------------------------------------------------------------
void cRTOS::Task::Start( void )
{
  if( !isActiveFlag )
  {
    isActiveFlag = true;
    OnStart();
    rtos.Start( *this );
  }
}

//*******************************************************************
//
// cRTOS::Timer
//
//*******************************************************************
//-------------------------------------------------------------------
cRTOS::Timer::Timer( WORD timeToWait_msec )
{
  set( timeToWait_msec ); // Don't use cTimer constructor
}

//-------------------------------------------------------------------
DWORD cRTOS::Timer::getTics( void )
{
  return( cHwRTOS_MCU::getSysTime() );
}

//-------------------------------------------------------------------
DWORD cRTOS::Timer::getTimeOfTic( void )
{
  return( 1000/*us*/ );
}

//*******************************************************************
//
// cRTOS
//
//*******************************************************************
//-------------------------------------------------------------------
cRTOS::cRTOS( void )
{
  ptr = this;
}

//-------------------------------------------------------------------
int cRTOS::Start( cRTOS::Task &task )
{
  int ret = 0;

  // Disable context switching to support multi-threaded calls to
  // this function
  cSystem::disableInterrupt();

  unsigned sp = cHwRTOS_MCU::start( task.stackAddr,
                                    task.stackSize,
                                    (void *)&task,
                                    cRTOS::Task::starter );

  ret = add( sp );

  //Enable context switching
  cSystem::enableInterrupt();

  task.id = ret;

  return (ret);
}

//-------------------------------------------------------------------
void cRTOS::Pause( cRTOS::Task &task )
{
  cHwRTOS_MCU::pause();
}

//-------------------------------------------------------------------
void cRTOS::Stop( cRTOS::Task &task )
{
  cHwRTOS_MCU::stop( get(task.id) );

  del( task.id );
}

//EOF
