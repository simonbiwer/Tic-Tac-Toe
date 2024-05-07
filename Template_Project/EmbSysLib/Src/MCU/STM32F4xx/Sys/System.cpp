//*******************************************************************
/*!
\file   System.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.

\brief  Controller specific implementation of class cSystem
*/

//*******************************************************************
#include "MCU/System.h"

//-------------------------------------------------------------------
#include "stm32f4xx.h"

//-------------------------------------------------------------------
#if !defined  (HSE_STARTUP_TIMEOUT)
  #define HSE_STARTUP_TIMEOUT  (0x05000)  //!< Time out for HSE start up
#endif

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
void cSystem::enableWatchdog( MODE mode )
{
  DWORD pr  = 0;
  DWORD rlr = 0;

  // timeout = LSI(40kHz) / (4*2^pr * pl)
  switch( mode )
  {
    default:
    case WD_TIMEOUT_16ms:   pr = 0; rlr =  160; break; // 40kHz/4*16ms
    case WD_TIMEOUT_32ms:   pr = 0; rlr =  320; break; // 40kHz/4*32ms
    case WD_TIMEOUT_65ms:   pr = 0; rlr =  650; break; // 40kHz/4*65ms
    case WD_TIMEOUT_130ms:  pr = 0; rlr = 1300; break; // 40kHz/4*130ms
    case WD_TIMEOUT_260ms:  pr = 0; rlr = 2600; break; // 40kHz/4*260ms
    case WD_TIMEOUT_520ms:  pr = 1; rlr = 2600; break; // 40kHz/8*520ms
    case WD_TIMEOUT_1000ms: pr = 2; rlr = 2500; break; // 40kHz/16*1000ms
    case WD_TIMEOUT_2000ms: pr = 3; rlr = 2500; break; // 40kHz/32*2000ms
  }

  IWDG->KR  = 0x5555;
  IWDG->PR  = pr;
  IWDG->KR  = 0x5555;
  IWDG->RLR = rlr;
  IWDG->KR  = 0xAAAA;
  IWDG->KR  = 0xCCCC;
}

//-------------------------------------------------------------------
void cSystem::disableWatchdog( void )
{
  // The watchdog can NOT be disabled by software
}

//-------------------------------------------------------------------
void cSystem::feedWatchdog( void )
{
  IWDG->KR  = 0xAAAA;
}

//-------------------------------------------------------------------
void cSystem::reset( void )
{
  __DSB();
  *((unsigned long *)(0x2000FFF0)) = 0xDEADBEEF;
  NVIC_SystemReset();
}

#pragma GCC push_options
#pragma GCC optimize ("-O0")
//-------------------------------------------------------------------
void cSystem::delayMicroSec( unsigned short delay )
{
  // Calibration:
  delay *= 16.5;
  for(;delay>0;delay--)
  {
    asm volatile("nop");
  }
}
#pragma GCC pop_options

#pragma GCC push_options
#pragma GCC optimize ("-O0")
//-------------------------------------------------------------------
void cSystem::delayMilliSec( unsigned short delay )
{
  for(;delay>0;delay--)
    delayMicroSec(1000);
}
#pragma GCC pop_options

