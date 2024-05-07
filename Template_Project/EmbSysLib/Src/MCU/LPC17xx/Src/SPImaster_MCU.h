//*******************************************************************
/*!
\file   SPImaster_MCU.h
\author Thomas Breuer
\date   02.03.2011
*/

//*******************************************************************
#ifndef _HW_SPI_MASTER_MCU_H
#define _HW_SPI_MASTER_MCU_H

//*******************************************************************
#include "Com/Hardware/SPI/SPImaster.h"

//*******************************************************************
/*! 
\class cHwSPImaster_0

\brief Implementation of SPI hardware in master mode

\example cHwSPImaster.cpp
*/
class cHwSPImaster_0 : public cHwSPImaster
{
  public:
    //---------------------------------------------------------------
    /*! Initialize SPI hardware
        CS is the chip select of the slave device
    */
    cHwSPImaster_0( MODE         mode,          //!< Clock rate
                    ClockPolPha  clockPolPhaIn
);
 
    //---------------------------------------------------------------
    virtual BYTE transceiveByte( BYTE value = 0 );

    //---------------------------------------------------------------
    virtual BYTE transceiveByteExt( BYTE bit   = 0, 
                                    BYTE value = 0);


}; //cHwSPImaster_0

//*******************************************************************
/*! 
\class cHwSPImaster_1

\brief Implementation of SPI hardware in master mode

\example cHwSPImaster.cpp
*/
class cHwSPImaster_1 : public cHwSPImaster
{
  public:
    //---------------------------------------------------------------
    /*! Initialize SPI hardware
        CS is the chip select of the slave device
    */
    cHwSPImaster_1( MODE         mode,          //!< Clock rate 
                    ClockPolPha  clockPolPhaIn
                  );
 
    //---------------------------------------------------------------
    virtual BYTE transceiveByte( BYTE value = 0 );

    //---------------------------------------------------------------
    virtual BYTE transceiveByteExt( BYTE bit   = 0, 
                                    BYTE value = 0);

       
}; //cHwSPImaster_1

#endif
