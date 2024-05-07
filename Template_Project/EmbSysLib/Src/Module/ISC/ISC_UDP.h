//*******************************************************************
/*!
\file   Module/ISC_UDP.h
\author Thomas Breuer
\date   04.11.2016
*/

//*******************************************************************
#ifndef _ISC_UDP_H
#define _ISC_UDP_H

//*******************************************************************
#include "Module/ISC.h"

//*******************************************************************
/*!
\class cISC_UDP

\brief ISC transport class with UDP

\remark The length of the payload is limited to 64 bytes

\example cISC.cpp
*/
class cISC_UDP : public cISC, public cNetApplication
{
  public:
    //---------------------------------------------------------------
    /*! Instantiate an ISC transport object with UDP

        \param
        \param crcMode Select CRC calculation mode (FAST or SMALL)
    */
    cISC_UDP( cNetUDP &udp,
               cNetAddr<4> addr,
               WORD port,
               cCRC::MODE  crcMode = cCRC::SMALL )
: cISC( crcMode ),
  socket(udp,*this,addr,port)
{
  idx = 0;
  state = 0x80;
  error = false;
  ready = false;
 // socket.openDefault();
}


    //---------------------------------------------------------------
    /*! Update the ISC transport object

        Checks, if new data are arrived. In that case ISC copies the
        data to identified data object, sets the new data flag and
        calls the related \b update() method.
    */
//    virtual void update( void );
 virtual void open( void )
 {
  socket.openDefault();
}

 virtual void close( void )
 {
  socket.close();
}

 virtual BYTE isOpen()
 {
  return( socket.isConnected() );
}

  private:
    //---------------------------------------------------------------
    virtual void writeStream( BYTE  id,
                              BYTE *data,
                              BYTE  size,
                              WORD  crc )
                              {
  socket.clear();

  socket.fill( (const char*)&crc, sizeof(WORD));
  socket.fill( id );
  socket.fill( (const char)0 );
  socket.fill( (const char*)data, size );
  socket.send();
}



  private:
    //---------------------------------------------------------------
//    cHwUART &uart;
    //---------------------------------------------------------------
    virtual void OnReceive( void )
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

// from cISC:
    virtual void update( void ) {}

// from cNetApplication:
    virtual void OnUpdate( void ) {}

    virtual void OnTimeout( void ) {}

    virtual void OnError( void ) {}

 //   virtual void addPage( cHTTP_Page *page );


  private:
    //---------------------------------------------------------------
    cNetUDP::Socket socket;

    static const WORD maxLength = 60;

    BYTE     data[maxLength];

    bool     error;
    WORD     errorCnt;
    WORD     crcValue;
    BYTE     idx;
    BYTE     ready;
    BYTE     length;
    BYTE     id;
    BYTE     state;

}; //cISC_UDP

#endif
