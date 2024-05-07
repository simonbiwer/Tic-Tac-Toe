//*******************************************************************
/*!
\file   UART_MCU.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "UART_MCU.h"
#include "../Sys/PinConfig.h"

//*******************************************************************
//
// cHwUART_N
//
//*******************************************************************
//-------------------------------------------------------------------
#if ( system_PCLK_UART != 32000000 )
  #error "system_PCLK_UART not defined or wrong value"
#endif

//-------------------------------------------------------------------
cHwUART_N *cHwUART_N::uartPtr_1 = 0;
cHwUART_N *cHwUART_N::uartPtr_2 = 0;
cHwUART_N *cHwUART_N::uartPtr_3 = 0;

//-------------------------------------------------------------------
cHwUART_N::cHwUART_N( USART_Id id,
                      Mode     mode,
                      BYTE     sizeRxBuf,
                      BYTE     sizeTxBuf )

: cHwUART( sizeRxBuf, sizeTxBuf )

{
  switch( id )
  {
    default:
      //error!
      break;
    
    case USART_1:
      ptr           = (USART_TypeDef*)USART1_BASE;
      uartPtr_1     = this;
      RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
      cHwPinConfig::set( cHwPinConfig::USART1_RX, cHwPinConfig::ALTERNATE_FUNC);
      cHwPinConfig::set( cHwPinConfig::USART1_TX, cHwPinConfig::ALTERNATE_FUNC);
      NVIC_EnableIRQ( USART1_IRQn );
      break;

    case USART_2:
      ptr           = (USART_TypeDef*)USART2_BASE;
      uartPtr_2     = this;
      RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
      cHwPinConfig::set( cHwPinConfig::USART2_RX, cHwPinConfig::ALTERNATE_FUNC);
      cHwPinConfig::set( cHwPinConfig::USART2_TX, cHwPinConfig::ALTERNATE_FUNC);
      NVIC_EnableIRQ( USART2_IRQn );
      break;

    case USART_3:
      ptr           = (USART_TypeDef*)USART3_BASE;
      uartPtr_3     = this;
      RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
      cHwPinConfig::set( cHwPinConfig::USART3_RX, cHwPinConfig::ALTERNATE_FUNC);
      cHwPinConfig::set( cHwPinConfig::USART3_TX, cHwPinConfig::ALTERNATE_FUNC);
      NVIC_EnableIRQ( USART3_IRQn );
      break;
  }

  float baudRate;

  switch( mode )
  {
    default:
    case BR_2400:   baudRate =   2400; break;
    case BR_4800:   baudRate =   4800; break;
    case BR_9600:   baudRate =   9600; break;
    case BR_19200:  baudRate =  19200; break;
    case BR_38400:  baudRate =  38400; break;
    case BR_57600:  baudRate =  57600; break;
    case BR_115200: baudRate = 115200; break;
  }

  ptr->CR2 |=  ((MTYPE)0<<12); // 0: 1 stop bit

  ptr->CR1 |=  (  !USART_CR1_M    // 8 Bit
                | !USART_CR1_PCE  // no parity
                |  USART_CR1_RE   // RX mode
                |  USART_CR1_TE );// TX mode

  ptr->CR3 |=  (  !USART_CR3_RTSE
                | !USART_CR3_CTSE ); // no hardware flow control

  // Configure the USART Baud Rate:
  //
  // OVER8==0:
  //   BRR: mmmm mmmm mmmm ffff
  //   div: Fixpoint number = M+F/16
  //
  //            fck                         fck
  //   div = ---------  =>  BRR = 16*div = ------
  //         16 x baud                      baud
  //
  ptr->BRR  = (WORD)(system_PCLK_UART / baudRate);

  ptr->CR1 |= (  USART_CR1_UE       // Enable USART
               | USART_CR1_TCIE     // Transm. complete interr. enable
               | USART_CR1_RXNEIE );// Receive reg. not empty interr. enable
}

//-------------------------------------------------------------------
inline BYTE cHwUART_N::getByte( void )
{
  return( ptr->DR );
}

//-------------------------------------------------------------------
inline void cHwUART_N::setByte( BYTE c )
{
  ptr->DR = c;
}

//-------------------------------------------------------------------
void cHwUART_N::isr( void )
{
  if( ptr->SR & USART_SR_RXNE ) // Read data register not empty?
  {
    isrRx();
  }
  if( ptr->SR & USART_SR_TC ) // Transmission Complete?
  {
    ptr->SR = ~(USART_SR_TC);    
    isrTx();
  }
}

//-------------------------------------------------------------------
extern "C"
{
  void USART1_IRQHandler(void)
  {
    cHwUART_N::uartPtr_1->isr();
  }
}

//-------------------------------------------------------------------
extern "C"
{
  void USART2_IRQHandler(void)
  {
    cHwUART_N::uartPtr_2->isr();
  }
}

//-------------------------------------------------------------------
extern "C"
{
  void USART3_IRQHandler(void)
  {
    cHwUART_N::uartPtr_3->isr();
  }
}

//EOF
