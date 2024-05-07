//*******************************************************************
/*!
\file   DAC_MCP4922.h
\author Thomas Breuer
\date   30.03.2011
*/

//*******************************************************************
#ifndef _HW_DAC_MCP4922_H
#define _HW_DAC_MCP4922_H

//*******************************************************************
#include "Com/Hardware/DAC.h"
#include "Com/Hardware/SPImaster.h"

//*******************************************************************
/*! 
\class cHwDAC_MCP4922

\brief Digital-to-analog converter MCP4922

\example cHwDAC.cpp
*/
class cHwDAC_MCP4922 : public cHwDAC
{
  public:
    //---------------------------------------------------------------
    /*! Initialization of DAC hardware 
        \param spi Reference to SPI interface
        \param gain 
                    - 0: Vmax=Vreff
                    - 1: Vmax=2*Vreff
    */
  cHwDAC_MCP4922( cHwSPImaster::Device &spi,
                    BYTE                gain = 0 );

    //---------------------------------------------------------------
    virtual void set( WORD value, 
                      BYTE ch );

    //---------------------------------------------------------------
    virtual void enable( BYTE ch = 0 ) { /* nothing to do */ }

  private:
    //---------------------------------------------------------------
    cHwSPImaster::Device  spi;

    BYTE ga;

}; //cHwDAC_MCP4922

#endif
