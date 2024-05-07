//*******************************************************************
/*!
\file   Module/ISC_UART.cpp
\author Thomas Breuer
\date   11.12.2014, 17.03.2016
*/

//*******************************************************************
#include "lib.h"
#include "Module/ISC.h"

//*******************************************************************
//
// cISC_UART
//
//*******************************************************************
/*
  In order to achieve a fast synchronisation of the data stream
  without using a timeout, each byte of the payload is devided in
  two parts. The payload is bit-or operated with an
  identifier befor sending. To synchronize the data stream, just wait
  until 0001 xxxx is received.

  Byte | 7654 3210
  ---- | ---- ----
  0    | 0001 high part of low byte crc
  1    | 0010 low  part of low byte crc
  2    | 0011 high part of high byte crc
  3    | 0100 low  part of high byte crc
  4    | 0101 high part of identifier
  5    | 0110 low  part of identifier
  6    | 0111 high part of reserved
  7    | 1000 low  part of reserved
  ...
  2i+8 | 1001 high part of data byte i
  2i+9 | 1010 low  part of data byte i
  ...
  2N+6 | 1011 high part of data byte N-1
  2N+7 | 1100 low  part of data byte N-1
*/
//-------------------------------------------------------------------
cISC_UART::cISC_UART( cHwUART &uartIn, cCRC::MODE crcMode )
: cISC( crcMode ),
  uart(uartIn)
{
  idx = 0;
  state = 0x90;
  error = false;
  ready = false;
}

//-------------------------------------------------------------------
void cISC_UART::writeStream( BYTE  id,
                             BYTE *data,
                             BYTE  size,
                             WORD  crc )
{
  BYTE  buf[ 2*cISC::DATA::maxLength + 8 ];
  BYTE *bufPtr = buf;

  if( size < 2 || cISC::DATA::maxLength < size )
  {
    return;
  }

  *(bufPtr++) = 0x20 | ( (crc>> 4)&0x0F ); // crc, low byte, high part
  *(bufPtr++) = 0x30 | ( (crc    )&0x0F ); // crc, low byte, low part

  *(bufPtr++) = 0x40 | ( (crc>>12)&0x0F ); // crc, high byte, high part
  *(bufPtr++) = 0x50 | ( (crc>> 8)&0x0F ); // crc, high byte, low part

  *(bufPtr++) = 0x40 | (  id>>4  ); // id, high part
  *(bufPtr++) = 0x50 | (  id&0x0F); // id, low part

  *(bufPtr++) = 0x40 | (  0      ); // reserved, high part
  *(bufPtr++) = 0x50 | (  0      ); // reserved, low part

  for( BYTE i=0; i<size-1; i++ )
  {
    *(bufPtr++) = 0x40 | (data[i]>>4  ); // data[0:N-2], high part
    *(bufPtr++) = 0x50 | (data[i]&0x0F); // data[0:N-2], low part
  }

  *(bufPtr++) = 0x80 | (data[size-1]>>4  ); // data[0:N-2], high part
  *(bufPtr++) = 0x90 | (data[size-1]&0x0F); // data[0:N-2], low part

  uart.set( buf, 2*size+8 );
}

//-------------------------------------------------------------------
// Parse and synchronize incomming data stream
void cISC_UART::update( void )
{
  BYTE c = 0;
  BYTE d = 0;

  data.reserved = 0;

  while( uart.get(&c) && c!= 0 )
  {
    d = c & 0x0F;
    c = c & 0xF0;
    switch( c )
    {
      case 0x20: // START. crc, low byte, high part
        if( state != 0x90 )
        {
          error = true; // package is restarted, skip previous data
        }
        idx = 0;
        ((BYTE*)(&data))[idx] = d<<4;
        break;

     case 0x30: // crc, low byte, low part
        if( state != 0x20 )
        {
          error = true;
        }
        ((BYTE*)(&data))[idx++] |= d;
        break;

      case 0x40: // crc, high byte, high part
        if( state != 0x30 && state != 0x50) // check both, we are in a loop !
        {
          error = true;
        }
        ((BYTE*)(&data))[idx] = d<<4;
        break;

      case 0x50: // crc, high byte, low part
        if( state != 0x40 )
        {
          error = true;
        }
        ((BYTE*)(&data))[idx++] |= d;
        break;

	  case 0x80: // id, low part
        if( state != 0x50 )
        {
          error = true;
        }
        ((BYTE*)(&data))[idx] = d<<4;
        break;

	  case 0x90: // id, high part // FINISH. last data, low part
        if( state != 0x80 )
        {
          error = true;
        }
        ((BYTE*)(&data))[idx] |= d;

        ready = true;

        break;

      default:
        error = true;
        break;
    }

    if( idx > sizeof(cISC::DATA) )
    {
      error = true;
    }

    state = c;

    if( error )
    {
      error = false;
      ready = false;
      idx   = 0;
      state = 0x90;
      errorCnt++;
    }

    if( ready )
    {
      ready = false;

      // look up correct data object: identifier and length OK?
      DataInterface *ptr = (DataInterface*)list.getFirst();

      while( ptr && ptr->id != data.id )
      {
        ptr = (DataInterface*)ptr->getNext();
      }

      if(    ptr
          && idx == ptr->dataLength + 3
          && data.crcValue == crc( (BYTE*)&data.id, idx-1 ) )
      {
        memcpy( ptr->dataRef, data.data, ptr->dataLength );
        ptr->update(); // we found a matching data object
      }
      state = 0x90;
      idx   = 0;
    }
  }
}

//EOF