//*******************************************************************
//
// SystemInit
//
//*******************************************************************
/*!
This function is a summary of "system_stm32f4xx.c" generated by
"STM32L1xx_Clock_Configuration_V1.1.0.xls"

\see STMicroelectronics, AN3309 Clock configuration tool for
STM32L1xx microcontrollers, Doc ID 18200 Rev 2, January 2012
*/
void SystemInit( void )
{
  // Set FPU
  #if (__FPU_PRESENT == 1) && (__FPU_USED == 1)

    // System Control Block (SCB), Coprocessor Access Control Register
    SCB->CPACR |=   (3UL << 10*2)  // CP10: Full access
                  | (3UL << 11*2); // CP11: Full access

  #endif

  // Clock control register
  RCC->CR |= RCC_CR_HSION;

  // Clock configuration register
  RCC->CFGR = 0x00000000;       // reset ...

  // Clock control register
  RCC->CR &= ~(   RCC_CR_PLLON  // reset ...
                | RCC_CR_CSSON
                | RCC_CR_HSEON );

  // PLL configuration register
  RCC->PLLCFGR = 0x24003010;   // Reset value,
                               // see Reference manual

  // Clock control register
  RCC->CR &= ~(RCC_CR_HSEBYP); // reset ...

  // Clock interrupt register
  RCC->CIR = 0;                // Disable all interrupts

  //-----------------------------------------------------------------
  #if defined (_HSE_BYPASS_ON )
    RCC->CR |= (RCC_CR_HSEON | RCC_CR_HSEBYP);
  #elif defined (_HSE_BYPASS_OFF )
    RCC->CR |= (RCC_CR_HSEON );
  #else
    #error "_HSE_BYPASS not defined"
  #endif
  //-----------------------------------------------------------------

  //! \todo Check code
  // Clock control register
  RCC->CR |= RCC_CR_HSION;   // Need HSION in ADC (only?)

  // Wait until HSE is ready or timeout
  for( unsigned i = 0; i < HSE_STARTUP_TIMEOUT; i++ )
  {
    if( RCC->CR & RCC_CR_HSERDY )
      break;
  }

  if( RCC->CR & RCC_CR_HSERDY )
  {
    // Flash Acess Control Register
    FLASH->ACR =   FLASH_ACR_ICEN          // Instruction cache enable
                 | FLASH_ACR_DCEN          // Data cache enable
                 | FLASH_ACR_LATENCY_5WS;  // Latency: 5 wait states

    // Advanced Peripheral Bus Enable Register
    RCC->APB1ENR |= RCC_APB1ENR_PWREN;    // Power interface clock: enable

    // Power Control Register
    PWR->CR   |= (1<<14);                 // Regulator voltage scaling output selection:
                                          // VOS=1: Scale 1 mode

    // Clock Configuration Register
    //! \todo Check clock configuration
    RCC->CFGR |=   RCC_CFGR_HPRE_DIV1     // AHB prescaler:                   HCLK  = SYSCLK
                 | RCC_CFGR_PPRE2_DIV4    // APB high-speed prescaler (APB2): PCLK2 = HCLK/4
                                          //   PCLK2 must not exceed 84 MHz
                 | RCC_CFGR_PPRE1_DIV4;   // APB low-speed  prescaler (APB1): PCLK1 = HCLK/4
                                          //   PCLK1 must not exceed 42 MHz

    //---------------------------------------------------------------
    /* PLL configuration

       f_osc  +----+ f_in  +-----+ f_out      +----+   f_pllclk
       ------>| /M |------>| VCO |--+------+->| /P |---------->
              +----+    +->|     |  |      |  +----+
                        |  +-----+  |      |
                        |           |      |  +----+   f_pll48ck
                        |  +----+   |      +->| /Q |----------->
                        +--| *N |<--+         +----+
                           +----+
        f_osc: HSI or HSE
        f_in      = f_osc / M (range:   1 to   2MHz, M =   2,..., 63)
        f_out     = f_in  * N (range: 192 to 432MHz, N = 192,...,432)
        f_pllclk  = f_out / P (range:  up to 168MHz, P = 2,4,6,8    )
        f_pll48ck = f_out / Q (equal to 48 MHz,      Q =   2,..., 15)

        Allowed frequencies due to f_pll48ck:
        f_out = 192, 240, 288, 336, 384, 432
            Q =   4    5    6    7    8    9
    */
    //---------------------------------------------------------------

    const DWORD pll_M = (_HSE_CLK)/1000UL; // -> f_in      =     1 MHz
    const DWORD pll_N = 336;               // -> f_out     = 336*1 MHz
    const DWORD pll_P = 4;                 // -> f_pllclk  = 336/4 MHz = 84 MHz
    const DWORD pll_Q = 7;                 // -> f_pll48ck = 336/7 MHz = 48 MHz

    // PLL configuration register
    RCC->PLLCFGR =   RCC_PLLCFGR_PLLSRC_HSE
                   | ( pll_M           )
                   | ( pll_N      <<  6)
                   | ((pll_P/2-1) << 16)
                   | ( pll_Q      << 24);

    // Clock control register
    RCC->CR |= RCC_CR_PLLON;            // PLL enable: ON
    while( !(RCC->CR & RCC_CR_PLLRDY) );// Wait until PLL is ready

    // Clock Configuration Register
    RCC->CFGR &= ~RCC_CFGR_SW;          // reset system clock switch
    RCC->CFGR |=  RCC_CFGR_SW_PLL;      // System clock switch:
                                        //  PLL selected as system clock

    // Wait for system clock switch is ready
    while( (RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL );
  }
  else
  {
    // Error: Wrong clock configuration
  }

  // System Control Block
  SCB->VTOR = FLASH_BASE | 0x00; // Vector Table Relocation in internal FLASH
}

//EOF