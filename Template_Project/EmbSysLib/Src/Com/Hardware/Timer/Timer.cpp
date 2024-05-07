//*******************************************************************
/*!
\file   Com/Hardware/Timer.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "Timer.h"

//*******************************************************************
// 
// cHwTimer
//
//*******************************************************************
//-------------------------------------------------------------------
DWORD cHwTimer::getCycleTime( void )
{
  return( cycleTime );
}

//-------------------------------------------------------------------
void cHwTimer::add( cList::Item *ptr )
{
  isrList.add( ptr );
}

//-------------------------------------------------------------------
inline void cHwTimer::isrHandler( void )
{
  isrList.updateAll();
}

//EOF
