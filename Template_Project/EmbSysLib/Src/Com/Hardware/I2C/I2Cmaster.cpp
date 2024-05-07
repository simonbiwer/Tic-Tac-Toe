//*******************************************************************
/*!
\file   I2Cmaster.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/


//*******************************************************************
#include "I2Cmaster.h"

//*******************************************************************
//
// cHwI2Cmaster
//
//*******************************************************************
//-------------------------------------------------------------------
cHwI2Cmaster::cHwI2Cmaster( BYTE maskIntrIn )
{
  isHardwareOK = true;
  maskIntr     = maskIntrIn;
}

//-------------------------------------------------------------------
BYTE cHwI2Cmaster::Device::read( void )
{
  BYTE dat = 0;

  isErrorFlag |= i2c.read( hwAddr, NULL, 0, &dat, 1 );

  return( dat );
}

//-------------------------------------------------------------------
BYTE cHwI2Cmaster::Device::read( BYTE addr )
{
  BYTE dat = 0;

  isErrorFlag |= i2c.read( hwAddr, &addr, 1, &dat, 1 );

  return( dat );
}

//-------------------------------------------------------------------
BYTE cHwI2Cmaster::Device::read( WORD addr )
{
  BYTE dat        = 0;
  BYTE addrTmp[2] = { (BYTE)(addr>>8),
                      (BYTE)(addr&0xFF) };

  isErrorFlag |= i2c.read( hwAddr, (BYTE *)&addrTmp, 2, &dat, 1 );

  return( dat );
}

//-------------------------------------------------------------------
void cHwI2Cmaster::Device::read( BYTE *data, BYTE size )
{
  isErrorFlag |= i2c.read( hwAddr, NULL, 0, data, size );
}

//-------------------------------------------------------------------
void cHwI2Cmaster::Device::read( BYTE addr, BYTE *data, BYTE size )
{
  isErrorFlag |= i2c.read( hwAddr, &addr, 1, data, size );
}

//-------------------------------------------------------------------
void cHwI2Cmaster::Device::read( WORD addr, BYTE *data, BYTE size )
{
  BYTE addrTmp[2] = { (BYTE)(addr>>8),
                      (BYTE)(addr&0xFF) };

  isErrorFlag |= i2c.read( hwAddr, addrTmp, 2, data, size );
}

//-------------------------------------------------------------------
void cHwI2Cmaster::Device::write( BYTE data )
{
  isErrorFlag |= i2c.write( hwAddr, &data, 1, NULL, 0 );
}

//-------------------------------------------------------------------
void cHwI2Cmaster::Device::write( BYTE addr, BYTE data )
{
  isErrorFlag |= i2c.write( hwAddr, &addr, 1, &data, 1 );
}

//-------------------------------------------------------------------
void cHwI2Cmaster::Device::write( WORD addr, BYTE data )
{
  BYTE addrTmp[2] = { (BYTE)(addr>>8),
                      (BYTE)(addr&0xFF) };

  isErrorFlag |= i2c.write( hwAddr, (BYTE*)&addrTmp, 2, &data, 1 );
}

//-------------------------------------------------------------------
void cHwI2Cmaster::Device::write( BYTE *data, BYTE size )
{
  isErrorFlag |= i2c.write( hwAddr, data, size, NULL, 0 );
}

//-------------------------------------------------------------------
void cHwI2Cmaster::Device::write( BYTE addr, BYTE *data, BYTE size )
{
  isErrorFlag |= i2c.write( hwAddr, &addr, 1, data, size );
}

//-------------------------------------------------------------------
void cHwI2Cmaster::Device::write( WORD addr, BYTE *data, BYTE size )
{
  BYTE addrTmp[2] = { (BYTE)(addr>>8),
                      (BYTE)(addr&0xFF) };

  isErrorFlag |= i2c.write( hwAddr, addrTmp, 2, data, size );
}

//-------------------------------------------------------------------
BYTE cHwI2Cmaster::Device::isError( void )
{
  BYTE ret = isErrorFlag;

  isErrorFlag = false;

  return( ret );
}

//-------------------------------------------------------------------
BYTE cHwI2Cmaster::write( BYTE  hwAddr,
                          BYTE *adr,
                          BYTE  sizeAdr,
                          BYTE *data,
                          BYTE  sizeData )
{

  BYTE i = 0;
  isHardwareOK = true;

  if( maskIntr )
    cSystem::disableInterrupt();

  if( sizeAdr || sizeData )
  {
    start();
    sendAddr( hwAddr ); // master write
    for( i=0; i< sizeAdr; i++ )
    {
       writeByte( adr[i] );
    }
    for( i=0; i< sizeData; i++ )
    {
       writeByte( data[i] );
    }
  }

  stop();

  if( maskIntr )
    cSystem::enableInterrupt();


  return( !isHardwareOK );
}

//-------------------------------------------------------------------
BYTE cHwI2Cmaster::read( BYTE  hwAddr,
                         BYTE *adr,
                         BYTE  sizeAdr,
                         BYTE *data,
                         BYTE  sizeData )
{
  BYTE i = 0;

  isHardwareOK = true;

  if( maskIntr )
    cSystem::disableInterrupt();

  if( sizeAdr )
  {
    start();
    sendAddr( hwAddr ); // master write
    for( i=0; i< sizeAdr; i++ )
    {
       writeByte( adr[i] );
    }
  }

  if( sizeData )
  {
    start();
    sendAddr( hwAddr | 0x01 ); // master read
    for( i=0; i < sizeData - 1; i++ )
    {
      data[i] = readByteAck();
    }
    data[i] = readByteNack();
  }

  stop();

  if( maskIntr )
    cSystem::enableInterrupt();

  return( !isHardwareOK );
}

//*******************************************************************
//
// cHwI2Cmaster_Emul
//
//*******************************************************************
//-------------------------------------------------------------------
cHwI2Cmaster_Emul::cHwI2Cmaster_Emul( cHwPort::Pin &pinSCL_In,
                                      cHwPort::Pin &pinSDA_In,
                                      MODE          mode )

: cHwI2Cmaster( false),
  pinSCL      ( pinSCL_In ),
  pinSDA      ( pinSDA_In )

{
  pinSCL.set();
  pinSDA.set();
  pinSCL.setMode( cHwPort::OutOD );
  pinSDA.setMode( cHwPort::OutOD );

  switch( mode )
  {
    default:
    case CR_10kHz:     Twait = 33; break;
    case CR_50kHz:     Twait =  6; break;
    case CR_100kHz:    Twait =  3; break;
    case CR_400kHz:    Twait =  1; break;
    case CR_1000kHz:   Twait =  0; break;
  }
}

//-------------------------------------------------------------------
void cHwI2Cmaster_Emul::wait( void )
{
  cSystem::delayMicroSec( Twait );
}

//-------------------------------------------------------------------
void cHwI2Cmaster_Emul::waitForAckn( void )
{
  WORD i= 0xFFFF;

  while( (--i) && pinSDA.get() ); // wait for ACK

  if( i == 0 )
  {
    isHardwareOK = false;
  //  stop();
  }
  else
  {
    isHardwareOK = true;
  }
}

//-------------------------------------------------------------------
// START-Condition: Fallende Flanke SDA während SCL = High
void cHwI2Cmaster_Emul::start( void )
{
  wait();
  pinSDA.set();
  wait();
  pinSCL.set();
  wait();
  pinSDA.clr();
  wait();
  pinSCL.clr();
  wait();

}

//-------------------------------------------------------------------
// STOP-Condition: Steigende Flanke SDA während SCL = High
void cHwI2Cmaster_Emul::stop( void )
{
  wait();
  pinSDA.clr();
  wait();
  pinSCL.set();
  wait();
  pinSDA.set();
  wait();
  pinSCL.clr();
  wait();
  pinSCL.set();
}

//-------------------------------------------------------------------
void cHwI2Cmaster_Emul::sendAddr( BYTE addr )
{
  writeByte( addr );
}

//-------------------------------------------------------------------
void cHwI2Cmaster_Emul::writeByte( BYTE byte )
{
  wait();
  pinSCL.clr();
  for( BYTE mask = 0x80; mask; mask >>= 1 )
  {
    wait();
    pinSDA.set( byte & mask );

    // raising edge on SCL  0 -> 1 -> 0
    wait();
    pinSCL.set();
    wait();
    pinSCL.clr();
  }

  wait();
  pinSDA.set();

  wait();
  waitForAckn();

  wait();
  pinSCL.set();
  wait();
  pinSCL.clr();
}

//-------------------------------------------------------------------
BYTE cHwI2Cmaster_Emul::readByteNack(void) // read with no acknowledge
{
  BYTE byte = 0;

  wait();
  pinSDA.set();

  for (BYTE mask=0x80; mask ; mask >>= 1)
  {
    wait();
    pinSCL.set();
    wait();
    byte |= (pinSDA.get() ? mask : 0 );
    wait();
    pinSCL.clr();
  }

  pinSDA.set(); // here: NAK

  // raising edge on SCL  0 -> 1 -> 0
  wait();
  pinSCL.set();
  wait();
  pinSCL.clr();
  wait();
  pinSDA.set();
  wait();

  return byte;
}


//-------------------------------------------------------------------
BYTE cHwI2Cmaster_Emul::readByteAck(void) // read with acknowledge
{
  BYTE byte = 0;

  wait();
  pinSDA.set();

  for (BYTE mask=0x80; mask ; mask >>= 1)
  {
    wait();
    pinSCL.set();
    wait();
    byte |= (pinSDA.get() ? mask : 0 );
    wait();
    pinSCL.clr();
  }

  pinSDA.clr(); // here: ACKN

  // raising edge on SCL  0 -> 1 -> 0
  wait();
  pinSCL.set();

  wait();
  pinSCL.clr();
  pinSDA.set();

  return byte;
}

//EOF
