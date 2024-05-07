//*******************************************************************
/*!
\file   SPImaster.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_SPI_MASTER_H
#define _HW_SPI_MASTER_H

//*******************************************************************
#include "Com/Hardware/Port/Port.h"

//*******************************************************************
/*! 
\class cHwSPImaster

\brief Abstract class supporting the SPI hardware in master mode

SPI is a serial communication interface. 
This base class handles data transmit/receive actions \n

\remark Interrupts are disabled during data transfer

Derived classes should at least:
 - initialize the SPI hardware
 - implement \a start() and \a stop() to control transmission 
 - implement \a transceiveByte() to read/write a data byte from/to 
   the hardware
                                                 
\example cHwSPImaster.cpp
*/
class cHwSPImaster
{
  public:
    //---------------------------------------------------------------
    /*! SPI operating mode\n  
    */
    typedef enum
    {
      CR_250kHz  =  0, //!< Clock rate = 250kHz
      CR_500kHz,       //!< Clock rate = 500kHz
      CR_1000kHz,      //!< Clock rate = 1MHz
      CR_2000kHz,      //!< Clock rate = 2MHz
      CR_4000kHz,      //!< Clock rate = 4MHz
      CR_8000kHz       //!< Clock rate = 8MHz
    } MODE;

    //---------------------------------------------------------------
    /*! SPI clock polarioty and phase
    */
    typedef enum
    {
      CPOL_L_CPHA_L = 0x00, //!< SCK low in idle state  & sample data at SCK rising edge 
      CPOL_L_CPHA_H = 0x01, //!< SCK low in idle state  & sample data at SCK falling edge
      CPOL_H_CPHA_L = 0x10, //!< SCK high in idle state & sample data at SCK falling edge
      CPOL_H_CPHA_H = 0x11  //!< SCK high in idle state & sample data at SCK rising edge
      
    } ClockPolPha;

    //---------------------------------------------------------------
    /*! \class Device
        \todo comment missing ...
    */
    class Device
    {
      public:
        //-----------------------------------------------------------
        /*! \todo comment missing ...
            \param spiIn Reference to SPI hardware
            \param CSin  Reference to chip select pin
        */
        Device( cHwSPImaster &spiIn,
                cHwPort      &CS_port_In,
                BYTE          CS_pin_In )
        
        : spi( spiIn ),
          CS( CS_port_In, CS_pin_In )
        {
          CS.setMode( cHwPort::Out );
          CS.set();
        }

        //-----------------------------------------------------------
        /*! \todo comment missing ...
        */
        void start()
        {
          CS.clr();
        }

        //-----------------------------------------------------------
        /*! \todo comment missing ...
        */
        void stop()
        {
          CS.set();
        }
        
        //---------------------------------------------------------------
        /*! Transmit and receive one data byte
            \param data Transmitted data byte
            \return Received data byte
        */
        virtual BYTE transceive( BYTE data = 0 );
        
        //---------------------------------------------------------------
        /*! Transmit and receive multiple data bytes
            \param data Pointer to transmitted data byte
            \param size Number of data bytes
        */
        virtual void transceive( BYTE *data, WORD size );
        
        //---------------------------------------------------------------
        /*! Get one data byte from slave
            \return Received data byte
        */
        virtual BYTE read( void );
        
        //---------------------------------------------------------------
        /*! Get \a size data byte from slave
            \param data Pointer to received data bytes
            \param size Number of data bytes
        */
        virtual void read( BYTE *data, WORD size );
        
        //---------------------------------------------------------------
        /*! Write one data byte to slave
            \param data Transmitted data byte
        */
        virtual void write( BYTE data );

        //---------------------------------------------------------------
        /*! Write one data word (16 bit) to slave, MSB first
            \param data Transmitted data word
        */
        virtual void write( WORD data );

        //---------------------------------------------------------------
        /*! Write \a size data byte to slave
            \param data Pointer to transmitted data bytes
            \param size Number of data bytes
        */
        virtual void write( BYTE *data, WORD size );

        //---------------------------------------------------------------
        /*! Write one data byte with preceding 9th bit to slave
            \param data Transmitted data byte
            \param bit9 Additional 9th bit

            \todo writeExt() wegen MIO7846, ggf besser mit WORD 
                  (0000 0001 dddd dddd)
        */
        virtual void writeExt( BYTE bit9, BYTE data );

        //---------------------------------------------------------------
        /*! Write one data word (16 bit) with  preceding 9th bit to slave, 
            MSB first
            \param data Transmitted data word
            \param bit9 Additional 9th bit to each transmitted byte
        */
        virtual void writeExt( BYTE bit9, WORD data );

      public:
        //-----------------------------------------------------------
        cHwSPImaster &spi;
        cHwPort::Pin  CS;
    };

  protected:
    //---------------------------------------------------------------
    // Standard constructor
    //
    cHwSPImaster( void );
    
  public:
//  private:
/*! \todo Make member private or protected */
    //---------------------------------------------------------------
    // Write data into transmission buffer, wait for transmission 
    // complete and return received data
    // data:   Transmitted data byte
    // return: Received data byte
    //
    virtual BYTE transceiveByte( BYTE data = 0 ) = 0;
    
    //---------------------------------------------------------------
    // Write a single data bit 
    // bit:   Transmitted data bit
    // \todo Kommentar falsch
    //
    virtual BYTE transceiveByteExt( BYTE bit = 0, BYTE data = 0 ) = 0;

}; //cHwSPImaster

#endif
