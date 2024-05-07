//*******************************************************************
/*!
\file   RAM_MCU.h
\author Thomas Breuer
\date   25.02.2011
*/

//*******************************************************************
#ifndef _HW_RAM_MCU_H
#define _HW_RAM_MCU_H

//*******************************************************************
#include "Hardware/Common/Memory.h"

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

  private:
    //---------------------------------------------------------------
    virtual void writeByte( WORD addr, 
                            BYTE data );

    //---------------------------------------------------------------
    virtual BYTE readByte( WORD addr );

  private:
    //---------------------------------------------------------------
    DWORD *ptr;

}; //cHwMemory_RAM

#endif
