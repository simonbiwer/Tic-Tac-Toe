//*******************************************
//
//*******************************************
//-------------------------------------------------------------------
cNetUDP::cNetUDP( cNetIP &ipIn ) //, cNetARP &arpIn )

: cNetTransport( ),
  ip( ipIn )

{
  ip.setUDP( this );
//  arp.setUDP( this );
}

//-------------------------------------------------------------------
void cNetUDP::create( Socket &con, WORD payloadLen )
{
  cNetUDP_Msg &msg = *(cNetUDP_Msg*)ip.eth.buf;

  msg.udp.sourcePort = con.myPort;
  msg.udp.destPort   = con.remotePort;
  msg.udp.length     = sizeof( cNetUDP_Header ) + payloadLen;

  ip.create( con.addrPhy,
             con.addr,
             payloadLen+sizeof(cNetUDP_Header),
             cNetIP::PROTOCOL_UDP );

  // Calculate checksum:
  WORD  len = sizeof( cNetUDP_Header) + payloadLen;

  msg.udp.checksum = 0;
  msg.udp.checksum = Checksum( (BYTE*)&msg.ip.sourceAddr,
                                len + 8,
                                (DWORD)len + cNetIP::PROTOCOL_UDP );

  ip.eth.PacketSend( ip.eth.buf,
                     sizeof( cNetUDP_Msg) + payloadLen );
}



//-------------------------------------------------------------------
//-------------------------------------------------------------------
cNetUDP::Socket::Socket( cNetUDP         &udpIn,
                         cNetApplication &appIn,
                         cNetAddr<4>      inAddrIn,
                         WORD             portIn,
                         WORD             updateTime )

: cNetTransport::Socket( (cNetTransport &)udpIn,
                         appIn,
                         inAddrIn,
                         portIn ),
  udp( udpIn )
{
}

//-------------------------------------------------------------------
//-------------------------------------------------------------------
void cNetUDP::Socket::open( cNetAddr<4> addrIn,
                            WORD        portIn )
{
  addr = addrIn;
  remotePort = portIn;

  if( addrIn == broadcastAddr )
  {
    addrPhy = broadcastAddrPhy;
    state   = STATE_WAITING;
  }
  else
  {
    state = STATE_OPEN_WAIT_ARP;
    udp.ip.arp.request( addr );
  }
  setTimeout( 5 );
}

//-------------------------------------------------------------------
void cNetUDP::Socket::close( void )
{
  state = STATE_WAITING;
}

//-------------------------------------------------------------------
BYTE cNetUDP::Socket::isConnected( void )
{
  return( state == STATE_CONNECTED );
}

//-------------------------------------------------------------------
BYTE cNetUDP::Socket::isReady( void )
{
  return(    !(udp.ip.addr == zeroAddr)
          &&   state == STATE_WAITING );
}

//-------------------------------------------------------------------
void cNetUDP::Socket::clear( void )
{
  udp.ip.eth.plen = 0;
}

//-------------------------------------------------------------------
void cNetUDP::Socket::fillBuffer( const char c )
{
  WORD pos = sizeof( cNetUDP_Msg ) + udp.ip.eth.plen;

  if( pos < BUFFER_SIZE )
  {
    udp.ip.eth.buf[pos] = c;
    udp.ip.eth.plen++;
  }

  if( pos + 1 >= BUFFER_SIZE )
  {
    send( );
  }
}

//-------------------------------------------------------------------
void cNetUDP::Socket::send( void )
{
  udp.create( *this, udp.ip.eth.plen );

  udp.ip.eth.plen = 0;
}

//-------------------------------------------------------------------
BYTE cNetUDP::Socket::get( char *c )
{
  if( udp.inPos < udp.inBufLen )
  {
    *c = udp.buf[udp.inPos++];
    return( true );
  }
  return( false );
}

//-------------------------------------------------------------------
BYTE *cNetUDP::Socket::getDataPtr( void )
{
  return( (BYTE*)&udp.ip.eth.buf[ sizeof(cNetUDP_Msg) ] );
}

//-------------------------------------------------------------------
void cNetUDP::Socket::setDataLength( WORD len )
{
  udp.ip.eth.plen = len;
}

//-------------------------------------------------------------------
//-------------------------------------------------------------------
BYTE cNetUDP::Socket::process( void )
{
  cNetUDP_Msg &msg = *(cNetUDP_Msg*)udp.ip.eth.buf;

  if( !(myPort == msg.udp.destPort) )
  {
    return( false );
  }

  WORD  dataLen = msg.udp.length - sizeof(cNetUDP_Header);
  BYTE *dataPtr = NULL;;

  if( dataLen > 0 )
  {
    WORD idx = sizeof( cNetUDP_Msg );
    dataPtr  = &udp.ip.eth.buf[ idx ];
  }

  if( state == STATE_WAITING
      && (   remoteAddr == broadcastAddr
          || remoteAddr == msg.ip.sourceAddr ) )
  {
    addrPhy = msg.eth.sourceAddr;
    addr    = msg.ip.sourceAddr;
    remotePort    = msg.udp.sourcePort;
    state   = STATE_CONNECTED;
  }
  if(    state == Socket::STATE_CONNECTED
      && dataLen > 0 )
  {
    udp.buf          = dataPtr;
    udp.inPos        = 0;
    udp.inBufLen     = dataLen;

    app.OnReceive();
  }

  return( true );
}

//-------------------------------------------------------------------
void cNetUDP::Socket::update( void )
{
  if(      state == STATE_OPEN_WAIT_ARP
      && !(addrPhy == zeroAddrPhy) )
  {
    state = STATE_CONNECTED;
  }

//  if( updateTic && !(--updateTic) )
//  {
//    updateTic = updateTime;
//    app.update();
//  }
}

//-------------------------------------------------------------------
void cNetUDP::Socket::timeout( void )
{
  if( timeOutTic && !(--timeOutTic) )
  {

    switch( state )
    {
      case STATE_OPEN_WAIT_ARP:
        state = STATE_WAITING;
        break;
    }
    app.OnError();
  }

//  if( updateTic && !(--updateTic) )
//  {
//    updateTic = updateTime;
    app.update();
//  }
}

//-------------------------------------------------------------------
void cNetUDP::handleARP( cNetAddr<4> addr, cNetAddr<6> addrPhy )
{
  Socket *ptr = (Socket *)appList.getFirst();
  while( ptr )
  {
    if(    ptr->addr == addr
        && (   ptr->state == Socket::STATE_WAITING
            || ptr->state == Socket::STATE_OPEN_WAIT_ARP ) )
    {
      ptr->addrPhy = addrPhy;
      ptr->state = Socket::STATE_OPEN_WAIT_ARP;
    }
    ptr = (Socket *)ptr->getNext();
  }
}


//EOF
