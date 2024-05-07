//*******************************************************************
/*!
\file   UART.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "UART.h"

//*******************************************************************
//
// cHwUART
//
//*******************************************************************
//-------------------------------------------------------------------
cHwUART::cHwUART( BYTE sizeRxBuf, BYTE sizeTxBuf )

: dataRxBuf( sizeRxBuf ), // initialize both FIFOs
  dataTxBuf( sizeTxBuf )

{
  txReady = true;
}

//-------------------------------------------------------------------
inline void cHwUART::isrRx( void )
{
  BYTE data = getByte(); // read data from hardware

  dataRxBuf << data;     // pipe data into FIFO
}

//-------------------------------------------------------------------
inline void cHwUART::isrTx( void )
{
  BYTE data = 0;

  if( !dataTxBuf.isEmpty() ) // data to been sent?
  {
    dataTxBuf >> data;       // read data from FIFO
    txReady = false;         // set flag before setByte() because
                             // some hardware doesn't support
                             // interrupts and isrTx is called recursiv
    setByte( data );         // write data to hardware
  }
  else
  {
    txReady = true;          // we are ready
  }
}

//-------------------------------------------------------------------
void cHwUART::transmitByte( BYTE data )
{
/*
//TODO (Variante KNX)
  if( dataTxBuf.isFull() ) // wait until FIFO is ready
  {
    txReady = true;
  }
  dataTxBuf << data;          // pipe data into FIFO

  if( txReady )               // at first time, isrTx has to be
                              // called explicit without interrupt
  {
    isrTx();
  }
//-------------------------------------------------------------
*/

  while( dataTxBuf.isFull() ) // wait until FIFO is ready
  {
    if( txReady )             // this case is an error:
                              //   FIFO is full,
                              //   but isrTx is not running
    {
      isrTx();                // call isrTx explicit
    }
                              // else: Data transfer is running,
                              //       we have to wait until complete
  }

  dataTxBuf << data;          // pipe data into FIFO

  if( txReady )               // at first time, isrTx has to be
                              // called explicit without interrupt
  {
    isrTx();
  }
}

//-------------------------------------------------------------------
void cHwUART::set( BYTE data )
{
  transmitByte( data );
}

//-------------------------------------------------------------------
void cHwUART::set( const BYTE *data, BYTE length )
{
  while( length-- )
  {
    transmitByte( *(data++ ) ); // put a character and set pointer to next
  }
}

//-------------------------------------------------------------------
void cHwUART::set( const char *str )
{
  while( *str )       // until end of null terminated string
  {
    transmitByte( *(str++ ) ); // put a character and set pointer to next
  }
}
//-------------------------------------------------------------------
inline bool cHwUART::isTxBufferFull( void )
{
  return( dataTxBuf.isFull() );
}

//-------------------------------------------------------------------
bool cHwUART::get( BYTE *data )
{
  BYTE tmp = 0;

  if( dataRxBuf >> tmp )   // is there a data byte in the FIFO?
  {
    *data = tmp;           // copy data byte to pointer
    return( true );        // yes, we received a data byte
  }
  else
  {
    return( false );       // no data byte received
  }
}

//-------------------------------------------------------------------
BYTE cHwUART::get( void )
{
  BYTE tmp = 0;

  if( get( &tmp) )   // is there a data byte in the FIFO?
  {
    return( tmp );        // yes, we received a data byte
  }
  else
  {
    return( 0 );         // no data byte received
  }
}

//EOF
