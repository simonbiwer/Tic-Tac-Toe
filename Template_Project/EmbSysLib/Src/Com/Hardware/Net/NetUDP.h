#ifndef NET_UDP_H
#define NET_UDP_H

#include "NetIP.h"

#pragma pack(1)

class cNetUDP_Header
{
  public:                // Byte No.:
    cNetWORD sourcePort; //   0
    cNetWORD destPort;   //   2
    cNetWORD length;     //   4
    cNetWORD checksum;   //   6
                         // length = 8
};

class cNetUDP_Msg
{
  public:                   // Byte No.:
    cHwEthernet_Header eth; //   0
    cNetIP_Header     ip;   //  14
    cNetUDP_Header    udp;  //  34
                            // length = 42
};

#pragma pack(8)

//*******************************************
//
//*******************************************

class cNetUDP : public cNetTransport
{
  public:
    //*******************************************************************
    class Socket : public cNetTransport::Socket
    {
      public:
        //-----------------------------------------------------------
        Socket( cNetUDP         &udp,
                cNetApplication &app,
                cNetAddr<4>      inAddr,
                WORD             port,
                WORD             updateTime = 0
              );

      virtual void open( cNetAddr<4> addr,
                         WORD        port );

      virtual void close( void );

      virtual BYTE isConnected( void );

      virtual BYTE isReady( void );

      virtual void clear( void );

      virtual void fillBuffer( const char c );

      virtual void send( void );

      virtual BYTE get( char *c );

      virtual BYTE *getDataPtr( void );

      virtual void setDataLength( WORD len );


      private:
        //-------------------------------------------------------------------
        virtual BYTE process( void );
        virtual void update( void );
        virtual void timeout( void );


      private:
        WORD        dataLen;
        BYTE       *dataPtr;

        cNetUDP         &udp;

      friend class cNetUDP;

    }; //Socket

    //*******************************************************************
    cNetUDP( cNetIP   &ip//,
             //cNetARP  &arp
           );

    virtual void handleARP( cNetAddr<4> addr, cNetAddr<6> addrPhy );

  private:
    //---------------------------------------------------------------
    void create( Socket &con, WORD payloadLen );
  public:
    virtual cNetAddr<4> getAddr( void )
    {
      return( ip.addr );
    }

    virtual const cNetAddr<6> getAddrPhy( void )
    {
      return( ip.eth.addrPhy );
    }

  public:
    cNetIP   &ip;

  private:
    WORD inPos;
    WORD inBufLen;
    BYTE *buf;

}; //cNetUDP

#endif
