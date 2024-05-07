//*******************************************************************
/*!
\file   USBinterfClassHID.cpp
\author Thomas Breuer
\date   01.06.2012
*/

//*******************************************************************
// 
// cHwUSBinterfClassHID
//
//*******************************************************************
//-------------------------------------------------------------------
cHwUSBinterfClassHID::cHwUSBinterfClassHID( cHwUSB &usb, 
                                            BYTE    configId, 
                                            BYTE    interfId )

: cHwUSBinterf( usb, configId, interfId )
{
}

//-------------------------------------------------------------------
cDataPointer cHwUSBinterfClassHID::GetDescriptor( WORD value )
{
  switch( value >> 8 )
  {
    case HID_HID_DESCRIPTOR_TYPE:      return( usb.desc.getDescriptorHID      ( configId, interfId, 0 ) );
    case HID_REPORT_DESCRIPTOR_TYPE:   return( usb.desc.getDescriptorHIDreport( configId, interfId, 0 ) );
    case HID_PHYSICAL_DESCRIPTOR_TYPE: break; // HID Physical Descriptor is not supported
  }
  return( cDataPointer() );
}

//-------------------------------------------------------------------
int cHwUSBinterfClassHID::requestCtrlIN( cDataPointer &dataPtr, BYTE request, WORD value, WORD length )
{
  switch( request ) 
      {
        case HID_REQUEST_GET_REPORT: // IN
          //pendingRequest = HID_REQUEST_GET_REPORT;
          // next transmit will request a report

          // "The Get_Report request allows the host to receive a report via the Control pipe."
          transmit( 0, dataPtr );
          return( true );

        case HID_REQUEST_SET_REPORT:  // ÓUT ???
          dataPtr.set(NULL, 0);
          return(true);

        case HID_REQUEST_GET_IDLE: // IN     
          //pendingRequest = HID_REQUEST_GET_IDLE;
          //if (HID_GetIdle(usb.epCtrl.setupData,usb.epCtrl.EP0Buf)) 
          dataPtr.set(NULL, 0);
          return(true);
          
        case HID_REQUEST_SET_IDLE: // OUT
          //if (HID_SetIdle(usb.epCtrl.setupData)) 
          
           // usb.epCtrl.writeAcknowledge();                               // send Acknowledge
          dataPtr.set(NULL, 0);
          return(true);
          
        case HID_REQUEST_GET_PROTOCOL: // IN
          //pendingRequest = 
          //if (HID_GetProtocol(usb.epCtrl.EP0Buf)) 
          dataPtr.set(NULL, 0);
          return(true);
          
        case HID_REQUEST_SET_PROTOCOL: // OUT
          //if (HID_SetProtocol(usb.epCtrl.setupData)) 
          dataPtr.set(NULL, 0);
          return(true);
          
      } // switch
      dataPtr.set(NULL, 0);
      return(false);
}

//-------------------------------------------------------------------
int cHwUSBinterfClassHID::requestCtrlOUT( cDataPointer &dataPtr, BYTE request, WORD value, WORD length )
{
  switch( request ) 
      {
        case HID_REQUEST_GET_REPORT: // IN
          //pendingRequest = HID_REQUEST_GET_REPORT;
          // next transmit will request a report

          // "The Get_Report request allows the host to receive a report via the Control pipe."
          transmit( 0, dataPtr );
          return( true );

        case HID_REQUEST_SET_REPORT:  // ÓUT ???
          dataPtr.set(NULL, 0);
          return(true);

        case HID_REQUEST_GET_IDLE: // IN     
          //pendingRequest = HID_REQUEST_GET_IDLE;
          //if (HID_GetIdle(usb.epCtrl.setupData,usb.epCtrl.EP0Buf)) 
          dataPtr.set(NULL, 0);
          return(true);
          
        case HID_REQUEST_SET_IDLE: // OUT
          //if (HID_SetIdle(usb.epCtrl.setupData)) 
          
           // usb.epCtrl.writeAcknowledge();                               // send Acknowledge
          dataPtr.set(NULL, 0);
          return(true);
          
        case HID_REQUEST_GET_PROTOCOL: // IN
          //pendingRequest = 
          //if (HID_GetProtocol(usb.epCtrl.EP0Buf)) 
          dataPtr.set(NULL, 0);
          return(true);
          
        case HID_REQUEST_SET_PROTOCOL: // OUT
          //if (HID_SetProtocol(usb.epCtrl.setupData)) 
          dataPtr.set(NULL, 0);
          return(true);
          
      } // switch
      dataPtr.set(NULL, 0);
      return(false);
}



/*
 *  HID Set Report Request Callback
 *   Called automatically on HID Set Report Request
 *    Parameters:      None (global setup and EP0Buf)
 *    Return Value:    TRUE - Success, FALSE - Error
 */

//-------------------------------------------------------------------
DWORD cHwUSBinterfClassHID::HID_SetReport( cUSBctrlSetup &setupData, 
                                           const cDataPointer  &buffer) 
{

//  /* ReportID = setupData.wValue.WB.L; */
//  switch (setupData.valueHigh()) {
//    case HID_REPORT_INPUT:
//      return (false);          /* Not Supported */
//    case HID_REPORT_OUTPUT:
//      receive( buffer );
//      
//      break;
//    case HID_REPORT_FEATURE:
//      return (false);          /* Not Supported */
//  }
  return (true);
}


/*
 *  HID Get Idle Request Callback
 *   Called automatically on HID Get Idle Request
 *    Parameters:      None (global setup and EP0Buf)
 *    Return Value:    TRUE - Success, FALSE - Error
 */

//-------------------------------------------------------------------
DWORD cHwUSBinterfClassHID::HID_GetIdle (cUSBctrlSetup &setupData, BYTE *buffer) 
{

//  buffer[0] = HID_IdleTime[setupData.valueLow()];
  return (true);
}


/*
 *  HID Set Idle Request Callback
 *   Called automatically on HID Set Idle Request
 *    Parameters:      None (global setup)
 *    Return Value:    TRUE - Success, FALSE - Error
 */

//-------------------------------------------------------------------
DWORD cHwUSBinterfClassHID::HID_SetIdle (WORD value) 
{
  HID_IdleTime[value&0x0F] = value >> 8;

  /* Idle Handling if needed */
  /* ... */

  return (true);
}


/*
 *  HID Get Protocol Request Callback
 *   Called automatically on HID Get Protocol Request
 *    Parameters:      None (global setup)
 *    Return Value:    TRUE - Success, FALSE - Error
 */

//-------------------------------------------------------------------
DWORD cHwUSBinterfClassHID::HID_GetProtocol (BYTE *buffer) 
{

//  buffer[0] = HID_Protocol;
  return (true);
}


/*
 *  HID Set Protocol Request Callback
 *   Called automatically on HID Set Protocol Request
 *    Parameters:      None (global setup)
 *    Return Value:    TRUE - Success, FALSE - Error
 */

//-------------------------------------------------------------------
DWORD cHwUSBinterfClassHID::HID_SetProtocol (cUSBctrlSetup &setupData) 
{

//  HID_Protocol = setupData.valueLow();

  /* Protocol Handling if needed */
  /* ... */

  return (true);
}

