//*******************************************************************
#ifndef _NET_TCP_H
#define _NET_TCP_H

//*******************************************************************
class cNetARP;

//*******************************************
//
//*******************************************
class cNetTCP : public cNetTransport
{
  private:
    //***************************************************************
    //***************************************************************
    #pragma pack(1)
    class Header
    {
      public:                        // Byte No.:
        cNetWORD  sourcePort;        //   0
        cNetWORD  destPort;          //   2
        cNetDWORD sequenceNumber;    //   4
        cNetDWORD acknowledgeNumber; //   8
        cNetWORD  dataOffset_flags;  //  12
        cNetWORD  windowSize;        //  14
        cNetWORD  checksum;          //  16
        cNetWORD  urgentPointer;     //  18
        // no options and padding
                                     // length = 20

        //-----------------------------------------------------------     
        WORD getDataOffset()
        {
          return( (WORD)((dataOffset_flags.data & 0x00FF)>>4) * 4 );
        }

        //-----------------------------------------------------------     
        void setDataOffset( BYTE offset )
        {
          dataOffset_flags.data = (dataOffset_flags.data &0xFF00) | (offset/4)<<4;
        }

        //-----------------------------------------------------------     
        BYTE getFlags()
        {
          return( (dataOffset_flags.data & 0xFF00) >> 8 );
        }

        //-----------------------------------------------------------     
        void setFlags( BYTE flags )
        {
          dataOffset_flags.data = (dataOffset_flags.data &0x00FF) | ((WORD)flags<<8);
        }
    };
    #pragma pack(8)

  private:
    //*******************************************************************
    //***************************************************************
    #pragma pack(1)
    class Msg
    {
      public:                   // Byte No.:
        cHwEthernet_Header eth; //   0
        cNetIP_Header      ip;  //  14
        cNetTCP::Header    tcp; //  34
                                //  length = 54
    };
    #pragma pack(8)

  public:
    //***************************************************************
    //***************************************************************
    class Socket : public cNetTransport::Socket
    {
      public:
        //-----------------------------------------------------------
        Socket( cNetTCP         &tcp,
                cNetApplication &app,
                cNetAddr<4>      inAddr,
                WORD             port );

        virtual void open( cNetAddr<4> addr,
                           WORD port );

        virtual void close( void );

        virtual BYTE isConnected( void );

        virtual BYTE isReady( void );

        virtual void clear( void );

        virtual void fillBuffer( const char c);

        virtual void send( void );

        virtual BYTE get( char *c );

        virtual BYTE *getDataPtr( void );

        virtual void setDataLength( WORD len);

      private:
        //-------------------------------------------------------------------
        virtual BYTE process( void );
        virtual void update( void );
        virtual void timeout( void );

      private:
        enum
        {
          STATE_PENDING          = 100,
          STATE_OPEN_WAIT_SERVER,
          STATE_CONNECTED_WAIT_ACK,
          STATE_FINISHING
        };

      private:
        WORD     flags;
        BYTE     mss;
        DWORD    initialSeqNum;
        DWORD    seqNum;
        DWORD    ackNum;
        DWORD    ackNumExpected;
        cNetTCP &tcp;

      friend class cNetTCP;

    }; //class Socket

    //---------------------------------------------------------------
    enum
    {
      FLAG_NONE   = 0x00,
      FLAG_FIN    = 0x01,
      FLAG_SYN    = 0x02,
      FLAG_RST    = 0x04,
      FLAG_PUSH   = 0x08,
      FLAG_ACK    = 0x10,
      FLAG_URG_V  = 0x20,
      FLAG_ECE_V  = 0x40,
      FLAG_CWR_V  = 0x80
    };

  public:
    //---------------------------------------------------------------
    cNetTCP( cNetIP  &ip );

    virtual void handleARP( cNetAddr<4> addr, cNetAddr<6> addrPhy );

    virtual cNetAddr<4> getAddr( void )
    {
      return( ip.addr );
    }

    virtual const cNetAddr<6> getAddrPhy( void )
    {
      return( ip.eth.addrPhy );
    }

  private:
    //---------------------------------------------------------------
    void create( Socket &con, WORD payloadLen );

  private:
    //---------------------------------------------------------------
    cNetIP  &ip;
    WORD     inPos;
    WORD     inBufLen;
    BYTE    *buf;

}; // class cNetTCP

#endif
