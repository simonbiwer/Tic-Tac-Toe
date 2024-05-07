//*******************************************************************
/*!
\file   Memory.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "Memory.h"

//*******************************************************************
// 
// cHwMemory
//
//*******************************************************************
//-------------------------------------------------------------------
cHwMemory::cHwMemory( DWORD sizeIn, BYTE defIn ) 
{
  size        = sizeIn;
  def         = defIn;
  isFlashFlag = false;
}

//-------------------------------------------------------------------
inline void cHwMemory::write( DWORD addr, BYTE data ) 
{
  if( addr < size )        // valid address?
  {
    writeByte(addr, data); // write data byte
  }
}

//-------------------------------------------------------------------
inline BYTE cHwMemory::read( DWORD addr ) 
{
  if( addr < size )           // valid address?
  {
    return( readByte(addr) ); // read data byte
  }
  return( def );
}

//-------------------------------------------------------------------
inline void cHwMemory::clear( DWORD offset ) 
{
  for( DWORD i = offset; i < size; i++ )  // write default to all addresses
  {
    writeByte( i, def );
  }
}

//-------------------------------------------------------------------
inline DWORD cHwMemory::getSize( void ) 
{
  return( size );
}

//-------------------------------------------------------------------
inline bool cHwMemory::isFlash( void ) 
{
  return( isFlashFlag );
}

//EOF
