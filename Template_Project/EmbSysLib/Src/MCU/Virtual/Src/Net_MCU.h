//*******************************************************************
#ifndef _HW_NET_WINSOCKET_H
#define _HW_NET_WINSOCKET_H
#define _HW_NET_WINSOCKET_C

//*******************************************************************
#include <windows.h>
#include <winsock.h>
#include <stdio.h>

//*******************************************************************
#include "Com/Hardware/Net/NetStd.h"
#include "Com/Hardware/Net/NetApp.h"
#include "Com/Hardware/Net/NetTransport.h"

//*******************************************************************
class cNetWinTransport;
class cNetTCP;
class cNetUDP;

//*******************************************************************
static BYTE firstWSA = true;

//*******************************************************************
/*!
\class cNetWin

\brief

\example
*/
class cNetWin
{
  public:
    //---------------------------------------------------------------
    cNetWin( void );

    //---------------------------------------------------------------
    virtual void update();

    //---------------------------------------------------------------
    /*const */cNetAddr<4> &getIP( void );

  private:
    //---------------------------------------------------------------
    virtual void setTCP( cNetWinTransport *transportIn );

    //---------------------------------------------------------------
    virtual void setUDP( cNetWinTransport *transportIn );

  public:
    //---------------------------------------------------------------
    static const WORD bufSize = 2000;

    BYTE buf[bufSize];
    WORD bufLen;
    WORD bufIdx;

    long int timeTic;

   private:
    //---------------------------------------------------------------
    cNetWinTransport *tcp;
    cNetWinTransport *udp;

    WSADATA w;

  friend cNetTCP;
  friend cNetUDP;
};

//*******************************************************************
/*!
\class cNetWinTransport

\brief

\example
*/
class cNetWinTransport : public cNetTransport
{
  public:
    //***************************************************************
    class Socket : public cNetTransport::Socket
    {
      public:
        //-----------------------------------------------------------
        Socket( cNetWinTransport &transportIn,
                cNetApplication  &app,
                cNetAddr<4>       remoteAddr,
                WORD              port )

        : cNetTransport::Socket( transportIn,
                                 app,
                                 remoteAddr,
                                 port ),

          transport( transportIn )

        {
          isServerFlag    = (remoteAddr == broadcastAddr);
          isConnectedFlag = false;
          aSocket = 0;
          s = 0;
        }

        //-----------------------------------------------------------
        virtual void open( cNetAddr<4> addr,
                           WORD        portIn ) = 0;

        //-----------------------------------------------------------
        virtual void close( void ) = 0;

        //-----------------------------------------------------------
        virtual BYTE process( void ) = 0;

        //-----------------------------------------------------------
        virtual void update( void )
        {
        }

        //-----------------------------------------------------------
        virtual void timeout( void )
        {
          if( timeOutTic && !(--timeOutTic) )
          {
            app.OnError();
          }
          app.update();
        }

        //-----------------------------------------------------------
        virtual BYTE isConnected( void )
        {
          return( isConnectedFlag );
        }

        //-----------------------------------------------------------
        virtual BYTE isReady( void )
        {
          return( !isConnectedFlag );
        }

        //-----------------------------------------------------------
        virtual BYTE isServer()
        {
            return( isServerFlag );
        }
        //-----------------------------------------------------------
        virtual void clear( void )
        {
          transport.net.bufIdx = 0;
          transport.net.bufLen = 0;
        }

        //-----------------------------------------------------------
        virtual BYTE *getDataPtr()
        {
          return(0);
        }

        //-----------------------------------------------------------
        virtual void setDataLength(WORD len)
        {
        }

        //-----------------------------------------------------------
        virtual void send( void ) = 0;

        //-----------------------------------------------------------
        virtual BYTE get( char *c )
        {
          if( transport.net.bufIdx < transport.net.bufLen )
          {
            *c = transport.net.buf[transport.net.bufIdx++];
            return( true );
          }
          return( false );
        }

