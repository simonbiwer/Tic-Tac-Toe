//*******************************************************************
/*!
\file   RTC_MCU.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   20.07.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "RTC_MCU.h"
#include <time.h>

//*******************************************************************
//
// cHwRTC_0
//
//*******************************************************************
static BYTE x=0;
  //-------------------------------------------------------------------
cHwRTC_0::cHwRTC_0( void )
{
  offset = 0;
}

//-------------------------------------------------------------------
void cHwRTC_0::set( const cHwRTC::Properties &clock )
{
  time_t rawtime;
  struct tm * ptm;

  time ( &rawtime );

  ptm = gmtime ( &rawtime );

  WORD newSecOfDay = (WORD)clock.hour*3600+(WORD)clock.minute*60+(WORD)clock.second;
  WORD actSecOfDay = (WORD)ptm->tm_hour*3600+(WORD)ptm->tm_min*60+(WORD)ptm->tm_sec;
  offset = ((24*3600) + newSecOfDay - actSecOfDay)%(24*3600);
/*
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
            |((DWORD)((clock.year %10)&0xF) <<16)
            |((DWORD)((clock.year /10)&0xF) <<20);

  // exit initialization
  RTC->ISR &= ~RTC_ISR_INIT;
  */
}

//-------------------------------------------------------------------
BYTE cHwRTC_0::get( cHwRTC::Properties &clock )
{
  time_t rawtime;
  struct tm * ptm;

  time ( &rawtime );

  rawtime += offset;

  ptm = gmtime ( &rawtime );

 // printf ("UTC:%2d:%02d\n", ptm->tm_hour, ptm->tm_min);


  //WORD minutesOfDay = (WORD)ptm->tm_hour*60+(WORD)ptm->tm_min;

  clock.minute = ptm->tm_min; //((minutesOfDay+offset)   )%60;
  clock.hour   = ptm->tm_hour; //((minutesOfDay+offset)/60)%24;
  clock.second = ptm->tm_sec; //(BYTE)(((RTC->TR >> 0)&0xF) + 10*((RTC->TR >> 4)&0x7));
 // clock.minute = ptm->tm_min; //(BYTE)(((RTC->TR >> 8)&0xF) + 10*((RTC->TR >>12)&0x7));
 // clock.hour   = ptm->tm_hour; //(BYTE)(((RTC->TR >>16)&0xF) + 10*((RTC->TR >>20)&0x3));

  clock.dow    = (ptm->tm_wday==0)?7:ptm->tm_wday; //(BYTE)(((RTC->DR >> 0)&0xF) + 10*((RTC->DR >> 4)&0x3));
  clock.day    = ptm->tm_mday; //(BYTE)(((RTC->DR >> 0)&0xF) + 10*((RTC->DR >> 4)&0x3));
  clock.month  = ptm->tm_mon+1; //(BYTE)(((RTC->DR >> 8)&0xF) + 10*((RTC->DR >>12)&0x1));
  clock.year   = ptm->tm_year+1900; //(BYTE)(((RTC->DR >>16)&0xF) + 10*((RTC->DR >>20)&0xF));

  return( true );
}

// EOF
