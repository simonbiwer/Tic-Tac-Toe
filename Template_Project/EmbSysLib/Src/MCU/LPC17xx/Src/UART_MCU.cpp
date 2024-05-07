//*******************************************************************
/*!
\file   UART_MCU.cpp
\author Thomas Breuer
\date   14.02.2011
*/

//*******************************************************************
//
// cHwUART_N
//
//*******************************************************************
//-------------------------------------------------------------------
#if ( system_PCLK_UART != 25000000 )
  #error "system_PCLK_UART not defined or wrong value"
#endif

//-------------------------------------------------------------------
cHwUART_N *cHwUART_N::uartPtr_0 = 0;
cHwUART_N *cHwUART_N::uartPtr_1 = 0;
cHwUART_N *cHwUART_N::uartPtr_3 = 0;

//-------------------------------------------------------------------
cHwUART_N::cHwUART_N( UART_ID id,
                      Mode    modeIn,
                      BYTE    sizeRxBuf,
                      BYTE    sizeTxBuf )

: cHwUART( sizeRxBuf, sizeTxBuf )

{
  BYTE dlm, dll, fdr;

  switch( id )
  {
    default:
      // error!
    case UART_0:
      uartPtr_0 = this;
      ptr       = (LPC_UART_TypeDef *)LPC_UART0;
      cHwPinConfig::set( cHwPinConfig::TXD0 );
      cHwPinConfig::set( cHwPinConfig::RXD0 );
      NVIC_EnableIRQ( UART0_IRQn );
      break;

    case UART_1:
      uartPtr_1 = this;
      ptr       = (LPC_UART_TypeDef *)LPC_UART1;
      cHwPinConfig::set( cHwPinConfig::TXD1 );
      cHwPinConfig::set( cHwPinConfig::RXD1 );
      NVIC_EnableIRQ( UART1_IRQn );
      break;

    case UART_3:
      uartPtr_3         = this;
      ptr               = LPC_UART3;
      LPC_SC->PCONP    |= (1<<25);         // PCUART3: Power ON
      cHwPinConfig::set( cHwPinConfig::TXD3 );
      cHwPinConfig::set( cHwPinConfig::RXD3 );
      NVIC_EnableIRQ( UART3_IRQn );
      break;
  }

  switch( modeIn )
  {
    // This table is calculated with
    // PCLK = 25MHz, see User Manual, Chapter 14.4.12
    default:
    case BR_9600:   dlm = 0; dll = 106; fdr = (8<<0)|(15<<4); break;
    case BR_19200:  dlm = 0; dll =  50; fdr = (5<<0)|( 8<<4); break;
    case BR_38400:  dlm = 0; dll =  25; fdr = (5<<0)|( 8<<4); break;
    case BR_115200: dlm = 0; dll =   8; fdr = (9<<0)|(13<<4); break;
    //                                         |       +----- MULLVAL
    //                                         +------------- DIVADDVAL
  }

  ptr->LCR  =  (3<<0)  // 8bits
              |(0<<2)  // 1 stop bit
              |(0<<3)  // parity disable
              |(1<<7); // DLAB=1

  ptr->DLM  = dlm;
  ptr->DLL  = dll; //

  ptr->LCR &= ~(1<<7); // DLAB = 0

  ptr->FDR  =  fdr;

  ptr->IER  =  ( 1<<0)  // RBR IE
              |( 1<<1); // THRE IE
}

//-------------------------------------------------------------------
inline BYTE cHwUART_N::getByte( void )
{
  return( ptr->RBR );
}

//-------------------------------------------------------------------
inline void cHwUART_N::setByte( BYTE c )
{
  ptr->THR = c;
}

//-------------------------------------------------------------------
void cHwUART_N::handler(void)
{
  if( ptr->IIR & (1<<1) ) // THRE Interrupt?
  {
    isrTx();
  }
  if( ptr->IIR & (1<<2) )  // RDA Interrupt?
  {
    isrRx();
  }
}

//-------------------------------------------------------------------
extern "C"
{
  void UART0_IRQHandler(void)
  {
    cHwUART_N::uartPtr_0->handler();
  }
}

//-------------------------------------------------------------------
extern "C"
{
  void UART1_IRQHandler(void)
  {
    cHwUART_N::uartPtr_1->handler();
  }
}

//-------------------------------------------------------------------
extern "C"
{
  void UART3_IRQHandler(void)
  {
    cHwUART_N::uartPtr_3->handler();
  }
}


//EOF
