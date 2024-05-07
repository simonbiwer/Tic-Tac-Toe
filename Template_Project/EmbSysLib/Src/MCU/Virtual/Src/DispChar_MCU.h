//*******************************************************************
/*!
\file   DispChar_Virtual.h
\author Thomas Breuer
\date   10.03.2011
*/

//*******************************************************************
#ifndef _HW_DISP_CHAR_VIRTUAL_H
#define _HW_DISP_CHAR_VIRTUAL_H

//********************************************
#include "Com/Hardware/Display/Display.h"
#include "MCU/Virtual/Sys/UDPclient.h"

//*******************************************************************
//extern cSystemNet sysNet;


//*******************************************************************
/*!
\class cHwDispChar_Virtual

\brief Virtual character display (Server)

\example cHwDispChar_Virtual.cpp
*/
class cHwDispChar_Virtual : public cHwDisplay
//, public cNetApplication
{
  public:
    //---------------------------------------------------------------
    class Data
    {
      public:
        BYTE      cmd;
        cNetWORD  line;
        cNetWORD  column;
        char      c;
    };

  public:
    //---------------------------------------------------------------
    /*! Initialize display
        \param client Reference to a client
    */
    cHwDispChar_Virtual( cNetAddr<4> addr, WORD port );

    //---------------------------------------------------------------
    virtual void clear( void );

    //---------------------------------------------------------------
    virtual void refresh( void );

    //---------------------------------------------------------------
    virtual void gotoTextPos( BYTE line,
                              BYTE column );

    //---------------------------------------------------------------
    virtual void putChar( char c );

  private:
    //-------------------------------------------------------------------
    //void putString(  const char *item, WORD line, WORD colum, char c = ' ' );

    //---------------------------------------------------------------
   // virtual void process( void );

    //---------------------------------------------------------------
   // virtual void update( void );

    //---------------------------------------------------------------
     //virtual void timeout( void );

  private:
    //-------------------------------------------------------------------
   // void transceive();

  private:
    //----------------------------------------
   // cNetUDP::Socket socket;

  private:
    //---------------------------------------------------------------
    //cHwClient &client;
    UDPclient   client;
    BYTE        line;
    BYTE        colum;

    //---------------------------------------------------------------
    //
    // configuration:
    //
    static const WORD NUM_OF_LINE  =  8;
    static const WORD NUM_OF_COLUM = 20;

}; //cHwDispChar_Virtual

#endif
