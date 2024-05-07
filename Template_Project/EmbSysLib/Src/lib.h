//*******************************************************************
/*!
\file   lib.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.

\brief  Library main include file
*/

//*******************************************************************
#ifndef _LIB_H
#define _LIB_H

//*******************************************************************
//
//*******************************************************************

#include "MCU/System.h"
#include "MCU.h"

//*******************************************************************
// Hardware
////*******************************************************************
#include "Com/Hardware/Net/Net.h"

//*******************************************************************
// Peripheral
////*******************************************************************
//#include "Peripheral/Peripheral.h"

//*******************************************************************
// Std
//*******************************************************************
#include "Com/Std/Std.h"
#include "Com/Std/StaticArray.h"
#include "Com/Std/CRC.h"
#include "Com/Std/List.h"
#include "Com/Std/Fifo.h"
#include "Com/Std/SharedMem.h"
#include "Com/Std/DataPointer.h"
#include "Com/Std/Timer.h"

//*******************************************************************
// Device
//*******************************************************************
//*******************************************************************
// Device/Analog
//*******************************************************************
#include "Com/Device/Analog/devAnalogInADC.h"
#include "Com/Device/Analog/devAnalogOutDAC.h"
#include "Com/Device/Analog/devAnalogOutPWM.h"

//*******************************************************************
// Device/Digital
//*******************************************************************
#include "Com/Device/Digital/devDigital.h"
#include "Com/Device/Digital/devDigitalIndicator.h"

//*******************************************************************
// Device/Display
//*******************************************************************
#include "Com/Device/Display/devDisplay.h"
#include "Com/Device/Display/devDisplayChar.h"
#include "Com/Device/Display/devDisplayGraphic.h"

//*******************************************************************
// DEVICE/MEMORY
//*******************************************************************
#include "Com/Device/Memory/devMemory.h"
#include "Com/Device/Memory/devMemoryFlash.h"

//*******************************************************************
// Device/TextIO
//*******************************************************************
#include "Com/Device/TextIO/devTextIO_UART.h"

//*******************************************************************
// Device/Control
//*******************************************************************
#include "Com/Device/Control/devControlEncoder.h"
#include "Com/Device/Control/devControlEncoderJoystick.h"
#include "Com/Device/Control/devControlEncoderRotaryknob.h"
#include "Com/Device/Control/devControlPointer.h"

//*******************************************************************
// Task
//*******************************************************************
#include "Com/Task/TaskHandler.h"

#endif
