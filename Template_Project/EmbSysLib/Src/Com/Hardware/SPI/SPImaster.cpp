//*******************************************************************
/*!
\file   SPImaster.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "SPImaster.h"

//*******************************************************************
// 
// cHwSPImaster
//
//*******************************************************************
//-------------------------------------------------------------------
cHwSPImaster::cHwSPImaster( void )
{
  // nothing to do ...
}

//-------------------------------------------------------------------
BYTE cHwSPImaster::Device::transceive(  BYTE    data )
{
  cSystem::disableInterrupt();

  start();

  BYTE ret = spi.transceiveByte( data );
  stop();

  cSystem::enableInterrupt();
  return(ret);
}

//-------------------------------------------------------------------
void cHwSPImaster::Device::transceive( BYTE   *data, 
                                      WORD    size )
{
  cSystem::disableInterrupt();

  start();
  for( WORD i = 0; i < size; i++ )
  {
    data[i] = spi.transceiveByte(data[i]);
  }
  stop();

  cSystem::enableInterrupt();
}

//-------------------------------------------------------------------
inline BYTE cHwSPImaster::Device::read( void )
{
  return( transceive( ) );
}

//-------------------------------------------------------------------
inline void cHwSPImaster::Device::read( BYTE   *data, 
                                WORD    size )
{
  cSystem::disableInterrupt();

  start();
  for( WORD i = 0; i < size; i++ )
  {
    data[i] = spi.transceiveByte();
  }
  stop();

  cSystem::enableInterrupt();
}

//-------------------------------------------------------------------
inline void cHwSPImaster::Device::write( BYTE    data )
{
  transceive( data );
}

//-------------------------------------------------------------------
inline void cHwSPImaster::Device::write(  WORD    data )
{
  cSystem::disableInterrupt();

  start();
  spi.transceiveByte( data >> 8    );
  spi.transceiveByte( data &  0xFF );
  stop();

  cSystem::enableInterrupt();
}

//-------------------------------------------------------------------
inline void cHwSPImaster::Device::write(  BYTE   *data, 
                                 WORD    size )
{
  cSystem::disableInterrupt();

  start();
  for( WORD i = 0; i < size; i++ )
  {
    spi.transceiveByte( data[i] );
  }
  stop();

  cSystem::enableInterrupt();
}

//-------------------------------------------------------------------
inline void cHwSPImaster::Device::writeExt(   BYTE    bit9, 
                                    BYTE    data )
{
  cSystem::disableInterrupt();

  start();
  spi.transceiveByteExt( bit9, data );
  stop();

  cSystem::enableInterrupt();
}

//-------------------------------------------------------------------
inline void cHwSPImaster::Device::writeExt(   BYTE    bit, 
                                    WORD    data )
{
  cSystem::disableInterrupt();

  start();
  spi.transceiveByteExt( bit, data>>8 );
  spi.transceiveByteExt( bit, data &  0xFF );
  stop();

  cSystem::enableInterrupt();
}

//EOF
