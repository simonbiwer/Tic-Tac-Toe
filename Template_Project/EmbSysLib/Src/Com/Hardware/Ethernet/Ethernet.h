#ifndef _HW_ETHERNET_H
#define _HW_ETHERNET_H
#define _HW_ETHERNET_C

#include "Com/Hardware/Net/NetStd.h"

#define BUFFER_SIZE  1500

#pragma pack(1)  //__packed

class cHwEthernet_Header
{
  public:                        // Byte No.:
    cNetAddr<6> destinationAddr; //  0
    cNetAddr<6> sourceAddr;      //  6
    cNetWORD    type;            // 12
	                               // length = 14
};     

#pragma pack(8)

class cNetARP;
class cNetIP;

//*****************************************************************************
class cHwEthernet
{
  public:
    enum
    {
      TYPE_IP    = 0x0800,
      TYPE_ARP   = 0x0806,
      TYPE_UNDEF = 0
    };

    cHwEthernet( const cNetAddr<6> &addrPhy );

    virtual void update();

    virtual void create( const cNetAddr<6> destAddr,
                         const WORD        type
                       ) = 0;

    virtual void PacketSend( BYTE *packet,
                             WORD  len                 
                           ) = 0;

    virtual bool PacketReceive( void ) = 0;

    virtual WORD getType( void ) = 0;
    
    void setARP( cNetARP *arpIn );
    void setIP( cNetIP *ipIn );

    /*const*/ cNetAddr<4> &getIP( void );
    bool isNewIP();    

  public:
    BYTE        buf[BUFFER_SIZE+1];
    WORD        plen;
    const cNetAddr<6> &addrPhy;
  
    cNetARP   *arp;
    cNetIP *ip;
  
};//cHwEthernet

#endif
