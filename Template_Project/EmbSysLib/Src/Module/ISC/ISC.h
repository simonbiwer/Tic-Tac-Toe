//*******************************************************************
/*!
\file   Module/ISC.h
\author Thomas Breuer
\date   11.12.2014, 17.03.2016
*/

//*******************************************************************
#ifndef _ISC_H
#define _ISC_H

//*******************************************************************
#include "Com/Std/CRC.h"

//*******************************************************************
/*!
\class cISC

\brief ISC transport base class

This class is the base class for ISC transport objects. Derived
classes use a communication port to transport ISC data objects.
A 16-bit CRC is used.

To create an ISC data object:
- Define an application specific class with POD subclass named \b
  'Data'
- This class may have an \b update() method, which is called on
  data receive
- Instantiate an object from the template class cISC::Data.
  The first template parameter is the name of the aplication
  specific data class.
  The second parameter must be an unique ID to identify data objects

\example cISC.cpp
*/
class cISC
{
public:
      //*******************************************************************
  #pragma pack(1)
  class DATA
  {
    public:
      static const WORD maxLength = 60;

      WORD crcValue;
      BYTE id;
      BYTE reserved;
      BYTE data[ maxLength ];
  };
  #pragma pack()

  protected:
    //---------------------------------------------------------------
    class DataInterface : public cList::Item
    {
      public:
        //-----------------------------------------------------------
        virtual void update( void ) {}

      public:
        //-----------------------------------------------------------
        BYTE *dataRef;
        WORD  dataLength;
        BYTE  id;
    }; // cISC::DataInterface
    //---------------------------------------------------------------

  public:
    //---------------------------------------------------------------
    /*! Template class for ISC data objects
        \param T Used data class
        \param ID Unique identifier
    */
    template <class T, BYTE ID> class Data : DataInterface
    {
      public:
        //-----------------------------------------------------------
        /*! Instantiate an ISC data object
            \param ISCIn Reference to an ISC. The instantiated object
                         is bound to this ISC transport object
        */
        Data( cISC &ISCIn )
        : data( prop.data ),
          ISC ( ISCIn     )

        {
          dataRef    = (BYTE*)&prop.data;
          dataLength = sizeof( typename T::Data );
          id         = ID;
          flag       = false;
          ISC.list.add( this );
        }

        //-----------------------------------------------------------
        /*! Write an object

            The object is written with the ISC transport object
            defined by Constructor
        */
        void write( void )
        {
          ISC.write( id, dataRef, dataLength );
        }

        //-----------------------------------------------------------
        /*! Ceck, if new data are received

            \return
                    - true, if new data are received
                    - false otherwise
        */
        BYTE isNew( void )
        {
          if( flag )
          {
            flag = false;
            return( true );
          }
          else
          {
            return( false );
          }
        }

      protected:
        //-----------------------------------------------------------
        virtual void update( void )
        {
          flag = true;
          prop.update();
        }

      public:
        //-----------------------------------------------------------
        typename T::Data &data;
        T                 prop;

      protected:
        //-----------------------------------------------------------
        cISC  &ISC;
        BYTE   flag;

    }; // cISC::Data
    //---------------------------------------------------------------

  protected:
    //---------------------------------------------------------------
    cISC( cCRC::MODE crcMode );

  public:
    //---------------------------------------------------------------
    virtual void update( void ) = 0;

  protected:
    //---------------------------------------------------------------
    virtual void write( BYTE id, BYTE *data, BYTE size );

    //---------------------------------------------------------------
  public:
    virtual void writeStream( BYTE  id,
                              BYTE *data,
                              BYTE  size,
                              WORD  crc ) = 0;

  protected:
    public:
    //---------------------------------------------------------------
    cList    list;
    cCRC     crc;

}; //cISC

#endif
