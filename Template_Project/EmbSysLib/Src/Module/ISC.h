//*******************************************************************
/*!
\file   Module/ISC.h
\author Thomas Breuer
\date   09.02.2016

\brief  Summary of ISC classes (Inter system communication)
*/

//*******************************************************************
#include "Module/ISC/ISC.h"
#include "Module/ISC/ISC_UART.h"
#include "Module/ISC/ISC_UDP.h"
#include "Module/ISC/ISC_TCP.h"
#ifdef _MCU_TYPE_VIRTUAL
  #ifdef USB_ON
 #include "Module/ISC/ISC_USBhost.h"
#endif
#else
  #include "Module/ISC/ISC_USBdevice.h"
#endif


//EOF
