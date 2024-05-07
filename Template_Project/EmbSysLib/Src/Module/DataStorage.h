//*******************************************************************
/*!
\file   DataStorage.h
\author Thomas Breuer
\date
\brief
*/

#ifndef _DATA_STORAGE_H
#define _DATA_STORAGE_H


//*******************************************************************
//#include "lib.h"

//*******************************************************************
class cDataStorage
{
  public:
class Header
    {
      public:
      DWORD key;
      DWORD length;

      BOOL operator==( Header &h)
      {
        return( (this->key == h.key && this->length == h.length)?true:false );
      }
    };

        //***************************************************************
    /*!
    \class
    */

class Record;
    //***************************************************************
    /*!
    \class
    */
    class RecordHandler : public cList::Item
    {
      public:
        //-----------------------------------------------------------
        /*!
        */
        RecordHandler( cDataStorage &dsIN, cDataStorage::Record &recordIN )
        : ds(dsIN),
          record(recordIN)
        {
          ds.rhList.add(this);
        }

        //-----------------------------------------------------------
        /*!
        */
        void update( void )
        {
          record.storeRecord();
        }

        //-----------------------------------------------------------
        /*!
        */
        BOOL open( Header &h )
        {
          return( ds.open( this, h ) );
        }

        //-----------------------------------------------------------
        /*!
        */
         BOOL create( Header &h )
        {
          return( ds.create(this,h) );
        }

        //-----------------------------------------------------------
        /*!
        */
        BOOL read( DWORD addr, BYTE *data )
        {
          return( ds.read( this, addr, data, sizeof(BYTE) ) );
        }

        //-----------------------------------------------------------
        /*!
        */
        BOOL read( BYTE *data, DWORD len )
        {
          return( ds.read( this, 0, data, len ) );
        }

        //-----------------------------------------------------------
        /*!
        */
        BOOL write( DWORD addr, BYTE data )
        {
          return ( ds.write( this, addr, &data, sizeof(BYTE) ) );
        }

        //-----------------------------------------------------------
        /*!
        */
        BOOL write( BYTE *data, DWORD len )
        {
          return ( ds.write( this, 0, data, len ) );
        }

      private:
        //-----------------------------------------------------------
        cDataStorage &ds;
        DWORD            startIndex;
        DWORD            length;
        cDataStorage::Record &record;



        friend cDataStorage;

      }; // class RecordHandler

class Record
    {
    public:

      Record(cDataStorage &ds,cDataStorage::Record &p, DWORD keyIN, DWORD length);

      void storeRecord();
      virtual void store() = 0;
      virtual void recall() = 0;


private:
      Header h; //char name[16];
      //DWORD size;
protected:
      RecordHandler rh;
    };
  public:
    //---------------------------------------------------------------
    /*!
    */
    cDataStorage( cHwMemory &memIN )
    : mem(memIN),
      crcCalulator( cCRC::SMALL )

    {
      error = 0;
    }



    //---------------------------------------------------------------
    /*!
    */
    void readHeader( Header *header, DWORD startIndex )
    {
      BYTE *ptr = (BYTE *)header;
      for(DWORD i=0;i<sizeof(Header);i++,startIndex++)
          *(ptr+i) = mem.read(startIndex);
    }

    //---------------------------------------------------------------
    /*!
    */
    void writeHeader( Header *header, DWORD startIndex )
    {
      BYTE *ptr = (BYTE *)header;
      for(DWORD i=0;i<sizeof(Header);i++,startIndex++)
          mem.write(startIndex, *(ptr+i));

    }

    //---------------------------------------------------------------
    /*!
    */
    DWORD find( RecordHandler *rh, Header &h )
    {
      DWORD index = 0;
      Header header;

      while( index + sizeof(Header) < mem.getSize() )
      {
        readHeader( &header, index );

        if( header == h )
        {
          return( index );
        }
        index += sizeof(Header)+header.length+2;
      }
      return( -1 );  // not found
    }

    //---------------------------------------------------------------
    /*!
    */
    bool open( RecordHandler *rh, Header &h )
    {
      DWORD index = 0;
      Header header;

      if( (index = find(rh, h )) != (DWORD)(-1) )
      {
        readHeader( &header, index );
        rh->startIndex = index;
        rh->length = header.length;
        return( true );
      }
      else
      {
        rh->startIndex = -1;
        rh->length = 0;

        error = 1;
        return( false );
     }
    }


    //---------------------------------------------------------------
    /*!
    */
    bool create(RecordHandler *rh, Header &h )
    {
      if( open(rh,h) == true )
      {
        return( true );
      }

      DWORD index = 0;
      Header header;

      while( index + sizeof(Header) < mem.getSize() )
      {
        readHeader( &header, index );
        if( header.length == 0 || header.length == (DWORD)(-1) )
          break;
        index += sizeof(Header)+header.length+2;
      }
      header = h;

      writeHeader( &header, index );
      rh->startIndex = index;
      rh->length = h.length;
      return( false );
    }

    //---------------------------------------------------------------
    /*!
    */
    bool read(RecordHandler *rh,DWORD addr, BYTE *data, DWORD len)
    {
      // todo: check at open: startIndex+sizeof(HEader)+rh->length < mem.getSize
      if( rh->startIndex != (DWORD)(-1) && addr+len <= rh->length )
      {
        DWORD index = rh->startIndex + sizeof(Header) + addr;

        for( DWORD i=0;i<len;i++,index++)
        {
          data[i] = mem.read(index);
        }
        WORD crc = (WORD)mem.read(index)<<8 | mem.read(index+1);

        if( cDataStorage::crcCalulator( data, len ) == crc )
        {
          return( true );
        }
      }
      return( false );

    }

    //---------------------------------------------------------------
    /*!
    */
    bool write(RecordHandler *rh,DWORD addr, BYTE *data, DWORD len)
    {
      // todo: check at open: startIndex+sizeof(HEader)+rh->length < mem.getSize
      if( rh->startIndex != (DWORD)(-1) && addr+len <= rh->length )
      {
        DWORD index = rh->startIndex + sizeof(Header) + addr;

        for( DWORD i=0;i<len;i++,index++)
        {
          mem.write(index,data[i]);
        }
        WORD crc = crcCalulator( data, len );
        mem.write(index,   crc>>8);
        mem.write(index+1, crc&0xFF);

        return( true );
      }
      return( false );
    }

    bool reorganize()
    {
      RecordHandler *rh = (RecordHandler *)rhList.getFirst();
      mem.clear();
      while( rh )
      {
        rh->update();
        rh = (RecordHandler *)rh->getNext();
      }
      return( false );
    }

  public:
    //---------------------------------------------------------------
    cHwMemory &mem;
    cList      rhList;
    int error;
    cCRC crcCalulator; //( cCRC::SMALL );

};

#endif // _DATA_STORAGE_H
