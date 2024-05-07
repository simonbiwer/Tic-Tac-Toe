//*******************************************************************
/*!
\file   Disp_Terminal.h
\author Thomas Breuer
\date   10.03.2011
*/

//*******************************************************************
#ifndef _HW_DISP_TERMINAL_H
#define _HW_DISP_TERMINAL_H

//*******************************************************************
#include "lib.h"
#include "Com/Hardware/Display/Display.h"
#include "Com/Hardware/UART/UART.h"

//*******************************************************************
/*! 
\class cHwDisp_Terminal

\brief Terminal display

This class emulates a character display on an uart/tty terminal.

\example cHwDisp_Terminal.cpp
*/
class cHwDisp_Terminal : public cHwDisplay
{
  public:
    //---------------------------------------------------------------
    /*! Initialize display
       \param uart Reference to an UART interface
    */
    cHwDisp_Terminal( cHwUART &uart );

    //---------------------------------------------------------------
    virtual void clear( void );

    //---------------------------------------------------------------
    virtual void refresh( void );

    //---------------------------------------------------------------
    virtual void gotoTextPos( BYTE line, 
                              BYTE colum );
	
    //---------------------------------------------------------------
    virtual void putChar( char c );

  private:
    //---------------------------------------------------------------
    void sendESC( const char *seq );

    //---------------------------------------------------------------
    cHwUART &uart;
    BYTE     line;
    BYTE     colum;

  public:
    //---------------------------------------------------------------
    static const WORD NUM_OF_LINE  = 10;
    static const WORD NUM_OF_COLUM = 20;
	       
}; //cHwDispTerminal

#endif
