//*******************************************************************
/*!
\file   I2Cslave.h
\author Thomas Breuer
\date   02.03.2011
*/

//*******************************************************************
#ifndef _HW_I2C_SLAVE_H
#define _HW_I2C_SLAVE_H

//*******************************************************************
/*! 
\class cHwI2Cslave

\brief Abstract class supporting the I2C hardware in slave mode

I2C is a serial communication interface in master/slave mode. 
This base class handles data transmit/receive actions. The 
application will become an I2C device \n

Derived classes should at least:
 - initialize the I2C hardware
 - implement an \a isr() and call them in the appropriate ISR
                     
The application has to derive cHwI2CslaveDataHandler. The instance of 
the derived class will then respond to the I2C data transfer interrupt

\example cHwI2Cslave.cpp
*/
class cHwI2Cslave
{
  public:
//*******************************************************************
/*! 
\class DataHandler

\brief Abstract class as interface to cHwI2Cslave

The application has to derive his own class from this interface. 
The derived class must then referred to the cHwI2Cslave object, which 
will call back the receive() and transmit() methods.

\remark The I2C slave acknowledges the request. Because there I2C 
master is waiting for this acknwledge, the receive() and transmit() 
methods are time critical

\example cHwI2Cslave.cpp
*/
class DataHandler
{
  public:
    /*! Call back method, called by cHwI2Cslave object on master 
        write.  
        \param data  Received data byte
        \param id    Number of received byte (repeated master write)
        \remark This method is time critical, because master is waiting ...
    */
    virtual void receive( BYTE data, 
                          BYTE id   ) = 0;

    //---------------------------------------------------------------
    /*! Call back method, called by cHwSPImaster object on master 
        read.  
        \param id  Number of transmitted byte (repeated master read)
        \return    Transmitted data byte
        \remark This method is time critical, because master is waiting ...
    */
    virtual BYTE transmit( BYTE id ) = 0;

    //---------------------------------------------------------------
    /*! Get the expected number of bytes in repeated master read mode.
        The cHwI2Cslave object needs the number while acknoledge a 
        repeated master read
        \remark This method is time critical
        \todo This methode is obsolete, until we have repeated start condition
    */
    //virtual BYTE getSize() = 0;

}; //DataHandler

  protected:
    //---------------------------------------------------------------
    // Initialize I2C hardware in slave mode and install the handler
    // handler:  Reference to the aplication specific 
    //           cHwI2Cslave::DataHandler
    // hwAddr:   Hardware address of this I2C device (LSB = 0)
    //
    cHwI2Cslave( DataHandler &handler,
                 BYTE         hwAddr  );
    
  protected:
    //---------------------------------------------------------------
    DataHandler &handler;
    BYTE         hwAddr;
   
}; //cHwI2Cslave

#endif
