//*******************************************************************
/*!
\file   ADC.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_ADC_H
#define _HW_ADC_H

//*******************************************************************
#include "Com/Hardware/Timer/Timer.h"

//*******************************************************************
/*! 
\class cHwADC

\brief Abstract class supporting the analog to digital converter (ADC)


This class is an interface to the ADC hardware. 

All registered channels (see \a addChannel()) are scanned after 
calling the update() method. The sampled analog values are then 
stored in a buffer and can be obtained by get() \b after the update() 
method is called next time.\n
In other words: An ongoing conversion does not affect the values given 
by get(), until the conversion is ready.\n
A timer object (see: cHwTimer) may used to trigger the conversion 
automatically.\n
Multiple channels are supported (limited by hardware).\n
Independently of the resolution of the used ADC, a 16 bit value 
is delivered

Derived classes should at least:
 - initialize the ADC hardware
 - implement getResult(), startCh() and configCh() to access the 
   hardware
 - call \a isr() in the appropriate ISR

\example cHwADC.cpp
*/
class cHwADC : public cList::Item
{
  protected:
    //---------------------------------------------------------------
    // Initialize the ADC and allocate buffer memory
    // num:   Number of supported channels
    // tPtr:  Referenz to a timer object (optional). If declared, 
    //        auto trigger conversion is used. Otherwise the update() 
    //        methode must be called explicit
    //
    cHwADC( BYTE      num, 
            cHwTimer *tPtr = 0 );

  public:
    //---------------------------------------------------------------
    /*! Enable a channel by adding to the scan list
        \param ch  Channels number
        \param para Additional configuration parameter, HW specific
    */
    virtual void enable( BYTE ch, BYTE para = 0 );

    //---------------------------------------------------------------
    /*! Get the last sample of a channel
        \param ch  Channels number
        \return    Sample value
    */
    virtual WORD get( BYTE ch );

    //---------------------------------------------------------------
    /*! Get number of channels supported by the device
        \return Number of channels
    */
    virtual BYTE getNumberOfChannels( void );

    //---------------------------------------------------------------
    /*! Start a scan. This function returns immediately and does not 
        wait for completition of the scan
    */
    virtual void update( void );

  public:
    //---------------------------------------------------------------
    // Interrupt Service Routine of adc interrupt
    // Stores the sample in the buffer and starts sampling of next 
    // channel if necessary 
    //
    virtual void isr( void );

  protected:
    //---------------------------------------------------------------
    // Get sample value from ADC hardware
    // return: Sample value
    //
    virtual WORD getResult( void ) = 0;

    //---------------------------------------------------------------
    // Start sampling
    // ch:  Channels number
    //
    virtual void startCh( BYTE ch ) = 0;

    //---------------------------------------------------------------
    // Configure the channel secific adc hardware 
    // ch:  Channels number
    //
    virtual void configCh( BYTE ch, BYTE para = 0 ) = 0;

  protected:
    //---------------------------------------------------------------
    WORD *result[2];      // sample buffer
    BYTE  idx;            // index to sample buffer (alternating)
    BYTE *chList;         // list of registered chanels
    BYTE  numOfChannels;  // number of supported channels
    BYTE  numActivatedCh; // number or registered channels
    BYTE  currentCh;      // actual scanned channel
    BYTE  currentId;      // index to chList of actual scanned channel
    BYTE  isRunning;      // 0: scan is not running, 1: scan is running

}; //cHwADC

#endif
