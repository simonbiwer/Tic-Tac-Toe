//*******************************************************************
/*!
\file   devAnalogOutPWM.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.

*/

//*******************************************************************
#ifndef _DEV_ANALOG_OUT_PWM_H
#define _DEV_ANALOG_OUT_PWM_H

//*******************************************************************
#include "devAnalogOut.h"
#include "Com/Device/Digital/devDigital.h"
#include "Com/Hardware/Timer/Timer.h"

//*******************************************************************
/*!
\class cDevAnalogOutPWM

\brief Analog output device (PWM), using cHwTimer

\example cDevAnalog.cpp
*/
class cDevAnalogOutPWM : public cDevAnalogOut
{
  public:
    //---------------------------------------------------------------
    /*! Instatiate a PWM output device
        \param timer   Reference to timer hardware
        \param mode    Operating mode of timer
        \param channel Channel ID
        \param max     Analog value corresponding to maximum raw value
        \param min     Analog value corresponding to minimum raw value
    */
    cDevAnalogOutPWM( cHwTimer       &timer,
                      cHwTimer::Mode  mode    = cHwTimer::NORMAL,
                      BYTE            channel = 0,
                      float           max     = 1.0f,
                      float           min     = 0.0f );

  public:
    //---------------------------------------------------------------
    /*! Set the raw output value [0,..,0xFFFF]
        \param value Value to set
    */
    virtual void setRaw( WORD value );

  private:
    //---------------------------------------------------------------
    cHwTimer &timer;

  public:
    //---------------------------------------------------------------
    using cDevAnalogOut::operator=;

}; //cDevAnalogOutPWM


//*******************************************************************
/*!
\class cDevAnalogOutPWMemul

\brief Analog output device (PWM), using emulated PWM

\example cDevAnalog.cpp
*/
class cDevAnalogOutPWMemul : public cDevAnalogOut, 
                                      cList::Item
{
  public:
    //---------------------------------------------------------------
    /*! Instatiate a analog output device

        Generate PWM within a time-triggered ISR
        \param timer Reference to a timer
        \param port  Reference to the output port
        \param res   PWM resolution
        \param max   Analog value corresponding to maximum raw value
        \param min   Analog value corresponding to minimum raw value
    */
    cDevAnalogOutPWMemul( cHwTimer    &timer,
                          cDevDigital &port,
                          BYTE         res = 16,
                          float        max = 1.0,
                          float        min = 0.0 );

  public:
    //---------------------------------------------------------------
    /*! Set the raw output value [0,..,0xFFFF]
        \param value Value to set
    */
    virtual void setRaw( WORD value );

  private:
    //---------------------------------------------------------------
    virtual void update( void );

  private:
    //---------------------------------------------------------------
    cHwTimer         &timer;
    BYTE              shift;
    WORD              t;
    WORD              max;
    WORD              limit;
    cDevDigital      &port;
    cSharedMem<WORD>  limitBuf;

  public:
    //---------------------------------------------------------------
    using cDevAnalogOut::operator=;

}; //cDevAnalogOutPWMemul

#endif
