//*******************************************************************
/*!
\file   Timer_MCU.cpp
\author Thomas Breuer
\date   23.02.2012
*/

//*******************************************************************
//
// cHwTimer_MCU
//
//*******************************************************************
//-------------------------------------------------------------------
//cHwTimer_MCU *cHwTimer_MCU::timerPtr = 0;

//-------------------------------------------------------------------
cHwTimer_MCU::cHwTimer_MCU( DWORD cycleTimeIn )

: cHwTimer()

{
//  timerPtr = this;

  cycleTime = cycleTimeIn; // unit: us

threadID=0;
  threadHandle = CreateThread(NULL,
              10000,/*stack size*/
              (LPTHREAD_START_ROUTINE)starter, //MyThreadFunction,
              this, //NULL, //arg, /* argument to thread function */
              0, /* creation flags*/
              &threadID );
}

//-------------------------------------------------------------------
cHwTimer_MCU::~cHwTimer_MCU( void )
{
  TerminateThread(threadHandle, 0);
      CloseHandle(threadHandle);
}



//-------------------------------------------------------------------
void cHwTimer_MCU::enablePWM( BYTE ch, Mode pol )
{
  // no PWM with this timer
}

//-------------------------------------------------------------------
void cHwTimer_MCU::setPWM( WORD value, BYTE ch )
{
  // no PWM with this timer
}
