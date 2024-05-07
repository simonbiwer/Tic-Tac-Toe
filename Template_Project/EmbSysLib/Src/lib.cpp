//*******************************************************************
/*!
\file   lib.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.

\brief Summary of complete library code
*/

//*******************************************************************
#include "lib.h"

//*******************************************************************
// Hardware/MCU
//*******************************************************************
#include "MCU.cpp"

//*******************************************************************
// Hardware
//*******************************************************************
//*******************************************************************
// Com/Hardware
//*******************************************************************
#include "Com/Hardware/Analog/ADC.cpp"
#include "Com/Hardware/Analog/DAC.cpp"
#include "Com/Hardware/Display/Display.cpp"
#include "Com/Hardware/Display/DisplayFont.cpp"
#include "Com/Hardware/Display/DisplayGraphic.cpp"
#include "Com/Hardware/Timer/Encoder.cpp"
#ifndef _MCU_TYPE_VIRTUAL
 #include "Com/Hardware/Ethernet/Ethernet.cpp"
#endif
#include "Com/Hardware/I2C/I2Cmaster.cpp"
#include "Com/Hardware/I2C/I2Cslave.cpp"
#include "Com/Hardware/Memory/Memory.cpp"
#include "Com/Hardware/Port/Port.cpp"
#include "Com/Hardware/RTC/RTC.cpp"
#include "Com/Hardware/SPI/SPImaster.cpp"
#include "Com/Hardware/SPI/SPIslave.cpp"
#include "Com/Hardware/Timer/Timer.cpp"
#include "Com/Hardware/Display/Touch.cpp"
#include "Com/Hardware/UART/UART.cpp"

//#include "Com/Hardware/USB.cpp"
//-------------------------------------------------------------------
#include "Com/Hardware/USB/USBhardware.cpp"
#include "Com/Hardware/USB/USBctrl.cpp"
#include "Com/Hardware/USB/USBdesc.cpp"
#include "Com/Hardware/USB/USBendpoint.cpp"
#include "Com/Hardware/USB/USBinterf.cpp"

#include "Com/Hardware/Net/Net.cpp"
//-------------------------------------------------------------------
/*#include "Com/Hardware/Net/NetStd.cpp"
#include "Com/Hardware/Net/NetTransport.cpp"


#ifndef _MCU_TYPE_VIRTUAL
  #include "Com/Hardware/Net/NetARP.cpp"
  #include "Com/Hardware/Net/NetDHCP.cpp"
  #include "Com/Hardware/Net/NetICMP.cpp"
  #include "Com/Hardware/Net/NetIP.cpp"
  #include "Com/Hardware/Net/NetTCP.cpp"
  #include "Com/Hardware/Net/NetUDP.cpp"
#endif
*/
//*******************************************************************
// 
//*******************************************************************
//#include "Peripheral/Peripheral.cpp"

//*******************************************************************
// Device
//*******************************************************************
//*******************************************************************
// Device/Analog
//*******************************************************************
#include "Com/Device/Analog/devAnalog.cpp"
#include "Com/Device/Analog/devAnalogIn.cpp"
#include "Com/Device/Analog/devAnalogInADC.cpp"
#include "Com/Device/Analog/devAnalogOut.cpp"
#include "Com/Device/Analog/devAnalogOutDAC.cpp"
#include "Com/Device/Analog/devAnalogOutPWM.cpp"

//*******************************************************************
// Device/Digital
//*******************************************************************
#include "Com/Device/Digital/devDigital.cpp"
#include "Com/Device/Digital/devDigitalIndicator.cpp"

//*******************************************************************
// Device/Display
//*******************************************************************
#include "Com/Device/Display/devDisplay.cpp"
#include "Com/Device/Display/devDisplayChar.cpp"
#include "Com/Device/Display/devDisplayGraphic.cpp"

//*******************************************************************
// DEVICE/MEMORY
//*******************************************************************
#include "Com/Device/Memory/devMemory.cpp"

//*******************************************************************
// Device/TextIO
//*******************************************************************
#include "Com/Device/TextIO/devTextIO.cpp"
#include "Com/Device/TextIO/devTextIO_UART.cpp"

//*******************************************************************
// Device/Control
//*******************************************************************
#include "Com/Device/Control/devControlEncoder.cpp"
#include "Com/Device/Control/devControlEncoderJoystick.cpp"
#include "Com/Device/Control/devControlEncoderRotaryknob.cpp"
#include "Com/Device/Control/devControlPointer.cpp"

//*******************************************************************
// STD
//*******************************************************************
#include "Com/Std/Std.cpp"
#include "Com/Std/StaticArray.cpp"
#include "Com/Std/CRC.cpp"
#include "Com/Std/List.cpp"
#include "Com/Std/Fifo.cpp"
#include "Com/Std/DataPointer.cpp"
#include "Com/Std/SharedMem.cpp"
#include "Com/Std/Timer.cpp"

//*******************************************************************
// Task
//*******************************************************************
#include "Com/Task/TaskHandler.cpp"

// EOF
