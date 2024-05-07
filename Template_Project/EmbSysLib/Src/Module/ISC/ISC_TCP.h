//*******************************************************************
/*!
\file   Module/ISC_TCP.h
\author Thomas Breuer
\date   04.11.2016
*/

//*******************************************************************
#ifndef _ISC_TCP_H
#define _ISC_TCP_H

//*******************************************************************
#include "Module/ISC.h"

//*******************************************************************
/*!
\class cISC_TCP

\brief ISC transport class with TCP

\remark The length of the payload is limited to 64 bytes

\example cISC.cpp
*/
class cISC_TCP : public cISC, public cNetApplication
{
    public:
cISC_TCP( cNetTCP &tcp,
               cNetAddr<4> addr,
               WORD port,
                    cCRC::MODE crcMode )
: cISC( crcMode ),
  socket(tcp,*this,addr,port)
{
  idx = 0;
  state = 0x80;
  error = false;
  ready = false;
  socket.openDefault();
}

//-------------------------------------------------------------------
    virtual void writeStream( BYTE  id,
                              BYTE *data,
                              BYTE  size,
                            WORD  crc )
{
  socket.clear();
  /*
    WORD     crcValue;
      BYTE id;
      BYTE reserved;
      BYTE data[ maxLength ];
  */

  socket.fill( (const char*)&crc, sizeof(WORD));
  socket.fill( id );
  socket.fill( (char)0 );
  socket.fill( (const char*)data, size );
  socket.send();
}

//-------------------------------------------------------------------
//
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

//-------------------------------------------------------------------
virtual void update( void )
{
}
    //---------------------------------------------------------------
//-------------------------------------------------------------------
virtual void OnUpdate( void )
{
}
    //---------------------------------------------------------------
    /*! Instantiate an ISC transport object with TCP

        \param
        \param crcMode Select CRC calculation mode (FAST or SMALL)
    */
   /* cISC_TCP( cNet_TCP &tcp,
               cNetAddr<4> addr,
               WORD port,
               cCRC::MODE  crcMode = cCRC::SMALL );
*/
    //---------------------------------------------------------------
    /*! Update the ISC transport object

        Checks, if new data are arrived. In that case ISC copies the
        data to identified data object, sets the new data flag and
        calls the related \b update() method.
    */
//    virtual void update( void );

  private:
    //---------------------------------------------------------------
    /*virtual void writeStream( BYTE  id,
                              BYTE *data,
                              BYTE  size,
                              WORD  crc );
*/
  private:
    //---------------------------------------------------------------
//    cHwUART &uart;
    //---------------------------------------------------------------
    //virtual void process( void );

   // virtual void update( void );

    virtual void OnTimeout( void )
{
socket.close();
socket.openDefault();
}


virtual void OnError()
{

}
 //   virtual void addPage( cHTTP_Page *page );

  private:
    //---------------------------------------------------------------
typename    cNetTCP::Socket socket;

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

}; //cISC_TCP

#endif
