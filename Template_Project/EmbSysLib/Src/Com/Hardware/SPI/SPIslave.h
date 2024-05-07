//*******************************************************************
/*!
\file   SPIslave.h
\author Thomas Breuer
\date   02.03.2011
*/

//*******************************************************************
#ifndef _HW_SPI_SLAVE_H
#define _HW_SPI_SLAVE_H

//*******************************************************************
#include "SPIslave.h"

//*******************************************************************
/*! 
\class cHwSPIslave

\brief Abstract class supporting the SPI hardware in slave mode

SPI is a serial communication interface in master/slave mode. 
This base class handles data transmit/receive actions \n

Derived classes should at least:
 - initialize the SPI hardware
 - call \a isr() in the appropriate ISR
                     
The application has to derive cHwSPIslaveDataHandler. The instance of 
the derived class will then respond to the SPI data transfer 

\example cHwSPIslave.cpp
*/
class cHwSPIslave
{
  public:
//*******************************************************************
/*! 
\class cHwSPIslaveDataHandler

\brief Abstract class as interface to cHwSPIslave

The application has to derive a own class from this interface. 
The derived class must then referred to the cHwSPIslave object, which 
will call back the transceive() method. 

\remark Because there is no handshake to the SPI master, the 
transceive() method is time critical

\example cHwSPIslave.cpp
*/
class DataHandler
{
  public:
    //---------------------------------------------------------------
    /*! Call back method, called by cHwSPIslave object.  
        Due to the SPI transfer protocol (shift register), \a data 
        is transmitted to the master at next transfer only
        \param data  Transmitted data byte (next time)
        \return      Received data byte
        \remark This method is time critical, because there is no 
        handshake with the master
    */
    virtual BYTE transceive( BYTE data ) = 0;

}; //DataHandler
     
protected:
    //---------------------------------------------------------------
    // Initialize SPI hardware in slave mode and install the handler
    // handler:  Reference to the aplication specific 
    //           cHwSPIslaveDataHandler
    //
    cHwSPIslave( DataHandler &handler );
    
  protected:
    //---------------------------------------------------------------
    DataHandler &handler;
   
}; //cHwSPIslave

#endif
