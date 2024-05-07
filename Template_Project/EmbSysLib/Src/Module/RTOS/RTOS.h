//*******************************************************************
/*!
\file   Module/RTOS/RTOS.h
\author Thomas Breuer
\date   17.12.2014, 09.03.2016
*/

//*******************************************************************
#ifndef _RTOS_H
#define _RTOS_H

//*******************************************************************
#include "lib.h"

//*******************************************************************
/*!
\class cRTOS

\brief Interface to the real time operating system (RTOS)

\todo Add description

\example cRTOS.cpp
*/
class cRTOS
{
  public:
    //***************************************************************
    /*!
    \class Task

    \brief Abstract base class of RTOS tasks
    
    A RTOS task is a class derived from \b Task. The derived class 
    has to implement the \b update() method, which is called by RTOS.
    Additionaly the \b onStart() and \b onStop() methods can be 
    overwritten. 
    This methods are called by RTOS when a task is started or stopped.

    \example cRTOS.cpp
    */
    class Task
    {
      protected:
        //-----------------------------------------------------------
        /*! Initialize task
            \param rtos      Reference to RTOS
            \param stackSize Stack size for this task
        */
        Task( cRTOS    &rtos,
              unsigned  stackSize );

        //-----------------------------------------------------------
        /*! Task destructor
        */
        virtual ~Task( void );


      public:
        //-----------------------------------------------------------
        /*! Stop the task
            
            Stop() stops the task execution and calls \b onStop()
            \remark Stop() must not be called within the \b same 
                    task context. Use Finish() instead
        */
        virtual void Stop( void );

        //-----------------------------------------------------------
        /*! Pauses the task execution for defined time
            \param time Time to wait before task is continued
        */
        virtual void Pause( WORD time = 0 );

        //-----------------------------------------------------------
        /*! Start a task execution
        */
        virtual void Start( void );

        //-----------------------------------------------------------
        /*! Stop() stops the task execution and calls \b onStop()
            \remark Stop() must not be called in an \b other task 
                    context. Use Stop() instead
        */
        virtual void Finish( void );

        //-----------------------------------------------------------
        /*! Determines wether a task is active or not
            \return 
                    - true: Task is active
                    - fasle: Task is not active
        */
        virtual bool isActive( void ) { return( isActiveFlag );}

      private:
        //-----------------------------------------------------------
        virtual void update( void ) = 0;

        //-----------------------------------------------------------
        virtual void OnStart( void ) {}

        //-----------------------------------------------------------
        virtual void OnStop( void ) {}

        //-----------------------------------------------------------
        static DWORD WINAPI starter( void *ptr );

      private:
        //-----------------------------------------------------------
        char     *stackAddr;
        unsigned  stackSize;
        int       id;
        BYTE      isActiveFlag;

        public:
        //-----------------------------------------------------------
        cRTOS &rtos;

      //-------------------------------------------------------------
      friend class cRTOS;

      }; //cRTOS::Task

  public:
    //***************************************************************
    /*!
    \class Timer

    \brief Implements a RTOS timer
    \see cTimer
    \example cRTOS.cpp

    \todo An automatic restart of the timer within timeout() fails, if 
          a Task is stopped and restarted. Reason: timeToGo is NOT 
          recalculated. timer.start() MUST be used OR NO auto restart!
    */
    class Timer : public cTimer
    {
      public:
        //-----------------------------------------------------------
        /*! Instantiate a timer
        
            The runtime will be stored in the object. Further calls to
            \a start() or \a timeout() without parameter will use this 
            stored runtime.
            \param timeToWait_msec Runtime in miliseconds (ms)
        */
        Timer( WORD timeToWait_msec = 0);

      private:
        //---------------------------------------------------------------
        virtual DWORD getTics();

        //---------------------------------------------------------------
        virtual DWORD getTimeOfTic();

    }; //RTOS::Timer

  public:
    //---------------------------------------------------------------
    /*! Instatiate a RTOS
    
        Setup RTOS and init RTOS related hardware (system tic 
        interrupt,...)
    */
    cRTOS( void );

  protected:
    //---------------------------------------------------------------
    int Start( Task &task );

    //---------------------------------------------------------------
    void Pause( Task &task );

    //---------------------------------------------------------------
    void Stop( Task &task );

  protected:
    //---------------------------------------------------------------
    virtual int add( unsigned sp ) = 0;

    //---------------------------------------------------------------
    virtual DWORD del( int id ) = 0;
    
    //---------------------------------------------------------------
    virtual DWORD get( int id ) = 0;

  protected:
    //---------------------------------------------------------------
    virtual unsigned scheduler( unsigned sp,
                                bool     isSysTic ) = 0;

  public:
    //---------------------------------------------------------------
    // Execute the scheduler
    // Static interface to the interupt services routine
    static DWORD schedule( DWORD sp, BYTE flag )
    {
      return( ptr->scheduler( sp, flag ) );
    }

  public:
    //---------------------------------------------------------------
    static cRTOS  *ptr;

}; //cRTOS

#endif
