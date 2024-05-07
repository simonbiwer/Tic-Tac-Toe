//*******************************************************************
/*!
\file   RTC_MCU.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "RTC_MCU.h"

//*******************************************************************
//
// cHwRTC_0
//
//*******************************************************************
//-------------------------------------------------------------------
cHwRTC_0::cHwRTC_0( RTC_ClockConfig_t config )
{
  if( config == LSI )
	{
    // In LSI mode, HSE is selected after power only.
    // Initialize only, if LSI is NOT selected
    if( ((RCC->BDCR >> RCC_BDCR_RTCSEL_Pos) & 0x03) != 2 ) 
    {
      PWR->CR1 |= PWR_CR1_DBP; // Disable write protection

      // BDCR reset
      RCC->BDCR |=  RCC_BDCR_BDRST; 
      RCC->BDCR &= ~RCC_BDCR_BDRST; 
      
      RCC->CSR |= RCC_CSR_LSION;
      
      while( !(RCC->CSR & RCC_CSR_LSIRDY) );
      
      // RTC clock selection
      RCC->BDCR &= ~(0x03<<8); // reset RTCSEL
      RCC->BDCR |=  (0x02<<8); // LSI select
      RCC->BDCR |=  RCC_BDCR_RTCEN;
    }
  }  
  else if( config == LSE )
	{
    // In LSE mode, HSE is selected after power only.
    // Initialize only, if LSE is NOT selected
    if( ((RCC->BDCR >> RCC_BDCR_RTCSEL_Pos) & 0x03) != 1 ) 
    {
      PWR->CR1 |= PWR_CR1_DBP; // Disable write protection
     
      // BDCR reset
      RCC->BDCR |=  RCC_BDCR_BDRST; 
      RCC->BDCR &= ~RCC_BDCR_BDRST; 

      RCC->BDCR |= RCC_BDCR_LSEON;
      
      while( !(RCC->BDCR & RCC_BDCR_LSERDY) );
      
      // RTC clock selection
      RCC->BDCR &= ~(0x03<<8); // reset RTCSEL
      RCC->BDCR |=  (0x01<<8); // LSE select
      RCC->BDCR |=  RCC_BDCR_RTCEN;
    }
  }  
}

//-------------------------------------------------------------------
void cHwRTC_0::set( const cHwRTC::Properties &clock )
{
  BYTE dow;

  // unlock write protection:
  PWR->CR1 |= PWR_CR1_DBP;

  RTC->WPR = 0xCA;
  RTC->WPR = 0x53;

  // initialization
  RTC->ISR |= RTC_ISR_INIT;

  while( !(RTC->ISR & RTC_ISR_INITF) );

  if( clock.dow == 0 )
  {
    dow = getDayOfWeek( clock.day, clock.month, clock.year );
  }
  else
  {
    dow = clock.dow;
  }

  WORD year = clock.year%100;

  RTC->TR =  ((DWORD)((clock.second%10)&0xF) << 0)
            |((DWORD)((clock.second/10)&0x7) << 4)
            |((DWORD)((clock.minute%10)&0xF) << 8)
            |((DWORD)((clock.minute/10)&0x7) <<12)
            |((DWORD)((clock.hour  %10)&0xF) <<16)
            |((DWORD)((clock.hour  /10)&0x3) <<20);

  RTC->DR =  ((DWORD)((clock.day  %10)&0xF) << 0)
            |((DWORD)((clock.day  /10)&0x3) << 4)
            |((DWORD)((clock.month%10)&0xF) << 8)
            |((DWORD)((clock.month/10)&0x1) <<12)
            |((DWORD)((dow  % 8)&0x7) <<13)
            |((DWORD)((year %10)&0xF) <<16)
            |((DWORD)((year /10)&0xF) <<20);

  // exit initialization
  RTC->ISR &= ~RTC_ISR_INIT;

  PWR->CR1 &= ~PWR_CR1_DBP; // Enable write protection
}

//-------------------------------------------------------------------
BYTE cHwRTC_0::get( cHwRTC::Properties &clock )
{
  BYTE sec;

  clock.second = (BYTE)(((RTC->TR >> 0)&0xF) + 10*((RTC->TR >> 4)&0x7));
  clock.minute = (BYTE)(((RTC->TR >> 8)&0xF) + 10*((RTC->TR >>12)&0x7));
  clock.hour   = (BYTE)(((RTC->TR >>16)&0xF) + 10*((RTC->TR >>20)&0x3));

  clock.dow    = (BYTE)(((RTC->DR >>13)&0x7)                          );

  clock.day    = (BYTE)(((RTC->DR >> 0)&0xF) + 10*((RTC->DR >> 4)&0x3));
  clock.month  = (BYTE)(((RTC->DR >> 8)&0xF) + 10*((RTC->DR >>12)&0x1));
  clock.year   = (BYTE)(((RTC->DR >>16)&0xF) + 10*((RTC->DR >>20)&0xF));

  // reread sec to check overflow
  sec          = (BYTE)(((RTC->TR >> 0)&0xF) + 10*((RTC->TR >> 4)&0x7));

  clock.year += 2000;

  return( (clock.second <= sec) ? true : false );
}

// EOF
