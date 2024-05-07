#ifndef _NET_APP_H
#define _NET_APP_H

#include "Com/Std/List.h"

class cNetApplication : public cList::Item
{
  public:
    cNetApplication( void )
    {
      timeOutTic = 0;
    }

  private:
    virtual void OnReceive( void ) = 0;

    virtual void OnError( void ) = 0;

    virtual void OnUpdate( void ) = 0;

    virtual void OnTimeout( void ) = 0;

  protected:
    virtual void setTimeout( WORD timeSec, WORD timeMilli = 0 )
    {
      // Time Base: 10 ms
      timeOutTic = (DWORD)100*timeSec + timeMilli/10;
    }

  private:
    virtual void update( void )
    {
      OnUpdate();
      if( timeOutTic && !(--timeOutTic) )
      {
        OnTimeout();
      }
    }

    DWORD       timeOutTic;

  friend class cNetTCP;
  friend class cNetUDP;
  friend class cNetWinTransport;
};

#endif
