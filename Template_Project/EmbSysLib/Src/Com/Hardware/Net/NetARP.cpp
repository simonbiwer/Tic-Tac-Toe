#include "NetARP.h"
#include "NetTCP.h"
#include "NetUDP.h"
extern cDevTextIO_UART    com;


//*****************************************************************************
cNetARP::cNetARP( cHwEthernet &ethIn,
                  //cNetIP      &ip ) //
                  cNetAddr<4> &addrIn )

: eth ( ethIn  ), 
  addr( addrIn ) ,
  msg( *(cNetARP_Msg*)eth.buf )

{
  eth.setARP( this );
  tcp = NULL;
  udp = NULL;
}

//*****************************************************************************
void cNetARP::process( void )
{
  switch( msg.arp.operationCode )
  {
    case OPCODE_REQUEST:
      if( msg.arp.destAddr == addr )
      {
        eth.create( msg.eth.sourceAddr, cHwEthernet::TYPE_ARP );

        msg.arp.operationCode = OPCODE_REPLY;
        msg.arp.sourceAddrPhy = eth.addrPhy;
        msg.arp.sourceAddr    = addr;
        msg.arp.destAddrPhy   = msg.arp.sourceAddrPhy;
        msg.arp.destAddr      = msg.arp.sourceAddr;

        eth.PacketSend( (BYTE*)&msg, sizeof(cNetARP_Msg) ); 
      }
      break;

    case OPCODE_REPLY:
      if( tcp )
      {
        tcp->handleARP( msg.arp.sourceAddr, 
                        msg.arp.sourceAddrPhy );
      }
      if( udp )
      {
        udp->handleARP( msg.arp.sourceAddr, 
                        msg.arp.sourceAddrPhy );
      }
      break;
  }
}

//*****************************************************************************
void cNetARP::request( cNetAddr<4> &addrIn )
{
  eth.create( broadcastAddrPhy, cHwEthernet::TYPE_ARP );

  msg.arp.hardwareType    = (WORD)1; 
  msg.arp.protocolType    = 0x0800;
  msg.arp.physicalAddrLen = 6;
  msg.arp.protocolAddrLen = 4;
  msg.arp.operationCode   = OPCODE_REQUEST;
  msg.arp.sourceAddrPhy   = eth.addrPhy;
  msg.arp.sourceAddr      = addr;
  msg.arp.destAddrPhy     = broadcastAddrPhy;
  msg.arp.destAddr        = addrIn;

  eth.PacketSend( (BYTE*)&msg,  sizeof(cNetARP_Msg) ); 
}

//*****************************************************************************
void cNetARP::setTCP( cNetTCP *tcpIn )
{
  tcp = tcpIn;
}

//*****************************************************************************
void cNetARP::setUDP( cNetUDP *udpIn )
{
  udp = udpIn;
}

//EOF
