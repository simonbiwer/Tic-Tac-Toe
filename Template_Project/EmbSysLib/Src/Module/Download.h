//*******************************************************************
/*!
\file   Module/Download.h
\author Thomas Breuer
\date   04.05.2016
*/

//*******************************************************************
#ifndef _DOWNLOAD_H
#define _DOWNLOAD_H

//*******************************************************************
#include "Com/Std/CRC.h"
#include "Module/ISC.h"

//*******************************************************************
/*!
\class cDownload

\brief Download a data package via IPC to memory

This class can be used to download and store data in a memory (flash,
EERPOM,...). A download object can be linked to multiple memory areas.

\example cDownload.cpp
*/
class cDownload
{
  private:
    //***************************************************************
    class Reply
    {
      public:
        //-----------------------------------------------------------
        #pragma pack(1)
        class Data
        {
          public:
            static const DWORD blockSize = 32L;

          public:
            Data() {}
            WORD  error;
            WORD  crc;
            DWORD length;
            BYTE  payload[Data::blockSize];
        } data;
        #pragma pack()

        //-----------------------------------------------------------
        virtual void update() {}
    };

  private:
    //***************************************************************
    class Image
    {
      public:
        //-----------------------------------------------------------
        #pragma pack(1)
        class Data
        {
          public:
            static const DWORD blockSize = 32L;

          public:
            Data() {}
            WORD  index;
            WORD  option;
            DWORD numOfBlocks;
            DWORD blockId;
            BYTE  payload[Data::blockSize];

        } data;
        #pragma pack()

        //-----------------------------------------------------------
        Image( void );

        //-----------------------------------------------------------
        virtual void update( void );

      public:
        //-----------------------------------------------------------
        cISC::Data<Reply, 255> *out;
        cDownload              *download;

     friend class cDownload;
    };

  public:
    //***************************************************************
    /*!
    \class cDownload::Interface

    \brief Connecting a memory area with download
    */
    class Interface : public cList::Item
    {
      public:
        //-----------------------------------------------------------
        /*! Initialize an interface and connect a memory with a
            download object.
            \param download Reference to a download object
            \param mem Reference to a memory object
        */
        Interface( cDownload &download,
                   cHwMemory &mem );

        //-----------------------------------------------------------
        /*! This method is called by starting a download.

            The application can overwrite this function.
            \return true, if download enabled
        */
        virtual bool onStart( void ) { return( true ); }

        //-----------------------------------------------------------
        /*! This method is called after finishing a download

            The application can overwrite this function
        */
        virtual void onReady( void ) {}

        //-----------------------------------------------------------
        /*! Return and reset new data state

            \return true after a new download
        */
        virtual bool isNew( void );

        //-----------------------------------------------------------
        /*! Return running state
            \return true, if download is running
        */
        virtual bool isRunning( void );

        //-----------------------------------------------------------
        /*! Return data size
            \return number of downloaded data bytes
        */
        virtual DWORD getSize( void );

      private:
        //-----------------------------------------------------------
        virtual bool store( cDownload::Image::Data  &data,
                            cDownload::Reply::Data &reply );
        virtual bool read( cDownload::Image::Data  &data,
                            cDownload::Reply::Data &reply );

      private:
        //-----------------------------------------------------------
        bool       run;
        bool       isNewFlag;
        DWORD      totalSize;
        DWORD      numOfBlocks;

      public:
        //-----------------------------------------------------------
        cHwMemory &mem; //!< Reference to memory area

      friend class cDownload;
    };

  public:
    //---------------------------------------------------------------
    /*! Initialize a download object
        \param ipc Reference to an ipc
    */
    cDownload( cISC &isc );

  private:
    //---------------------------------------------------------------
    cISC                   &isc;
    cList                   interfaceList;
    cISC::Data<Image, 254>  in;
    cISC::Data<Reply, 255>  out;

}; //cDownload

#endif
