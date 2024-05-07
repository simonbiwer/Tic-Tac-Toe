//*******************************************************************
/*!
\file   Module/ISC_TCP.cpp
\author Thomas Breuer
\date   04.11.2016
*/

//*******************************************************************
/*#include "lib.h"
#include "Module/ISC.h"
*/
//*******************************************************************
//
// cISC_TCP
//
//*******************************************************************
/*
//-------------------------------------------------------------------
template <class P>cISC_TCP<P>::cISC_TCP( P &tcp,
                    cNetAddr<4> addr,
                    WORD port,
                    cCRC::MODE crcMode )
: cISC( crcMode ),
*/
//  socket(tcp,*this,addr,port,10/*update time*/)
/*{
  idx = 0;
  state = 0x80;
  error = false;
  ready = false;
  socket.openDefault();
}

//-------------------------------------------------------------------
template <class P> void cISC_TCP<P>::writeStream( BYTE  id,
                            BYTE *data,
                            BYTE  size,
                            WORD  crc )
{
  socket.clear();

  socket.fill( id );
  socket.fill( size );
  socket.fill( (const char*)&crc, sizeof(WORD));
  socket.fill( (const char*)data, size );
  socket.send();
}

//-------------------------------------------------------------------
//
template <class P> void cISC_TCP<P>::process( void )
{
  cISC::DATA rec;
  WORD pos = 0;

  char c = 0;

  while( pos < sizeof(cISC::DATA) && socket.get( &c ) )
  {
    *((BYTE *)&rec + pos) = c;
    pos++;
  }

  if( 4 <= pos && pos <= sizeof(cISC::DATA) )
  {
      // look up correct data object: identifier and length OK?
      DataInterface *ptr = (DataInterface*)list.getFirst();

      while( ptr && ptr->id != rec.id )
      {
        ptr = (DataInterface*)ptr->getNext();
      }

      if(    ptr
          && rec.crcValue  == crc( &rec.id, ptr->dataLength+2 ) )
      {
        memcpy( ptr->dataRef, rec.data, ptr->dataLength );
        ptr->update(); // we found a matching data object
      }
  }
  else
  {
    return;
  }
}

//-------------------------------------------------------------------
template <class P> void cISC_TCP<P>::update( void )
{
}
*/
//EOF
