#ifndef _NET_ARP_H
#define _NET_ARP_H

#include "Com/Hardware/Ethernet/Ethernet.h"

#pragma pack(1)

class cNetARP_Header
{
  public:                         // Byte No.:
    cNetWORD    hardwareType;     //  0
    cNetWORD    protocolType;     //  2
    cNetBYTE    physicalAddrLen;  //  4
    cNetBYTE    protocolAddrLen;  //  5
    cNetWORD    operationCode;    //  6
    cNetAddr<6> sourceAddrPhy;    //  8
    cNetAddr<4> sourceAddr;       // 14
    cNetAddr<6> destAddrPhy;      // 18
    cNetAddr<4> destAddr;         // 24
                                  // length = 28                                
};

class cNetARP_Msg
{
  public:                    // Byte No.:
    cHwEthernet_Header eth;  //  0
    cNetARP_Header     arp;  // 14
                             // length = 42
};

#pragma pack(8)

class cNetTCP;
class cNetUDP;

//*******************************************
//
//*******************************************
class cNetARP
{
  public:
    cNetARP( cHwEthernet &eth,
             //cNetIP      &ip //) //
  cNetAddr<4> &addr
           );

    void process( void );
  
    void request( cNetAddr<4> &addr 
                );
  
  void setTCP( cNetTCP *tcp 
               );

    void setUDP( cNetUDP *udp 
               );

  private:
    enum 
    {
      OPCODE_REQUEST = 0x0001,
      OPCODE_REPLY   = 0x0002
    };

  private:
    cHwEthernet  &eth;
    cNetAddr<4>  &addr;
    cNetARP_Msg  &msg;
    cNetTCP      *tcp;
    cNetUDP      *udp;

}; // cNetARP

#endif
