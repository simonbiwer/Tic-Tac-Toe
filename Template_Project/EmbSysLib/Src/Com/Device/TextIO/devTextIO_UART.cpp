//*******************************************************************
/*!
\file   devTextIO_UART.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "devTextIO_UART.h"

//*******************************************************************
//
// cDevTextIO_UART
//
//*******************************************************************
//-------------------------------------------------------------------
cDevTextIO_UART::cDevTextIO_UART( cHwUART    &uartIn,
                                  BYTE        inBufSizeIn,
                                  BYTE        outBufSizeIn,
                                  const char *eosIn,
                                  const char *keyIn)

: cDevTextIO( inBufSizeIn,
              outBufSizeIn,
              eosIn,
              keyIn ),
                          
  uart      ( uartIn )

{
}

//-------------------------------------------------------------------
inline void cDevTextIO_UART::set( BYTE *str, BYTE size )
{
  uart.set( str, size );
}
    
//-------------------------------------------------------------------
inline bool cDevTextIO_UART::get( BYTE *c )
{
  return( uart.get( c ) );
}    

//EOF
