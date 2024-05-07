//*******************************************************************
/*!
\file   System.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _SYSTEM_H
#define _SYSTEM_H

//*******************************************************************
//#include "MCU.h"

//*******************************************************************
/*! 
\class cSystem

\brief Low level system functions

This class has to been instantiate once. 
*/
class cSystem
{
  public:
    //---------------------------------------------------------------
    /*! Watchdog timeout\n  
    */
    typedef enum
    {
      WD_TIMEOUT_16ms = 0,  //!<   ---
      WD_TIMEOUT_32ms,      //!<   ---
      WD_TIMEOUT_65ms,      //!<   ---
      WD_TIMEOUT_130ms,     //!<   ---
      WD_TIMEOUT_260ms,     //!<   ---
      WD_TIMEOUT_520ms,     //!<   ---
      WD_TIMEOUT_1000ms,    //!<   ---
      WD_TIMEOUT_2000ms     //!<   ---
    } MODE;

    //---------------------------------------------------------------
    /*! Hardware initialization
        \param disableInterrupts If false, interrupts are NOT
                                 disabled by a call to \a
                                 disableInterrupt()
    */
    cSystem( unsigned char disableInterrupts = false );

    //---------------------------------------------------------------
    /*! Start Hardware
    */
    void start( void );

    //---------------------------------------------------------------
    /*! Global interrupt disabling

        Each call to this function increments an internal counter, 
        see \a enableInterrupt()
    */
    static void disableInterrupt( void );

    //---------------------------------------------------------------
    /*! Global interrupt enabling

        Decrements the internal counter, see \a disableInterrupt(). 
        The interrupts are enabled, if this counter reaches 0
    */
    static void enableInterrupt( void );

    //---------------------------------------------------------------
    /*! Increment interrupt counter ( \see \a enableInterrupt() and 
        \a disableInterrupt() ) but don't touch interrupt enable fag
    */
    static void enterISR( void );

    //---------------------------------------------------------------
    /*! Decrement interrupt counter ( \see \a enableInterrupt() and 
        \a disableInterrupt() ) but don't touch interrupt enable fag
    */
    static void leaveISR(void);

    //---------------------------------------------------------------
    /*! Enable system's watchdog
        \param mode Watchdog mode, especially reset time
    */
    static void enableWatchdog( MODE mode );

    //---------------------------------------------------------------
    /*! Disable system's watchdog
    */
    static void disableWatchdog( void );

    //---------------------------------------------------------------
    /*! Feed the watchdog
    */
    static void feedWatchdog( void );

    //---------------------------------------------------------------
    /*! Controller reset
    */
    static void reset( void );

    //---------------------------------------------------------------
    /*! Runs timer update() functions instead interrupt, "VIRTUAL" 
        target only
    */
//    static void run( void );

    //---------------------------------------------------------------
    /*! Delays programm execution
        \param delay time in µs (micro seconds)
        \warning No exact timing!
    */
    static void delayMicroSec( unsigned short delay );

    //---------------------------------------------------------------
    /*! Delays programm execution
        \param delay time in ms (milli seconds)
        \warning No exact timing!
    */
    static void delayMilliSec( unsigned short delay );

  private:
    //---------------------------------------------------------------
    static unsigned char cntInterrupt;

}; // cSystem

//*******************************************************************
/*!
\brief Low level system initialization
*/
extern "C" 
{
  void SystemInit(void);
}

#endif
