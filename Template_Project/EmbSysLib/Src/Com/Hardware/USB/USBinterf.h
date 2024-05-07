//*******************************************************************
/*!
\file   USBinterf.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_USB_INTERF_H
#define _HW_USB_INTERF_H

//*******************************************************************
#include "Com/Std/DataPointer.h"

//*******************************************************************
class cHwUSB;

//*******************************************************************
/*! 
\class cHwUSBinterf

\brief 
*/
class cHwUSBinterf
{
  public:
    //---------------------------------------------------------------
    /*! Instantiate an USB interface
  
        \param usb      Reference to USB
        \param configId USB configuration ID
        \param interfId USB interface ID
    */
    cHwUSBinterf( cHwUSB &usb, 
                  BYTE    configId, 
                  BYTE    interfId );

  protected:
    //---------------------------------------------------------------
    /*! Call back function
        
        The function is called from interrupt on IN transfer (data 
        transmit from device to host). 
        The application must fill \b epdata sending to host
        \param epId   Endpoint ID
        \param epdata Data send to host
        \return 
          - true:  OK
          - false: Not OK
    */
    virtual bool transmit( BYTE          epId, 
                           cDataPointer &epdata ) = 0;

    //---------------------------------------------------------------
    /*! Call back function
  
        The function is called from interrupt on OUT transfer (data 
        received from host). The application has to set \b epdata to 
        a data buffer, where received data will be stored. This 
        function is called before \b receive().
        \param epId   Endpoint ID
        \param epdata Pointer to data buffer
        \return 
          - true: Pointer is valid, data can be stored
          - false: Data can not be received
    */
    virtual bool request( BYTE          epId, 
                          cDataPointer &epdata ) = 0;

    //---------------------------------------------------------------
    /*! Call back function
    
        The function is called from interrupt on SETUP transfer, the 
        host requests a data transfer from device via control endpoint.
        The application must fill \b epdata sending to host. This 
        function is called before \b transmit() on control endpoint.
        \param epdata  Pointer sending to data
        \param request Request type from setup
        \param value   Value from setup
        \param length  Length of requested data
        \return 
          - true:  OK
          - false: Not OK
    */
    virtual bool requestCtrlIN( cDataPointer &epdata, 
                                BYTE          request,
                                WORD          value, 
                                WORD          length ) = 0;

    //---------------------------------------------------------------
    /*! Call back function
    
        The function is called from interrupt on SETUP transfer, the 
        host requests a data transfer to device via control endpoint.
        The application has to set \b epdata to a data buffer, where 
        received data will be stored. This function is called before 
        \b receive() on control endpoint.
        \param epdata  Pointer to data receive buffer
        \param request Request type from setup
        \param value   Value from setup
        \param length  Length of requested data
        \return 
          - true: Pointer is valid, data can be stored
          - false: Data can not be received
    */
    virtual bool requestCtrlOUT( cDataPointer &epdata, 
                                 BYTE          request,
                                 WORD          value, 
                                 WORD          length ) = 0;

    //---------------------------------------------------------------
    /*! Call back function

        The function is called from interrupt on OUT transfer (data 
        received from host) and data are written to the data buffer, 
        determined in \b request(). The application can handle data 
        now.
        \param epId Endpoint ID
        \param len  Num of received data bytes
        \return 
          - true: OK
          - false: Not OK
    */
    virtual bool receive( BYTE epId, WORD len )  = 0;

  private:
    //---------------------------------------------------------------
    virtual cDataPointer GetDescriptor( WORD value ) 
    {
      return( cDataPointer() );
    }

    //---------------------------------------------------------------
    virtual void clrFeature( void )
    {
    }

    //---------------------------------------------------------------
    virtual void setFeature( void )
    {
    }

  protected:
    //---------------------------------------------------------------
    cHwUSB         &usb;
    cHwUSBendpoint *epIN;
    cHwUSBendpoint *epOUT;
    BYTE            configId;
    BYTE            interfId;
  
  //-----------------------------------------------------------------
  friend class cHwUSBendpoint;
  friend class cHwUSBctrl;

}; //cHwUSBinterf

#endif
