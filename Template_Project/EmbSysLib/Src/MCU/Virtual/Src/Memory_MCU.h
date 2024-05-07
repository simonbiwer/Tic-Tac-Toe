//*******************************************************************
/*!
\file   Memory_MCU.h
\author Thomas Breuer
\date   25.02.2011
*/

//*******************************************************************
#ifndef _HW_MEMORY_MCU_H
#define _HW_MEMORY_MCU_H

//*******************************************************************
#include "Com/Hardware/Memory/Memory.h"

//*******************************************************************
/*!
\class cHwMemory_MCU

\brief Implementation of ...

\example cHwMemory.cpp
*/
class cHwMemory_MCU : public cHwMemory
{
  public:
    //---------------------------------------------------------------
    /*! Initialize ...
    */
    cHwMemory_MCU( char *filename, DWORD size = 0, BYTE def = 0 );

   //---------------------------------------------------------------
    virtual void lock( ) {}
    virtual void unlock() {}
  private:
    //---------------------------------------------------------------
    virtual void writeByte( DWORD addr,
                            BYTE  data );

    //---------------------------------------------------------------
    virtual BYTE readByte( DWORD addr );


  private:
    //---------------------------------------------------------------
    DWORD *ptr;
    int    fh;

}; //cHwMemory_MCU

#endif
