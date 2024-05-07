//*******************************************************************
/*!
\file   Module/ISC_UDP.cpp
\author Thomas Breuer
\date   04.11.2016
*/

//*******************************************************************
#include "lib.h"
#include "Module/ISC.h"

//*******************************************************************
//
// cISC_UDP
//
//*******************************************************************
//-------------------------------------------------------------------
//template <class T> cISC_UDP<T>::cISC_UDP( T &t,
//                    cNetAddr<4> addr,
//                    WORD port,
//                    cCRC::MODE crcMode )
//: cISC( crcMode ),
//  socket(t,*this,addr,port,10/*update time*/)
//{
//  idx = 0;
//  state = 0x80;
//  error = false;
//  ready = false;
// // socket.openDefault();
//}

//-------------------------------------------------------------------
//template <class T> void cISC_UDP<T>::writeStream( BYTE  id,
//                            BYTE *data,
//                            BYTE  size,
//                            WORD  crc )
//{
//  socket.clear();
//
//  socket.fill( (const char*)&crc, sizeof(WORD));
//  socket.fill( id );
//  socket.fill( (const char)0 );
//  socket.fill( (const char*)data, size );
//  socket.send();
//}
//
//template <class T> void cISC_UDP<T>::close(void)
//{
//  socket.close();
//}

//template <class T> void cISC_UDP<T>::open(void)
//{
//  socket.openDefault();
//}

//template <class T> BYTE cISC_UDP<T>::isOpen()
//{
//  return( socket.isConnected() );
//}
//
////-------------------------------------------------------------------
////
//template <class T> void cISC_UDP<T>::process( void )
//{
//  cISC::DATA rec;
//  WORD pos = 0;
//
//  char c = 0;
//
//  while( pos < sizeof(cISC::DATA) && socket.get( &c ) )
//  {
//    *((BYTE *)&rec + pos) = c;
//    pos++;
//  }
//
//  if( 4 <= pos && pos <= sizeof(cISC::DATA) )
//  {
//      // look up correct data object: identifier and length OK?
//      DataInterface *ptr = (DataInterface*)list.getFirst();
//
//      while( ptr && ptr->id != rec.id )
//      {
//        ptr = (DataInterface*)ptr->getNext();
//      }
//
//      if(    ptr
//          && rec.crcValue  == crc( &rec.id, ptr->dataLength+2 ) )
//      {
//        memcpy( ptr->dataRef, rec.data, ptr->dataLength );
//        ptr->update(); // we found a matching data object
//      }
//  }
//  else
//  {
//    return;
//  }
//}

////-------------------------------------------------------------------
//template <class T> void cISC_UDP<T>::update( void )
//{
//}

//EOF
