//*******************************************************************
/*!
\file   Timer_MCU.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_TIMER_MCU_H
#define _HW_TIMER_MCU_H

//*******************************************************************
#include "Com/Hardware/Timer/Timer.h"

//*******************************************************************
/*! 
\class cHwTimer_N

\brief Implementation of timer 2/3/4/5, 6/7

\example cHwTimer.cpp
*/
class cHwTimer_N : public cHwTimer
{
  public:
    //---------------------------------------------------------------
    /*! \enum TimerId
        \brief Timer identification
    */
    typedef enum
    {
      TIM_1 = 1, //!< Timer 1
      TIM_2,     //!< Timer 2
      TIM_3,     //!< Timer 3
      TIM_4,     //!< Timer 4
      TIM_5,     //!< Timer 5
      TIM_7,     //!< Timer 7
      TIM_8,     //!< Timer 8
      TIM_9,     //!< Timer 9
      TIM_10,    //!< Timer 10
      TIM_11,    //!< Timer 11
      TIM_14     //!< Timer 14
    } TimerId;

  public:
    //---------------------------------------------------------------
    /*! Instantiate a timer
        \param timerId   Timer hardware selection
        \param cycleTime Interrupt cycle time in micro seconds (us)
    */
    cHwTimer_N( TimerId timerId, DWORD cycleTime );

    //---------------------------------------------------------------
    virtual void enablePWM( BYTE channel = 0, Mode polarity = NORMAL );

    //---------------------------------------------------------------
    virtual void setPWM( WORD value, BYTE channel = 0 );

    //---------------------------------------------------------------
    // Interrupt Service Routine (ISR) of timer interrupt.
    // This function must be public, because it is called 
    // in extern "C"
    void isr_N( void );

  public:
    //---------------------------------------------------------------
    static cHwTimer_N *timerPtr_1;
    static cHwTimer_N *timerPtr_2;
    static cHwTimer_N *timerPtr_3;
    static cHwTimer_N *timerPtr_4;
    static cHwTimer_N *timerPtr_5;
    static cHwTimer_N *timerPtr_7;
    static cHwTimer_N *timerPtr_8;
    static cHwTimer_N *timerPtr_9;
    static cHwTimer_N *timerPtr_10;
    static cHwTimer_N *timerPtr_11;
    static cHwTimer_N *timerPtr_14;
  
  private:
    //---------------------------------------------------------------
    DWORD        tics;
    TimerId      timerId;
    TIM_TypeDef *ptr;

}; //cHwTimer_N

#endif
