#ifndef _HW_NET_TRANSPORT_H
#define _HW_NET_TRANSPORT_H

#include "NetStd.h"
#include "NetApp.h"

//*******************************************************************
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

//*******************************************
//
//*******************************************
class cNetTransport
{
  public:

    //*******************************************
    //
    //*******************************************
  class Socket : public cList::Item
    {
      public:
        Socket( cNetTransport   &trans,
                cNetApplication &app,
                cNetAddr<4>      inAddrIn,
                WORD             portIn
              );

        virtual void open( cNetAddr<4> addr,
                           WORD port
                         ) = 0;

        virtual void openDefault( void )
        {
          open( remoteAddr, remotePort );
        }

        virtual void close( void ) = 0;

        virtual BYTE isConnected( void ) = 0;

        virtual BYTE isReady( void ) = 0;

        virtual cNetAddr<4> getRemoteIP( void );

        virtual void clear( void ) = 0;

        virtual BYTE *getDataPtr() = 0;

        virtual void setDataLength(WORD len) = 0;

        virtual void send( void ) = 0;

        virtual BYTE get( char *c ) = 0;

        virtual BYTE isServer()
		{
			return( isServerFlag );
		}

      private:
        virtual void fillBuffer( const char c ) = 0;



        //******  should be abstract
        virtual void update( void )
        {
        }

      public:
        virtual void fill( const char c )
        {
          fillBuffer( c );
        }

        virtual void fill( const char *str )
        {
          fill( str, strlen(str) );
        }

        virtual void fill( const char *buf,
                           WORD        len
                         )
        {
          for( WORD i = 0; i< len; i++ )
          {
            fill( buf[i] );
          }
        }
				
				//-------------------------------------------------------------------
				void printf( const char *format, ... )
				{
					char strOut[128+1];
					va_list argzeiger;

					va_start ( argzeiger, format );
					vsnprintf( strOut, 128, format, argzeiger );
					va_end   ( argzeiger );

					// Set output
					fill( strOut );
				}


        

            virtual BYTE process( void )= 0;
          //  virtual void update( void ) = 0;
            virtual void timeout( void ) = 0;

      protected:
        virtual void setTimeout( WORD timeSec, WORD timeMilli = 0 )
        {
          // Time Base: 10 ms
          timeOutTic = (DWORD)100*timeSec + timeMilli/10;
        }
        
        
      protected:
        enum
        {
          STATE_WAITING = 0,
          STATE_OPEN_WAIT_ARP,
          STATE_CONNECTED,
        };

      protected:
        cNetAddr<6> addrPhy;
        cNetAddr<4> addr;
        cNetWORD    myPort;
        cNetAddr<4> remoteAddr;
        cNetWORD    remotePort;
        DWORD       timeOutTic;
//        WORD        updateTic;
//        WORD        updateTime;
        BYTE        state;
        //WORD        dataLen;
        //BYTE       *dataPtr;
		
		BYTE isServerFlag;

        cNetApplication &app;

      friend class cNetTransport;

    }; //Socket



  protected:
    cNetTransport( /*cNetIP   &ip */);

  public:

 // virtual void handleARP( cNetAddr<4> addr, cNetAddr<6> addrPhy );

   virtual void process( void );

    virtual void update( void );

    virtual void timeout( void );

    virtual cNetAddr<4> getAddr( void ) = 0;

    virtual const cNetAddr<6> getAddrPhy( void ) = 0;

  public:
   // cNetIP   &ip;
  protected:
  public:
//    cNetIP   &ip;
   //cNetARP  &arp;

  public:
    cList  appList;

}; // cNetTransport

#endif
