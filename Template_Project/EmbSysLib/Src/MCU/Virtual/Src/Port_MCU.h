//*******************************************************************
/*!
\file   Port_Virtual.h
\author Thomas Breuer
\date   10.11.2016
*/

//*******************************************************************
#ifndef _HW_PORT_VIRTUAL_H
#define _HW_PORT_VIRTUAL_H

//*******************************************************************
#include "Com/Hardware/Port/Port.h"
#include "Com/Hardware/Net/Net.h"

//*******************************************************************
/*!
\class cHwPort_Virtual

\brief Implementation of a digital I/O interface

Supports 8-Bit interfaces only

\example cHwPort_Virtual.cpp
*/
class cHwPort_Virtual : public cHwPort
{
  private:
    //---------------------------------------------------------------
    class Data
    {
      public:
        cNetDWORD dir;
        cNetDWORD value;

    };

  public:
    //---------------------------------------------------------------
    /*! Initialize hardware\n
        \param client Reference to a client
    */
    cHwPort_Virtual( cNetAddr<4> addr, WORD port );

    //---------------------------------------------------------------
    virtual void setMode( MTYPE mask, Mode mode );

    //---------------------------------------------------------------
    virtual void setPinMode( BYTE pinId, Mode modeIn );

    //---------------------------------------------------------------
    virtual void set( MTYPE mask );

    //---------------------------------------------------------------
    virtual void set( MTYPE mask, MTYPE value );

    //---------------------------------------------------------------
    virtual void clr( MTYPE mask );

    //---------------------------------------------------------------
    virtual MTYPE get( void );

  private:
    //-------------------------------------------------------------------
    void transceive();

  private:
    //----------------------------------------
    UDPclient  client;
    MTYPE      valueDir;
    MTYPE      valueOut;
    MTYPE      valueIn;

}; //cHwPort_Virtual

#endif
