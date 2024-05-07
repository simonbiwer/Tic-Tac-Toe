//*******************************************************************
/*!
\file   USBdesc.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.

\todo
    - Anzahl config pro device und interf / config:
      * Konstanten verwenden
      * Bereichsüberschreitung prüfen, Fehlerbehandlung????
    - HID
      * Zur Zeit nur ein Report möglich
      * Eigenes Modul für HID-Descriptoren???
    - Statische Klassenelemente (cHwUSBdescBase)
      * Kein Zugriffsschutz auf Descriptoren
      * Nur 1x USB möglich
    - String Descriptoren
      * Zur Zeit fest auf 32 Byte
         + Länge ok?
         + Konstante verwenden!
*/

//*******************************************************************
#ifndef _HW_USB_DESC_H
#define _HW_USB_DESC_H

//*******************************************************************
#include "Com/Std/DataPointer.h"

//*******************************************************************
// Bits in field bmAttributes of Configuration Descriptor
#define USB_CONFIG_SELF_POWERED      0x40
#define USB_CONFIG_REMOTE_WAKEUP     0x20

// Bits returned by getConfigDeviceStatus
#define USB_STATUS_BIT_SELF_POWERED  0x01
#define USB_STATUS_BIT_REMOTE_WAKEUP 0x02

//*******************************************************************
class cHwUSBinterf;
class cHwUSBendpoint;

//*******************************************************************
/*!
\class cHwUSBdesc

\brief Abstract base class for USB descriptor

The concrete USB descriptor class can be generated with
\a \b Tools/DescGen.exe \n

\see <A HREF="../../Doc/EmbSysLib-Manual.pdf">EmbSyLib-Manual</A>

\todo Write DescGen-Manual.pdf
*/
#pragma pack(1)
class cHwUSBdesc
{
  public:
    //---------------------------------------------------------------
    /*! \enum DeviceClassType
        \brief USB Device Classes
    */
    typedef enum
    {
      RESERVED_CLASS              = 0,   //!< .
      AUDIO_CLASS                 = 1,   //!< .
      COMMUNICATIONS_CLASS        = 2,   //!< CDC
      HUMAN_INTERFACE_CLASS       = 3,   //!< HID
      MONITOR_CLASS               = 4,   //!< .
      PHYSICAL_INTERFACE_CLASS    = 5,   //!< .
      POWER_CLASS                 = 6,   //!< .
      PRINTER_CLASS               = 7,   //!< .
      STORAGE_CLASS               = 8,   //!< MSD
      HUB_CLASS                   = 9,   //!< .
      MISCELLANEOUS_CLASS         = 239, //!< .
      VENDOR_SPECIFIC_CLASS       = 255  //!< VSC
    } DeviceClassType;

    //---------------------------------------------------------------
    /*! \enum EndpointType
        \brief USB Endpoint Type identification
    */
    typedef enum
    {
      CONTROL_ENDPOINT     = 0,
      ISOCHRONOUS_ENDPOINT = 1,
      BULK_ENDPOINT        = 2,
      INTERRUPT_ENDPOINT   = 3
    } EndpointType;

  protected:
    //---------------------------------------------------------------
    // ID of requested descriptor type
    typedef enum
    {
      DEVICE_DESCRIPTOR                  =  1,
      CONFIGURATION_DESCRIPTOR           =  2,
      STRING_DESCRIPTOR                  =  3,
      INTERFACE_DESCRIPTOR               =  4,
      ENDPOINT_DESCRIPTOR                =  5,
      DEVICE_QUALIFIER_DESCRIPTOR        =  6,
      OTHER_SPEED_CONFIG_DESCRIPTOR      =  7,
      INTERFACE_POWER_DESCRIPTOR         =  8,
      OTG_DESCRIPTOR                     =  9,
      DEBUG_DESCRIPTOR                   = 10,
      INTERFACE_ASSOCIATION_DESCRIPTOR   = 11
    } DescriptorType;

  protected:
    //-----------------------------------------------------------------
    class cDevice
    {
      public:
        BYTE  bLength;
        BYTE  bDescriptorType;
        WORD  bcdUSB;
        BYTE  bDeviceClass;
        BYTE  bDeviceSubClass;
        BYTE  bDeviceProtocol;
        BYTE  bMaxPacketSize0;
        WORD  idVendor;
        WORD  idProduct;
        WORD  bcdDevice;
        BYTE  iManufacturer;
        BYTE  iProduct;
        BYTE  iSerialNumber;
        BYTE  bNumConfigurations;
    };

