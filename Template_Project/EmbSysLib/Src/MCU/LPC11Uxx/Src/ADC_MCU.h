//*******************************************************************
/*!
\file   ADC_MCU.h
\author Thomas Breuer
\date   28.03.2013
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
    virtual void configCh( BYTE ch, BYTE para );

  public:
    //---------------------------------------------------------------
    static cHwADC *adcPtr;

  private:
    //---------------------------------------------------------------
    MTYPE cr;

}; //cHwADC_0

#endif
