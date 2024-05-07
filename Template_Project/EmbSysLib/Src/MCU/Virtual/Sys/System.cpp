//*******************************************************************
/*!
\file   System.cpp
\author Thomas Breuer
\date   11.03.2011
*/

//*******************************************************************
#include <stdio.h>

//*******************************************************************
static CRITICAL_SECTION _critSection;

//*******************************************************************
void SystemInit( void )
{
}

//*******************************************************************
long int GetSysTimeMicroSec( void )
{
  LARGE_INTEGER ticksPerSecond;
  LARGE_INTEGER tick;
  long long      time;

  QueryPerformanceFrequency(&ticksPerSecond);
  QueryPerformanceCounter(&tick);

  time = ((tick.QuadPart/*%1000 000 000*/)*1000000)/ticksPerSecond.QuadPart;

  return(time);
}

//*******************************************************************
long int GetSysTimeMilliSec( void )
{
  LARGE_INTEGER ticksPerSecond;
  LARGE_INTEGER tick;
  long long      time;

  QueryPerformanceFrequency(&ticksPerSecond);
  QueryPerformanceCounter(&tick);

  time = ((tick.QuadPart/*%1000 000 000*/)*1000)/ticksPerSecond.QuadPart;

  return(time);
}

//*******************************************************************
class cSystemTimer
{
  public:
    cSystemTimer( cHwTimer **tPtr )
    {
      this->tPtr = tPtr;
      this->id   = idCnt++;
    }

    void run(long int timeDelta)
    {
      int cnt=0;
      rest += timeDelta;
      cHwTimer *timerPtr = *tPtr;
      while(timerPtr && rest > timerPtr->getCycleTime())
      {
        timerPtr->isrHandler();
        rest -= timerPtr->getCycleTime();
        cnt++;
        if(cnt>=10000)
        {
          printf("Time %d aborted (%d cycles, %ld)\n",id, cnt, GetSysTimeMicroSec());
          rest=0;
          break;
        }
      }
    //  printf("Time %d done (%d cycles)\n",id,cnt);
    }

    cHwTimer **tPtr;
    unsigned long int rest;
    BYTE id;
    static BYTE idCnt;
};

BYTE cSystemTimer::idCnt = 0;





//*******************************************************************
//
// cSystem
//
//*******************************************************************
//-------------------------------------------------------------------
unsigned char cSystem::cntInterrupt = 0;

static long int timeLast = 0;

//cSystemTimer t0( &cHwTimer_0::timerPtr );
//cSystemTimer t1( &cHwTimer_1::timerPtr );


//-------------------------------------------------------------------
cSystem::cSystem( unsigned char disableInterrupts )
{
  InitializeCriticalSection (& _critSection);

  SystemInit();

  disableWatchdog();

  timeLast = GetSysTimeMicroSec();

  cntInterrupt = 0;
}

//-------------------------------------------------------------------
void cSystem::disableInterrupt( void )
{
  if( cntInterrupt == 0 )
  {
    EnterCriticalSection (& _critSection);
  }
  cntInterrupt++;
}

//-------------------------------------------------------------------
void cSystem::enableInterrupt( void )
{

  if( cntInterrupt > 0 )
  {
    cntInterrupt--;
  }
  if( cntInterrupt == 0 )
  {
    LeaveCriticalSection (& _critSection);
  }
}

//-------------------------------------------------------------------
void cSystem::enterISR( void )
{
//  cntInterrupt++;
}

//-------------------------------------------------------------------
void cSystem::leaveISR( void )
{
/*
  if( cntInterrupt > 0 )
  {
    cntInterrupt--;
  }
*/
}

//-------------------------------------------------------------------
//void  cSystem::run( void )
//{
 // long int timeDelta;
 // long int time = GetSysTimeMicroSec();

//  timeDelta = time - timeLast;
//  if(timeDelta < 0)
//  {
//    timeDelta += (long int)(-1);
//    printf("time %ld last %ld delta %ld\n",time, timeLast, timeDelta);

//  }

 // printf("systime:time=%ld timeLast=%ld delta=%ld %d\n",time,timeLast, timeDelta, cHwTimer0::timerPtr->getCycleTime());

//  timeLast = time;
//  t0.run( timeDelta );
//  t1.run( timeDelta );
//}

//-------------------------------------------------------------------
void cSystem::enableWatchdog( MODE mode )
{
  //<! \remark watchdog isn't implemented yet
}

//-------------------------------------------------------------------
void cSystem::disableWatchdog( void )
{
  //<! \remark watchdog isn't implemented yet
}

//-------------------------------------------------------------------
void cSystem::feedWatchdog( void )
{
  //<! \remark watchdog isn't implemented yet
}

//-------------------------------------------------------------------
void cSystem::reset( void )
{
  // todo:
  // stop all threads here (register threads first...)
  printf("\nfinished\n");
  exit( 1 );
}

//-------------------------------------------------------------------
void cSystem::delayMicroSec( unsigned short delay )
{
  #warning 'delayMicroSec not implemented'
}

//-------------------------------------------------------------------
void cSystem::delayMilliSec( unsigned short delay )
{
//  for(;delay>0;delay--)
//    delayMicroSec(1000);
  Sleep( delay );
}

//EOF
