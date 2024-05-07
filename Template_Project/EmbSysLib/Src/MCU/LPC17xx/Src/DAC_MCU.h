//*******************************************************************
/*!
\file   DAC_MCU.h
\author Thomas Breuer
\date   17.02.2011
*/

//*******************************************************************
#ifndef _HW_DAC_MCU_H
#define _HW_DAC_MCU_H

//*******************************************************************
#include "Com/Hardware/Analog/DAC.h"

//*******************************************************************
/*! 
\class cHwDAC_0

\brief Implementation of the digital to analog converter (DAC)

\example cHwDAC.cpp
*/
class cHwDAC_0 : public cHwDAC
{
  public:
    //---------------------------------------------------------------
    /*! Initialize the ADC hardware
    */
    cHwDAC_0( void );

    //---------------------------------------------------------------
    virtual void set( WORD value, 
                      BYTE ch = 0 );

    //---------------------------------------------------------------
    virtual void enable( BYTE ch = 0 ) { /* nothing to do */ }

}; // cHwDAC_0

#endif
