//*******************************************************************
/*!
\file   USBdesc.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "USBdesc.h"

//*******************************************************************
//
// cHwUSBdesc
//
//*******************************************************************
//-------------------------------------------------------------------
cDataPointer cHwUSBdesc::getDescriptorDevice( void )
{
  WORD id  = getId( DEVICE, 0, 0, 0 );
  
  cHwUSBdesc::cDevice *ptr 
    = (cHwUSBdesc::cDevice *)getDescriptor( id );
  
  if( ptr )
  {
    return( cDataPointer( (BYTE*)ptr, ptr->bLength ) );
  }
  return( cDataPointer() );
}

//-------------------------------------------------------------------
cDataPointer cHwUSBdesc::getDescriptorConfig( BYTE confId )
{
  WORD id = getId( CONFIG, confId, 0, 0 );
  
  cHwUSBdesc::cConfiguration *ptr 
    = (cHwUSBdesc::cConfiguration *)getDescriptor( id );
  
  if( ptr )
  {
    return( cDataPointer( (BYTE*)ptr, ptr->wTotalLength ) );
  }
  return( cDataPointer() );
}

//-------------------------------------------------------------------
cDataPointer cHwUSBdesc::getDescriptorInterface( BYTE confId, 
                                                 BYTE interfId )
{
  WORD id = getId( INTERF, confId, interfId, 0 );
  
  cHwUSBdesc::cInterface *ptr 
    = (cHwUSBdesc::cInterface *)getDescriptor( id );

  if( ptr )
  {
    return( cDataPointer( (BYTE*)ptr, ptr->bLength ) );
  }
  return( cDataPointer() );
}

//-------------------------------------------------------------------
cDataPointer cHwUSBdesc::getDescriptorEndpoint( BYTE confId, 
                                                BYTE interfId, 
                                                BYTE epId )
{
  WORD id = getId( ENDPOINT, confId, interfId, epId );
  
  cHwUSBdesc::cEndpoint *ptr 
    = (cHwUSBdesc::cEndpoint *)getDescriptor( id );

  if( ptr )
  {
    return( cDataPointer( (BYTE*)ptr, ptr->bLength ) );
  }
  return( cDataPointer() );
}

//-------------------------------------------------------------------
cDataPointer cHwUSBdesc::getDescriptorHID( BYTE confId, 
                                           BYTE interfId, 
                                           BYTE hidId )
{
  WORD id = getId( CLASS, confId, interfId, hidId );
  
  cHwUSBdesc::cHID *ptr 
    = (cHwUSBdesc::cHID *)getDescriptor( id );

  if( ptr )
  {
    return( cDataPointer( (BYTE*)ptr, ptr->bLength ) );
  }
  return( cDataPointer() );
}

//-------------------------------------------------------------------
cDataPointer cHwUSBdesc::getDescriptorHIDreport( BYTE confId, 
                                                 BYTE interfId, 
                                                 BYTE hidId )
{
  WORD id = getId( REPORT, confId, interfId, hidId );
  
  cHwUSBdesc::cReport *ptr 
    = (cHwUSBdesc::cReport *)getDescriptor( id );

  if( ptr )
  {
    return( cDataPointer( (BYTE*)ptr+2, ptr->bLength-2 ) );  // skip first WORD (bLength)
  }
  return( cDataPointer() );
}

//-------------------------------------------------------------------
cDataPointer cHwUSBdesc::getDescriptorString( BYTE strId )
{
  WORD id = getId( STRING, 0, 0, strId );
  
  cHwUSBdesc::cString *ptr 
    = (cHwUSBdesc::cString *)getDescriptor( id );

  if( ptr )
  {
    return( cDataPointer( (BYTE*)ptr, ptr->bLength ) ); 
  }
  return( cDataPointer() );
}

//-------------------------------------------------------------------
BYTE cHwUSBdesc::getMaxPacketSize0( void )
{
  cHwUSBdesc::cDevice *ptr 
    = (cHwUSBdesc::cDevice *)cHwUSBdesc::getDescriptorDevice();
  
  if( ptr )
    return( ptr->bMaxPacketSize0 );
  return( 0 );
}

//-------------------------------------------------------------------
BYTE cHwUSBdesc::getConfigDeviceStatus( BYTE confId )
{
  cHwUSBdesc::cConfiguration *ptr 
    = (cHwUSBdesc::cConfiguration *)cHwUSBdesc::getDescriptorConfig( confId );

  BYTE ret = 0;

  if( ptr )
  {
    if( ptr->bmAttributes & USB_CONFIG_SELF_POWERED )
    {
      ret |= USB_STATUS_BIT_SELF_POWERED;
    }
    if( ptr->bmAttributes & USB_CONFIG_REMOTE_WAKEUP )
    {
      ret |= USB_STATUS_BIT_REMOTE_WAKEUP;
    }
  }
  return( ret );      
}

//EOF
