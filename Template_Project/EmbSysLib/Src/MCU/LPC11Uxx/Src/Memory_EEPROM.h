//*******************************************************************
/*!
\file   Memory_EEPROM.h
\author Thomas Breuer
\date   25.03.2013
*/

//*******************************************************************
#ifndef _HW_MEMORY_EEPROM_H
#define _HW_MEMORY_EEPROM_H

//*******************************************************************
#include "Com/Hardware/Memory/Memory.h"

//*******************************************************************
/*! 
\class cHwMemory_EEPROM

\brief Implementation of EEPROM as a cHwMemory class

\example cHwMemory.cpp
*/
class cHwMemory_EEPROM : public cHwMemory
{
  public:
    //---------------------------------------------------------------
    /*! Initialize battery buffered EEPROM hardware
    */
    cHwMemory_EEPROM( void );

  private:
    //---------------------------------------------------------------
    virtual void writeByte( DWORD addr, 
                            BYTE data );

    //---------------------------------------------------------------
    virtual BYTE readByte( DWORD addr );

  private:
    //---------------------------------------------------------------
    DWORD *ptr;

}; //cHwMemory_EEPROM

#endif
