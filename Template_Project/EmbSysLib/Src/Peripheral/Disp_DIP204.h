//*******************************************************************
/*!
\file   Disp_DIP204.h
\author Thomas Breuer
\date   10.03.2011
*/

//*******************************************************************
#ifndef _HW_DISP_DIP204_H
#define _HW_DISP_DIP204_H

//*******************************************************************
#include "Com/Hardware/Display.h"
#include "Com/Hardware/Port.h"

//*******************************************************************
/*! 
\class cHwDisp_DIP204

\brief LCD character display DIP204

\todo Pinbelegung port <-> Display konfigurierbar

\example cHwDisp_DIP204.cpp
*/
class cHwDisp_DIP204 : public cHwDisplay
{
  public:
    //---------------------------------------------------------------
    /*! Initialize display
       \param port Reference to digital port
    */
    cHwDisp_DIP204( cHwPort &port );

    //---------------------------------------------------------------
    virtual void clear( void );

    //---------------------------------------------------------------
    virtual void gotoTextPos( BYTE lineIn, 
                              BYTE columIn );

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
    cHwPort &port;
    BYTE     line;
    BYTE     colum;

    //---------------------------------------------------------------
    static const WORD NUM_OF_LINE  =  4;
    static const WORD NUM_OF_COLUM = 20;

    // Pin configuration
    // data bit 0..3 => port pin 0..3
    static const BYTE DIP204_RES = ((BYTE)(1<<4)); // reset
    static const BYTE DIP204_EN  = ((BYTE)(1<<5)); // enable
    static const BYTE DIP204_RW  = ((BYTE)(1<<6)); // read/write
    static const BYTE DIP204_RS  = ((BYTE)(1<<7)); // data / command


            
}; //cHwDisp_DIP204

#endif
