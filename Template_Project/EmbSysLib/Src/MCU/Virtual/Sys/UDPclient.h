//*******************************************************************
/*!
\file   UDPclient.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _UDP_CLIENT_H
#define _UDP_CLIENT_H

//*******************************************************************
/*!
\class UDPclient

\brief


*/
//*******************************************************************
class UDPclient
{
  public:
  UDPclient( cNetAddr<4> addrIn, WORD portIn )
  {
    remoteAddr = addrIn;
    remotePort = portIn;

    if( /*firstWSA && */ WSAStartup(0x0202, &w) )
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

    if( (aSocket = socket( AF_INET, SOCK_DGRAM, IPPROTO_UDP )) == INVALID_SOCKET )
          {
            printf("\nWSA-ERROR:%u\n", WSAGetLastError() );
            return ;
          }

    SOCKADDR_IN saddr;
          saddr.sin_family = AF_INET;


            // Open as a client
            s = aSocket;
            saddr.sin_addr.s_addr = (DWORD)remoteAddr;
            saddr.sin_port        = htons(remotePort);

//            isConnectedFlag = true;

  }


  //-----------------------------------------------------------
        virtual void send( BYTE *buffer, WORD len )
        {
          if( len > 0  )
          {
            SOCKADDR_IN addr;

            addr.sin_family      = AF_INET;
            addr.sin_addr.s_addr = (DWORD)remoteAddr;
            addr.sin_port        = htons(remotePort);

            if( ::sendto( s,(const char*)buffer, len,0,(SOCKADDR*)&addr,sizeof(SOCKADDR_IN)) !=len )
            {
              printf("\nWSA-ERROR:%u\n",WSAGetLastError());
            }
          }
        }

        WORD receive(BYTE *buffer, WORD len)
        {
          int plen = 0;

          SOCKADDR_IN tmpAddr;
          int	tmpAddrLen = sizeof(SOCKADDR_IN);

          if( (plen = recvfrom(s, (char*)buffer,len, 0, (SOCKADDR*)&tmpAddr,&tmpAddrLen)) >  0)
          {
            ///////
return( plen );
            ///////
          }
          else if( plen < 0 )
          {

            int err = WSAGetLastError();

            if( err != 10035 && err != 10022)
            {
              printf("\nWSA-ERROR:%u\n",err);
            }

          }
					return(-1);
        }

        WORD transceive( BYTE *dataOut, WORD lenOut, BYTE *dataIn, WORD lenIn)
        {
          WORD len=0;
          send( dataOut, lenOut);
          while( (len=receive( dataIn, lenIn)) == 0 );
          return( len );
        }
  public:
    cNetAddr<4> remoteAddr;
    WORD        remotePort;

    WSADATA w;
    SOCKET  s;
        SOCKET  aSocket;
};

#endif
