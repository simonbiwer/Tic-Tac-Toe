//*******************************************************************
/*!
\file   ADC_MCU.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_ADC_MCU_H
#define _HW_ADC_MCU_H

//*******************************************************************
#include "Com/Hardware/Analog/ADC.h"

//*******************************************************************
/*! 
\class cHwADC_0

\brief Implementation of the analg to digital converter (ADC)

\example cHwADC.cpp
*/
class cHwADC_0 : public cHwADC
{
  public:
      typedef enum
      {
          SAMPLING_TIME_3 = 0,
          SAMPLING_TIME_15,
          SAMPLING_TIME_28,
          SAMPLING_TIME_56,
          SAMPLING_TIME_84,
          SAMPLING_TIME_112,
          SAMPLING_TIME_144,
          SAMPLING_TIME_480
      } Para;

  public:
    //---------------------------------------------------------------
    /*! Initialize the ADC hardware
        \param tPtr  Reference to a timer object (option). If 
                     declared, auto trigger conversion is used. 
                     Otherwise the update() function must be called 
                     explicit
    */
    cHwADC_0( cHwTimer *tPtr = 0 );

  private:
    //---------------------------------------------------------------
    virtual WORD getResult( void );

    //---------------------------------------------------------------
    virtual void startCh( BYTE ch );

    //---------------------------------------------------------------
    virtual void configCh( BYTE ch, BYTE para = 0 );

  public:
    //---------------------------------------------------------------
    static cHwADC *adcPtr;
    
}; //cHwADC_0

#endif
