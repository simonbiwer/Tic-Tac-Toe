//*******************************************************************
/*!
\file   Memory_Flash.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
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

/*!
\todo use parameter for memory size and start address. 
                Clear with paramter "start address". 
                 method returning page size
                 
\todo (all cHwMomory classes): ssize, addr etc. with 32 bit DWORD
         
\todo 16-bit write possible?
     Doku:
     - writeByte will clear the complete memory page, when address points 
       to page start adress
     - writeByte writes only when address matches 0x03 (each fourth adress) 
       => total number of bytes should be a  multiple of 4
     
      // see Datasheet, Table 8 to 11
*/
class cHwMemory_Flash : public cHwMemory
{
  public:
    //---------------------------------------------------------------
    /*! Initialize hardware
        \param startAddress Physical start address of the memory area
               size         Used memory size
    */
    cHwMemory_Flash( DWORD *startAddress, DWORD size );

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
    DWORD *ptr;
    DWORD  dataDoubleWord;
  
}; //cHwMemory_Flash

#endif

