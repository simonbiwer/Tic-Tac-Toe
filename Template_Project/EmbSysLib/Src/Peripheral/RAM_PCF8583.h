//*******************************************************************
/*!
\file   RAM_PCF8583.h
\author Thomas Breuer
\date   11.03.2011
*/

//*******************************************************************
#ifndef _HW_RAM_PCF8583_H
#define _HW_RAM_PCF8583_H

//*******************************************************************
#include "Com/Hardware/Memory.h"
#include "Com/Hardware/I2Cmaster.h"

//*******************************************************************
/*!
\class cHwRAM_PCF8583

\brief Implementation of battery buffered RAM PCF8583

\example cHwMemory.cpp
*/
class cHwRAM_PCF8583 : public cHwMemory
{
  public:
    //---------------------------------------------------------------
    /*! Initialize PCF8574, part RAM
        \param i2c    Reference to I2C interface
        \param hwAddr Slave address of PCF8574
    */
    cHwRAM_PCF8583( cHwI2Cmaster &i2c,
                    BYTE          hwAddr );

  private:
    //---------------------------------------------------------------
    virtual void writeByte( DWORD addr,
                            BYTE  data );

    //---------------------------------------------------------------
    virtual BYTE readByte( DWORD addr );

  private:
    //---------------------------------------------------------------
  cHwI2Cmaster::Device i2c;

    //---------------------------------------------------------------
    static const BYTE baseAdr = 0xA0;
    static const BYTE maskAdr = 0x01;

}; //cHwRAM_PCF8583

#endif
