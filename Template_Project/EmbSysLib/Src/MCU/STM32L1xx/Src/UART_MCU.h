//*******************************************************************
/*!
\file   UART_MCU.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
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
    /*! \enum USART_Id
        \brief USART identification
    */
    typedef enum
    {
      USART_1 = 1, //!< USART 1
      USART_2,     //!< USART 2
      USART_3      //!< USART 3
    } USART_Id;

  public:
    //---------------------------------------------------------------
    /*! Initialize the UART hardware
        \param id   USART identification
        \param mode Baud rate, parity etc., see \b cHwUART. 
                    Default: 9600-8-n-1
        \param sizeRxBuf Size of receive buffer
        \param sizeTxBuf Size of transmit buffer
    */
    cHwUART_N( USART_Id id,
               Mode     mode,
               BYTE     sizeRxBuf,
               BYTE     sizeTxBuf );

    //---------------------------------------------------------------
    // Interrupt Service Routine (ISR) of USART interrupt.
    // This function must be public, because it is called 
    // in extern "C"
    void isr( void );

  private:
    //---------------------------------------------------------------
    virtual BYTE getByte( void );

    //---------------------------------------------------------------
    virtual void setByte( BYTE c );

  public:
    //---------------------------------------------------------------
    static cHwUART_N *uartPtr_1;
    static cHwUART_N *uartPtr_2;
    static cHwUART_N *uartPtr_3;
        
  private:
    //---------------------------------------------------------------
    USART_TypeDef *ptr;
  
}; //cHwUART_N

#endif
