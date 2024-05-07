//*******************************************************************
/*!
\file   TaskHandler.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _TASK_HANDLER_H
#define _TASK_HANDLER_H

//*******************************************************************
#include "Com/Std/List.h"
#include "Com/Std/Timer.h"

//*******************************************************************
/*!
\class cTaskHandler

Periodically call of the \a update() method of all tasks, which are
added to the update list.

There are two ways, how the task handler may be called:
- Timer interrupt (timer task)
- Execution of the run() method, in main loop for example (idle task)

To support the cTaskTimer class in a idle task (without timer),
another cTaskTimer (with timer) is required.

\example cTaskHandler.cpp
*/
class cTaskHandler : public cList::Item
{
  public:
    //*******************************************************************
    /*!
    \class Task

    \brief Base class for tasks

    A task is an object, which \a update() method is called periodically.

    Derived classes should at least:
     - Overwrite the \a update() method
    */
    class Task : public cList::Item
    {
      public:
        //---------------------------------------------------------------
        /*! Instantiate a class with given taskHandler. The task is added
            to the update list.
            \param taskHandler Referenz to a task handler object
        */
        // TODO: Da der Task sofort gestartet wird, sollte die Anmeldung nicht(!!!) automatisch erfolgen. 
        // statt dessen: explizite Anmeldung im Anwendungs-Konstruktor !!!
        
        // TODO: Ggf. cTaskManager statt cTaskHandler
        
        Task( cTaskHandler &taskHandler );

      private:
        //---------------------------------------------------------------
        /*! This is the \a update() method, which is called periodically
        */
        virtual void update( void ) = 0;

    }; //cTask


  public:
    //*******************************************************************
    /*!
    \class Timer

    \brief Timing features within a task

    The timer uses the timer tics, which are provided by a task object.
    */
    class Timer : public cTimer
    {
      public:
        //---------------------------------------------------------------
        /*! Instantiate a timer
            The runtime will be stored in the object. Further calls to
            \a start() or \a timeout() without parameter will use this stored runtime.
            \param taskHandler Reference to a task handler, which 
                               provides the timer tics
            \param timeToWait_msec Runtime in miliseconds (ms)
            \param timeToWait_usec Runtime in microseconds (us)
        */
        Timer( cTaskHandler &taskHandler,
               WORD          timeToWait_msec = 0,
               WORD          timeToWait_usec = 0 );

      private:
        //---------------------------------------------------------------
        virtual DWORD getTics( void );

        //---------------------------------------------------------------
        virtual DWORD getTimeOfTic( void );

      private:
        //---------------------------------------------------------------
        cTaskHandler &taskHandler;

    }; //Timer

  public:
    //---------------------------------------------------------------
    /*! Instatiate a task handler as a timer task (triggered by timer)
        \param timerPtr Pointer to a timer
    */
    cTaskHandler( cHwTimer *timerPtr );

    //---------------------------------------------------------------
    /*! Instatiate a task handler as an idle task.
        An idle task requires a explicit call of the \a run() method
        \param taskPtr (optional) to trigger time measurement 
                       (see \b Timer)
    */
    cTaskHandler( cTaskHandler *taskPtr = 0 );

    //---------------------------------------------------------------
    /*! Returns the cycle time of the task handler
        \return Cycle time in mikroseconds (us)
    */
    virtual DWORD getCycleTime( void );

    //---------------------------------------------------------------
    /*! Returns the number of tics resp. number of cycles, the task
        handler is called
        \return Number of tics
    */
    virtual unsigned long getTics( void );

    //---------------------------------------------------------------
    /*! Start the update() method of all added tasks. Idle tasks only
    */
    virtual void run( void );

    //---------------------------------------------------------------
    /*! Add a task to the update list of the task handler
        \param taskPtr Pointer to the task
    */
    virtual void addTask( Task *taskPtr );

  private:
    //---------------------------------------------------------------
    virtual void update( void );

  private:
    //---------------------------------------------------------------
    DWORD         tics;
    DWORD         cycleTime;
    cHwTimer     *timerPtr;
    cTaskHandler *taskPtr;
    cList         idle;

}; //cTaskHandler

#endif