      private:
        //-----------------------------------------------------------
        virtual void fillBuffer( const char c )
        {
          if( transport.net.bufIdx >= transport.net.bufSize )
          {
            send();
          }
          transport.net.buf[transport.net.bufIdx] = c;
          transport.net.bufIdx++;
          transport.net.bufLen++;
        }

      protected:
        //-----------------------------------------------------------
        SOCKET  s;
        SOCKET  aSocket;
        WSADATA w;
        BYTE    isServerFlag;
        BYTE    isConnectedFlag;

        cNetWinTransport &transport;

    }; // class Socket
    //***************************************************************

  public:
    //---------------------------------------------------------------
    cNetWinTransport( cNetWin &netIn )
    : net( netIn )
    {
    }

  public:
    //---------------------------------------------------------------
    cNetWin &net;

}; // class cNetWinTransport


//*******************************************************************
/*!
\class cNetTCP

\brief

\example
*/
class cNetTCP : public cNetWinTransport
{
  public:
    //***************************************************************
    class Socket : public cNetWinTransport::Socket
    {
      public:
        //-----------------------------------------------------------
        Socket( cNetWinTransport &transportIn,
                cNetApplication  &app,
                cNetAddr<4>       remoteAddr,
                WORD              port )

        : cNetWinTransport::Socket( transportIn,
                                    app,
                                    remoteAddr,
                                    port )
        {
          if( isServerFlag )
          {
          //  open( broadcastAddr, port);
          }
        }

        //-----------------------------------------------------------
        virtual void open( cNetAddr<4> addr,
                           WORD port )
        {
          remoteAddr = addr;
          remotePort = port;

          if( WSAStartup(0x0202, &w) )
          {
            printf("\nWSA-ERROR:%u\n",WSAGetLastError());
            return ;
          }

          if( w.wVersion != 0x0202 )
          {
            WSACleanup ();
            return ;
          }

          if( (aSocket = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP )) == INVALID_SOCKET )
          {
            printf("\nWSA-ERROR:%u\n",WSAGetLastError());
            return ;
          }

          SOCKADDR_IN saddr;
          saddr.sin_family = AF_INET;

          if( isServerFlag )
          {
            // Open as a server
            saddr.sin_addr.s_addr = htonl(INADDR_ANY);
            saddr.sin_port        = htons(port);
            if( bind( aSocket, (LPSOCKADDR)&saddr, sizeof(saddr) ) == SOCKET_ERROR )
            {
              printf("\nWSA-ERROR:%u\n",WSAGetLastError());
              return ;
            }

            if( listen(aSocket, 2) == SOCKET_ERROR )
            {
              printf("\nWSA-ERROR:%u\n",WSAGetLastError());
              return ;
            }

            s = 0;

            unsigned long arg = 1;
            ioctlsocket(aSocket, FIONBIO, &arg);
          }
          else
          {
            // Open as a client
            s = aSocket;
            saddr.sin_addr.s_addr = (DWORD)remoteAddr;
            saddr.sin_port        = htons(port);
            if (connect(s, (SOCKADDR *)&saddr, sizeof(saddr)) == SOCKET_ERROR)
            {
              printf("\nWSA-ERROR:%u\n",WSAGetLastError());

              close();
              return ; //Couldn't connect
            }

            unsigned long arg = 1;
            ioctlsocket(s, FIONBIO, &arg);
            isConnectedFlag = true;
          }
          //TODO (from ORB)
//          BOOL flag = true;
//          int e = setsockopt(s, SOL_SOCKET, TCP_NODELAY, (char *) &flag, sizeof(flag));
//          if(e)
//            printf("e=%d\n",e);
          //---------------
        }

