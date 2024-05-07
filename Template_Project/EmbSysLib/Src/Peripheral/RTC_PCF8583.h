//*******************************************************************
/*!
\file   RTC_PCF8583.h
\author Thomas Breuer
\date   11.03.2011
*/

//*******************************************************************
#ifndef _HW_RTC_PCF8583_H
#define _HW_RTC_PCF8583_H

//*******************************************************************
#include "Com/Hardware/RTC.h"
#include "Com/Hardware/I2Cmaster.h"

//*******************************************************************
/*!
\class cHwRTC_PCF8583

\brief Implementation of the real time clock (RTC) PCF8583

\example cHwRTC_PCF8583.cpp
*/
class cHwRTC_PCF8583 : public cHwRTC
{
  public:
    //---------------------------------------------------------------
    /*! Initialize PCF8574, part RTC
        \param i2c    Reference to I2C interface
        \param hwAddr Slave address of PCF8574
    */
    cHwRTC_PCF8583( cHwI2Cmaster &i2c, BYTE hwAddr );

    //---------------------------------------------------------------
    virtual void set( const cHwRTC::Properties &clock );

    //---------------------------------------------------------------
    virtual BYTE get( cHwRTC::Properties &clock );

  private:
    //---------------------------------------------------------------
    // Convert BCD coded number into dual coded
    // bcd: number to convert
    BYTE BCD_2_Dual( BYTE bcd );

    //---------------------------------------------------------------
    // Convert dual coded number into BCD coded
    // dual: number to convert
    BYTE Dual_2_BCD( BYTE dual );

    //----------------------------------------
  cHwI2Cmaster::Device i2c;

    static const BYTE baseAdr = 0xA0;
    static const BYTE maskAdr = 0x01;

}; //cHwRTC_PCF8583

#endif
