//*******************************************************************
/*!
\file   Memory_RAM.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_MEMORY_RAM_H
#define _HW_MEMORY_RAM_H

//*******************************************************************
#include "Com/Hardware/Memory/Memory.h"

//*******************************************************************
/*! 
\class cHwMemory_RAM

\brief Implementation of the battery buffered RAM

\example cHwMemory.cpp
*/
class cHwMemory_RAM : public cHwMemory
{
  public:
    //---------------------------------------------------------------
    /*! Initialize battery buffered RAM hardware
    */
    cHwMemory_RAM( void );

    //---------------------------------------------------------------
    virtual void unlock( void );
    
    //---------------------------------------------------------------
    virtual void lock( void );
    
  private:
    //---------------------------------------------------------------
    virtual void writeByte( DWORD addr, 
                            BYTE  data );

    //---------------------------------------------------------------
    virtual BYTE readByte( DWORD addr );

  private:
    //---------------------------------------------------------------
    DWORD *ptr;

}; //cHwMemory_RAM

#endif
