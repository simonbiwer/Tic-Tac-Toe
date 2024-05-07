//*******************************************************************
/*!
\file   devTextIO_UART.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _DEV_TEXT_IO_UART_H
#define _DEV_TEXT_IO_UART_H

//*******************************************************************
#include "devTextIO.h"
#include "Com/Hardware/UART/UART.h"

//*******************************************************************
/*!
\class cDevTextIO_UART

\brief TextIO device using cHwUART
\see   cDevTextIO

\example cDevTextIO.cpp
*/
class cDevTextIO_UART : public cDevTextIO
{
  public:
    //---------------------------------------------------------------
    /*! Initialize a TextIO device using UART hardware

    */
    cDevTextIO_UART( cHwUART    &uart,         //!< Reference to hardware object
                     BYTE        inBufSize,    //!< Size of input buffer
                     BYTE        outBufSize,   //!< Size of output buffer
                     const char *eos = "\n\r", //!< Defines end-of-string characters
                     const char *key = ""      //!< Defines single key characters
                   );

  protected:
    //---------------------------------------------------------------
    virtual void set( BYTE *str, BYTE size );
    
    //---------------------------------------------------------------
    virtual bool get( BYTE *c );
    
  private:
    //---------------------------------------------------------------
    cHwUART    &uart;
 
}; //cDevTextIO_UART

#endif