        //-----------------------------------------------------------
        virtual void close( void )
        {
          send();
          if( s )
          {

            closesocket(s);
            //closesocket(aSocket);
            if( !isServerFlag )
            {
             //   WSACleanup();
            }
          }
          isConnectedFlag = false;
          s=0;
          printf("\nclosed\n");
        }


        //-----------------------------------------------------------
        virtual void send( void )
        {
          if( transport.net.bufLen > 0 )
          {
            if( ::send( s,(const char*)transport.net.buf, transport.net.bufLen,0) !=transport.net.bufLen )
            {
             //printf("\nWSA-ERROR:%u\n",WSAGetLastError());
             int err = WSAGetLastError();
              if( err != 10054 )
                  printf("\nWSA-ERROR:%u\n",err);
                  /// close();
            }
            transport.net.bufIdx = 0;
            transport.net.bufLen = 0;
          }
        }

        //-----------------------------------------------------------
        virtual BYTE process( void )
        {
          if( isServerFlag && s == 0 )
          {
            SOCKADDR saddr;
            int         addrLen = sizeof(SOCKADDR);

            if( (int)(s = accept(aSocket, &saddr, &addrLen)) > 0 )
            {
              isConnectedFlag = true;

              unsigned long arg = 1;
              ioctlsocket(s, FIONBIO, &arg);
              remoteAddr = *(DWORD*)&saddr.sa_data[2];

              printf("accepted %u.%u.%u.%u\n", remoteAddr.addr[0],
                                               remoteAddr.addr[1],
                                               remoteAddr.addr[2],
                                               remoteAddr.addr[3]);
            }
            else
            {
              s = 0;
            }
          }

          if(s==0)
          {
            return 0;
          }

          int plen = 0;

          if( (plen = recv(s, (char*)transport.net.buf,transport.net.bufSize,0 )) >  0)
             {
               transport.net.bufIdx = 0;
               transport.net.bufLen = plen;
               app.OnReceive();
             }
             //else if( plen < 0 )
             //TODO (ORB)
              else if( plen < 0 || (plen == 0 && isServerFlag) )
             //

             {
               transport.net.bufIdx = 0;
               transport.net.bufLen = 0;

               int err = WSAGetLastError();

                if( err != 10035 )
                 {
                 if( err != 10054 )
                  printf("\nWSA-ERROR:%u\n",err);
                   close();


                 }
             }
           transport.net.bufIdx = 0;
           transport.net.bufLen = 0;
           return(1);
        }
    };  // class Socket
    //***************************************************************

  public:
    //---------------------------------------------------------------
    cNetTCP( cNetWin &netIn )
    : cNetWinTransport( netIn )
    {
      net.setTCP( this );
    }

    virtual cNetAddr<4> getAddr( void )
    {
      return( net.getIP() );
    }

    virtual const cNetAddr<6> getAddrPhy( void )
    {
      static cNetAddr<6> ret = {0,0,0,0,0,0};
      return( ret ); //ip.eth.addrPhy );
    }

};

//*******************************************************************
/*!
\class cNetUDP

\brief

\example
*/
class cNetUDP : public cNetWinTransport
{
  public:
    //***************************************************************
    class Socket : public cNetWinTransport::Socket
    {
      public:
        //-----------------------------------------------------------
        Socket( cNetWinTransport &transportIn,
                  cNetApplication  &app,
                  cNetAddr<4>       remoteAddr,
                  WORD              port )

        : cNetWinTransport::Socket( transportIn,
                                    app,
                                    remoteAddr,
                                    port )
        {
          if( isServerFlag )
          {
          //  open( remoteAddr, remotePort );
          }
        }

