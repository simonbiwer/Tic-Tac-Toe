//*******************************************************************
/*!
\file   USBctrl.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.

\todo Handle Event "out stall" and "in stall"
*/

//*******************************************************************
#include "USBctrl.h"

//*******************************************************************
//
// cHwUSBctrl
//
//*******************************************************************
//-------------------------------------------------------------------
cHwUSBctrl::cHwUSBctrl(cHwUSB &usbPtr)

: usb  ( usbPtr ),
  epIN ( usbPtr, 0x80, usb.desc.getMaxPacketSize0() ),
  epOUT( usbPtr, 0x00, usb.desc.getMaxPacketSize0() )
  
{
  DeviceStatus = usb.desc.getConfigDeviceStatus( 1 );
}

//*******************************************************************
//*******************************************************************
//-------------------------------------------------------------------
void cHwUSBctrl::setup()
{
  WORD cnt = usb.readEP( 0x00, (BYTE *)&setupData, sizeof(setupData) );
                      // ^--- this is a control endpoint, we read from 0x00

  if( cnt ==  sizeof( setupData ) )
  {
    switch( setupData.reqRecipient() )
    {
      case REQ_RECIPIENT_DEVICE:     ReqDevice   (); return;
      case REQ_RECIPIENT_INTERFACE:  ReqInterface(); return;
      case REQ_RECIPIENT_ENDPOINT:   ReqEndpoint (); return;
    }
  }
  Stall();
}

//-------------------------------------------------------------------
void cHwUSBctrl::in()
{
  //! \todo if( setupData.reqDir() == REQ_DIR_DEVICE_TO_HOST )
  {
    switch(setupData.reqRecipient())
    {
      case REQ_RECIPIENT_DEVICE:    epIN.writeData(); return;
      case REQ_RECIPIENT_INTERFACE: epIN.inCtrl();    return;
      case REQ_RECIPIENT_ENDPOINT:                    return;
    }
  }
}

//-------------------------------------------------------------------
void cHwUSBctrl::out()
{
  if( setupData.reqDir() == REQ_DIR_HOST_TO_DEVICE )
  {
    switch( setupData.reqRecipient() )
    {
      case REQ_RECIPIENT_DEVICE:                     return;
      case REQ_RECIPIENT_INTERFACE: epOUT.outCtrl(); return;
      case REQ_RECIPIENT_ENDPOINT:                   return;
    }
  }
}

//*******************************************************************
// Handle requests
//*******************************************************************
//-------------------------------------------------------------------
__inline void cHwUSBctrl::ReqDevice()
{
  switch( setupData.reqType() )
  {
    case REQ_TYPE_STANDARD:
      switch( setupData.request() )
      {
        case REQUEST_GET_STATUS:        ReqDeviceStd_GetStatus();        return;
        case REQUEST_CLR_FEATURE:       break;                           // not supported
        case REQUEST_RESERVED_0:        break;                           // not supported
        case REQUEST_SET_FEATURE:       break;                           // not supported
        case REQUEST_RESERVED_1:        break;                           // not supported
        case REQUEST_SET_ADDRESS:       ReqDeviceStd_SetAddress();       return;
        case REQUEST_GET_DESCRIPTOR:    ReqDeviceStd_GetDescriptor();    return;
        case REQUEST_SET_DESCRIPTOR:    break;                           // not supported
        case REQUEST_GET_CONFIGURATION: ReqDeviceStd_GetConfiguration(); return;
        case REQUEST_SET_CONFIGURATION: ReqDeviceStd_SetConfiguration(); return;
        case REQUEST_GET_INTERFACE:     break;                           // not supported
        case REQUEST_SET_INTERFACE:     break;                           // not supported
        case REQUEST_SYNC_FRAME:        break;                           // not supported
      }
      break;

    case REQ_TYPE_CLASS:
      break;

    case REQ_TYPE_VENDOR:
      break;
  }
  Stall();
}

