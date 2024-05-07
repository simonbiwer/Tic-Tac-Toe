//*******************************************************************
/*!
\file   devDigital.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "devDigital.h"

//*******************************************************************
//
// cDevDigital
//
//*******************************************************************
//-------------------------------------------------------------------
cDevDigital::cDevDigital( cHwPort &port,
                          BYTE     pinId,
                          Mode     mode,
                          bool     def  )
: pin( port, pinId )
{
  valueIn     = 0;
  valueOut    = 0;
  pinDefault  = def;

  pin.set( def );
  pin.setMode( (cHwPort::Mode)mode );
}

//-------------------------------------------------------------------
void cDevDigital::setMode( Mode mode )
{
  pin.setMode( (cHwPort::Mode)mode );
}

//-------------------------------------------------------------------
void cDevDigital::set( bool value )
{
  valueOut = value;
  pin.set( value ^ pinDefault );
}

//-------------------------------------------------------------------
bool cDevDigital::get( void )
{
  return( pin.get() != pinDefault );
}

//EOF
