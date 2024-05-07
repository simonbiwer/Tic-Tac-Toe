//*******************************************************************
/*!
\file   UART_MCU.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "UART_MCU.h"

//*******************************************************************
//
// cHwUART_N
//
//*******************************************************************
//-------------------------------------------------------------------
#if ( system_PCLK_UART != 72000000 )
  #error "system_PCLK_UART not defined or wrong value"
#endif

//-------------------------------------------------------------------
cHwUART_N *cHwUART_N::uartPtr_1 = 0;
cHwUART_N *cHwUART_N::uartPtr_2 = 0;
cHwUART_N *cHwUART_N::uartPtr_3 = 0;
cHwUART_N *cHwUART_N::uartPtr_4 = 0;
cHwUART_N *cHwUART_N::uartPtr_5 = 0;
cHwUART_N *cHwUART_N::uartPtr_6 = 0;

//-------------------------------------------------------------------
cHwUART_N::cHwUART_N( USART_Id id,
                      DWORD    mode,
                      BYTE     sizeRxBuf,
                      BYTE     sizeTxBuf )

: cHwUART( sizeRxBuf, sizeTxBuf )

{
  switch( id )
  {
    default:
      //error!
      break;
    
//    case USART_1:
//      ptr           = (USART_TypeDef*)USART1_BASE;
//      uartPtr_1     = this;
//      RCC->APB2ENR |= RCC_APB2ENR_USART1EN;  // enable USART3
//      cHwPinConfig::set( cHwPinConfig::USART1_RX );
//      cHwPinConfig::set( cHwPinConfig::USART1_TX );
//      if( mode & RTS )
//      {
//        cHwPinConfig::set( cHwPinConfig::USART1_RTS );
//      }
//      if( mode & CTS )
//      {
//        cHwPinConfig::set( cHwPinConfig::USART1_CTS );
//      }
//      NVIC_EnableIRQ( USART1_IRQn );
//      break;

  case USART_2:
      ptr           = (USART_TypeDef*)USART2_BASE;
      uartPtr_2     = this;
      RCC->APB1ENR1 |= RCC_APB1ENR1_USART2EN;  // enable USART3
      cHwPinConfig::set( cHwPinConfig::USART2_RX );
      cHwPinConfig::set( cHwPinConfig::USART2_TX );
////      if( mode & RTS )
////      {
////        cHwPinConfig::set( cHwPinConfig::USART2_RTS );
////      }
////      if( mode & CTS )
////      {
////        cHwPinConfig::set( cHwPinConfig::USART2_CTS );
////      }
      NVIC_EnableIRQ( USART2_IRQn );
      break;

//    case USART_3:
//      ptr           = (USART_TypeDef*)USART3_BASE;
//      uartPtr_3     = this;
//      RCC->APB1ENR |= RCC_APB1ENR_USART3EN;  // enable USART3
//      cHwPinConfig::set( cHwPinConfig::USART3_RX );
//      cHwPinConfig::set( cHwPinConfig::USART3_TX );
//      if( mode & RTS )
//      {
//        cHwPinConfig::set( cHwPinConfig::USART3_RTS );
//      }
//      if( mode & CTS )
//      {
//        cHwPinConfig::set( cHwPinConfig::USART3_CTS );
//      }
//      NVIC_EnableIRQ( USART3_IRQn );
//      break;

//    case UART_4:
//      ptr           = (USART_TypeDef*)UART4_BASE;
//      uartPtr_4     = this;
//      RCC->APB1ENR |= RCC_APB1ENR_UART4EN;  // enable USART3
//      cHwPinConfig::set( cHwPinConfig::UART4_RX );
//      cHwPinConfig::set( cHwPinConfig::UART4_TX );
//      if( mode & RTS )
//      {
//       // cHwPinConfig::set( cHwPinConfig::UART4_RTS );
//      }
//      if( mode & CTS )
//      {
//        //cHwPinConfig::set( cHwPinConfig::UART4_CTS );
//      }
//      NVIC_EnableIRQ( UART4_IRQn );
//      break;

//    case UART_5:
//      ptr           = (USART_TypeDef*)UART5_BASE;
//      uartPtr_5     = this;
//      RCC->APB1ENR |= RCC_APB1ENR_UART5EN;  // enable USART3
//      cHwPinConfig::set( cHwPinConfig::UART5_RX );
//      cHwPinConfig::set( cHwPinConfig::UART5_TX );
//      if( mode & RTS )
//      {
//       // cHwPinConfig::set( cHwPinConfig::UART5_RTS );
//      }
//      if( mode & CTS )
//      {
//        //cHwPinConfig::set( cHwPinConfig::UART5_CTS );
//      }
//      NVIC_EnableIRQ( UART5_IRQn );
//      break;

//    case USART_6:
//      ptr           = (USART_TypeDef*)USART6_BASE;
//      uartPtr_6     = this;
//      RCC->APB2ENR |= RCC_APB2ENR_USART6EN;  // enable USART6
//      cHwPinConfig::set( cHwPinConfig::USART6_RX );
//      cHwPinConfig::set( cHwPinConfig::USART6_TX );
//      if( mode & RTS )
//      {
//        cHwPinConfig::set( cHwPinConfig::USART6_RTS );
//      }
//      if( mode & CTS )
//      {
//        cHwPinConfig::set( cHwPinConfig::USART6_CTS );
//      }

//      NVIC_EnableIRQ( USART6_IRQn );
//      break;
  }

  DWORD baudRate;

  switch( mode & 0xFFFF )
  {
    default:
    case BR_2400:   baudRate =   2400; break;
    case BR_4800:   baudRate =   4800; break;
    case BR_9600:   baudRate =   9600; break;
    case BR_19200:  baudRate =  19200; break;
    case BR_38400:  baudRate =  38400; break;
    case BR_57600:  baudRate =  57600; break;
    case BR_115200: baudRate = 115200; break;
    case BR_230400: baudRate = 230400; break;
    case BR_460800: baudRate = 460800; break;
  }

  ptr->CR2 |=  ((MTYPE)0<<12); // 0: 1 stop bit

  ptr->CR1 |=  (        ((mode&(EVEN|ODD))?USART_CR1_M  :0)  // 8+paritry = 9 Bit
                     |  ((mode&(EVEN|ODD))?USART_CR1_PCE:0)  //  parity
                     |  ((mode&      ODD )?USART_CR1_PS :0)  // 0: even
                     |  USART_CR1_RE   // RX mode
                     |  USART_CR1_TE );// TX mode

  ptr->CR3 |=  (  ((mode&RTS)?USART_CR3_RTSE:0)
                | ((mode&CTS)?USART_CR3_CTSE:0) ); // no hardware flow control

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
  return( ptr->RDR );
}

//-------------------------------------------------------------------
inline void cHwUART_N::setByte( BYTE c )
{
  ptr->TDR = c;
}

//-------------------------------------------------------------------
void cHwUART_N::isr( void )
{
  if( ptr->ISR & USART_ISR_TC ) // transmission complete?
  {
    ptr->ICR |= (USART_ICR_TCCF);
    isrTx();
  }
  if( (ptr->ISR & USART_ISR_RXNE) || (ptr->ISR & USART_ISR_ORE) )// receive data register not empty
  {
    isrRx();
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

//-------------------------------------------------------------------
extern "C"
{
  void UART4_IRQHandler(void)
  {
    cHwUART_N::uartPtr_4->isr();
  }
}

//-------------------------------------------------------------------
extern "C"
{
  void UART5_IRQHandler(void)
  {
    cHwUART_N::uartPtr_5->isr();
  }
}

//-------------------------------------------------------------------
extern "C"
{
  void USART6_IRQHandler(void)
  {
    cHwUART_N::uartPtr_6->isr();
  }
}
//EOF
