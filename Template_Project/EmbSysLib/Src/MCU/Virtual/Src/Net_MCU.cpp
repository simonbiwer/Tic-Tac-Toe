#include <conio.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

#include <iostream>
#include <stdio.h>

using namespace std;

// Quelle:
// http://www.codeproject.com/Articles/13071/Programming-Windows-TCP-Sockets-in-C-for-the-Begin
#include <windows.h>
#include <winsock.h>

//*******************************************************************
#include "Net_MCU.h"

//*******************************************************************
//
// cNetWin
//
//*******************************************************************
//-------------------------------------------------------------------
cNetWin::cNetWin( void )
{
  tcp = NULL;
  udp = NULL;
  timeTic = GetSysTimeMilliSec();

  if( firstWSA && WSAStartup(0x0202, &w) )
  {
    printf("\nWSA-ERROR:%u\n",WSAGetLastError());
    return ;
  }
  firstWSA = false;

  if( w.wVersion != 0x0202 )
  {
    WSACleanup ();
    return ;
  }
}

//-------------------------------------------------------------------
void cNetWin::update()
{
  if( tcp )  tcp->process();
  if( udp )  udp->process();

  if( tcp )  tcp->update();
  if( udp )  udp->update();

  long int timeTicNow = GetSysTimeMilliSec();

  if( timeTicNow - timeTic >= 10 )
  {
    timeTic = timeTicNow;

    if( tcp )  tcp->timeout();
    if( udp )  udp->timeout();
  }
}

//-------------------------------------------------------------------
void cNetWin::setTCP( cNetWinTransport *transportIn )
{
  tcp = transportIn;
}

//-------------------------------------------------------------------
void cNetWin::setUDP( cNetWinTransport *transportIn )
{
  udp = transportIn;
}

//-------------------------------------------------------------------
/*const */cNetAddr<4> &cNetWin::getIP( void )
{
  static cNetAddr <4> ret = zeroAddr;

  PHOSTENT hostinfo = gethostbyname("");
  if( hostinfo )
  {
    struct in_addr addr = *(struct in_addr *)*hostinfo->h_addr_list;

    ret = addr.S_un.S_addr;
  }
  return( ret );
}

// EOF
