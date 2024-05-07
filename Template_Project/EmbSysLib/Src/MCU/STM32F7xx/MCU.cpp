//*******************************************************************
/*!
\file   MCU_STM32F7xx.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   21.07.2017

This file is released under the MIT License.

\brief Include controller specific source code

All controller specific source files are included here. 
*/

//*******************************************************************
#include "Sys/System.cpp"
 #include "Sys/PinConfig.cpp"
#include "Sys/RTOS_MCU.cpp"

//*******************************************************************
#include "Src/ADC_MCU.cpp"
#include "Src/DAC_MCU.cpp"
//#include "Src/DSI.cpp"
// #include "Src/Encoder_MCU.cpp"
// #ifdef _MCU_DEV_STM32F407
#include "Src/Ethernet_MCU.cpp"
// #endif
// 
#include "Src/I2Cmaster_MCU.cpp"
// #include "Src/Memory_BKPRAM.cpp"
#include "Src/Memory_Flash.cpp"
// #include "Src/Memory_RAM.cpp"
#include "Src/Port_MCU.cpp"
#include "Src/RTC_MCU.cpp"
// #include "Src/SPImaster_MCU.cpp"
#include "Src/Timer_MCU.cpp"
#include "Src/UART_MCU.cpp"
#include "Src/USB_MCU.cpp"

//*******************************************************************
WORD hton( const WORD in )
{
  return(  (((in>>8)&0xFF)   )
         | (((in   )&0xFF)<<8) );
}

DWORD hton( const DWORD in )
{
  return( (((in>>24)&0xFF)    )
         |(((in>>16)&0xFF)<< 8)
         |(((in>> 8)&0xFF)<<16)
         |(((in    )&0xFF)<<24) );
}

WORD ntoh( const WORD in )
{
  return( hton(in) );
}

DWORD ntoh( const DWORD in )
{
  return( hton(in) );
}

//EOF
