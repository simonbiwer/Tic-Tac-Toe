//*******************************************************************
/*!
\file   UART_MCU.h
\author Thomas Breuer
\date   27.03.2013
*/

//*******************************************************************
#ifndef _HW_UART_MCU_H
#define _HW_UART_MCU_H

//*******************************************************************
#include "Com/Hardware/UART/UART.h"

//*******************************************************************
/*! 
\class cHwUART_0

\brief Implementation of UART hardware

\example cHwUART.cpp
*/
class cHwUART_0 : public cHwUART
{
  public:
    //---------------------------------------------------------------
    /*! Initialize the UART hardware
    */
    cHwUART_0( cHwUART::Mode mode,      //!< Baud rate, parity etc., see \b cHwUART.
               BYTE          sizeRxBuf, //!< Size of receive buffer
               BYTE          sizeTxBuf  //!< Size of transmit buffer
             );

  private:
    //---------------------------------------------------------------
    virtual BYTE getByte(void);

    //---------------------------------------------------------------
    virtual void setByte(BYTE c);

  public:
    //---------------------------------------------------------------
    static cHwUART_0 *uartPtr;

}; //cHwUART_0

#endif
