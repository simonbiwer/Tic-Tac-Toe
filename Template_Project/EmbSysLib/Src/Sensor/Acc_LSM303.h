//*******************************************************************
/*!
\file   Acc_LSM303.h
\author Thomas Breuer
\date   21.11.2012
*/

//*******************************************************************
#ifndef _HW_SENSOR_ACC_LSM303_H
#define _HW_SENSOR_ACC_LSM303_H

TODO: Unterschied LM303 und LM303D ???
//*******************************************************************
#include "Com/Hardware/I2C/I2Cmaster.h"

//*******************************************************************
/*! 
\class cHwSensAcc_LSM303 

\brief 

\example 

\todo documentation
*/
class cHwSensAcc_LSM303
{
  public:
    //---------------------------------------------------------------
    /*! ??? 
        \param i2c Reference to I2C interface
    */
    cHwSensAcc_LSM303( cHwI2Cmaster &i2c );

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
    static const BYTE hwAddr = 0x3A;

}; //cHwSensAcc_LSM303

#endif
