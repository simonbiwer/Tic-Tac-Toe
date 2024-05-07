//*******************************************************************
/*!
\file   Memory_Flash.h
\author Thomas Breuer
\date   25.02.2011
*/

//*******************************************************************
#ifndef _HW_MEMORY_FLASH_H
#define _HW_MEMORY_FLASH_H

//*******************************************************************
#include "Com/Hardware/Memory/Memory.h"

//*******************************************************************
/*!
\class cHwMemory_FLASH

\brief Implementation of the Flash-RAM as a cHwMemory class

\example cHwMemory.cpp
*/
class cHwMemory_Flash : public cHwMemory
{
  public:
    //---------------------------------------------------------------
    /*! Initialize hardware
    */
    cHwMemory_Flash( BYTE *startAddress, DWORD size );

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

  public:
    //---------------------------------------------------------------
    virtual void clear( DWORD offset = 0 );

  private:
    //---------------------------------------------------------------
    BYTE  *ptr;
  
}; //cHwMemory_Flash

#endif

