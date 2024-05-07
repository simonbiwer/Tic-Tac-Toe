//*******************************************************************
/*!
\file   Memory_Flash.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   05.10.2019

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
      // see: RM0410,Reference manual STM32F76xxx/77xxx, ...
      // Table 3. 2 Mbytes Flash memory single bank organization (256 bits read width)
      SECTOR_0  = (0x00<<8)|( 0<<4)|(1<<0), //<! Sector 0,  0x0800 0000,  32K,    0-   32K
      SECTOR_1  = (0x01<<8)|( 1<<4)|(1<<0), //<! Sector 1,  0x0800 8000,  32K,   32-   64K
      SECTOR_2  = (0x02<<8)|( 2<<4)|(1<<0), //<! Sector 2,  0x0801 0000,  32K,   64-   96K
      SECTOR_3  = (0x03<<8)|( 3<<4)|(1<<0), //<! Sector 3,  0x0801 8000,  32K,   92-  128K
			
      SECTOR_4  = (0x04<<8)|( 4<<4)|(4<<0), //<! Sector 4,  0x0802 0000, 128K,  128-  256K

      SECTOR_5  = (0x08<<8)|( 5<<4)|(8<<0), //<! Sector 5,  0x0804 0000, 256K,  256-  512K
      SECTOR_6  = (0x10<<8)|( 6<<4)|(8<<0), //<! Sector 6,  0x0808 0000, 256K,  512-  768K
      SECTOR_7  = (0x18<<8)|( 7<<4)|(8<<0), //<! Sector 7,  0x080C 0000, 256K,  768- 1024K
      SECTOR_8  = (0x20<<8)|( 8<<4)|(8<<0), //<! Sector 8,  0x0810 0000, 256K, 1024- 1280K
      SECTOR_9  = (0x28<<8)|( 9<<4)|(8<<0), //<! Sector 9,  0x0814 0000, 256K, 1280- 1536K
      SECTOR_10 = (0x30<<8)|(10<<4)|(8<<0), //<! Sector 10, 0x0818 0000, 256K, 1536- 1792K
      SECTOR_11 = (0x38<<8)|(11<<4)|(8<<0), //<! Sector 11, 0x081C 0000, 256K, 1792- 2048K
      //           |         |       +- Sector size in times of 32K
      //           |         +--------- Sector ID
      //           +------------------- Sector start address in times of 32K
    } Sector;

  public:
    //---------------------------------------------------------------
    /*! Initialize hardware
        \param sector Flash memory sector
    */
    cHwMemory_Flash( Sector sector );

  //private:
    //---------------------------------------------------------------
    virtual void lock( void );
		
    //---------------------------------------------------------------
    virtual void unlock( void );

    //---------------------------------------------------------------
    virtual void writeByte( DWORD addr,
                            BYTE  data );

    //---------------------------------------------------------------
    virtual BYTE readByte( DWORD addr );

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
