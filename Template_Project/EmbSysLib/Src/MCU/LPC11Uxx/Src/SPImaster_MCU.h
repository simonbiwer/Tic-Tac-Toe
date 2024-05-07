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
\class cHwSPImaster_N

\brief Implementation of SPI hardware in master mode

\example cHwSPImaster.cpp
*/
class cHwSPImaster_N : public cHwSPImaster
{
  public:
    typedef enum
    {
      SPI0 = 0,
      SPI1
    } SPI_ID;
		
  public:
    //---------------------------------------------------------------
    /*! Initialize SPI hardware
        CS is the chip select of the slave device
    */
    cHwSPImaster_N( SPI_ID       id,           //!< Hardware ID
                    MODE         mode,         //!< Clock rate
                    ClockPolPha  clockPolPhaIn //!< Clock polarity and phase
                   );
 
    //---------------------------------------------------------------
    virtual BYTE transceiveByte( BYTE value = 0 );

    //---------------------------------------------------------------
    virtual BYTE transceiveByteExt( BYTE bit   = 0, 
                                    BYTE value = 0);

  private:
    WORD       cr0;

    LPC_SSPx_Type *ptr;

}; //cHwSPImaster_N

#endif
