
#include "Com/Hardware/Net/NetARP.h"
#include "Com/Hardware/Net/NetIP.h"
#include "Ethernet.h"

//*******************************************************************
#include "Ethernet.h"

//*****************************************************************************
//*****************************************************************************
cHwEthernet::cHwEthernet( const cNetAddr<6> &addrPhyIn )

: addrPhy( addrPhyIn )
{
  plen    = 0;
  arp = NULL;
  ip  = NULL;
}

//*****************************************************************************
void cHwEthernet::update( void )
{
  if( PacketReceive( ) )
  {
    switch( getType() )
    {
      case cHwEthernet::TYPE_ARP: if( arp )  arp->process(); break;
      case cHwEthernet::TYPE_IP:  if(  ip )   ip->process(); break;
    }
  }
  
  if( ip )
  {    
    ip->update();
  }
}


//*****************************************************************************
void cHwEthernet::setARP( cNetARP *arpIn )
{
  arp = arpIn;
}

//*****************************************************************************
void cHwEthernet::setIP( cNetIP *ipIn )
{
  ip = ipIn;
}

//*****************************************************************************
/*const*/ cNetAddr<4> &cHwEthernet::getIP( void )
{
	static cNetAddr <4> ret = zeroAddr;
	
  if( ip )
    ret = ip->getAddr();
  return( ret );
}

//*****************************************************************************
bool cHwEthernet::isNewIP()
{
  if( ip )
    return( ip->isNewIP() );
  return( false );
}

