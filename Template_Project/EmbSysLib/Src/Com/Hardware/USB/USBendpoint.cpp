//*******************************************************************
/*!
\file   USBendpoint.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "USBendpoint.h"

//*******************************************************************
// 
// cHwUSBendpoint
//
//*******************************************************************
//-------------------------------------------------------------------
cHwUSBendpoint::cHwUSBendpoint( cHwUSB       &usbIn, 
                                cHwUSBinterf *interfIn,
                                BYTE          idIn, 
                                WORD          maxPacketSizeIn,
                                BYTE          attributesIn )
: usb( usbIn )
{
  interf        = interfIn;
  id            = idIn;
  maxPacketSize = maxPacketSizeIn;
  attributes    = attributesIn;
}

//-------------------------------------------------------------------
cHwUSBendpoint::cHwUSBendpoint( cHwUSB &usbIn, 
                                BYTE    idIn, 
                                WORD    maxPacketSizeIn )
: usb( usbIn )
{
  interf        = NULL;
  id            = idIn;
  maxPacketSize = maxPacketSizeIn;
  attributes    = cHwUSBdesc::CONTROL_ENDPOINT;
}

//-------------------------------------------------------------------
void cHwUSBendpoint::in( void )
{
  if( interf && epData.isEmpty() )
  {
    interf->transmit( id, epData );
  }
  
  if( !epData.isEmpty() )
  {
    writeData( ); 
  }
}

//-------------------------------------------------------------------
void cHwUSBendpoint::inCtrl( void )
{
  writeData();
  if( epData.getSize() == 0 && interf )
  {
    interf->transmit( id, epData );
  }
}

//-------------------------------------------------------------------
//! \todo Check Code
void cHwUSBendpoint::out( void )
{
  WORD cnt = 0;
  
  if( interf ) //&& epData.isEmpty()) // new data
  {
    interf->request( id, epData );
  }
  
  cnt = readData( );

  if( interf ) //&& epData.isEmpty())
  {
    if( interf->receive( id, cnt ) != true)
    {
      stall();
    }
  }

////  if( interf  )
////  {
////    interf->out();
////  }
}
    
//-------------------------------------------------------------------
//! \todo Check Code
void cHwUSBendpoint::outCtrl( void )
{
  WORD cnt = readData( );
  if( interf ) //&& epData.isEmpty())
  {
    if( interf->receive( 0x00, cnt ) )
    {
      writeAcknowledge();
    }
    else
    {
      stall();
    }
  }
}

//-------------------------------------------------------------------
WORD cHwUSBendpoint::readData( void ) 
{
  WORD cnt = usb.readEP( id,  
                         epData.getPtr(), 
                         epData.getSize() );
  
  epData.shift( cnt );
  
  return( cnt );
}

//-------------------------------------------------------------------
void cHwUSBendpoint::writeData( void )
{
  WORD cnt = usb.writeEP( id, 
                          epData.getPtr(), 
                          MIN( epData.getSize(), 
                               maxPacketSize ) );
  
  epData.shift( cnt ); 
}

//-------------------------------------------------------------------
void cHwUSBendpoint::writeData( const cDataPointer &epDataIn )
{
  epData.set( epDataIn );
  writeData();
}

//-------------------------------------------------------------------
void cHwUSBendpoint::writeDataLen( const cDataPointer &epDataIn, 
                                   WORD                maxLen )
{
  cDataPointer tmp( epDataIn );
   
  epData.set( tmp.getPtr(), MIN( tmp.getSize(), maxLen ));
  writeData();
}

//-------------------------------------------------------------------
void cHwUSBendpoint::writeAcknowledge( void ) 
{
  usb.writeEP( id, NULL, 0 );
}

//-------------------------------------------------------------------
void cHwUSBendpoint::readAcknowledge( void ) 
{
  BYTE buffer;

  usb.readEP( id, &buffer, 1 );
}

//-------------------------------------------------------------------
void cHwUSBendpoint::setConfiguration( void ) 
{
  usb.configEP( id, maxPacketSize, attributes );
}

//-------------------------------------------------------------------
void cHwUSBendpoint::stall( void )
{
  usb.setStallEP( id );
}

//-------------------------------------------------------------------
void cHwUSBendpoint::clrStall( void )
{
  usb.clrStallEP( id );
}

//-------------------------------------------------------------------
void cHwUSBendpoint::clrFeature( void )
{
  if( interf )
  {
    interf->clrFeature();
  }
}

//EOF
