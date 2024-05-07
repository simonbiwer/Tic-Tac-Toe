#include "NetDHCP.h"

//*******************************************************************
// 
// cNetDHCP
//
//*******************************************************************
//-------------------------------------------------------------------
cNetDHCP::cNetDHCP( cNetUDP     &udpIn,
                    const char  *hostNameIn )

: //addr   ( udpIn.getAddr()    ),
  addrPhy( udpIn.getAddrPhy() ),
  udp    ( udpIn ),
  con    ( udpIn, *this, broadcastAddr, 68 )
{
  hostName       = hostNameIn;
  serverAddr     = zeroAddr;

  setTimeout( 1 );
}

//*****************************************************************************
void cNetDHCP::OnReceive()
{
  cNetDHCP_Data &dhcp = *(cNetDHCP_Data*)con.getDataPtr();

  // check message
  if(    dhcp.op   == 2               // DHCP reply?
      && dhcp.hlen == sizeof(addrPhy) // compare MAC-Addr
      && memcmp( (char*)&addrPhy,
                 dhcp.chAddr, 
                 sizeof(addrPhy) ) == 0 )
  {
    switch( parse_options( dhcp.options, sizeof(dhcp.options) ) )
    {
      case OFFER:
        if( serverAddr == zeroAddr )
        {
          serverAddr = dhcp.siAddr;
//          addr       = dhcp.yiAddr;
          udp.ip.addr = dhcp.yiAddr;
          con.open( broadcastAddr, 67 );
          send( REQUEST );
        }
        break;

      case ACK:
      case NAK:
        setTimeout( 3600 ); // refresh time in sec
        break;
    }
  }
}

//*****************************************************************************
void cNetDHCP::OnError()
{
}
  
//*****************************************************************************
void cNetDHCP::OnTimeout()
{
  if( udp.ip.addr == zeroAddr )
  {
    con.open( broadcastAddr, 67 );
    send( DISCOVER ); 
  }
  else
  {
    con.open( serverAddr, 67 );
    send( REQUEST ); 
  }
  setTimeout( 3 ); // refresh time in sec
}

//*****************************************************************************
BYTE cNetDHCP::parse_options( BYTE *optptr, int len )
{
  BYTE pos = 4; // skip magic code
  BYTE type = 0;

  while(pos < len) 
  {
    switch( optptr[pos] ) 
    {
      case 53: // message type
        type = optptr[pos + 2];
        break;

      case 255: // option end
        return type;
    }
    pos += optptr[pos+1] + 2;
  }
  return type;
}

//*****************************************************************************
void cNetDHCP::send( BYTE msgType )
{
  // Prepare data
  // ============
  cNetDHCP_Data &dhcp = *(cNetDHCP_Data*)con.getDataPtr();
  
  memset((char*)&dhcp, 0, sizeof(cNetDHCP_Data));
  
  dhcp.op    = 1; // DHCP request
  dhcp.htype = 1; // hardware-type: ethernet
  dhcp.hlen  = sizeof( addrPhy );
  dhcp.hops  = 0;
  dhcp.xid   = 0x1234abcd;
  dhcp.secs  = 0;
  dhcp.flags = 0x8000; // BOOTP broadcast

  memcpy( dhcp.chAddr, &addrPhy, dhcp.hlen );

  con.setDataLength( sizeof(cNetDHCP_Data) - sizeof(dhcp.options) );

  // Transmit data
  // =============
  // Add DHCP options
  // ----------------
  //
  // RFC 2132: magic cookie
  con.fill(  99 ); 
  con.fill( 130 );
  con.fill(  83 );
  con.fill(  99 );

  // RFC 2132: DHCP Message Type
  con.fill( 53 ); 
  con.fill( 1 );
  con.fill( msgType );

  // RFC 2132:  Host Name Option
  con.fill( 12 ); 
  con.fill( strlen( hostName ) );
  con.fill( hostName );

  // RFC 2132: End option
  con.fill( 255 ); 

  con.send();
}

//EOF
