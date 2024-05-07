//*******************************************************************
/*!
\file   UART_MCU.cpp
\author Thomas Breuer
\date   27.02.2013
*/
//*******************************************************************
//
// cHwUART_0
//
//*******************************************************************
//-------------------------------------------------------------------
#if ( system_PCLK_UART != 24000000 )
  #error "system_PCLK_UART not defined or wrong value"
#endif

//-------------------------------------------------------------------
cHwUART_0 *cHwUART_0::uartPtr = 0;

//-------------------------------------------------------------------
cHwUART_0::cHwUART_0( cHwUART::Mode modeIn,
                      BYTE          sizeRxBuf,
                      BYTE          sizeTxBuf )

: cHwUART( sizeRxBuf, sizeTxBuf )

{
  BYTE dlm, dll, fdr;

  uartPtr                    = this;

  LPC_SYSCON->SYSAHBCLKCTRL |= (1<<12); // Enable UART0

  cHwPinConfig::set( cHwPinConfig::RXD );
  cHwPinConfig::set( cHwPinConfig::TXD );

  switch( modeIn )
  {
    // This table is calculated with
    // PCLK = 24MHz, see User Manual, Chapter 12.5.14
    default:
    case BR_2400:   dlm = 1; dll = 160; fdr = (1<<0)|(2<<4); break;
    case BR_9600:   dlm = 0; dll = 104; fdr = (1<<0)|(2<<4); break;
    case BR_19200:  dlm = 0; dll =  52; fdr = (1<<0)|(2<<4); break;
    case BR_38400:  dlm = 0; dll =  26; fdr = (1<<0)|(2<<4); break;
    case BR_115200: dlm = 0; dll =   8; fdr = (5<<0)|(8<<4); break;
    //                                         |      +----- MULLVAL
    //                                         +------------ DIVADDVAL
   }

  LPC_USART->LCR =  (3<<0)  // 8bits
                   |(0<<2)  // 1 stop bit
                   |(0<<3)  // parity disable
                   |(1<<7); // DLAB=1

  LPC_USART->DLM = dlm;
  LPC_USART->DLL = dll; //

  LPC_USART->LCR &= ~(1<<7); // DLAB = 0

  LPC_USART->FDR =  fdr;

  LPC_USART->IER =  ( 1<<0)  // RBR IE
                   |( 1<<1)  // THRE IE
                   |( 1<<2); // RLS IE

  LPC_USART->FCR =  0x1;

  NVIC_EnableIRQ( UART_IRQn );
}

//-------------------------------------------------------------------
inline BYTE cHwUART_0::getByte( void )
{
  return( LPC_USART->RBR );
}

//-------------------------------------------------------------------
inline void cHwUART_0::setByte( BYTE c )
{
  LPC_USART->THR = c;
}

//-------------------------------------------------------------------
extern "C"
{
  void UART_IRQHandler(void)
  {
    DWORD lsr;
		DWORD iir;
		
		while( (( iir = LPC_USART->IIR ) & 0x01 ) == 0 )
		{
			switch( iir & 0x0F )
			{
				case 0x02: // THRE interrupt
					// lsr = LPC_USART->LSR;
					cHwUART_0::uartPtr->isrTx();
					break;

				case 0x04: // RDA interrupt
					cHwUART_0::uartPtr->isrRx();
					break;

				case 0x06: // RLS interrupt
					lsr = LPC_USART->LSR;
					if( lsr & (1<<0) )  // LSR_RDR Interrupt?
					{
						cHwUART_0::uartPtr->isrRx();
					}
					if( lsr & ((1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<7)) ) // error
					{
						BYTE dummy = LPC_USART->RBR; // dummy read to clear error
					}
					break;

				case 0x0C: // CTI interrupt
					break;

				default:
					break;
			}
		}
  }
}

//EOF
