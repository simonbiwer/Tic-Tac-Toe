//*******************************************************************
/*!
\file   USBinterfClassVSC.h
\author Thomas Breuer
\date   02.03.2016
*/

//*******************************************************************
#ifndef _USB_INTERF_CLASS_VSC_H
#define _USB_INTERF_CLASS_VSC_H

//*******************************************************************
#include "Com/Hardware/USB/USB.h"

//*******************************************************************
/*!
\class   cUSBinterfClassVSC

\brief   Template class supporting USB communication as
         vendor specific class (VSC)

The application can derive own classes from this template class to
create a simple USB communication. When an USB OUT tansfer is
received, the method \b onReceive() is called automatically and the
application can handle the received OUT data package.
When an USB IN transfer is requested by the host, the onTransmit()
method is called automatically and the application should fill the
IN data package, which is send to USB host afterwards.
The structures of IN and OUT data packages are used as parameters in
template specialization.

\see     Com/Hardware/USB.cpp
\example cUSBinterfClassVSC.cpp
*/
//-----------------------------------------------------------------
template <class IN_T, class OUT_T>
class cUSBinterfClassVSC : public cHwUSBinterf
{
  public:
    //---------------------------------------------------------------
    /*! Instantiate an USB vendor specific class (VSC) object
        \param usb Reference to an USB hardware object
        \param confId   USB configuration ID, defined by descriptor.
                        The ID of the first configuration is 1
        \param interfId USB interface ID, defined by descriptor
    */
    cUSBinterfClassVSC( cHwUSB &usb,
                        BYTE    confId,
                        BYTE    interfId )

    : cHwUSBinterf( usb, confId, interfId )

    {
    }

    //---------------------------------------------------------------
    /*! Call back on host IN request. \n
        The application has to complete the data structure. The
        return value indicates wether or not the application has
        accomplished.
        The transfer is starting after return from this method.
        \param data Reference to data structure
        \return
                - true:  new data to transmit
                - false: no data to transmit
    */
    virtual int onTransmit( IN_T &data ) = 0;

    //---------------------------------------------------------------
    /*! Call back on host OUT transfer. \n
        The application can handle received OUT data and indicate
        'acknowledge' or 'not acknowledge' by return value.
        \param data Reference to received data structure
        \return
               - true: acknowledge
               - false: not acknowledge
    */
    virtual int onReceive( OUT_T &data ) = 0;

  private:
    //---------------------------------------------------------------
    virtual bool transmit( BYTE epId, cDataPointer &data )
    {
      onTransmit( dataBufIN );
      data.set( dataBufIN );
      return( true );
    }

    //---------------------------------------------------------------
//    virtual int transmitCtrl( cDataPointer &data )
//    {
//      data = cDataPointer();
//      return(false);
//    }

    //---------------------------------------------------------------
    virtual bool receive( BYTE epId, WORD cnt )
    {
      return( onReceive( dataBufOUT ) );
    }

//    //---------------------------------------------------------------
//    virtual int receiveCtrl( WORD cnt )
//    {
//      return(false);
//    }

    //---------------------------------------------------------------
    virtual bool requestCtrlIN( cDataPointer &data,
                                BYTE          request,
                                WORD          value,
                                WORD          length )
    {
      data = cDataPointer();
      return( false );
    }

    //---------------------------------------------------------------
    virtual bool requestCtrlOUT( cDataPointer &data,
                                 BYTE          request,
                                 WORD          value,
                                 WORD          length )
    {
      return( false );
    }

    //---------------------------------------------------------------
    virtual bool request( BYTE epId, cDataPointer &data )
    {
      data.set( dataBufOUT );
      return( true );
    }

  private:
    //---------------------------------------------------------------
    IN_T  dataBufIN;
    OUT_T dataBufOUT;

};

#endif
