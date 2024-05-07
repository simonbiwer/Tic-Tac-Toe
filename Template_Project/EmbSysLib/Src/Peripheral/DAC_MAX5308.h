//*******************************************************************
/*!
\file   DAC_MAX5308.h
\author Thomas Breuer
\date   24.03.2011
*/

//*******************************************************************
#ifndef _HW_DAC_MAX5308_H
#define _HW_DAC_MAX5308_H

//*******************************************************************
#include "Com/Hardware//DAC.h"
#include "Com/Hardware//SPImaster.h"

//*******************************************************************
/*! 
\class cHwDAC_MAX5308

\brief Digital-to-analog converter MAX5308

\warning This module is not tested!

\example cHwDAC.cpp
*/
class cHwDAC_MAX5308 : public cHwDAC
{
  public:
    //---------------------------------------------------------------
    /*! Initialization of DAC hardware 
        \param spi Reference to SPI interface
    */
  cHwDAC_MAX5308( cHwSPImaster::Device &spi );

    //---------------------------------------------------------------
    virtual void set( WORD value, 
                      BYTE ch    );

    //---------------------------------------------------------------
    virtual void enable( BYTE ch = 0 ) { /* nothing to do */ }

  private:
    //---------------------------------------------------------------
    cHwSPImaster::Device  spi;


}; //cHwDAC_MAX5308

#endif
