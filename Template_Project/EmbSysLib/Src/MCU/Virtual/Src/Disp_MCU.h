//*******************************************************************
/*!
\file   Disp_Virtual.h
\author Thomas Breuer
\date   14.02.2012
*/

//*******************************************************************
#ifndef _HW_DISP_VIRTUAL_H
#define _HW_DISP_VIRTUAL_H

//********************************************
#include "Com/Hardware/Display/DisplayGraphic.h"
#include "MCU/Virtual/Sys/UDPclient.h"


//*******************************************************************
//extern cSystemNet sysNet;
#define GC 2
#define GP 3
#define GR 4
#define GA 5
#define GF 6

//*******************************************************************
/*!
\class cHwDisp_Virtual

\brief Virtual graphic display (Server)

\example cHwDisp_Virtual.cpp
*/
class cHwDisp_Virtual : public cHwDisplayGraphic
{
  public:
    //---------------------------------------------------------------
    class Data
    {
      public:
        BYTE      cmd;
        cNetWORD  x;
        cNetWORD  y;
        cNetWORD  c;
        cNetWORD  d;
        cNetWORD  color;
    };

  public:
    //---------------------------------------------------------------
    /*! Initialize display
        \param client Reference to a client
        \param font   Display font
        \param zoom   Display font zoom size (1,2,3,...)
    */
    cHwDisp_Virtual( cNetAddr<4> addr, WORD port,
                     cHwDisplayFont  font,
                     BYTE            zoom = 1 );

    //---------------------------------------------------------------
    virtual void clear( void );

    //---------------------------------------------------------------
    virtual void setPixel( WORD color,
                           WORD x,
                           WORD y );

    //---------------------------------------------------------------
    virtual void setPixel( WORD color );

    //---------------------------------------------------------------
    virtual void setArea( WORD x,
                          WORD y,
                          WORD w,
                          WORD h );

    //---------------------------------------------------------------
    virtual void putRectangle( WORD x,
                               WORD y,
                               WORD w,
                               WORD h );

  private:
    //-------------------------------------------------------------------
    //void putString(  const char *item, WORD line, WORD colum, WORD c = ' ' );
    //void putString(  const char *item, WORD line, WORD colum, WORD, WORD );
    void transceive( BYTE cmd, WORD x, WORD y, WORD c, WORD d = 0, WORD color = 0);
    //---------------------------------------------------------------
    //virtual void process( void );

    //---------------------------------------------------------------
    //virtual void update( void );

    //---------------------------------------------------------------
    // virtual void timeout( void );

  private:
    //----------------------------------------
    //cNetUDP::Socket socket;

  private:
    //---------------------------------------------------------------
//    cHwClient &client;
UDPclient   client;

    //---------------------------------------------------------------
    //
    // configuration:
    //
    static const WORD WIDTH  = 320;
    static const WORD HEIGHT = 240;

    WORD t;
}; //cHwDisp_Virtual

#endif
