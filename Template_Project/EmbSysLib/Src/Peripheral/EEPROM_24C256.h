//*******************************************************************
/*!
\file   EEPROM_24C256.h
\author Thomas Breuer
\date   25.08.2014
*/

//*******************************************************************
#ifndef _HW_EEPROM_24C256_H
#define _HW_EEPROM_24C256_H

//*******************************************************************
#include "Com/Hardware/Memory.h"
#include "Com/Hardware/I2Cmaster.h"

//*******************************************************************
/*!
\class cHwEEPROM_24C256

\brief Implementation of EEPROM 24C256

\example cHwMemory.cpp
*/
class cHwEEPROM_24C256 : public cHwMemory
{
  public:
    //---------------------------------------------------------------
    /*! Initialize 24C256
        \param i2c    Reference to I2C interface
        \param hwAddr Slave address of 24C256
    */
    cHwEEPROM_24C256( cHwI2Cmaster &i2c,
                      BYTE          hwAddr );

  private:
    //---------------------------------------------------------------
    /*! Unlock memory
    */
    virtual void unlock( void );
    
    //---------------------------------------------------------------
    /*! Lock memory
    */
    virtual void lock( void );
    
    //---------------------------------------------------------------
    virtual void writeByte( DWORD addr,
                            BYTE  data );

    //---------------------------------------------------------------
    virtual BYTE readByte( DWORD addr );

  private:
public:
    //---------------------------------------------------------------
    cHwI2Cmaster::Device i2c;

    //---------------------------------------------------------------
    static const BYTE baseAdr = 0xA0;
    static const BYTE maskAdr = 0x03;

}; //cHwEEPROM_24C256

#endif
