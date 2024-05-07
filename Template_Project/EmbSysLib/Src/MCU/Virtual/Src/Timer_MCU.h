//*******************************************************************
/*!
\file   Timer_MCU.h
\author Thomas Breuer
\date   23.02.2012

*/

//*******************************************************************
#ifndef _HW_TIMER_MCU_H
#define _HW_TIMER_MCU_H

//*******************************************************************
#include "Com/Hardware/Timer/Timer.h"

//*******************************************************************
/*!
\class cHwTimer_MCU

\brief Implementation of a timer

\example cHwTimer.cpp
*/
class cHwTimer_MCU : public cHwTimer
{
  public:
    //---------------------------------------------------------------
    /*! Initialize timer 0
        \param cycleTime  Cycle time in microseconds (us)
    */
    cHwTimer_MCU( DWORD cycleTime );
~cHwTimer_MCU( void );

static DWORD starter( cHwTimer_MCU *ptr )
        {
          ptr->run( ptr );
          return(0);
        }

void run(cHwTimer_MCU *ptr)
{
long long time=0;
          long long timeNext = GetSysTimeMicroSec();
          while(1)
          {
            if( (time=GetSysTimeMicroSec()) >= timeNext )
            {
              ptr->isrHandler(); // The task should never end
              timeNext = time + ptr->cycleTime;
            }
//            Sleep(100);
          }
          printf("\nend of thread\n");
}

//*******************************************************************
static long long GetSysTimeMicroSec( void )
{
  LARGE_INTEGER ticksPerSecond;
  LARGE_INTEGER tick;
  long long      time;

  QueryPerformanceFrequency(&ticksPerSecond);
  QueryPerformanceCounter(&tick);

  time = ((tick.QuadPart/*%1000 000 000*/)*1000000)/ticksPerSecond.QuadPart;

  return(time);
}

    //---------------------------------------------------------------
    virtual void enablePWM( BYTE ch = 0, Mode pol = NORMAL );

    //---------------------------------------------------------------
    virtual void setPWM( WORD value,
                         BYTE ch = 0 );

  public:
    //---------------------------------------------------------------
   // static cHwTimer_MCU *timerPtr;

    DWORD threadID;
  HANDLE  threadHandle;

}; //cHwTimer_MCU

#endif
