//*******************************************************************
/*!
\file   System.cpp
\author Thomas Breuer
\date   28.03.2013

\brief  Controller specific implementation of class cSystem
*/

//*******************************************************************
#include "MCU/LPC11Uxx/Sys/system_LPC11Uxx.cpp"

//*******************************************************************
// 
// cSystem
//
//*******************************************************************
//-------------------------------------------------------------------
unsigned char cSystem::cntInterrupt = 0;

//-------------------------------------------------------------------
cSystem::cSystem( unsigned char disableInterrupts )
{
  SystemInit();

  disableWatchdog();
  if( disableInterrupts )
  {
    disableInterrupt();
  }
}

//-------------------------------------------------------------------
void cSystem::start( void )
{
  enableInterrupt();
}

//-------------------------------------------------------------------
void cSystem::disableInterrupt( void )
{
  __disable_irq();
	
  cntInterrupt++;
}

//-------------------------------------------------------------------
void cSystem::enableInterrupt( void )
{
  if(cntInterrupt > 0)
  {
    cntInterrupt--;
  }
  if(cntInterrupt == 0)
  {
    __enable_irq();
  }
}

//-------------------------------------------------------------------
void cSystem::enterISR( void )
{
  
  cntInterrupt++;
}

//-------------------------------------------------------------------
void cSystem::leaveISR( void )
{
  if( cntInterrupt > 0 )
  {
    cntInterrupt--;
  }
}

//-------------------------------------------------------------------
//void cSystem::run( void )
//{
//  // nothing to do
//}

//-------------------------------------------------------------------
void cSystem::enableWatchdog( MODE mode )
{
  DWORD prescale = 0;

  LPC_SYSCON->SYSAHBCLKCTRL |=  (1<<15); 
  LPC_SYSCON->PDRUNCFG      &= ~(1<<6);  //   power/clock control bit: ON


  // Timeout = WDTC / (f_WDCLK /4) => WDTC = Timeout*f_WDCLK/4
  switch( mode )
  {
    default:
    case WD_TIMEOUT_16ms:   prescale =   48000L; break;
    case WD_TIMEOUT_32ms:   prescale =   96000L; break;
    case WD_TIMEOUT_65ms:   prescale =  195000L; break;
    case WD_TIMEOUT_130ms:  prescale =  390000L; break;
    case WD_TIMEOUT_260ms:  prescale =  780000L; break;
    case WD_TIMEOUT_520ms:  prescale = 1560000L; break;
    case WD_TIMEOUT_1000ms: prescale = 3000000L; break;
    case WD_TIMEOUT_2000ms: prescale = 6000000L; break;
  }
  
  LPC_WWDT->TC = prescale;
  LPC_WWDT->CLKSEL = (0<<0); // CLKSEL: IRC

  // Start WDT
  LPC_WWDT->MOD |=  (1<<0)  // WDEN
                   |(1<<1); // WDRESET

  LPC_WWDT->FEED = 0xAA;    // feed to start
  LPC_WWDT->FEED = 0x55;
}

//-------------------------------------------------------------------
void cSystem::disableWatchdog( void )
{
  // The watchdog can NOT be disabled by software
}

//-------------------------------------------------------------------
void cSystem::feedWatchdog( void )
{
  LPC_WWDT->FEED = 0xAA;
  LPC_WWDT->FEED = 0x55;
}

//-------------------------------------------------------------------
void cSystem::reset( void )
{
  __disable_irq();
  enableWatchdog( WD_TIMEOUT_16ms );

  while(1);
}

//-------------------------------------------------------------------
void cSystem::delayMicroSec( unsigned short delay )
{
  // Calibration:
  delay *= 4.0;
  for(;delay>0;delay--)
  {
    asm volatile("nop");
  }
}

//-------------------------------------------------------------------
void cSystem::delayMilliSec( unsigned short delay )
{
  for(;delay>0;delay--)
    delayMicroSec(1000);
}


//EOF
