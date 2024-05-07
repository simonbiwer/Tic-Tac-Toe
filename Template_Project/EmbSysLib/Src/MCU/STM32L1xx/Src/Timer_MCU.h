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
      TIM_2 = 2,  //!< Timer 2 
      TIM_3,      //!< Timer 3 
      TIM_4,      //!< Timer 4
      TIM_5,      //!< Timer 5
      TIM_6,      //!< Timer 6
      TIM_7       //!< Timer 7
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
    void isr( void );

  public:
    //---------------------------------------------------------------
    static cHwTimer_N *timerPtr_2;
    static cHwTimer_N *timerPtr_3;
    static cHwTimer_N *timerPtr_4;
    static cHwTimer_N *timerPtr_5;
    static cHwTimer_N *timerPtr_6;
    static cHwTimer_N *timerPtr_7;
 
  private:
    //---------------------------------------------------------------
    DWORD        tics; 
    TimerId      timerId;
    TIM_TypeDef *ptr;

}; //cHwTimer_N

#endif
