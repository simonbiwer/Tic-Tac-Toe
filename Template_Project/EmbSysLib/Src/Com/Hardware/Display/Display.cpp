//*******************************************************************
/*!
\file   Display.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   05.04.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "Display.h"

//*******************************************************************
//
// cHwDisplay
//
//*******************************************************************
//-------------------------------------------------------------------
cHwDisplay::cHwDisplay( BYTE numberOfLinesIn,
                        BYTE numberOfColumnsIn )
{
  numberOfLines  = numberOfLinesIn;
  numberOfColumns = numberOfColumnsIn;
}

//-------------------------------------------------------------------
inline BYTE cHwDisplay::getNumberOfLines( void )
{
  return( numberOfLines );
}

//-------------------------------------------------------------------
inline BYTE cHwDisplay::getNumberOfColumns( void )
{
  return( numberOfColumns );
}

//EOF
