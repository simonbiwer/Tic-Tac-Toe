//*******************************************************************
/*!
\file   Gyro_L3GD20.h
\author Thomas Breuer
\date   21.11.2012
*/

//*******************************************************************
#ifndef _HW_SENSOR_GYRO_L3GD20_H
#define _HW_SENSOR_GYRO_L3GD20_H

//*******************************************************************
#include "Com/Hardware/I2Cmaster.h"

//*******************************************************************
/*! 
\class cHwSensGyro_L3GD20

\brief 

\example 

\todo documentation
*/
class cHwSensGyro_L3GD20
{
  public:
    //---------------------------------------------------------------
    /*! Initialization of Gyro hardware 
        \param i2c Reference to I2C interface
        \param hwAddr Sub address of L3GD20 defined by SAD[0] pin
    */
    cHwSensGyro_L3GD20( cHwI2Cmaster &i2c,
	                BYTE          hwAddr );

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
    static const BYTE baseAdr = 0xD4;

}; //cHwSensGyro_L3GD20

#endif
