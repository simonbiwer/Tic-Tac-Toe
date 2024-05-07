//*******************************************************************
/*!
\file   System.cpp
\author Thomas Breuer
\date   11.03.2011

\brief  Controller specific implementation of class cSystem
*/

//*******************************************************************
#include "MCU/LPC17xx/Sys/system_LPC17xx.cpp"

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

  // Timeout = WDTC / (f_WDCLK /4)
  // WDTC = 1000, f_WDCLK = 4MHz => Timeout = 1ms
  switch( mode )
  {
    default:
    case WD_TIMEOUT_16ms:   prescale =   16000L; break;
    case WD_TIMEOUT_32ms:   prescale =   32000L; break;
    case WD_TIMEOUT_65ms:   prescale =   65000L; break;
    case WD_TIMEOUT_130ms:  prescale =  130000L; break;
    case WD_TIMEOUT_260ms:  prescale =  260000L; break;
    case WD_TIMEOUT_520ms:  prescale =  520000L; break;
    case WD_TIMEOUT_1000ms: prescale = 1000000L; break;
    case WD_TIMEOUT_2000ms: prescale = 2000000L; break;
  }

  LPC_WDT->WDTC = prescale;
  // Start WDT
  LPC_WDT->WDMOD |=  (1<<0)  // WDEN
                    |(1<<1); //WDRESET
  LPC_WDT->WDFEED = 0xAA;    // feed to start
  LPC_WDT->WDFEED = 0x55;
}

//-------------------------------------------------------------------
void cSystem::disableWatchdog( void )
{
  // The watchdog can NOT be disabled by software
}

//-------------------------------------------------------------------
void cSystem::feedWatchdog( void )
{
  LPC_WDT->WDFEED = 0xAA;    // feed to start
  LPC_WDT->WDFEED = 0x55;
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
  delay *= 16.5;
  for(;delay>0;delay--)
  {
//    asm volatile("nop");
  }
}

//-------------------------------------------------------------------
void cSystem::delayMilliSec( unsigned short delay )
{
  for(;delay>0;delay--)
    delayMicroSec(1000);
}


//EOF
