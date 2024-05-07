//*******************************************************************
/*!
\file   RTC_MCU.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_RTC_MCU_H
#define _HW_RTC_MCU_H

//*******************************************************************
#include "Com/Hardware/RTC/RTC.h"

//*******************************************************************
/*!
\class cHwRTC_0

\brief Implementation of the real time clock (RTC)

\example cHwRTC.cpp
*/
class cHwRTC_0 : public cHwRTC
{
  public:
    //---------------------------------------------------------------
    /*! Initialize the RTC hardware
    */
    cHwRTC_0( void );

    //---------------------------------------------------------------
    virtual void set( const cHwRTC::Properties &clock );

    //---------------------------------------------------------------
    virtual BYTE get( cHwRTC::Properties &clock );

    WORD offset;
}; //cHwRTC_0

#endif
