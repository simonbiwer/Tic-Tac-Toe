//*******************************************************************
/*!
\file   Acc_ADXL345.h
\author Thomas Breuer
\date   21.11.2012
*/

//*******************************************************************
#ifndef _HW_SENSOR_ACC_ADXL345_H
#define _HW_SENSOR_ACC_ADXL345_H

//*******************************************************************
#include "Com/Hardware/I2C/I2Cmaster.h"

//*******************************************************************
/*! 
\class cHwSensAcc_ADXL345 

\brief 

\example 

\todo documentation
*/
class cHwSensAcc_ADXL345
{
  public:
    //---------------------------------------------------------------
    /*! ??? 
        \param i2c Reference to I2C interface
    */
    cHwSensAcc_ADXL345( cHwI2Cmaster &i2c );

    //---------------------------------------------------------------
    virtual WORD getX( void );
    virtual WORD getY( void );
    virtual WORD getZ( void );

  private:
    //---------------------------------------------------------------
    WORD readWord( BYTE addr );

  private:
    //---------------------------------------------------------------
  cHwI2Cmaster::Device i2c;

    //---------------------------------------------------------------
//    static const BYTE hwAddr = 0x3A;
   static const BYTE hwAddr = 0xA6;

}; //cHwSensAcc_ADXL345

#endif
