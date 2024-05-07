//*******************************************************************
/*!
\file   Std/Timer.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _STD_TIMER_H
#define _STD_TIMER_H

//*******************************************************************
/*!
\class cTimer

\brief Timing features within a task

The timer uses the timer tics, which are provided by a task object.
*/
class cTimer
{
  public:
    //---------------------------------------------------------------
    /*! Instantiate a timer
        
        Zero run time
    */
    cTimer( void );

    //---------------------------------------------------------------
    /*! Starts the time, regardless of the timer is running or not
        \param timeToWait_msec Runtime in miliseconds (ms)
        \param timeToWait_usec Runtime in microseconds (us)
    */
    void start( WORD timeToWait_msec,
                WORD timeToWait_usec = 0 );

    //---------------------------------------------------------------
    /*! \see \a start(), but reuse the stored runtime
    */
    void start( void );

    //---------------------------------------------------------------
    /*! Check timeout\n

        The behaviour depends on the run state of the timer:
        - Timer is running: If an timeout occures, the timer will be
                            stopped. All parameters are ignored
        - Timer is NOT running: The timer will be restarted with given
                                parameters
        \param timeToWait_msec Timer-Laufzeit (ms)
        \param timeToWait_usec Timer-Laufzeit (us)
        \return timer state:
                 - true: timeout
                 - false: timer is still running
    */
    BYTE timeout( WORD timeToWait_msec,
                  WORD timeToWait_usec = 0 );

    //--------------------------------------------------------------
    /*! \see \a timeout(), but reuse the stored runtime
        \return timer state:
                 - true: timeout
                 - false: timer is still running
    */
    BYTE timeout( void );

    //---------------------------------------------------------------
    /*! 
    */
    BYTE isRunning( void );

    //---------------------------------------------------------------
    /*! Stop the timer
        \remark The next call to \a timeout() does not indicate a timeout
    */
    void stop( void );

  protected:
    //---------------------------------------------------------------
    // Set runtime, but don't start the timer
    // timeToWait_msec: Runtime in miliseconds (ms)
    // timeToWait_usec: Runtime in microseconds (us)
    void set( WORD timeToWait_msec,
              WORD timeToWait_usec = 0 );
              
  protected:
    //---------------------------------------------------------------
    virtual DWORD getTics() = 0;

    //---------------------------------------------------------------
    virtual DWORD getTimeOfTic() = 0;

  protected:
    //---------------------------------------------------------------
    DWORD  startTime;
    DWORD  timeToGo;
    BYTE   running;

}; //Timer

#endif