    //-----------------------------------------------------------------
    class cConfiguration
    {
      public:
        BYTE  bLength;
        BYTE  bDescriptorType;
        WORD  wTotalLength;
        BYTE  bNumInterfaces;
        BYTE  bConfigurationValue;
        BYTE  iConfiguration;
        BYTE  bmAttributes;
        BYTE  bMaxPower;
    };

    //-----------------------------------------------------------------
    class cHID
    {
      public:
        BYTE bLength;
        BYTE bDescriptorType;
        WORD bcdHID;
        BYTE bCountryCode;
        BYTE bNumDescriptors;
        /* Array of one or more descriptors */
        struct _HID_DESCRIPTOR_LIST {
          BYTE bDescriptorType;
          WORD wDescriptorLength;
        } DescriptorList[1]; //!< \todo Here we have only one descriptor ???
    };

    //-----------------------------------------------------------------
    class cEndpoint
    {
      public:
        BYTE  bLength;
        BYTE  bDescriptorType;
        BYTE  bEndpointAddress;
        BYTE  bmAttributes;
        WORD  wMaxPacketSize;
        BYTE  bInterval;
    };

    //-----------------------------------------------------------------
    class cInterface
    {
      public:
        BYTE  bLength;
        BYTE  bDescriptorType;
        BYTE  bInterfaceNumber;
        BYTE  bAlternateSetting;
        BYTE  bNumEndpoints;
        BYTE  bInterfaceClass;
        BYTE  bInterfaceSubClass;
        BYTE  bInterfaceProtocol;
        BYTE  iInterface;
    };

    //-----------------------------------------------------------------
    class cReport
    {
      public:
        WORD  bLength;
    };

    //-----------------------------------------------------------------
    //
    class cString
    {
      public:
        BYTE bLength;
        BYTE bDescriptorType;
    };
#pragma pack()

  protected:
    //-----------------------------------------------------------------
    enum
    {
       DEVICE = 0,
       CONFIG,
       INTERF,
       CLASS,
       ENDPOINT,
       REPORT,
       STRING
    };

  protected:
    //-----------------------------------------------------------------
    static WORD getId( BYTE type,
                       BYTE confID,
                       BYTE interfID,
                       BYTE id )
    {
        // bitmask: oooo iiii cccc tttt
        return(    ((id      &0x0F)<<12)
                 | ((interfID&0x0F)<< 8)
                 | ((confID  &0x0F)<< 4)
                 | ((type    &0x0F)<< 0) );
    }

    //-----------------------------------------------------------------
    virtual const BYTE *getDescriptor( WORD id ) = 0;

    //-----------------------------------------------------------------
    virtual void registerEndpoint( BYTE            epId,
                                   cHwUSBendpoint *endpoint ) = 0;

    //-----------------------------------------------------------------
    virtual cHwUSBendpoint *getEndpoint( BYTE epId ) = 0;

    //-----------------------------------------------------------------
    virtual void registerInterface( BYTE          confId,
                                    BYTE          interfId,
                                    cHwUSBinterf *interf ) = 0;

    //-----------------------------------------------------------------
    virtual cHwUSBinterf *getInterface( BYTE confId,
                                        BYTE interfId ) = 0;

    //-----------------------------------------------------------------
    virtual cDataPointer getDescriptorDevice( void );

    //-----------------------------------------------------------------
    virtual cDataPointer getDescriptorConfig( BYTE confId );

    //-----------------------------------------------------------------
    virtual cDataPointer getDescriptorInterface( BYTE confId,
                                                 BYTE interfId );

    //-----------------------------------------------------------------
    virtual cDataPointer getDescriptorEndpoint( BYTE confId,
                                                BYTE interfId,
                                                BYTE epId );

    //-----------------------------------------------------------------
    virtual cDataPointer getDescriptorHID( BYTE confId,
                                           BYTE interfId,
                                           BYTE hidId );

    //-----------------------------------------------------------------
    virtual cDataPointer getDescriptorHIDreport( BYTE confId,
                                                 BYTE interfId,
                                                 BYTE hidId );

    //-----------------------------------------------------------------
    virtual cDataPointer getDescriptorString( BYTE strId );

  public: // \todo check using in LPC17xx USB_MCU.cpp
    //-----------------------------------------------------------------
    virtual BYTE getMaxPacketSize0( void );

  protected:
    //-----------------------------------------------------------------
    virtual BYTE getConfigDeviceStatus( BYTE confId );

  //-------------------------------------------------------------------
  friend class cHwUSB;
  friend class cHwUSBctrl;
  friend class cHwUSBinterf;

}; //cHwUSBdesc

#endif
