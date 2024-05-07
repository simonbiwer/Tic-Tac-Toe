//*******************************************************************
/*!
\file   MCU.h
\author Thomas Breuer
\date   15.04.2014

\brief Include controller specific header files

All controller specific header files are included here.
*/

//*******************************************************************
#ifndef _HW_MCU_VIRTUAL_H
#define _HW_MCU_VIRTUAL_H


#define _MCU_DEV_VIRTUAL
#define _MCU_TYPE_VIRTUAL

//*******************************************************************
#include <inttypes.h>
#include <stdlib.h>

//*******************************************************************
typedef uint8_t              BYTE;
typedef uint16_t             WORD;
typedef long unsigned int   DWORD;
typedef uint32_t            MTYPE;

//*******************************************************************
#define PROGMEM // nothing to do
#define GET_BYTE_PROGMEM(varName)       (varName)
#define GET_BYTE_PROGMEM_PTR(ptrName)   (*(ptrName))

#define __packed
//*******************************************************************
#include "Src/Memory_MCU.h"
#include "Src/Net_MCU.h"
#include "Src/UART_MCU.h"
#include "Src/Port_MCU.h"
#include "Src/RTC_MCU.h"
#include "Sys/RTOS_MCU.h"
#include "Src/Timer_MCU.h"
#include "Src/Touch_MCU.h"

#include "Src/ADC_MCU.h"
#include "Src/DAC_MCU.h"
#include "Src/Disp_MCU.h"
#include "Src/DispChar_MCU.h"

#ifdef USE_USB
#include "Src/USBhost_MCU.h"
#endif

#endif //_HW_MCU_VIRTUAL_H
