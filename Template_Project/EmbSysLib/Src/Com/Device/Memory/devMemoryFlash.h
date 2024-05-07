//*******************************************************************
/*!
\file   devMemoryFlash.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.06.2015, 23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _DEV_MEMORY_FLASH_H
#define _DEV_MEMORY_FLASH_H

//*******************************************************************
#include "devMemory.h"

//*******************************************************************
/*!
\class cDevMemoryFlash

\brief Access to a memory

\example cDevMemoryFlash.cpp
*/
template <class T> class cDevMemoryFlash
{
  public:
    //---------------------------------------------------------------
    /*! Initialize memory access

        Using cHwMemory hardware
        \param mem Reference to memory hardware
    */
    cDevMemoryFlash( cHwMemory &memIn )

    : mem( memIn )

    {
      WORD  checkSum = 0;
      DWORD i        = 0;

      isValidFlag = false;
      if( mem.read( sizeof(T)+2 ) == 0xAA ) // read validFlag
      {
        for( i = 0; i < sizeof(T); i++ )
        {
          checkSum += mem.read( i );
        }

        if(    (checkSum&0xFF) == mem.read( i++ )
            && (checkSum>>8)   == mem.read( i++ ) )
        {
          BYTE *ptr = (BYTE*)&data;
          for( i = 0; i < sizeof(T); i++, ptr++ )
          {
            *ptr = mem.read( i );
          }
          isValidFlag = true;
        }
      }
    }

    //---------------------------------------------------------------
    /*!
    */
    bool isValid()
    {
      return( isValidFlag );
    }
    //---------------------------------------------------------------
    /*! Write data into memory
    */
    BYTE store( void )
    {
      BYTE *ptr      = (BYTE*)&data;
      DWORD i        = 0;
      WORD  checkSum = 0;
      BYTE  ok       = true;


      mem.unlock();
      mem.clear();
      mem.lock();

      mem.unlock();
      for( i = 0; i < sizeof(T); i++, ptr++ )
      {
        mem.write( i, *ptr );
        checkSum += *ptr;
      }
      mem.write( i++, checkSum&0xFF );
      mem.write( i++, checkSum>>8  );
      mem.write( i++, 0xAA );
      while( i%4 ) // used size must be a multiple of 4
      {
        mem.write( i++, 0x00 );
      }
      mem.lock();


      // validate
      ptr = (BYTE*)&data;
      for( i = 0; i < sizeof(T); i++, ptr++ )
      {
        if( *ptr != mem.read( i ) )
        {
          ok = false;
        }
      }
      if(    (checkSum&0xFF) != mem.read( i++ )
          || (checkSum>>8  ) != mem.read( i++ )
          || (0xAA         ) != mem.read( i++ ) )
      {
        ok = false;
      }

      if( ok )
      {
        isValidFlag = true;
      }
      return( ok );
    }

  public:
    //---------------------------------------------------------------
    T          data;

  private:
    //---------------------------------------------------------------
    cHwMemory &mem;
    bool       isValidFlag;

}; //cDevMemoryFlash

#endif
