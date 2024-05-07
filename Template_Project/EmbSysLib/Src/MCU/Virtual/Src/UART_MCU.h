//*******************************************************************
/*!
\file   UART_MCU.h
\author Thomas Breuer
\date   14.02.2011
*/

//*******************************************************************
#ifndef _HW_UART_MCU_H
#define _HW_UART_MCU_H

//*******************************************************************
#include "Com/Hardware/UART/UART.h"
#include "MCU/Virtual/Sys/UDPclient.h"

#include <windows.h>
//*******************************************************************
/*!
\class cHwUART_Stdio

\brief Emulate an UART/Terminal interface by stdin/stdout

\example cHwUART.cpp
*/
class cHwUART_Stdio : public cHwUART
{
  public:
    //---------------------------------------------------------------
    /*! Initialize stdio as UART interface
        Control keys (arrow keys) are filtered out and mapped to
        an equivalent terminal ESC-sequence.
        Control key are never echoed.
        \param echo true: input is echoed on stdout\n
                    false: no echo
    */
    cHwUART_Stdio( BYTE echo = false );

    //-------------------------------------------------------------------
    // We have to overwrite these functions, because there is no Interrupt!
    //-------------------------------------------------------------------
    //-------------------------------------------------------------------
    virtual bool get( BYTE *c );
    virtual BYTE get( void ) { return( cHwUART::get());};

    //-------------------------------------------------------------------
    virtual void transmitByte( BYTE c );

    //-------------------------------------------------------------------
    //virtual void set( const char *str );

  private:
    //----------------------------------------
    virtual BYTE getByte( void );

    //----------------------------------------
    virtual void setByte( BYTE c );

  private:
    //----------------------------------------
    BYTE echo;
    BYTE ctrlState;

}; //cHwUART_Stdio

//*******************************************************************
/*!
\class cHwUART_File

\brief Emulate an UART interface by file read/write

\example cHwUART.cpp
*/
class cHwUART_File : public cHwUART
{
  public:
    //---------------------------------------------------------------
    /*! Initialize UART interface (file I/O)
        If no file name is specified, stdin/stdout will be used
        \param fileNameRx Name of file with receiving data (optional)
        \param fileNameTx Name of file with transmitting data (optional)
    */
    cHwUART_File( const char *fileNameRx = 0,
                  const char *fileNameTx = 0 );

    //-------------------------------------------------------------------
    // We have to overwrite these functions, because there is no Interrupt!
    //-------------------------------------------------------------------
    //-------------------------------------------------------------------
    virtual bool get( BYTE *c );

    //-------------------------------------------------------------------
    virtual void transmitByte( BYTE c );

  private:
    //-------------------------------------------------------------------
    virtual BYTE getByte( void );

    //-------------------------------------------------------------------
    virtual void setByte( BYTE c );

  public:
    //-------------------------------------------------------------------
  //  static cHwUART *uartPtr;

  private:
    //-------------------------------------------------------------------
    int fhTxD;
    int fhRxD;

}; //cHwUART_File

//*******************************************************************
/*!
\class cHwUART_Serial

\brief

\example cHwUART.cpp
*/
class cHwUART_Serial : public cHwUART
{
  public:
    //---------------------------------------------------------------
    /*!
    */
    cHwUART_Serial( const char *portName = 0 );
void open( const char *portName = 0 );
void close();
		bool isOpen()
		{
		    return( isOpenFlag );
		}

		void setPortName(const char *portName);
		char *getPortName()
		{
		    return(  portName );
		}

    //-------------------------------------------------------------------
    // We have to overwrite these functions, because there is no Interrupt!
    //-------------------------------------------------------------------
    //-------------------------------------------------------------------
    virtual bool get( BYTE *c );


    //-------------------------------------------------------------------
    virtual void transmitByte( BYTE c );
virtual void set( const BYTE *c, BYTE size );

   //-------------------------------------------------------------------
  //  virtual void set( const char *str );

  private:
    //-------------------------------------------------------------------
    virtual BYTE getByte( void );

    //-------------------------------------------------------------------
    virtual void setByte( BYTE c );

  public:
    //-------------------------------------------------------------------
  //  static cHwUART *uartPtr;

  private:
    //-------------------------------------------------------------------
    HANDLE hSerial;
    bool isOpenFlag;

    char portName[33];

}; //cHwUART_Serial

//*******************************************************************
/*!
\class cHwUART_MCU

\brief

\example cHwUART.cpp
*/
class cHwUART_MCU : public cHwUART
{
  public:
    //---------------------------------------------------------------
    class Data
    {
      public:
        BYTE  cmd;
        BYTE  value;
    };

  public:
    //---------------------------------------------------------------
    /*!
    */
    cHwUART_MCU( cNetAddr<4> addr, WORD port );

    //-------------------------------------------------------------------
    // We have to overwrite these functions, because there is no Interrupt!
    //-------------------------------------------------------------------
    //-------------------------------------------------------------------
    virtual bool get( BYTE *c );

    //-------------------------------------------------------------------
    virtual void transmitByte( BYTE c );
//virtual void set( BYTE *c, BYTE size );

   //-------------------------------------------------------------------
  //  virtual void set( const char *str );

  private:
    //-------------------------------------------------------------------
    virtual BYTE getByte( void );

    //-------------------------------------------------------------------
    virtual void setByte( BYTE c );

  public:
    //-------------------------------------------------------------------
  //  static cHwUART *uartPtr;

  private:
    //-------------------------------------------------------------------
    UDPclient   client;

}; //cHwUART_MCU
#endif
