#include <stdio.h>
#include "USBhost_MCU.h"

//*******************************************************************
 int cUSB::open( unsigned int vid,
                 unsigned int pid,
                 unsigned int iid )
{
  close();
 // libusb_init(NULL);         // Initialize the library.
  //usb_find_busses();  // Find all busses.
  //usb_find_devices(); // Find all connected devices.

  if( getDevice( vid, pid, iid ) < 0 )
  {
    printf( "device %04X:%04X not found!\n", vid, pid );
    return( false );
  }


if( devHandle)
{
    struct libusb_config_descriptor *config;
    libusb_device *dev;
    dev = libusb_get_device(devHandle);
    libusb_get_active_config_descriptor(dev,&config);

    for( int e = 0; e < config->interface->altsetting->bNumEndpoints; e++ )
    {
      int ep = config->interface->altsetting->endpoint[e].bEndpointAddress;
      if( ep&0x80 )
      {
        ep_IN = ep;
      }
      else
      {
        ep_OUT = ep;
      }
    }
    iID = iid;

	libusb_free_config_descriptor( config );
}

 /* if( interfDesc )
  {
    for( int e = 0; e < interfDesc->bNumEndpoints; e++ )
    {
      int ep = interfDesc->endpoint[e].bEndpointAddress;
      if( ep&0x80 )
      {
        ep;
      }
      else
      {
        ep_OUT = ep;
      }
    }
    iID = iid;
  }
  else
  {
    printf("\nError: interface decriptor (%u) not found\n", iid );
  }
*/
/*
  if( usb_set_configuration(devHandle,0+1) < 0 )
  {
    printf("set config failed %s\n", usb_strerror());
    return(false);
  }

  if( usb_claim_interface(devHandle, iid) < 0)
  {
    printf("claiming interface #%d!\n%s\n", iid, usb_strerror());
    return(false);
  }
*/
  return( true );
}

//*******************************************************************
int cUSB::write( void *buf, unsigned size )
{
    int tranfered=0;
  if ( devHandle == NULL)
    return(-1);

  int err;

  if( ep_OUT == 0x00 )
    err = libusb_control_transfer(devHandle, 0x21, 0x09, 0x0200, iID,(unsigned char *)buf, size, 500);
  else
    err = libusb_interrupt_transfer( devHandle,
                                 ep_OUT,
                                 (unsigned char *)buf,
                                 size,
                                 &tranfered,
                                 500 );
  if( err <= 0 )
  {
    //printf("\n%s\n", usb_strerror());
  }
  return( err );

}

//*******************************************************************
int cUSB::read( void *buf, unsigned size )
{
    int tranfered=0;
  if ( devHandle == NULL)
    return(-1);
  int err;

  if( ep_IN == 0x80 )
    err = libusb_control_transfer(devHandle, 0x21|0x80, 0x09, 0x0200, iID,(unsigned char *)buf, size, 500);
  else
    err = libusb_interrupt_transfer( devHandle,
                                ep_IN,
                                (unsigned char*)buf,
                                size,
                                &tranfered,
                                 500 );
  if( err < 0 )
  {
   // printf("\n%s\n", usb_strerror());
    Sleep(200);
  }
  return( err );

}

//*******************************************************************
void cUSB::close()
{
  if( devHandle )
 {
     libusb_release_interface(devHandle, 0);

     libusb_close( devHandle );
    libusb_exit(NULL);
}
//  interfDesc = NULL;
  devHandle  = NULL;

}

//*******************************************************************
//tInterfDesc* cUSB::getInterfDesc( tConfigDesc *configDescriptor,
//	                                WORD         interfNumber )
//{
/*	tInterfDesc* intf;

	if( !configDescriptor )
	{
	  return NULL;
	}

	for( int intfIndex = 0; intfIndex < configDescriptor->bNumInterfaces; intfIndex++ )
	{
		if( configDescriptor->interface[intfIndex].num_altsetting)
		{
			intf = &configDescriptor->interface[intfIndex].altsetting[0];

			if( intf && intf->bInterfaceNumber == interfNumber )
			{
				return intf;
			}
		}
	}
	*/

//	return NULL;
//}

//static void print_devs(libusb_device **devs)
//{
//	libusb_device *dev;
//	int i = 0, j = 0;
//	uint8_t path[8];
//
//	while ((dev = devs[i++]) != NULL) {
//		struct libusb_device_descriptor desc;
//		int r = libusb_get_device_descriptor(dev, &desc);
//		if (r < 0) {
//			fprintf(stderr, "failed to get device descriptor");
//			return;
//		}
//
//		printf("%04x:%04x (bus %d, device %d)",
//			desc.idVendor, desc.idProduct,
//			libusb_get_bus_number(dev), libusb_get_device_address(dev));
//
//		r = libusb_get_port_numbers(dev, path, sizeof(path));
//		if (r > 0) {
//			printf(" path: %d", path[0]);
//			for (j = 1; j < r; j++)
//				printf(".%d", path[j]);
//		}
//		printf("\n");
//	}
//}

//*******************************************************************
int cUSB::getDevice( WORD vid,
                     WORD pid,
                     WORD iid )
{
//  interfDesc = NULL;
  devHandle  = NULL;

 /* for (struct usb_bus *bus = usb_get_busses(); bus; bus = bus->next)
  {
    for (struct usb_device* dev = bus->devices; dev; dev = dev->next)
    {
      if (    dev->descriptor.idVendor  == vid
           && dev->descriptor.idProduct == pid)
      {
        tHandle* udev = usb_open(dev);
        if( udev )
        {
          if(dev->descriptor.bNumConfigurations)
          {
            interfDesc = getInterfDesc( &dev->config[0], iid );
            if( interfDesc != NULL)
            {
              devHandle = udev;
              return 0;
            }
          }
        }
        usb_close(udev);
      }
    }
  }
  */
  libusb_device **devs;

        libusb_init(NULL);

  /*
  ssize_t cnt = libusb_get_device_list(NULL, &devs);
 //print_devs( devs);

  libusb_device *dev;
	int i = 0, j = 0;
  while ((dev = devs[i++]) != NULL)
    {
		struct libusb_device_descriptor desc;
		int r = libusb_get_device_descriptor(dev, &desc);
		if (r < 0) {
			fprintf(stderr, "failed to get device descriptor");
			return(-1);
		}

		if(desc.idVendor == vid && desc.idProduct == pid)
        {
            // libusb_get_bus_number(dev)
		    // libusb_get_device_address(dev));
            break;
        }

	}
  libusb_free_device_list(devs, 1);
  */
devHandle = libusb_open_device_with_vid_pid( 	NULL,vid,pid);
if( devHandle)
{
   // libusb_set_auto_detach_kernel_driver(devHandle, 1);
	if( libusb_claim_interface(devHandle, 0) !=LIBUSB_SUCCESS)
    {
        close();
    }
}
//  libusb_exit(NULL);

if(devHandle )
return( 0 );
  return -1;
}
