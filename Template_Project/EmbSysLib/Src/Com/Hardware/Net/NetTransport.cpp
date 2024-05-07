#include "NetTransport.h"

//-------------------------------------------------------------------
cNetTransport::Socket::Socket( cNetTransport   &transIn,
                                cNetApplication &appIn,
                                cNetAddr<4>      inAddrIn,
                                WORD             portIn )
: app  ( appIn   )

{
  addrPhy    = zeroAddrPhy;
  addr       = zeroAddr;
  myPort     = portIn;
  remoteAddr = inAddrIn;
  remotePort = portIn;
  timeOutTic = 0;
//  updateTime = MAX((WORD)(updateTimeIn/10),(WORD)1); // Timebase = 10 ms
//  updateTic  = updateTime;
    setTimeout(1);

  state      = STATE_WAITING;

  isServerFlag = (inAddrIn == broadcastAddr);
  transIn.appList.add( (cList::Item*)this );
}

//-------------------------------------------------------------------
//-------------------------------------------------------------------
cNetTransport::cNetTransport( /*cNetIP  &ipIn*/ )

//: ip (  ipIn )

{
}

//-------------------------------------------------------------------
void cNetTransport::process( void )
{
  Socket *ptr = (Socket *)appList.getFirst();

  while( ptr   )
  {
    ptr->process();
    ptr = (Socket *)ptr->getNext();
  }
}

//-------------------------------------------------------------------
void cNetTransport::update( void )
{
  Socket *ptr = (Socket *)appList.getFirst();

  while( ptr )
  {
    ptr->update();
    ptr = (Socket *)ptr->getNext();
  }
}

//-------------------------------------------------------------------
void cNetTransport::timeout( void )
{
  Socket *ptr = (Socket *)appList.getFirst();

  while( ptr )
  {
    ptr->timeout();
    ptr = (Socket *)ptr->getNext();
  }
}

//-------------------------------------------------------------------
cNetAddr<4> cNetTransport::Socket::getRemoteIP( void )
{
  return( remoteAddr );
}

