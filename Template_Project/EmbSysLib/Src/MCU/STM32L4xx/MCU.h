//*******************************************************************
/*!
\file   MCU_STM32F4xx.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.

\brief Include controller specific header files

All controller specific header files are included here. 
*/

//*******************************************************************
#ifndef _HW_MCU_STM32L4XX_H
#define _HW_MCU_STM32L4XX_H
//*******************************************************************
#if defined STM32L432
  #define _MCU_DEV_STM32L432
  #define _MCU_TYPE_STM32L4XX

#else
  #error "MCU.h: device type mismatch"
#endif

//*******************************************************************
#include <inttypes.h>
#include <stdlib.h>
  
//-------------------------------------------------------------------
//#include "Sys/STM32L4xx.h"
#include <STM32L4xx.h>

//*******************************************************************
// 
// Summary of clock configuration in system_STM32F4xx.cpp"
// 
// These constants doesn't affect the PLCK settings.
// If other clock settings are used, all constants and their use in 
// "Hardware/Src" have to been checked.
//
#define system_PCLK          (72000000)
#define system_PCLK_SYSTIC   (system_PCLK)
#define system_PCLK_TIM      (system_PCLK/1)
#define system_PCLK_I2C      (system_PCLK/1)
#define system_PCLK_SPI      (system_PCLK)
#define system_PCLK_UART     (system_PCLK/1)

//*******************************************************************
typedef uint8_t    BYTE;
typedef uint16_t   WORD;
typedef uint32_t   DWORD;
typedef uint32_t   MTYPE;

//*******************************************************************
inline void* operator new[]    ( unsigned int  x ) { return malloc(x); }
inline void* operator new      ( unsigned int  x ) { return malloc(x); }
inline void  operator delete[] ( void         *x ) { if(x) free(x);    }
inline void  operator delete   ( void         *x ) { if(x) free(x);    }

//*******************************************************************
#define PROGMEM // nothing to do
#define GET_BYTE_PROGMEM(varName)       (varName)
#define GET_BYTE_PROGMEM_PTR(ptrName)   (*(ptrName))

//*******************************************************************
#include "Sys/PinConfig.h"
#include "Sys/RTOS_MCU.h"

//*******************************************************************
//#include "Src/ADC_MCU.h"
//#include "Src/DAC_MCU.h"
#include "Src/Encoder_MCU.h"
//#ifdef _MCU_DEV_STM32F407
//  #include "Src/Ethernet_MCU.h"
//#endif
//#include "Src/I2Cmaster_MCU.h"
//#include "Src/Memory_BKPRAM.h"
//#include "Src/Memory_Flash.h"
//#include "Src/Memory_RAM.h"
#include "Src/Port_MCU.h"
#include "Src/RTC_MCU.h"
//#include "Src/SPImaster_MCU.h"
#include "Src/Timer_MCU.h"
#include "Src/UART_MCU.h"
//#include "Src/USB_MCU.h"

//===================================================================
#define WINAPI // for future use ...
//===================================================================

#endif //_HW_MCU_STM32F4XX_H
