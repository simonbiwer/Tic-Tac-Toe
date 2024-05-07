//*******************************************************************
/*!
\file   Memory_EEPROM.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_MEMORY_EEPROM_H
#define _HW_MEMORY_EEPROM_H

//*******************************************************************
#include "Com/Hardware/Memory/Memory.h"

//*******************************************************************
/*!
\class cHwMemory_EEPROM

\brief Implementation of the EEPROM as a cHwMemory class

\example cHwMemory.cpp
*/
class cHwMemory_EEPROM : public cHwMemory
{
  public:
    //---------------------------------------------------------------
    /*! Initialize hardware
    */
    cHwMemory_EEPROM( DWORD offset, DWORD size );

    //---------------------------------------------------------------
    /*! Unlock memory
    */
    virtual void unlock( void );
    
    //---------------------------------------------------------------
    /*! Lock memory
    */
    virtual void lock( void );
    
  private:
    //---------------------------------------------------------------
    virtual void writeByte( DWORD addr,
                            BYTE  data );

    //---------------------------------------------------------------
    virtual BYTE readByte( DWORD addr );

  private:
    //---------------------------------------------------------------
    BYTE *ptr;
  
}; //cHwMemory_EEPROM

#endif

