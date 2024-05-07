//*******************************************************************
/*!
\file   TaskHandler.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "TaskHandler.h"

//*******************************************************************
//
// cTaskHandler
//
//*******************************************************************
//-------------------------------------------------------------------
cTaskHandler::cTaskHandler( cHwTimer *timerPtrIn )
{
  timerPtr = timerPtrIn;
  taskPtr  = 0;

  if( timerPtr )
  {
    timerPtr->add( this );

    cycleTime = timerPtr->getCycleTime();
  }
  else // kein Timer, daher Idle-Task ohne extere Task für Timer
  {
    cycleTime = (unsigned long)(-1);
  }
}

//-------------------------------------------------------------------
cTaskHandler::cTaskHandler( cTaskHandler *taskPtrIn )
{
  timerPtr = 0;
  taskPtr  = taskPtrIn;
  if( taskPtr )
  {
    cycleTime = taskPtr->timerPtr->getCycleTime();
  }
  else // kein Timer
  {
    cycleTime = (unsigned long)(-1);
  }
}

//-------------------------------------------------------------------
inline DWORD cTaskHandler::getCycleTime( void )
{
  return( cycleTime );
}

//-------------------------------------------------------------------
inline unsigned long cTaskHandler::getTics( void )
{
  return( tics );
}

//-------------------------------------------------------------------
inline void cTaskHandler::run( void )
{
  if( taskPtr )
  {
    cSystem::disableInterrupt();
    tics = taskPtr->getTics();
    cSystem::enableInterrupt();
  }
  idle.updateAll();
}

//-------------------------------------------------------------------
void cTaskHandler::addTask( Task *taskPtrIn )
{
  if( timerPtr )
  {
    timerPtr->add( taskPtrIn );
  }
  else
  {
    idle.add( taskPtrIn );
  }
}

//-------------------------------------------------------------------
inline void cTaskHandler::update( void )
{
  tics++;
}

//*******************************************************************
//
// cTaskHandler::Task
//
//*******************************************************************
//-------------------------------------------------------------------
cTaskHandler::Task::Task( cTaskHandler &taskHandler )
{
  taskHandler.addTask( this );
}

//*******************************************************************
//
// cTaskHandler::Timer
//
//*******************************************************************
//-------------------------------------------------------------------
cTaskHandler::Timer::Timer( cTaskHandler &taskHandlerIn,
                            WORD          timeToWait_msec,
                            WORD          timeToWait_usec )

: taskHandler( taskHandlerIn )

{ 
  set( timeToWait_msec, timeToWait_usec ); // Don't use cTimer constructor
}

//-------------------------------------------------------------------
DWORD cTaskHandler::Timer::getTics( void )
{
  return( taskHandler.getTics() );
}

//-------------------------------------------------------------------
DWORD cTaskHandler::Timer::getTimeOfTic( void )
{
  return( taskHandler.getCycleTime() );
}

//EOF