        //-----------------------------------------------------------
        virtual void open( cNetAddr<4> addr,
                           WORD port )
        {
          remoteAddr = addr;
          remotePort = port;

          if( WSAStartup(0x0202, &w) )
          {
            printf("\nWSA-ERROR:%u\n",WSAGetLastError());
            return ;
          }

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

          if( isServerFlag )
          {
            // Open as a server
            saddr.sin_addr.s_addr = htonl(INADDR_ANY);
            saddr.sin_port        = htons(port);
            if( bind( aSocket, (LPSOCKADDR)&saddr, sizeof(saddr) ) == SOCKET_ERROR )
            {
              printf("\nWSA-ERROR:%u\n",WSAGetLastError());
              return ;
            }

            s = aSocket;

          }
          else
          {
            // Open as a client
            s = aSocket;
            saddr.sin_addr.s_addr = htonl(INADDR_ANY); //(DWORD)remoteAddr;
            saddr.sin_port        = htons(port+1);

            if( bind( aSocket, (LPSOCKADDR)&saddr, sizeof(saddr) ) == SOCKET_ERROR )
            {
              printf("\nWSA-ERROR:%u\n",WSAGetLastError());
              return ;
            }
            isConnectedFlag = true;
          }
          unsigned long arg = 1;
          ioctlsocket(s, FIONBIO, &arg);
        }

        //-----------------------------------------------------------
        virtual void close( void )
        {
//          send();
//
          if( isConnectedFlag )
          {

            closesocket(s);
          }
          isConnectedFlag = false;
          printf("closed\n");
        }


        //-----------------------------------------------------------
        virtual void send( void )
        {
          if( transport.net.bufLen > 0  )
          {
            SOCKADDR_IN addr;

            addr.sin_family      = AF_INET;
            addr.sin_addr.s_addr = (DWORD)remoteAddr;
            addr.sin_port        = htons(remotePort);
            if( ::sendto( s,(const char*)transport.net.buf, transport.net.bufLen,0,(SOCKADDR*)&addr,sizeof(SOCKADDR_IN)) !=transport.net.bufLen )
            {
              printf("\nWSA-ERROR:%u\n",WSAGetLastError());
            }

            transport.net.bufIdx = 0;
            transport.net.bufLen = 0;
          }
        }

        //-----------------------------------------------------------
        virtual BYTE process( void )
        {
          if( isServerFlag && isConnectedFlag == false && s == 0)
          {
            if( (int)(s = accept(aSocket, NULL, NULL)) > 0 )
            {
              isConnectedFlag = true;
              unsigned long arg = 1;
              ioctlsocket(s, FIONBIO, &arg);
              printf("accepted\n");
            }
            else
            {
              s = 0;
            }
          }

          if( s == 0 )
          {
            return 0;
          }

          int plen = 0;

          SOCKADDR_IN tmpAddr;
          int	tmpAddrLen = sizeof(SOCKADDR_IN);

          if( (plen = recvfrom(s, (char*)transport.net.buf,transport.net.bufSize, 0, (SOCKADDR*)&tmpAddr,&tmpAddrLen)) >  0)
          {
            if( isServerFlag )
            {
              isConnectedFlag = true;
              remoteAddr      = tmpAddr.sin_addr.S_un.S_addr;
              remotePort      = ntohs(tmpAddr.sin_port);
            }

            transport.net.bufIdx = 0;
            transport.net.bufLen = plen;
            app.OnReceive();
          }
          else if( plen < 0 )
          {
            transport.net.bufIdx = 0;
            int err = WSAGetLastError();

            if( err != 10035 && err != 10022)
            {
              printf("\nWSA-ERROR:%u\n",err);
            }
          }

         transport.net.bufIdx = 0;

         return(1);
        }

    };  // class Socket
    //***************************************************************

  public:
    //---------------------------------------------------------------
    cNetUDP( cNetWin &netIn )
    : cNetWinTransport( netIn )
    {
      net.setUDP( this );
    }

    virtual cNetAddr<4> getAddr( void )
    {
      return( net.getIP() );
    }

    virtual const cNetAddr<6> getAddrPhy( void )
    {
      static cNetAddr<6> ret = {0,0,0,0,0,0};
      return( ret ); //ip.eth.addrPhy );
    }
};

#endif
