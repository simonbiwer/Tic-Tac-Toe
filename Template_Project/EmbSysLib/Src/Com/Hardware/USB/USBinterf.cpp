//*******************************************************************
/*!
\file   USBinterf.cpp
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

#include "lib.h"

//*******************************************************************
// 
// cHwUSBinterf
//
//*******************************************************************
//-------------------------------------------------------------------
cHwUSBinterf::cHwUSBinterf( cHwUSB &usbIn, 
                            BYTE    configIdIn, 
                            BYTE    interfIdIn )

:usb(usbIn)

{
  configId = configIdIn;
  interfId = interfIdIn;
  
  cHwUSBdesc::cEndpoint  *epDesc = NULL;
  
  usb.desc.registerInterface( configId, interfId, this );
  
  for( WORD e = 0;
       (epDesc = usb.desc.getDescriptorEndpoint( configId, interfId, e )) != NULL;
       e++ )
  {
    cHwUSBendpoint *ptr = new cHwUSBendpoint( usb, 
                        this, 
                        epDesc->bEndpointAddress,
                        epDesc->wMaxPacketSize,
                        epDesc->bmAttributes );
                        
    usb.desc.registerEndpoint( epDesc->bEndpointAddress, ptr );
                  
    // Ggf. Endpoint merken                        
    if( (epDesc->bEndpointAddress & 0x80) && !epIN && ptr )  
    {
      epIN = ptr;
    }      
    if( !(epDesc->bEndpointAddress & 0x80) && !epOUT && ptr )
    {
      epOUT = ptr;
    }      
  } 
}
  

//EOF
