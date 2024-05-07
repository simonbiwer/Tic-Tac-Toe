#include "NetICMP.h"

//*****************************************************************************
cNetICMP::cNetICMP( cNetIP &ipIn )

: ip( ipIn )

{
  ip.setICMP( this );
}

//*****************************************************************************
void cNetICMP::process( void )
{
  cNetICMP_Msg &msg = *(cNetICMP_Msg*)ip.eth.buf;

  switch( msg.icmp.type )
  {
    case TYPE_ECHOREQUEST:

      WORD dataLen    = msg.ip.packetLength;
      WORD payloadLen = dataLen - (   sizeof( cNetIP_Header ) 
                                    + sizeof( cNetICMP_Header ) );
      ip.create( msg.eth.sourceAddr, 
                 msg.ip.sourceAddr, 
                 payloadLen+sizeof(cNetICMP_Header),
                 cNetIP::PROTOCOL_ICMP );

      msg.icmp.type = TYPE_ECHOREPLY;

      msg.icmp.checksum = 0;
      msg.icmp.checksum = Checksum( (BYTE*)&msg.ip, dataLen, 0 );

      ip.eth.PacketSend( ip.eth.buf,
                         sizeof( cHwEthernet_Header ) + dataLen );
      break;
  }
}

//EOF
