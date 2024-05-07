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
\class cHwMemory_Flash

\brief Implementation of the Flash-RAM as a cHwMemory class

\example cHwMemory.cpp
*/
class cHwMemory_Flash : public cHwMemory
{
  public:
    //---------------------------------------------------------------
    typedef enum
    {
      // see: RM0090,Reference manual STM32F405xx/07xx, ...
      // Table 5. Flash module organization (STM32F40x and STM32F41x)
      SECTOR_0  = (0x00<<8)|( 0<<4)|(1<<0), //<! Sector 0,  0x0800 0000,  16K,   0-  16K
      SECTOR_1  = (0x01<<8)|( 1<<4)|(1<<0), //<! Sector 1,  0x0800 4000,  16K,  16-  32K
      SECTOR_2  = (0x02<<8)|( 2<<4)|(1<<0), //<! Sector 2,  0x0800 8000,  16K,  32-  48K
      SECTOR_3  = (0x03<<8)|( 3<<4)|(1<<0), //<! Sector 3,  0x0800 C000,  16K,  48-  64K
      SECTOR_4  = (0x04<<8)|( 4<<4)|(4<<0), //<! Sector 4,  0x0801 0000,  64K,  64- 128K

      SECTOR_5  = (0x08<<8)|( 5<<4)|(8<<0), //<! Sector 5,  0x0802 0000, 128K, 128- 256K
      SECTOR_6  = (0x10<<8)|( 6<<4)|(8<<0), //<! Sector 6,  0x0804 0000, 128K, 256- 384K
      SECTOR_7  = (0x18<<8)|( 7<<4)|(8<<0), //<! Sector 7,  0x0806 0000, 128K, 384- 512K

      SECTOR_8  = (0x20<<8)|( 8<<4)|(8<<0), //<! Sector 8,  0x0808 0000, 128K, 512- 640K
      SECTOR_9  = (0x28<<8)|( 9<<4)|(8<<0), //<! Sector 9,  0x080A 0000, 128K, 640- 768K
      SECTOR_10 = (0x30<<8)|(10<<4)|(8<<0), //<! Sector 10, 0x080C 0000, 128K, 768- 896K
      SECTOR_11 = (0x38<<8)|(11<<4)|(8<<0), //<! Sector 11, 0x080E 0000, 128K, 896-1024K
      //          |         |      +-- Sector size in times of 16K
      //          |         +--------- Sector ID
      //          +------------------- Sector start address in times of 16K
    } Sector;

  public:
    //---------------------------------------------------------------
    /*! Initialize hardware
        \param sector Flash memory sector
    */
    cHwMemory_Flash( Sector sector );

  //private:
    //---------------------------------------------------------------
    virtual void writeByte( DWORD addr,
                            BYTE  data );

    //---------------------------------------------------------------
    virtual BYTE readByte( DWORD addr );

    //---------------------------------------------------------------
    virtual void lock( ) {}
    virtual void unlock() {}

  public:
    //---------------------------------------------------------------
    virtual void clear( DWORD offset = 0 );

  protected:
    //---------------------------------------------------------------
    BYTE  *ptr;

  private:
    //---------------------------------------------------------------
    BYTE   sectorID;
    DWORD  dataDoubleWord;

}; //cHwMemory_Flash

#endif