//-------------------------------------------------------------------
__inline void cHwUSBctrl::ReqInterface()
{
  switch( setupData.reqType() )
  {
    case REQ_TYPE_STANDARD:
      switch( setupData.request() )
      {
        case REQUEST_GET_STATUS:        ReqInterfaceStd_GetStatus();     return;
        case REQUEST_CLR_FEATURE:       break;                           // not supported
        case REQUEST_RESERVED_0:        break;                           // not supported
        case REQUEST_SET_FEATURE:       break;                           // not supported
        case REQUEST_RESERVED_1:        break;                           // not supported
        case REQUEST_SET_ADDRESS:       break;                           // not supported
        case REQUEST_GET_DESCRIPTOR:    ReqInterfaceStd_GetDescriptor(); return;
        case REQUEST_SET_DESCRIPTOR:    break;                           // not supported
        case REQUEST_GET_CONFIGURATION: break;                           // not supported
        case REQUEST_SET_CONFIGURATION: break;                           // not supported
        case REQUEST_GET_INTERFACE:     ReqInterfaceStd_GetInterface();  return;
        case REQUEST_SET_INTERFACE:     ReqInterfaceStd_SetInterface();  return;
        case REQUEST_SYNC_FRAME:        break;                           // not supported
      }
      break;

    case REQ_TYPE_CLASS: //!< \todo funktion: ReqInterface_??? verwenden
      ReqInterfaceClass(); return;  

    case REQ_TYPE_VENDOR:
      break;
  }
  Stall();
}

//-------------------------------------------------------------------
__inline void cHwUSBctrl::ReqEndpoint()
{
  switch( setupData.reqType() )
  {
    case REQ_TYPE_STANDARD:
      switch( setupData.request() )
      {
        case REQUEST_GET_STATUS:        break;                        // not supported
        case REQUEST_CLR_FEATURE:       ReqEndpointStd_ClrFeature();     return;
        case REQUEST_RESERVED_0:        break;                        // not supported
        case REQUEST_SET_FEATURE:       ReqEndpointStd_SetFeature();     return;
        case REQUEST_RESERVED_1:        break;                        // not supported
        case REQUEST_SET_ADDRESS:       break;                        // not supported
        case REQUEST_GET_DESCRIPTOR:    break;                        // not supported
        case REQUEST_SET_DESCRIPTOR:    break;                        // not supported
        case REQUEST_GET_CONFIGURATION: break;                        // not supported
        case REQUEST_SET_CONFIGURATION: break;                        // not supported
        case REQUEST_GET_INTERFACE:     break;                        // not supported
        case REQUEST_SET_INTERFACE:     break;                        // not supported
        case REQUEST_SYNC_FRAME:        break;                        // not supported
      }
      break;

    case REQ_TYPE_CLASS:
      break;

    case REQ_TYPE_VENDOR:
      break;
  }
  Stall();
}

//*******************************************************************
// Methods, called in ReqDevice
//*******************************************************************
//-------------------------------------------------------------------
__inline void cHwUSBctrl::ReqDeviceStd_GetStatus( void )
{
  epIN.writeData( cDataPointer( (BYTE*)&DeviceStatus, setupData.length()) );
}

//-------------------------------------------------------------------
__inline void cHwUSBctrl::ReqDeviceStd_SetAddress( void )
{
  usb.setAddress( setupData.valueLow() );
}

//-------------------------------------------------------------------
__inline void cHwUSBctrl::ReqDeviceStd_GetDescriptor( void )
{
  switch( setupData.valueHigh() )
  {
    case cHwUSBdesc::DEVICE_DESCRIPTOR:
      epIN.writeDataLen( usb.desc.getDescriptorDevice(),
                         setupData.length() );
      return;

    case cHwUSBdesc::CONFIGURATION_DESCRIPTOR:
      epIN.writeDataLen( usb.desc.getDescriptorConfig( setupData.valueLow() + 1 ),
                         setupData.length() );
      return;

    case cHwUSBdesc::STRING_DESCRIPTOR:
      epIN.writeDataLen( usb.desc.getDescriptorString( setupData.valueLow() ),
                         setupData.length() );
       return;
    
    case cHwUSBdesc::INTERFACE_POWER_DESCRIPTOR:
       return;
  }
//  Stall();
}

//-------------------------------------------------------------------
__inline void cHwUSBctrl::ReqDeviceStd_GetConfiguration( void )
{
  epIN.writeData(cDataPointer( (BYTE*)&Configuration,
                               setupData.length()) );
}

