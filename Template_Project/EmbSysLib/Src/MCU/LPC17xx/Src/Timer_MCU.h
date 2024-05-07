//*******************************************************************
/*!
\file   Timer_MCU.h
\author Thomas Breuer
\date   08.09.2016
*/

//*******************************************************************
#ifndef _HW_TIMER_MCU_H
#define _HW_TIMER_MCU_H

//*******************************************************************
#include "Com/Hardware/Timer/Timer.h"

//*******************************************************************
/*!
\class cHwTimer_N

\brief Implementation of timer 0/1/2/3

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
      TIM_0 = 0, //!< Timer 0
      TIM_1,     //!< Timer 1
      TIM_2,     //!< Timer 2
      TIM_3,     //!< Timer 3
      TIM_PWM    //!< Timer PWM
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
    static cHwTimer_N *timerPtr_0;
    static cHwTimer_N *timerPtr_1;
    static cHwTimer_N *timerPtr_2;
    static cHwTimer_N *timerPtr_3;
    static cHwTimer_N *timerPtr_PWM;

  private:
    //---------------------------------------------------------------
    DWORD            tics;
    TimerId          timerId;
    LPC_TIM_TypeDef *ptr;

}; //cHwTimer_N

#endif
