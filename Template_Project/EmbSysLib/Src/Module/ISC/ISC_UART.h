//*******************************************************************
/*!
\file   Module/ISC_UART.h
\author Thomas Breuer
\date   11.12.2014, 17.03.2016
*/

//*******************************************************************
#ifndef _ISC_UART_H
#define _ISC_UART_H

//*******************************************************************
#include "Module/ISC.h"

//*******************************************************************
/*!
\class cISC_UART

\brief ISC transport class with UART hardware

\remark The length of the payload is limited to 64 bytes

\example cISC.cpp
*/
class cISC_UART : public cISC
{
  public:
    //---------------------------------------------------------------
    /*! Instantiate an ISC transport object with UART hardware

        \param uart Reference to UART hardware
        \param crcMode Select CRC calculation mode (FAST or SMALL)
    */
    cISC_UART( cHwUART    &uart,
               cCRC::MODE  crcMode = cCRC::SMALL );

    //---------------------------------------------------------------
    /*! Update the ISC transport object

        Checks, if new data are arrived. In that case ISC copies the
        data to identified data object, sets the new data flag and
        calls the related \b update() method.
    */
    virtual void update( void );

  private:
    //---------------------------------------------------------------
    virtual void writeStream( BYTE  id,
                              BYTE *data,
                              BYTE  size,
                              WORD  crc );

  private:
    //---------------------------------------------------------------
    cHwUART &uart;

    cISC::DATA data;

    bool     error;
    WORD     errorCnt;
    BYTE     idx;
    BYTE     ready;
    BYTE     length;
    BYTE     state;

}; //cISC_UART

#endif
