//*******************************************************************
/*!
\file   MCU_Virtual.cpp
\author Thomas Breuer
\date   15.04.2014

\brief Include controller specific source code

All controller specific source files are included here.
*/

//*******************************************************************
#include "Sys/System.cpp"
#include "Src/Memory_MCU.cpp"
#include "Src/Net_MCU.cpp"
#include "Src/Port_MCU.cpp"
#include "Src/RTC_MCU.cpp"
#include "Sys/RTOS_MCU.cpp"

#include "Src/ADC_MCU.cpp"
#include "Src/DAC_MCU.cpp"
#include "Src/DispChar_MCU.cpp"
#include "Src/Disp_MCU.cpp"
#include "Src/Timer_MCU.cpp"
#include "Src/Touch_MCU.cpp"
#include "Src/UART_MCU.cpp"
#ifdef USE_USB
#include "Src/USBhost_MCU.cpp"
#endif // USE_USB
//EOF
