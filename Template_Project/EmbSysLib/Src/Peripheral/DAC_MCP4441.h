//*******************************************************************
/*!
\file   DAC_MCP4441.h
\author Thomas Breuer
\date   15.10.2012
*/

//*******************************************************************
#ifndef _HW_DAC_MCP4441_H
#define _HW_DAC_MCP4441_H

//*******************************************************************
#include "Com/Hardware//DAC.h"
#include "Com/Hardware//I2Cmaster.h"

//*******************************************************************
/*! 
\class cHwDAC_MCP4441

\brief Digital potentiometer MCP4441

\example cHwDAC_MCP4441.cpp

\warning Module not tested
*/
class cHwDAC_MCP4441 : public cHwDAC
{
  public:
    //---------------------------------------------------------------
    /*! Initialization of DAC hardware 
        \param i2c Reference to I2C interface
        \param hwAddr Sub address of MCP4441 defined by A0 and A1 pins
    */
    cHwDAC_MCP4441( cHwI2Cmaster &i2c, 
                    BYTE          hwAddr );

    //---------------------------------------------------------------
    virtual void set( WORD value, 
                      BYTE ch );

    //---------------------------------------------------------------
    virtual void enable( BYTE ch = 0 ) { /* nothing to do */ }

  private:
    //---------------------------------------------------------------
    cHwI2Cmaster::Device i2c;

    //---------------------------------------------------------------
    static const BYTE baseAdr = 0x58;

}; //cHwDAC_MCP4441

#endif
