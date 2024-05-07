//*******************************************************************
#ifndef NET_DHCP_H
#define NET_DHCP_H

//*******************************************************************
#include "NetUDP.h"

//*******************************************************************
#pragma pack(1)
//*******************************************************************

//*******************************************************************
class cNetDHCP_Data
{
  public:                    // Byte No.:
    cNetBYTE    op;          //   0
    cNetBYTE    htype;       //   1
    cNetBYTE    hlen;        //   2
    cNetBYTE    hops;        //   3
    cNetDWORD   xid;         //   4
    cNetWORD    secs;        //   8
    cNetWORD    flags;       //  10
    cNetAddr<4> ciAddr;      //  12
    cNetAddr<4> yiAddr;      //  16
    cNetAddr<4> siAddr;      //  20
    cNetAddr<4> giAddr;      //  24
    cNetBYTE    chAddr[16];  //  28
    cNetBYTE    sname[64];   //  44
    cNetBYTE    bfile[128];  // 108
    cNetBYTE    options[64]; // 236
                             // length = 300
};

//*******************************************************************
#pragma pack(8)
//*******************************************************************

//*******************************************
//
//*******************************************
class cNetDHCP : public cNetApplication
{
  public:
    //-----------------------------------------------------------------
    cNetDHCP(cNetUDP     &udpIn,
             const char  *hostName = ""
            );

    //-----------------------------------------------------------------
    virtual void OnReceive( void );
    
    //-----------------------------------------------------------------
    virtual void OnUpdate( void ) {}

    //-----------------------------------------------------------------
    virtual void OnError( void );

    //-----------------------------------------------------------------
    virtual void OnTimeout( void );

  private:
   //-----------------------------------------------------------------
   enum
    {
      DISCOVER = 1,
      OFFER    = 2,
      REQUEST  = 3,
      DECLINE  = 4,
      ACK      = 5,
      NAK      = 6,
      RELEASE  = 7,
      INFORM   = 8
    };
    
  private:
    //-----------------------------------------------------------------
    void send( BYTE msgType );

    //-----------------------------------------------------------------
    BYTE parse_options( BYTE *optptr, 
                        int   len );

  private:   
    //-----------------------------------------------------------------
    const char        *hostName;
    //cNetAddr<4>       &addr; 
    const cNetAddr<6>  addrPhy;
    cNetAddr<4>        serverAddr;
    cNetUDP &udp;
    cNetUDP::Socket    con;
    
}; //cNetDHCP

#endif
