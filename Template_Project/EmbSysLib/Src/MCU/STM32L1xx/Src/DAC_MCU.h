//*******************************************************************
/*!
\file   DAC_MCU.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
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
    virtual void enable( BYTE ch = 0 );

}; // cHwDAC_0

#endif
