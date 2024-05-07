#ifndef _NET_ICMP_H
#define _NET_ICMP_H

//*******************************************************************
#include "NetIP.h"

#pragma pack(1)

class cNetICMP_Header
{
  public:              // Byte No.:
    cNetBYTE type;     //  0
    cNetBYTE code;     //  1
    cNetWORD checksum; //  2
                       // length = 4
};

class cNetICMP_Msg
{
  public:                    // Byte No.:
    cHwEthernet_Header eth;  //  0
    cNetIP_Header      ip;   // 14
    cNetICMP_Header    icmp; // 34
                             // length = 38
};

#pragma pack(8)

//*******************************************
//
//*******************************************
class cNetICMP
{
  public:
    cNetICMP( cNetIP &ip
            );

    void process( void );
    
    void update( void ) {}

    void timeout( void ) {}

  private:
    enum
    {
      TYPE_ECHOREPLY   = 0x00,
      TYPE_ECHOREQUEST = 0x08
    };
    
  private:
    cNetIP &ip;

}; //cNetICMP

#endif
