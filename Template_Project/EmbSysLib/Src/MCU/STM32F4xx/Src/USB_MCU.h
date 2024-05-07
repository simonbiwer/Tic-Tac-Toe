//*******************************************************************
/*!
\file   USB_MCU.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_USB_MCU_H
#define _HW_USB_MCU_H

//*******************************************************************
#include "Com/Hardware/USB/USB.h"

//*******************************************************************
/*!
\class cHwUSB_0

\brief


\example cHwUSB.cpp
*/
class cHwUSB_0 : public cHwUSB
{
  private:  
    //*****************************************************************
    class Buffer
    {
      public:
        //-----------------------------------------------------------
        BYTE data[128];
        BYTE size;
        BYTE flag;
        BYTE maxpacket;
      
        //-----------------------------------------------------------
        Buffer( void )
        {
          size      = 0;
          flag      = false;
          maxpacket = 0;
        }
    };
    
  private:
    //***************************************************************
    class EndpointIN
    {
      public:
        //-----------------------------------------------------------
        EndpointIN( void );
        
        //-----------------------------------------------------------
        void  init    ( BYTE numIn );
        void  config  ( WORD epMPS, BYTE epType = 0 ); // default: control EP
        void  flush   ( void );
        void  reset   ( void );
        void  start   ( void );
        void  setStall( void );
        void  clrStall( void );
        
        //-----------------------------------------------------------
        WORD  write      ( BYTE *dataPtr, WORD len );
        void  writeToFifo( void );
        void  transmit   ( bool flag );
        void  transmitZLP( void );
        
        //-----------------------------------------------------------
        DWORD getInterrupt( void );
        void  clrInterrupt( DWORD interruptID );

      private:
        //-----------------------------------------------------------
        BYTE                        num;
        Buffer                      txBuf;
        USB_OTG_INEndpointTypeDef  *inep;
        __IO DWORD                 *fifo;
        
    }; // EndpointIN
    //***************************************************************
  
  private:
    //***************************************************************
    class EndpointOUT
    {
      public:
        EndpointOUT( void );
        
        //-----------------------------------------------------------
        void init    ( BYTE numIn );
        void config  ( WORD epMPS, BYTE epType = 0 ); // default: control EP
        void flush   ( void );
        void reset   ( void );
        void start   ( void );
        void setStall( void );
        void clrStall( void );
      
        //-----------------------------------------------------------
        WORD read        ( BYTE *dataPtr, WORD len );
        void readFromFifo( WORD  len);
        void receive     ( void );
        void receiveZLP  ( void );

        //-----------------------------------------------------------
        DWORD getInterrupt( void );
        void  clrInterrupt( DWORD interruptID );
        
      private:
        //-----------------------------------------------------------
        BYTE                        num;
        Buffer                      rxBuf;
        USB_OTG_OUTEndpointTypeDef *outep;
        __IO DWORD                 *fifo;
        
    }; // EndpointOUT
    //***************************************************************

  public:
    //---------------------------------------------------------------
    /*! Instantiate an USB object
        \param desc Reference to a descriptor
    */
    cHwUSB_0( cHwUSBdesc &desc );

    //---------------------------------------------------------------
    /*! Start USB device
    */
    virtual void start( void );

    //---------------------------------------------------------------
    //
    void isr( void );

  private:
    //---------------------------------------------------------------
    //
    virtual void reset( void );

    //---------------------------------------------------------------
    virtual void configure( BYTE flag );

    //---------------------------------------------------------------
    virtual void setAddress( BYTE adr = 0 );

    //---------------------------------------------------------------
    virtual void configEP( BYTE epAddr,
                           WORD epMaxPacketSize,
                           BYTE epType );

    //---------------------------------------------------------------
    virtual void setStallEP( BYTE epAddr );

    //---------------------------------------------------------------
    virtual void clrStallEP( BYTE epAddr );

    //---------------------------------------------------------------
    virtual WORD readEP( BYTE  epAddr,
                         BYTE *dataPtr,
                         WORD  len );

    //---------------------------------------------------------------
    virtual WORD writeEP( BYTE  epAddr,
                          BYTE *dataPtr,
                          WORD  len );

  private:
    //---------------------------------------------------------------
    BYTE  CoreReset         ( void );
    DWORD getInInterrupt    ( void );
    DWORD getOutInterrupt   ( void );
    BYTE  isInterruptPending( DWORD interuptID );
    void  clrInterrupt      ( DWORD interuptID );

  public:
    //---------------------------------------------------------------
    static cHwUSB_0 *usbPtr;

  private:
    //---------------------------------------------------------------
    static const WORD NUM_OF_ENDPOINTS = 4;
    static const WORD MAX_EP0_SIZE     = 64;

    cHwUSB_0::EndpointIN  epIN [ NUM_OF_ENDPOINTS ];
    cHwUSB_0::EndpointOUT epOUT[ NUM_OF_ENDPOINTS ];

}; //cHwUSB_0

#endif
