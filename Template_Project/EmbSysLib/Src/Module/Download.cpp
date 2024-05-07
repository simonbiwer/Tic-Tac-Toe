//*******************************************************************
/*!
\file   Module/Download.cpp
\author Thomas Breuer
\date   04.05.2016
*/

//*******************************************************************
#include "lib.h"
#include "Module/ISC.h"
#include "Module/Download.h"

//*******************************************************************
//
// cDownload
//
//*******************************************************************
//-------------------------------------------------------------------
cDownload::cDownload( cISC &iscIn )

: isc      ( iscIn       ),
  in       ( isc         ),
  out      ( isc         )

{
  in.prop.out       = &out;
  in.prop.download  = this;
}

//*******************************************************************
//
// cDownload::Image
//
//*******************************************************************
//-------------------------------------------------------------------
cDownload::Image::Image( void )
{
  out       = NULL;
  download  = NULL;
}

//-------------------------------------------------------------------
void cDownload::Image::update( void )
{
  Interface *interf
   = (Interface *)(download?download->interfaceList[data.index]:NULL);

  if( interf && out )
  {
    if( (data.option & 0x02) )
    {
      if( interf->read( data, out->data ) )
    {
      out->write();// reply to downloader
    }
  }
    else if( interf->store( data, out->data ) )
    {
      out->write();// reply to downloader
    }
  }
}

//*******************************************************************
//
// cDownload::Interface
//
//*******************************************************************
//-------------------------------------------------------------------
cDownload::Interface::Interface( cDownload &downloadIn,
                                 cHwMemory &memIn )

: mem( memIn )

{
  downloadIn.interfaceList.add( this );
  run       = false;
  isNewFlag = false;
  totalSize = 0;
}

//-------------------------------------------------------------------
bool cDownload::Interface::isNew( void )
{
  if( isNewFlag )
  {
    isNewFlag = false;
    return( true );
  }
  return( false );
}

//-------------------------------------------------------------------
bool cDownload::Interface::isRunning( void )
{
  return( run );
}

//-------------------------------------------------------------------
DWORD cDownload::Interface::getSize( void )
{
  return( totalSize );
}

//-------------------------------------------------------------------
bool cDownload::Interface::store( cDownload::Image::Data &data,
                                  cDownload::Reply::Data &reply )
{
  if( data.blockId == 0 ) // first package
  {
    if( data.blockSize*data.numOfBlocks <= mem.getSize() )
    {
      if( onStart() )
      {
        totalSize = 0;
        run       = true;
        isNewFlag = false;

        reply.error = 0;
        numOfBlocks = data.numOfBlocks;

        mem.clear(0);
      }
      else
      {
        reply.error = 0x0002;
      }
    }
    else
    {
      reply.error = 0x0001;
    }
  }

  if( !run )
  {
    return( true );
  }



  if( numOfBlocks > 0 && data.blockId < numOfBlocks) // data to be stored
  {
    mem.unlock();
    for( BYTE j = 0; j < data.blockSize; j++ )
    {
      mem.write( data.blockSize*data.blockId + j, data.payload[j] );
    }
    mem.lock();
    totalSize = data.blockSize*(data.blockId+1);
  }

  if(    data.blockId == numOfBlocks-1 // last package
      || numOfBlocks  == 0 )           // or clear only
  {
    // clear remaining memory
    if( data.option & 0x0001 )
    {
      mem.unlock();
      for(DWORD j = totalSize; j< mem.getSize(); j++ )
      {
        mem.write( j, 0 );
      }
      mem.lock();
    }

    // calc CRC
    cCRC  crcCalulator( cCRC::SMALL );
    for( DWORD i = 0; i < totalSize; i++ )
    {
      crcCalulator( mem.read(i) );
    }
    reply.crc = crcCalulator.get();

    // reset
    isNewFlag = true;
    run       = false;
    onReady();
  }
  return( true );
}

//-------------------------------------------------------------------
bool cDownload::Interface::read( cDownload::Image::Data &data,
                                  cDownload::Reply::Data &reply )
{
  reply.length = mem.getSize();

  if( data.blockId == 0 ) // first package
  {
    if( data.blockSize*data.numOfBlocks <= mem.getSize() )
    {
      if( onStart() )
      {
        totalSize = 0;
        run       = true;
        isNewFlag = false;

        reply.error = 0;
        numOfBlocks = mem.getSize()/data.blockSize+1;
      }
      else
      {
        reply.error = 0x0002;
      }
    }
    else
    {
      reply.error = 0x0001;
    }
  }

  if( !run )
  {
    return( true );
  }

  if( numOfBlocks > 0 && data.blockId < numOfBlocks) // data to be stored
  {
   // mem.unlock();
    for( BYTE j = 0; j < data.blockSize; j++ )
    {
      reply.payload[j]=mem.read(data.blockId*data.blockSize+j);
    //  mem.write( data.blockSize*data.blockId + j, data.payload[j] );
    }
   // mem.lock();
    totalSize = data.blockSize*(data.blockId+1);
  }

  if(    data.blockId == numOfBlocks-1 // last package
      || numOfBlocks  == 0 )           // or clear only
  {
    // clear remaining memory
    if( data.option & 0x0001 )
    {
    //  mem.unlock();
      for(DWORD j = totalSize; j< mem.getSize(); j++ )
      {
     //   mem.write( j, 0 );
     reply.payload[j]=mem.read(data.blockId*data.blockSize+j);
      }
    //  mem.lock();
    }

    // calc CRC
    cCRC  crcCalulator( cCRC::SMALL );
    for( DWORD i = 0; i < mem.getSize(); i++ )
    {
      crcCalulator( mem.read(i) );
    }
    reply.crc = crcCalulator.get();



    // reset
    isNewFlag = true;
    run       = false;
    onReady();
  }
  return( true );
}

//EOF
