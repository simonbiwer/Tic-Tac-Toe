//*******************************************************************
/*!
\file   DAC_MAX521.h
\author Thomas Breuer
\date   25.03.2011
*/

//*******************************************************************
#ifndef _HW_DAC_MAX521_H
#define _HW_DAC_MAX521_H

//*******************************************************************
#include "Com/Hardware/DAC.h"
#include "Com/Hardware/I2Cmaster.h"

//*******************************************************************
/*! 
\class cHwDAC_MAX521

\brief Digital-to-analog converter MAX521

\warning This module is not tested!

\example cHwDAC.cpp
*/
class cHwDAC_MAX521 : public cHwDAC
{
  public:
    //---------------------------------------------------------------
    /*! Initialization of DAC hardware 
        \param i2c Reference to I2C interface
        \param hwAddr Sub address of MAX521 defined by AD0 and AD1 pins
    */
    cHwDAC_MAX521( cHwI2Cmaster &i2c, 
                   BYTE          hwAddr );

    //---------------------------------------------------------------
    virtual void set( WORD value, 
                      BYTE ch    );

    //---------------------------------------------------------------
    virtual void enable( BYTE ch = 0 ) { /* nothing to do */ }

  private:
    //---------------------------------------------------------------
    cHwI2Cmaster::Device i2c;

    //---------------------------------------------------------------
    static const BYTE baseAdr = 0x50;

}; //cHwDAC_MAX521

#endif
