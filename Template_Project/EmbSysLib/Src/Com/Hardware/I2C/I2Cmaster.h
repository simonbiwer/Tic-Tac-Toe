//*******************************************************************
/*!
\file   I2Cmaster.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_I2C_MASTER_H
#define _HW_I2C_MASTER_H

//*******************************************************************
#include "Com/Hardware/Port/Port.h"

//*******************************************************************
/*!
\class cHwI2Cmaster

\brief Abstract class supporting the I2C hardware in master mode

I2C is a serial communication interface.
This base class handles data transmit and receive actions \n

\remark Interrupts are disabled during data transfer

Derived classes should at least:
 - initialize the I2C hardware
 - implement \a start() and \a stop() to control transmission
 - implement \a sendAddr(), \a writeByte() and \a readByteNack()
   to read/write a data byte from/to hardware

\example cHwI2Cmaster.cpp
*/
class cHwI2Cmaster
{
  public:
    //---------------------------------------------------------------
    /*! I2C clock rate
    */
    typedef enum
    {
      CR_10kHz  = 0, //!<  clock rate =   10 kHz (SCL)
      CR_50kHz     , //!<  clock rate =   50 kHz (SCL)
      CR_100kHz    , //!<  clock rate =  100 kHz (SCL)
      CR_400kHz    , //!<  clock rate =  400 kHz (SCL)
      CR_1000kHz     //!<  clock rate = 1000 kHz (SCL)
    } MODE;

  protected:
    //---------------------------------------------------------------
    // Standard constructor
    //
    cHwI2Cmaster( BYTE maskIntrIn = true );

  public:
    //---------------------------------------------------------------
    /*! \todo comment missing ...
    */
    //---------------------------------------------------------------
    class Device
    {
      public:
        //-----------------------------------------------------------
        /*! \todo comment missing ...
        */
        //-----------------------------------------------------------
        Device( cHwI2Cmaster &i2cIn,     //!< Reference to I2C hardware
                BYTE          hwAddrIn   //!< Device's hardware address
              )

        : i2c( i2cIn)

        {
          hwAddr = hwAddrIn;
          isErrorFlag = false;
        }

        //---------------------------------------------------------------
        /*! \todo comment missing ...
            \return Received data byte
        */
        virtual BYTE read( void );

         //---------------------------------------------------------------
        /*! Write an adress to the device and get back a data byte.
            \param  addr Memory or register adress of the device
            \return Received data byte
        */
        virtual BYTE read( BYTE addr );

         //---------------------------------------------------------------
        /*! Write an adress to the device and get back a data byte.
            \param  addr Memory or register adress of the device
            \return Received data byte
        */
        virtual BYTE read( WORD addr );

        //---------------------------------------------------------------
        /*! \todo comment missing ...
            \param  data Pointer to data array
            \param  size Size of data array
        */
        virtual void read( BYTE *data, BYTE size   );

        //---------------------------------------------------------------
        /*! Write an adress to the device and get back a data byte.
            \param addr Memory or register adress of the device
            \param data Pointer to data array
            \param size Size of data array
        */
        virtual void read( BYTE addr, BYTE *data, BYTE size );

        //---------------------------------------------------------------
        /*! Write an adress to the device and get back a data byte.
            \param addr Memory or register adress of the device
            \param data Pointer to data array
            \param size Size of data array
        */
        virtual void read( WORD addr, BYTE *data, BYTE size );

        //---------------------------------------------------------------
        /*! Write a byte to the device
        */
        virtual void write( BYTE data  //!< Transmitted data byte
                          );

        //---------------------------------------------------------------
        /*! Write first an address and second a data byte.
        */
        virtual void write( BYTE addr,  //!< Memory or register adress of the device
                            BYTE data   //!< Transmitted data byte
                          );

        //---------------------------------------------------------------
        /*! Write first an address and second a data byte.
        */
        virtual void write( WORD addr,  //!< Memory or register adress of the device
                            BYTE data   //!< Transmitted data byte
                          );

        //---------------------------------------------------------------
        /*! Write first an address and second a data byte.
        */
        virtual void write( BYTE *data, //!< Pointer to transmitted data array
                            BYTE size   //!< Size of data array
                          );

        //---------------------------------------------------------------
        /*! Write first an address and second a data byte.
        */
        virtual void write( BYTE addr,  //!< Memory or register adress of the device
                            BYTE *data, //!< Pointer to transmitted data array
                            BYTE size   //!< Size of data array
                          );

        //---------------------------------------------------------------
        /*! Write first an address and second a data byte.
        */
        virtual void write( WORD addr,  //!< Memory or register adress of the device
                            BYTE *data, //!< Pointer to transmitted data array
                            BYTE size   //!< Size of data array
                          );

        //---------------------------------------------------------------
        /*! Check, if an error occurred
            Returns internal error flag. This flag is reseted by next
            call of \a read() or \a write()
            \return
                    - true:  Error, previous transfer was aborted
                    - false: No error
        */
        virtual BYTE isError( void );

        cHwI2Cmaster &i2c;
        BYTE          hwAddr;
        BYTE isErrorFlag;
    };

  protected:
    //---------------------------------------------------------------
    BYTE isHardwareOK;
    BYTE maskIntr;


  protected:
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
  private:
    //---------------------------------------------------------------
    // Start a I2C transfer.
    // Send Start-Condition and wait until ready
    //
    virtual void start( void ) = 0;

    //---------------------------------------------------------------
    // Stop I2C transfer
    // Send Stop-Condition
    //
    virtual void stop( void ) = 0;

    //---------------------------------------------------------------
    // Send hwAddr (slave) with added R/W flag, wait for acknowledge
    // hwAddr:  Device's hardware adress
    //          (master write: LSB = 0, master read: LSB = 1)
    //
    virtual void sendAddr( BYTE hwAddr ) = 0;

    //---------------------------------------------------------------
    // Send data byte and wait for acknowledge
    // data:  Transmitted data byte
    //
    virtual void writeByte( BYTE data ) = 0;

    //---------------------------------------------------------------
    // Wait for received data byte and return it
    // return: Received data byte
    //
    virtual BYTE readByteAck( void ) = 0;

    //---------------------------------------------------------------
    // Wait for received data byte and return it
    // return: Received data byte
    //
    virtual BYTE readByteNack( void ) = 0;

}; //cHwI2Cmaster

//*******************************************************************
/*!
\class cHwI2Cmaster_Emul

\brief Implementation of the I2C interface in master mode

\example cHwI2Cmaster.cpp
*/
class cHwI2Cmaster_Emul : public cHwI2Cmaster
{
  public:
    //---------------------------------------------------------------
    /*! Initialize I2C hardware.\n

        \param pinSCL pin number SCL
        \param pinSDA pin number SDA
        \param mode   Operating mode and baud rate

    */
    cHwI2Cmaster_Emul( cHwPort::Pin &pinSCL,
                       cHwPort::Pin &pinSDA,
                       MODE          mode );

  private:
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

    //---------------------------------------------------------------
    // Local method, wait until slave is responding
    //
    virtual void waitForAckn( void );

    //---------------------------------------------------------------
    virtual void wait( void );

  private:
    //---------------------------------------------------------------
    volatile BYTE *ptrIn;
    volatile BYTE *ptrDir;
    volatile BYTE *ptrOut;

    WORD Twait;

    BYTE maskSCL;
    BYTE maskSDA;

    cHwPort::Pin &pinSCL;
    cHwPort::Pin &pinSDA;

}; //cHwI2Cmaster_Emul

#endif
