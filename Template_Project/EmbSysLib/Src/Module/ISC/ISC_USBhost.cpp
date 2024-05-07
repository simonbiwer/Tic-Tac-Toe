//*******************************************************************
/*!
\file   ISC_USBhost.cpp
\author Thomas Breuer
\date   11.12.2014
*/

//*******************************************************************
#include "lib.h"
#include "ISC_USBhost.h"


//*******************************************************************
//
// cISC_USBhost
//
//*******************************************************************
//-------------------------------------------------------------------
cISC_USBhost::cISC_USBhost( cUSB &usbIn, BYTE interfId, cCRC::MODE crcMode )

: cISC( crcMode ),
  usb(usbIn)

{

}

//-------------------------------------------------------------------
void cISC_USBhost::update( void )
{
  cISC::DATA data;

  if( usb.read( &data, sizeof(cISC::DATA)) < 0 )
  {
  //  flag |= true;
  return;
  }

 DataInterface *ptr = (DataInterface*)list.getFirst();

  while( ptr && ptr->id != data.id)
  {
    ptr = (DataInterface*)ptr->getNext();
  }

  if( ptr && data.crcValue == crc((BYTE*)&data.id, ptr->dataLength+2))
  {
    for(BYTE i = 0; i < ptr->dataLength; i++ )
    {
      ptr->dataRef[i] = data.data[i];
    }
    ptr->update();
  }
  return; //( true );
}

//-------------------------------------------------------------------
void cISC_USBhost::writeStream( BYTE id, BYTE *data, BYTE size, WORD crc )
{
  cISC::DATA tmp;

  if( size > tmp.maxLength )
  {
    return;
  }

  memcpy( tmp.data, data, size );
  tmp.reserved = 0;
  tmp.id       = id;
  tmp.crcValue = crc;

  usb.write( &tmp, size+4 ); //sizeof(cISC_DATA) );
}


//EOF
