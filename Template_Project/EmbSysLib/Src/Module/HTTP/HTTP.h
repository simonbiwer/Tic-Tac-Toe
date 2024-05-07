//*******************************************************************
/*!
\file   HTTP.h
\author Thomas Breuer
\date   15.05.2014
*/

//*******************************************************************
#ifndef _HTTP_HTTP_H
#define _HTTP_HTTP_H

//*******************************************************************
#include "Com/Hardware/Net/Net.h"

//*******************************************************************
class cHTTP_Page;

//*******************************************************************
/*!
\class cHTTP

\brief ???

\example cHTTP.cpp
*/
class cHTTP : public cNetApplication
{
  public:
    //---------------------------------------------------------------
    /*! Intantiate ???
    */
    cHTTP ( cNetTCP &tcp,      //!< ???
            WORD     port = 80 //!< ???
          );

  private:
    //---------------------------------------------------------------
    virtual void OnReceive( void );

    virtual void OnUpdate( void ) {};

    virtual void OnTimeout( void );

    virtual void OnError( void ) ;

 //   virtual void addPage( cHTTP_Page *page );

  private:
    //---------------------------------------------------------------
    cNetTCP::Socket socket;
 //   cList           pageList;
    cHTTP_Page *page;
  friend class cHTTP_Page;

}; //cHTTP

#endif