//-------------------------------------------------------------------
 __inline void cHwUSBctrl::ReqDeviceStd_SetConfiguration( void )
{
  cHwUSBdesc::cEndpoint *epDesc   = NULL; 
  cHwUSBendpoint        *ep       = NULL;
  BYTE                   configId = setupData.valueLow();

  if( (void *)usb.desc.getDescriptorConfig( configId ) != NULL )
  {
    Configuration = configId;
    usb.configure(true);

    DeviceStatus = usb.desc.getConfigDeviceStatus( configId );
    
    // Iteration ueber alle in einer Configuration definierten Endpunkte
    for( WORD i = 0;
         (void *)usb.desc.getDescriptorInterface( configId, i ) != NULL; 
         i++ )
    { 
      for( WORD e=0;
           (epDesc = usb.desc.getDescriptorEndpoint( configId, i, e )) != NULL;
           e++ )
      {
        if( (ep = usb.desc.getEndpoint( epDesc->bEndpointAddress )) !=NULL )
        {
          ep->setConfiguration();
        }
      }
    }
    epIN.writeAcknowledge();
  }
  else
  {
    Configuration = 0;
    usb.configure(false); 
    Stall();
  }
}

//*******************************************************************
// Methods, called in ReqInterface
//*******************************************************************
//-------------------------------------------------------------------
 __inline void cHwUSBctrl::ReqInterfaceStd_GetStatus( void )
{
  // not supported
  Stall();
}

//-------------------------------------------------------------------
 __inline void cHwUSBctrl::ReqInterfaceStd_GetDescriptor( void )
{
  
  cHwUSBinterf *interf 
    = usb.desc.getInterface( setupData.valueLow()+1,  // cinfId
                             setupData.indexLow() );  // interfId
  if( interf )
  {
    epIN.writeDataLen( interf->GetDescriptor( setupData.value() ),
                       setupData.length() );
    return;
  }
  Stall();
}

//-------------------------------------------------------------------
 __inline void cHwUSBctrl::ReqInterfaceStd_GetInterface( void )
{
  // not supported
  Stall();
}

//-------------------------------------------------------------------
 __inline void cHwUSBctrl::ReqInterfaceStd_SetInterface( void )
{
  // not supported
  Stall();
}

//-------------------------------------------------------------------
 __inline void cHwUSBctrl::ReqInterfaceClass( void )
{
  cDataPointer tmp;

  cHwUSBinterf *interfTmp 
    = usb.desc.getInterface( 1, setupData.indexLow() );

  if( interfTmp )
  {
    switch( setupData.reqDir() )
    {
      case REQ_DIR_DEVICE_TO_HOST:
        if( interfTmp->requestCtrlIN( tmp, 
                                  setupData.request(),
                                  setupData.value(), 
                                  setupData.length() ))
        {
          epIN.interf = interfTmp;
          epIN.epData = tmp;
          epIN.writeData();
          return;
        }
        break;
      case REQ_DIR_HOST_TO_DEVICE:
        if( interfTmp->requestCtrlOUT( tmp, 
                                  setupData.request(),
                                  setupData.value(), 
                                  setupData.length() ))
        {
          epOUT.interf = interfTmp;
          epOUT.epData = tmp;
          epIN.writeAcknowledge(); //!< \todo Check this function call
          return;
        }
        break;
    }
  }

  Stall();
}

//*******************************************************************
// Methods, called in ReqEndpoint
//*******************************************************************
//-------------------------------------------------------------------
__inline void cHwUSBctrl::ReqEndpointStd_ClrFeature ( void )
{
  cHwUSBendpoint *ep = usb.desc.getEndpoint( setupData.indexLow() );
  
  if( ep && Configuration > 0)
  {
    switch( setupData.value() )
    {
      case FEATURE_BIT_ENDPOINT_STALL:
        ep->clrStall();
        ep->clrFeature();
        epIN.writeAcknowledge();
        return;
    }
  }
  Stall();
}

//-------------------------------------------------------------------
__inline void cHwUSBctrl::ReqEndpointStd_SetFeature ( void )
{
  cHwUSBendpoint *ep = usb.desc.getEndpoint( setupData.indexLow() );

  if( ep && Configuration > 0 ) //!< \todo Check this condition:  && ep->isMask() )
  {
    switch( setupData.valueLow() )
    {
      case FEATURE_BIT_ENDPOINT_STALL: 
        ep->stall();
        epOUT.writeAcknowledge();
        return;
    }
  }
  Stall();
}

//*******************************************************************
// Other needfull methods
//*******************************************************************
//-------------------------------------------------------------------
__inline void cHwUSBctrl::Stall( void )
{
  epIN.stall();
}

//EOF
