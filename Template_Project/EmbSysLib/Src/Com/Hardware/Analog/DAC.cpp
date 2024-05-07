//*******************************************************************
/*!
\file   DAC.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "DAC.h"

//*******************************************************************
//
// cHwDAC
//
//*******************************************************************
//-------------------------------------------------------------------
cHwDAC::cHwDAC( BYTE numIn )
{
  numOfChannels = numIn;
}

//-------------------------------------------------------------------
inline BYTE cHwDAC::getNumberOfChannels( void )
{
  return( numOfChannels );
}

//EOF
