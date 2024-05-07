//*******************************************************************
/*!
\file   RTOS_MCU.h
\author Thomas Breuer
\date
*/

//*******************************************************************
#ifndef _HW_RTOS_MCU_H
#define _HW_RTOS_MCU_H

//*******************************************************************
//#include "Hardware/Common/SPImaster.h"
#include <windows.h>

long int GetSysTimeMilliSec( void );
//*******************************************************************
/*!
\class cHwRTOS_MCU

\brief

\example
*/
class cHwRTOS_MCU
{
  public:
    //---------------------------------------------------------------

  public:
    //---------------------------------------------------------------
    /*!
    */
    cHwRTOS_MCU( void );

    static void init( WORD us, DWORD (*scheduleIn)( DWORD sp, BYTE flag ))
    {
    }


    static DWORD start( char     *stackAddrIn,
                       unsigned  stackSizeIn,
                       PVOID  arg,
                       LPTHREAD_START_ROUTINE  starter )
    {

   DWORD threadID=0;
  HANDLE  threadHandle;


 threadHandle = CreateThread(NULL,
              0,/*stack size*/
              starter, //MyThreadFunction,
              arg, /* argument to thread function */
              0, /* creation flags*/
              &threadID );

      return( (DWORD)threadHandle );

    }

    static void stop(DWORD id)
    {
// TODO line deleted in ORB:
//      TerminateThread((HANDLE)id, 0);
      CloseHandle((HANDLE)id);
    }

    static void pause()
    {
      Sleep(1);
    }

		//---------------------------------------------------------------
    static unsigned long getSysTime( void )
		{
			return( (unsigned long)GetSysTimeMilliSec() );
		}

    static DWORD (*schedule)( DWORD sp, BYTE flag );

//-------------------------------------------------------------------
//This is called when the task returns
static void del_process( void )
{

//  task_table[current_task].flags = 0; //clear the in use and exec flags
//  SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk; //switch the context
//  while(1); //once the context changes, the program will no longer return to this thread

 //// cRTOS::ptr->taskStop();
  while(1);
}


}; //cHwRTOS_MCU

#endif
