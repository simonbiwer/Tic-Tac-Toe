
//-----------------------------------------------------------------
class cHwUSBinterfClassCDC : public cHwUSBinterf, public cHwUART
{
  public:
    //-----------------------------------------------------------------
    class cInterface : public cHwUSBinterf
    {
      public:
        //---------------------------------------------------------------
        cInterface(cHwUSB &usb, BYTE interfId)
        : cHwUSBinterf(usb, 1, interfId)

        {
        }

       //---------------------------------------------------------------
        virtual bool transmit(BYTE epId,cDataPointer &data)
        {
          data = cDataPointer( );
          return( true );
        }

        //---------------------------------------------------------------
        virtual int transmitCtrl(cDataPointer &data)
        {
          data = cDataPointer();
          return(true);
        }

        //---------------------------------------------------------------
        virtual bool receive(BYTE epId, WORD cnt)
        {
          return(true);
        }

        //---------------------------------------------------------------
        virtual int receiveCtrl( WORD cnt)
        {
          return(true);
        }

        //---------------------------------------------------------------
        virtual bool requestCtrlIN( cDataPointer &dataPtr,
                                   BYTE          request,
                                   WORD          value,
                                   WORD          length )
        {
          dataPtr = cDataPointer();
          return( true );
        }

        //---------------------------------------------------------------
        virtual bool requestCtrlOUT( cDataPointer &dataPtr,
                                   BYTE          request,
                                   WORD          value,
                                   WORD          length )
        {
           return( true );
        }

        //---------------------------------------------------------------
        virtual bool request( BYTE epId,cDataPointer &epdata )
        {
          epdata = cDataPointer(  );
          return( true );
        }

    };

  public:
    //---------------------------------------------------------------
    cHwUSBinterfClassCDC( cHwUSB &usb, BYTE interfId, BYTE interfId_I )

    : cHwUSBinterf ( usb, 1, interfId ),
      cHwUART      ( 100, 100 ),
      CDC_Interface( usb, interfId_I )

    {
      isInProgress = false;
    }

    //---------------------------------------------------------------
virtual bool transmit(BYTE epId,cDataPointer &data)
{
      if(  dataTxBuf.isEmpty() )
      {
        data = cDataPointer();
        isInProgress = false;
        return(false);
      }
      else
      {
        WORD c=0;
        while( !dataTxBuf.isEmpty() && c <64)
        {
          dataTxBuf>>dataBufTX[c++];
        }

        data = cDataPointer(dataBufTX,c);
        return( true );
      }
    }

    //---------------------------------------------------------------
    virtual int transmitCtrl(cDataPointer &data)
    {
      data = cDataPointer();
      return(true);
    }

    //---------------------------------------------------------------
    virtual bool receive(BYTE epId, WORD cnt)
    {
      WORD i=0;

      while( !dataRxBuf.isFull() && i < cnt)
      {
        dataRxBuf << (BYTE)dataBuf[i++];
      }
      return(true);
    }

        //---------------------------------------------------------------
        virtual int receiveCtrl( WORD cnt)
        {
          return(true);
        }

        //---------------------------------------------------------------
        virtual bool requestCtrlIN( cDataPointer &dataPtr,
                                   BYTE          request,
                                   WORD          value,
                                   WORD          length )
        {
          dataPtr = cDataPointer();
          return( true );
        }

        //---------------------------------------------------------------
        virtual bool requestCtrlOUT( cDataPointer &dataPtr,
                                   BYTE          request,
                                   WORD          value,
                                   WORD          length )
        {
           return( true );
        }

        //---------------------------------------------------------------
        virtual bool request( BYTE epId,cDataPointer &epdata )
        {
          epdata = cDataPointer( dataBuf );
          return( true );
        }


    //---------------------------------------------------------------
    virtual bool get( BYTE *x)
    {
      if( dataRxBuf.isEmpty() )
      {
        return ( false );
      }
      else
      {
        BYTE t;
        dataRxBuf>>t;
        *x = t;
        return( true );
      }
    }

    //---------------------------------------------------------------
    virtual void set( BYTE x )
    {
      if( !dataTxBuf.isFull() )
      {
        dataTxBuf<<x;
      }

      cSystem::disableInterrupt();

      if( !isInProgress && epIN )
      {

        epIN->writeData( cDataPointer() );
        isInProgress = true;
      }
      cSystem::enableInterrupt();

    }

    //---------------------------------------------------------------
    virtual void set( BYTE *data, BYTE size )
    {
       while( size-- )
       {
         set( *(data++ ) ); // put a character and set pointer to next
       }
    }

    //---------------------------------------------------------------
    virtual void set( const char *str )
    {
      set( (BYTE*)str, (BYTE)strlen( str ) );
    }

    //---------------------------------------------------------------
    virtual BYTE getByte( void )
    {
      return( 0 );
    }

    //---------------------------------------------------------------
    virtual void setByte( BYTE data )
    {
    }

    //---------------------------------------------------------------
    BYTE        dataBuf[64];
    BYTE        dataBufTX[64];
    BYTE        isInProgress;
    cInterface  CDC_Interface;
};

