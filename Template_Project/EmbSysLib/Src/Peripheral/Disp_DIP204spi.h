//*******************************************************************
/*!
\file   Disp_DIP204spi.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   05.04.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "Com/Hardware/SPI/SPImaster.h"
#ifndef _HW_DISP_DIP204_SPI_H
#define _HW_DISP_DIP204_SPI_H

//*******************************************************************
#include "Com/Hardware/Display/Display.h"

//*******************************************************************
/*! 
\class cHwDisp_DIP204spi

\brief LCD character display DIP204 with SPI interface

\example cHwDisp_DIP204spi.cpp
*/
class cHwDisp_DIP204spi : public cHwDisplay
{
  public:
    //---------------------------------------------------------------
    /*! Initialize display
       \param spi Reference to a SPI device object
    */
    cHwDisp_DIP204spi( cHwSPImaster::Device &spi );

    //---------------------------------------------------------------
    virtual void clear( void );
	
	  virtual void refresh() {}

    //---------------------------------------------------------------
    virtual void gotoTextPos( BYTE lineIn, 
                              BYTE columnIn );

    //---------------------------------------------------------------
    virtual void putChar( char c );

  private:
    //---------------------------------------------------------------
    void init( void );

    //---------------------------------------------------------------
    void waitBusy( void );

    //---------------------------------------------------------------
    void writeCmd( BYTE cmd );

    //---------------------------------------------------------------
    void writeDat( BYTE dat ); 

  private:
    //---------------------------------------------------------------      
    cHwSPImaster::Device &spi;
 
    BYTE          line;
    BYTE          column;

    //---------------------------------------------------------------
    static const WORD NUM_OF_LINE   =  4;
    static const WORD NUM_OF_COLUMN = 20;

}; //cHwDisp_DIP204spi

#endif
