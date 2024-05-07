//*******************************************************************
/*!
\file   Disp_SPFD5408Bspi.h
\author Thomas Breuer
\date   10.03.2011
*/

//*******************************************************************
#ifndef _HW_DISP_SPFD5408B_SPI_H
#define _HW_DISP_SPFD5408B_SPI_H

//*******************************************************************
#include "Com/Hardware/SPI/SPImaster.h"
#include "Com/Hardware/Port/Port.h"
#include "Com/Hardware/Display/Display.h"
#include "Com/Hardware/Display/DisplayGraphic.h"

//*******************************************************************
/*! 
\class cHwDisp_SPFD5408Bspi

\brief LCD character display SPFD5408Bspi

Datasheet: SPFD5408B.PDF, Dec. 24, 2007, ORISE Technology Co. Ltd.

\example  cHwDisp_SPFD5408Bspi.cpp
*/
class cHwDisp_SPFD5408Bspi : public cHwDisplayGraphic
{
  public:

    //---------------------------------------------------------------
    /*! Initialize display        
        \param spi   Reference to SPI interface device
        \param pinBL Reference to backlight port pin 
        \param font  Display font 
        \param zoom  Display font zoom size (1,2,3,...)
    */
    cHwDisp_SPFD5408Bspi( cHwSPImaster::Device  &spi, 
                          cHwPort::Pin          &pinBL,
                          cHwDisplayFont         font, 
                          BYTE                   zoom = 1 );
   
    //---------------------------------------------------------------
    virtual void clear( void );

    //---------------------------------------------------------------
    virtual void setArea( WORD x, 
                          WORD y,
                          WORD w,
                          WORD h );

   //---------------------------------------------------------------
    virtual void setPixel( WORD color,
                           WORD x, 
                           WORD y );

    //---------------------------------------------------------------
    virtual void setPixel( WORD color );

  private:
    //---------------------------------------------------------------
    // Initialize LCD
    void init( void );
      
    //---------------------------------------------------------------
    // Maximize painting area
    void maxWindow( void );
    
    //---------------------------------------------------------------
    // Write a command
    // cmd: Command WORD to be written
    void writeCmd( WORD cmd );

    //---------------------------------------------------------------
    // Write data
    // dat: Data WORD to be written
    void writeDat( WORD dat );

    //---------------------------------------------------------------
    // Write to a register
    // reg: Register address
    // val: Value to de written
    void writeReg( BYTE reg, 
                   WORD val );

  private:
     //---------------------------------------------------------------
    cHwSPImaster::Device  spi;

    BYTE          isMaxWindow;

    //---------------------------------------------------------------
    // 
    // configuration:
    //
    static const WORD WIDTH  = 320;
    static const WORD HEIGHT = 240;
   
}; //cHwDisp_SPFD5408Bspi

#endif
