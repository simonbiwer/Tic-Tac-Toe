//*******************************************************************
/*!
\file   RTOS_Scheduler.h
\author Thomas Breuer
\date   17.12.2014, 09.03.2016
*/

//*******************************************************************
#ifndef _RTOS_SCHEDULER_H
#define _RTOS_SCHEDULER_H

//*******************************************************************
#include "lib.h"
#include "RTOS.h"

//*******************************************************************
/*!
\class cRTOS_RR

\brief Base class for round robin scheduler

\example cRTOS.cpp
*/
template <BYTE NUM_OF_TASK> 
class cRTOS_RR : public cRTOS
{
  private:
    //---------------------------------------------------------------
    typedef struct
    {
      unsigned stackPtr; //The task's current stack pointer
      int      flags;    //Status flags includes activity status, etc.
    } TaskInfo;

  private:
    //---------------------------------------------------------------
    typedef enum
    {
      IN_USE_FLAG = 0x01,
      EXEC_FLAG   = 0x02,
      IDLE_FLAG   = 0x04
    } Flag;

  public:
    //---------------------------------------------------------------
    /*! Instantiate a RTOS with round robin task scheduler
    
        \param us Time slice per task [microsec]
    */
    cRTOS_RR( unsigned us = 1000 )
  
    : cRTOS()
    
    {
      currentTask       = 0;
      currentCyclicTask = 0;
      
      for( int i = 0; i < NUM_OF_TASK + 1; i++ )
      {
          taskTable[i].flags = 0;
      }
      taskTable[0].stackPtr = 0;
      taskTable[0].flags    = IN_USE_FLAG | EXEC_FLAG | IDLE_FLAG;

      cHwRTOS_MCU::init( (WORD)us , 
                         (DWORD (*)( DWORD sp, BYTE flag ))schedule );
    }
  private:
    //---------------------------------------------------------------
    // Add a task to the task list
    virtual int add( unsigned stackPtr )
    {
      if( currentCyclicTask == 0)
      {
        currentCyclicTask = 1;
      }
      int flags = IN_USE_FLAG | EXEC_FLAG;

      for(int i = 0; i < NUM_OF_TASK + 1; i++ )
      {
        if( taskTable[i].flags == 0 )
        {
          taskTable[i].stackPtr = stackPtr;
          taskTable[i].flags    = flags;
          return( i );
        }
      }
      return( 0 );
    }

    //---------------------------------------------------------------
    virtual DWORD del( int id )
    {
      DWORD ret = taskTable[id].stackPtr;
      
      taskTable[id].flags    = 0;
      taskTable[id].stackPtr = 0;
      return( ret );
    }

    //---------------------------------------------------------------
    // Get task stackPtr
    virtual DWORD get( int id )
    {
      return( taskTable[id].stackPtr );
    }

    //---------------------------------------------------------------
    virtual unsigned scheduler( unsigned stackPtr,
                                bool     isSysTic )
    {
      taskTable[currentTask].stackPtr = stackPtr;

      if( isSysTic ) // called by timeout
      {
        lastTask = currentCyclicTask;
        while( 1 )
        {
          currentCyclicTask++;
          
          if( currentCyclicTask == NUM_OF_TASK + 1 )
          {
            currentCyclicTask = 0;
          }
          if( currentCyclicTask == lastTask )
          {
            break;
          }
          if( taskTable[currentCyclicTask].flags & EXEC_FLAG )
          {  
            break;
          }
        }        
        currentTask = currentCyclicTask;
      }
      else
      {
        currentTask = 0;
      }

      return( taskTable[currentTask].stackPtr );
    }

  private:
    //---------------------------------------------------------------
    TaskInfo  taskTable[ NUM_OF_TASK + 1 ];
    int       currentTask;
    int       currentCyclicTask;
    int       lastTask;
};

#endif
