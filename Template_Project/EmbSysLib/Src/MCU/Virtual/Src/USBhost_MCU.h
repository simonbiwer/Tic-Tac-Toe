#ifndef _USB_H
#define _USB_H

#include "libusb.h"

typedef struct usb_interface_descriptor tInterfDesc;
typedef struct usb_config_descriptor    tConfigDesc;
typedef struct usb_dev_handle           tHandle;

//*******************************************************************
class cUSB
{
  public:
    //---------------------------------------------------------------
    cUSB()
    {
      ep_IN      = 0x80;
      ep_OUT     = 0;
//      interfDesc = 0;
      devHandle  = 0;
      iID = 0;
    }

    //---------------------------------------------------------------
    int open(unsigned int vid,
             unsigned int pid,
             unsigned int iid );

    //---------------------------------------------------------------
    int read (void *buf, unsigned size );

    //---------------------------------------------------------------
    template <class T> int read( T &buf )
    {
      return( read( (void*)&buf, sizeof(T) ) );
    }

    //---------------------------------------------------------------
    int write( void *buf, unsigned size );

    //---------------------------------------------------------------
    template <class T> int write( T &buf )
    {
      return( write( (void*)&buf, sizeof(T) ) );
    }

    //---------------------------------------------------------------
    void close();

    BYTE isOpen()
    {
      return( (devHandle!=NULL) );
    }

  private:
    //---------------------------------------------------------------
    //tInterfDesc* getInterfDesc( tConfigDesc* configDesc,
	//                              WORD         iid );

    //---------------------------------------------------------------
    int getDevice(WORD vid, WORD pid, WORD iid);

  private:
    //---------------------------------------------------------------
    int ep_IN;
    int ep_OUT;
    int iID;
   // libusb_interface_descriptor *interfDesc;
    libusb_device_handle* devHandle;

};
#endif // _USB_H
