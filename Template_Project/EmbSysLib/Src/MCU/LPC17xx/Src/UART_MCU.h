//*******************************************************************
/*!
\file   UART_MCU.h
\author Thomas Breuer
\date   14.02.2011
*/

//*******************************************************************
#ifndef _HW_UART_MCU_H
#define _HW_UART_MCU_H

//*******************************************************************
#include "Com/Hardware/UART/UART.h"

//*******************************************************************
/*! 
\class cHwUART_N

\brief Implementation of UART hardware

\example cHwUART.cpp
*/
class cHwUART_N : public cHwUART
{
  public:
    //---------------------------------------------------------------
    typedef enum
    {
      UART_0 = 0,
      UART_1 = 1,
      UART_3 = 3
    } UART_ID;

  public:
    //---------------------------------------------------------------
    /*! Initialize the UART hardware
    */
    cHwUART_N( UART_ID       id,        //!< UART channel identifier
               cHwUART::Mode mode,      //!< Baud rate, parity etc., 
                                        //!< see \b cHwUART. 
                                        //!< Default: 9600-8-n-1
               BYTE          sizeRxBuf, //!< Size of receive buffer
               BYTE          sizeTxBuf  //!< Size of transmit buffer
             );

    //---------------------------------------------------------------
    virtual void handler( void );

  private:
    //---------------------------------------------------------------
    virtual BYTE getByte(void);

    //---------------------------------------------------------------
    virtual void setByte(BYTE c);

  public:
    //---------------------------------------------------------------
    static cHwUART_N *uartPtr_0;
    static cHwUART_N *uartPtr_1;
    static cHwUART_N *uartPtr_3;

  private:
    //---------------------------------------------------------------
    LPC_UART_TypeDef *ptr;

}; //cHwUART_N

#endif
