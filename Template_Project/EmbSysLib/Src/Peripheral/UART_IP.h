//*******************************************************************
/*!
\file   UART_IP.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_UART_IP_H
#define _HW_UART_IP_H

//*******************************************************************
#include "Com/Hardware/Net/Net.h"
#include "Com/Hardware/UART/UART.h"

//*******************************************************************
/*!
\class cHwUART_IP

\brief Implementation of UART hardware

\example cHwUART.cpp
*/
template <class T> class cHwUART_IPserver : public cNetApplication, public cHwUART
{
  public:
    //---------------------------------------------------------------
    /*! Intantiate ???
    */
    cHwUART_IPserver( T &transport, WORD port = 23 )
    : cHwUART(255,255),
      socket( transport, *this, broadcastAddr, port, 10/* update time [ms] */ )
    {
      flag = false;
     // socket.setTimeout(6);
      isAlive = false;
socket.openDefault();
    }

bool flag;
bool isAlive;
  private:
    //---------------------------------------------------------------
    virtual void process( void )
    {
      char c;
       flag = true;
      while( socket.get( &c ) )
      {

        // TODO: Variante KNX:
          if(!dataRxBuf.isFull())
            dataRxBuf << c;
        // Variante ORB und original:
        if( c!= 0)
        {
          if(!dataRxBuf.isFull())
            dataRxBuf << c;
        }
        //----
      }
      isAlive = true;
    }

    virtual void update( void )
    {
      if( socket.isConnected() && !dataTxBuf.isEmpty() )
      {
         socket.clear( );
         while( !dataTxBuf.isEmpty() )
         {
           BYTE c;
           dataTxBuf >> c;
           socket.fill( c );
         }
         socket.send();
      }
    }

     virtual void timeout( void )
     {
       if(!isAlive && socket.isConnected())
       {
         socket.close();
         flag = false;
       }
       isAlive = false;
       socket.setTimeout(6);
     }

public:
    virtual void setByte(BYTE data) {}
    virtual BYTE getByte() {return(0);}
    virtual void transmitByte( BYTE data )
    {
      if( !dataTxBuf.isFull() ) // wait until FIFO is ready
      {

        dataTxBuf << data;          // pipe data into FIFO

      }
    }



//  private:
    //---------------------------------------------------------------
    typename T::Socket socket;

}; //cHwUART_UDP

//*******************************************************************
template <class T> class cHwUART_IPclient : public cNetApplication, public cHwUART
{
  public:
    //---------------------------------------------------------------
    /*! Intantiate ???
    */
    cHwUART_IPclient( T &transport, cNetAddr<4> addr, WORD port )
    : cHwUART(255,255),
      socket( transport, *this, addr, port )
 {
   socket.open( addr, port);
    socket.fill( (char)0 );
    socket.send();
   flag = true;
   socket.setTimeout(0);
 }

bool flag;
  private:
    //---------------------------------------------------------------
    virtual void OnReceive( void )
    {
      char c;
       flag = true;


      while( socket.get( &c ) )
      {
        if(!dataRxBuf.isFull())
          dataRxBuf << c;

      }
    }

    virtual void OnUpdate( void )
    {
      if(   /*socket.isConnected()*/  !dataTxBuf.isEmpty() )
      {
        if( !socket.isConnected() )
        {
          socket.openDefault();
          //return;
        }
         socket.clear( );
         while( !dataTxBuf.isEmpty() )
         {
           BYTE c;
           dataTxBuf >> c;
           socket.fill( c );
         }
         socket.send();
      }


    }

     virtual void OnTimeout( void )
     {
       printf("timeout\n");
       if(socket.isConnected())
       {
         socket.close();
         flag = false;
       }
       socket.openDefault();
     }

     virtual void OnError()
     {

     }

public:
    virtual void setByte(BYTE data) {}
    virtual BYTE getByte() {return(0);}
    virtual void transmitByte( BYTE data )
    {
      if( !dataTxBuf.isFull() ) // wait until FIFO is ready
      {

        dataTxBuf << data;          // pipe data into FIFO

      }
    }


  private:
    //---------------------------------------------------------------
    typename T::Socket socket;
};

#endif
