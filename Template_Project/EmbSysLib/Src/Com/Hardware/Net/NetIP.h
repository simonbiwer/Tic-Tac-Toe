//*******************************************************************
#ifndef _NET_IP_H
#define _NET_IP_H

#include "Com/Hardware/Ethernet/Ethernet.h"
#include "Com/Hardware/Timer/Timer.h"

//*******************************************************************
#pragma pack(1)

class cNetIP_Header
{
  public:                             // Byte No.:
    cNetBYTE    version_IHL;          //  0
    cNetBYTE    TypeOfService;        //  1
    cNetWORD    packetLength;         //  2
    cNetWORD    identification;       //  4
    cNetWORD    flags_fragmentOffset; //  6
    cNetBYTE    TTL;                  //  8
    cNetBYTE    protocol;             //  9
    cNetWORD    headerChecksum;       // 10
    cNetAddr<4> sourceAddr;           // 12
    cNetAddr<4> destAddr;             // 16
    // no options                     //
                                      // length = 20

    // getter und setter für flags und fragmentOffset
    BYTE getFlags()
    {
      return( flags_fragmentOffset.data & 0x00FF );
    }

    void setFlags( BYTE flags )
    {
      flags_fragmentOffset.data = (flags_fragmentOffset.data & 0xFF00) | flags;
    }

    BYTE getFragmentOffset()
    {
      return( (flags_fragmentOffset.data & 0xFF00) >> 8 );
    }

    void setFragmentOffset( BYTE offset )
    {
      flags_fragmentOffset.data = (flags_fragmentOffset.data & 0x00FF) | ((WORD)offset<<8);
    }
};

//*******************************************************************
class cNetIP_Msg
{
  public:                   // Byte No.:
    cHwEthernet_Header eth; //   0
    cNetIP_Header      ip;  //  14
                            // length = 34
};

//*******************************************************************
#pragma pack(8)

//*******************************************************************
class cNetICMP;
class cNetTCP;
class cNetUDP;

//*******************************************
//
//*******************************************
class cNetIP
{
  public:
    enum
    {
      PROTOCOL_NONE = 0x00,
      PROTOCOL_ICMP = 0x01,
      PROTOCOL_TCP  = 0x06,
      PROTOCOL_UDP  = 0x11
    };

  public:
    //---------------------------------------------------------------
    cNetIP( cHwEthernet &eth,
            const cNetAddr<4> &addr,
            cHwTimer    &timer
          );

    void create( const cNetAddr<6> destAddrPhy,
                 const cNetAddr<4> destAddr,
                 const WORD        len,
                 const WORD        protocol
               );

    void process( void );

    void update();

    void setTCP( cNetTCP  *tcp
               );

    void setUDP( cNetUDP  *udp
               );

    void setICMP( cNetICMP *icmp
                );

    cNetAddr<4> &getAddr( void )
    {
      return( addr );
    }
    
    bool isNewIP()
    {
      if( addr.addr[0] != 0 && !isNewIP_flag ) 
      {
        isNewIP_flag = true;
        return( true );
      }
      return( false );
    }      

  private:
    //*******************************************************************
  class cTimeOutTimer : public cList::Item
    {
      public:
        //---------------------------------------------------------------
        cTimeOutTimer( cHwTimer &timer )
        {
          timer.add( this );
          max = 10000L / timer.getCycleTime(); // once per 10 miliseconds

          if( max > 0 )
            max--;
          
          cnt = max;
        }

        //---------------------------------------------------------------
        virtual void update( void )
        {
          if( !(cnt--) )
          {
            cnt = max;
            flag = true;
          }
        }

        //---------------------------------------------------------------
        WORD cnt;
        WORD max;
        BYTE flag;
    };

  public:
    //---------------------------------------------------------------
    cHwEthernet &eth;
    cNetAddr<4>  addr;
    cNetARP      arp;

  private:
    //---------------------------------------------------------------
    static const BYTE  VERSION_IHL   = (0x40 | 0x05); // IPv4, 5x4=20 Byte header length

    cTimeOutTimer timeOutTimer;

    cNetIP_Msg &msg;
    cNetUDP    *udp;
    cNetTCP    *tcp;
    cNetICMP   *icmp;
  
    bool isNewIP_flag;

}; // cNetIP

#endif
