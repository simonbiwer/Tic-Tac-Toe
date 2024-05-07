//*******************************************************************
/*!
\file   I2Cmaster_MCU.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_I2C_MASTER_MCU_H
#define _HW_I2C_MASTER_MCU_H

//*******************************************************************
#include "Com/Hardware/I2C/I2Cmaster.h"

//*******************************************************************
/*! 
\class cHwI2Cmaster_N

\brief Implementation of the I2C interface in master mode

\example cHwI2Cmaster.cpp
*/
class cHwI2Cmaster_N : public cHwI2Cmaster
{
  public:
    //---------------------------------------------------------------
    /*! I2C hardware ID's
    */
    typedef enum
    {
      I2C_1 = 1, //!< Use I2C1 
      I2C_2,     //!< Use I2C2
      I2C_3,     //!< Use I2C3
      I2C_4      //!< Use I2C4
    } I2C_ID;
    
  public:
    //---------------------------------------------------------------
    /*! Initialize I2C hardware
        \param id         Hardware idetification
        \param mode       Operating mode (SCL clock rate selection)
        \param maskIntr 
                        - false: Disable interrupt while data 
                          transfer is running
                        - true: Don't disable interrupt
    */
    cHwI2Cmaster_N( I2C_ID id, 
                    MODE   mode, 
                    BYTE   maskIntr = true );

  private:
    //---------------------------------------------------------------
    virtual BYTE write( BYTE  hwAddr,
                             BYTE *adr,
                             BYTE  sizeAdr,
                             BYTE *data,
                             BYTE  sizeData );
		
    //---------------------------------------------------------------
    virtual BYTE read( BYTE  hwAddr,
                             BYTE *adr,
                             BYTE  sizeAdr,
                             BYTE *data,
                             BYTE  sizeData );
   	
		//---------------------------------------------------------------
    virtual void waitForAckn( MTYPE state ) {};

    //---------------------------------------------------------------
    virtual void start( void ) {};

    //---------------------------------------------------------------
    virtual void stop( void ) {};

    //---------------------------------------------------------------
    virtual void sendAddr( BYTE addr ) {};

    //---------------------------------------------------------------
    virtual void writeByte( BYTE byte ) {};

    //---------------------------------------------------------------
    virtual BYTE readByteAck( void ) { return(0); };

    //---------------------------------------------------------------
    virtual BYTE readByteNack( void ) { return(0); };

  private:
    //---------------------------------------------------------------
    I2C_TypeDef* ptrBase;

}; //cHwI2Cmaster_N

#endif
