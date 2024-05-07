//*******************************************************************
/*!
\file   SPImaster_MCU.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
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
    //---------------------------------------------------------------
    /*! \enum SPI_ID
        \brief SPI identification
    */
    typedef enum
    {
      SPI_1 = 1,  //!< SPI 1
      SPI_2,      //!< SPI 2
      SPI_3       //!< SPI 3
    } SPI_ID;

  public:
    //---------------------------------------------------------------
    /*! Initialize SPI hardware
        \param id           Hardware selection
               mode         Clock rate
               clockPolPha  Clock polarity and phase
    */
    cHwSPImaster_N( SPI_ID       id,      
                    MODE         mode,       
                    ClockPolPha  clockPolPha );

  private:
    //---------------------------------------------------------------
    virtual BYTE transceiveByte( BYTE value = 0 );

    //---------------------------------------------------------------
    virtual BYTE transceiveByteExt( BYTE bit   = 0,
                                    BYTE value = 0 );

  private:
    //---------------------------------------------------------------
    SPI_TypeDef *ptr;

}; //cHwSPImaster_N

#endif
