//*******************************************************************
/*!
\file   Com/Hardware/Timer.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_TIMER_H
#define _HW_TIMER_H

//*******************************************************************
#include "Com/Std/List.h"

//*******************************************************************
/*! 
\class cHwTimer

\brief Abstract class supporting timer hardware

The timer is used to generate PWM signals and/or periodical 
interrupts.

This base class contains a update-list, to which objects can been 
added if derived from \a cList::Item. The update()-methods of all 
added objects are successively called by each timer interrupt.

\example cHwTimer.cpp
*/
class cHwTimer
{
  public:
    //---------------------------------------------------------------
    /*! \enum Mode
        \brief Define the operating modes of PWM generation
    */
    typedef enum
    {
      NORMAL  = 0x00, //!< Output polarity: active high
      INVERS  = 0x01  //!< Output polarity: active low
    } Mode;

  protected:
    //---------------------------------------------------------------
    // Standard constructor
    // 
    cHwTimer( void )
    {
    }

  public:
    //---------------------------------------------------------------
    /*! Get cycle time of timer interrupt
        \return Time between interrupts, unit: micro seconds (us)
    */
    virtual DWORD getCycleTime( void );

    //---------------------------------------------------------------
    /*! Add a new object to the update-list. 
        After executing this method, the objects update()-method 
        will been called periodically by timer interrupt
        \param ptr Pointer to the object
    */
    virtual void add( cList::Item *ptr );

    //---------------------------------------------------------------
    /*! Enable a PWM-Channel, if PWM is supported by the timer
        \param channel  Channel identification (0,...)
        \param polarity PWM output polarity
    */
    virtual void enablePWM( BYTE channel  = 0, 
                            Mode polarity = NORMAL) = 0;

    //---------------------------------------------------------------
    /*! Set the PWM duty cycle, if PWM is enabled
        \param value   Duty cycle, normalized to 16 bit range 
        \param channel Channel ID (0,...)
    */
    virtual void setPWM( WORD value, 
                         BYTE channel = 0 ) = 0;

  protected:
  //<! \todo check mode
  public:
    //---------------------------------------------------------------
    // Interrupt Service Routine of timer interrupt
    // This method has to been called by the hardware driven 
    // interrupt service routine only
    //
    virtual void isrHandler( void );

  protected:
    //---------------------------------------------------------------
    DWORD cycleTime; // cycle time in milisec

  private:
    //---------------------------------------------------------------
    cList isrList; // list of callable objects  

}; //cHwTimer

#endif
