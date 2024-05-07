//*******************************************************************
/*!
\file   I2Cmaster_MCU.h
\author Thomas Breuer
\date   025.03.2013
*/

//*******************************************************************
#ifndef _HW_I2C_MASTER_MCU_H
#define _HW_I2C_MASTER_MCU_H

//*******************************************************************
#include "Com/Hardware/I2C/I2Cmaster.h"

//*******************************************************************
/*! 
\class cHwI2Cmaster_0

\brief Implementation of the I2C interface in master mode

\example cHwI2Cmaster.cpp
*/
class cHwI2Cmaster_0 : public cHwI2Cmaster
{
  public:
    //---------------------------------------------------------------
    /*! Initialize I2C hardware
        \param maskIntr 
                      - true:  Disable interrupt while data transfer 
                               is running
                      - false: Don't disable interrupt
    */
    cHwI2Cmaster_0( MODE   mode,          //!< SCL clock rate selection
                    BYTE   maskIntr = true
                  );

  private:
    //---------------------------------------------------------------
    virtual void waitForAckn( BYTE state );

    //---------------------------------------------------------------
    virtual void start( void );

    //---------------------------------------------------------------
    virtual void stop( void );

    //---------------------------------------------------------------
    virtual void sendAddr( BYTE addr );

    //---------------------------------------------------------------
    virtual void writeByte( BYTE byte );

    //---------------------------------------------------------------
    virtual BYTE readByteAck( void );

    //---------------------------------------------------------------
    virtual BYTE readByteNack( void );

}; //cHwI2Cmaster_0

#endif
