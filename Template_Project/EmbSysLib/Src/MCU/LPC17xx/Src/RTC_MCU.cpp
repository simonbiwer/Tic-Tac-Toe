//*******************************************************************
/*!
\file   RTC_MCU.cpp
\author Thomas Breuer
\date   25.02.2011
*/

//*******************************************************************
// 
// cHwRTC_0
//
//*******************************************************************
//-------------------------------------------------------------------
cHwRTC_0::cHwRTC_0( void )
{
  LPC_SC->PCONP |=  (1<<9); // power on

  LPC_RTC->CCR   =  (1<<0)  // time counters enable
                   |(0<<1)  // reset
                   |(1<<4); // calbration disable
}

//-------------------------------------------------------------------
void cHwRTC_0::set( const cHwRTC::Properties &clock )
{
  // stop clock
  LPC_RTC->CCR &= ~(1<<0); // time counters disable

  LPC_RTC->SEC   = clock.second;
  LPC_RTC->MIN   = clock.minute;
  LPC_RTC->HOUR  = clock.hour;
  
  LPC_RTC->YEAR  = clock.year;
  LPC_RTC->MONTH = clock.month;
  LPC_RTC->DOM   = clock.day;

  LPC_RTC->CCR |= (1<<0); // time counters enable
}

//-------------------------------------------------------------------
BYTE cHwRTC_0::get( cHwRTC::Properties &clock )
{
  BYTE sec;
  
  clock.second = (BYTE)LPC_RTC->SEC;
  clock.minute = (BYTE)LPC_RTC->MIN;
  clock.hour   = (BYTE)LPC_RTC->HOUR;
 
  clock.day    = (BYTE)LPC_RTC->DOM;
  clock.month  = (BYTE)LPC_RTC->MONTH;
  clock.year   = (WORD)LPC_RTC->YEAR;
 
  // reread sec to check overflow
  sec         = (BYTE)LPC_RTC->SEC;
  
  return( (clock.second <= sec) ? true : false );
}

// EOF
