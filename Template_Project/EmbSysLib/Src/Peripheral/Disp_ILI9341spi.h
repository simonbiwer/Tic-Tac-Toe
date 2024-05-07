//*******************************************************************
/*!
\file   Disp_ILI9341spi.h
\author Thomas Breuer
\date   10.03.2011
*/

//*******************************************************************
#ifndef _HW_DISP_ILI9341_SPI_H
#define _HW_DISP_ILI9341_SPI_H

//*******************************************************************
#include "Com/Hardware/Port.h"
#include "Com/Hardware/Display.h"
#include "Com/Hardware/DisplayGraphic.h"

//*******************************************************************
/*! 
\class cHwDisp_ILI9341spi

\brief LCD character display ILI9341spi

Datasheet: ILI9341_DS_V1.10_20110415.pdf, ILI Technology Corp.

\example  cHwDisp_ILI9341spi.cpp
*/
class cHwDisp_ILI9341spi : public cHwDisplayGraphic
{
  public:

    //---------------------------------------------------------------
    /*! Initialize display        
        \param spi   Reference to SPI interface
        \param port  Reference to backlight port pin 
        \param pinId Pin Id of backlight port pin
        \param font  Display font 
        \param zoom  Display font zoom size (1,2,3,...)
    */
  cHwDisp_ILI9341spi( cHwSPImaster::Device &spi, 
                        cHwPort::Pin       &pinBL,
                        cHwDisplayFont      font, 
                        BYTE                zoom = 1 );
   
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
    // Write a command
    // cmd: Command BYTE to be written
    void writeCmd( BYTE cmd );

    //---------------------------------------------------------------
    // Write data
    // dat: Data BYTE to be written
    void writeDat( BYTE dat );

    //---------------------------------------------------------------
    // Write to a register
    // dat: Data WORD to be written
    void writeDatWord( WORD dat );

  private:
     //---------------------------------------------------------------
    cHwSPImaster::Device  spi;

    //---------------------------------------------------------------
    // 
    // configuration:
    //
    static const WORD WIDTH  = 320;
    static const WORD HEIGHT = 240;
   
}; //cHwDisp_ILI9341spi

#endif
