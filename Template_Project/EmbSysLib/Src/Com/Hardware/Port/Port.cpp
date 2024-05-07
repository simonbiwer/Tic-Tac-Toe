//*******************************************************************
/*!
\file   Port.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "Port.h"

//*******************************************************************
//
// cHwPort
//
//*******************************************************************
//-------------------------------------------------------------------

// nothing to do ...

//*******************************************************************
//
// cHwPort::Pin
//
//*******************************************************************
//-------------------------------------------------------------------
cHwPort::Pin::Pin( cHwPort &portIn, BYTE pinIdIn )

: port( portIn )

{
  pinId   = pinIdIn;
  pinMask = (1<<pinId);
}

//-------------------------------------------------------------------
cHwPort::Pin::Pin( cHwPort &portIn, BYTE pinIdIn, Mode mode )

: port( portIn )

{
  pinId   = pinIdIn;
  pinMask = (1<<pinId);

  port.setPinMode( pinId, mode );
}

// EOF
