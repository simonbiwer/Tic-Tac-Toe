//*******************************************************************
/*!
\file   Timer_MCU.h
\author Thomas Breuer
\date   28.03.2013
*/

//*******************************************************************
#ifndef _HW_TIMER_MCU_H
#define _HW_TIMER_MCU_H

//*******************************************************************
#include "Com/Hardware/Timer/Timer.h"

//*******************************************************************
/*! 
\class cHwTimer_N

\brief Implementation of timer hardware

\example cHwTimer.cpp
*/
class cHwTimer_N : public cHwTimer
{
  public:
    //---------------------------------------------------------------
    typedef enum
    {
      CT16B0 = 0, //!< .
      CT16B1,     //!< .
      CT32B0,     //!< .
      CT32B1      //!< .
    } TIM_ID;

  public:
    //---------------------------------------------------------------
    /*! Initialize timer 
    */
    cHwTimer_N( TIM_ID  id,       //!< Timer hardware selection
                DWORD   cycleTime //!< Interrupt cycle time
                                  //!< in micro seconds (us)
              );

    //---------------------------------------------------------------
  virtual void enablePWM( BYTE ch = 0, cHwTimer::Mode pol = NORMAL );

    //---------------------------------------------------------------
    virtual void setPWM( WORD value, 
                         BYTE ch = 0 );

    //---------------------------------------------------------------
    virtual void irq( void );

  public:
    //---------------------------------------------------------------
    static cHwTimer_N *timerCT16B0_Ptr;
    static cHwTimer_N *timerCT16B1_Ptr;
    static cHwTimer_N *timerCT32B0_Ptr;
    static cHwTimer_N *timerCT32B1_Ptr;

  private:
    //---------------------------------------------------------------
    DWORD              tics;
    TIM_ID             id;
    LPC_CTxxBx_Type   *ptr;

}; //cHwTimer_N


#endif
