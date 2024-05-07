//*******************************************************************
/*!
\file   HTTP_Para.h
\author Thomas Breuer
\date   15.05.2014
*/

//*******************************************************************
#ifndef _HTTP_PARA_H
#define _HTTP_PARA_H

//*******************************************************************
#include "Module/HTTP/HTTP.h"

//*******************************************************************
/*!
\class cHTTP_Para

\brief Abstract class defining a command parameter
*/
class cHTTP_Para : private cList::Item
{
  protected:
    //---------------------------------------------------------------
    // Instantiate a parameter object
    //
    cHTTP_Para( cHTTP_Page &page,   // Reference to a cCmd object, which handles this parameter
                const char *name,   // Name of the parameter in a command string
                const char *format, // Format string. Defines output, if parameter value is requested
                const char *formatScan  // Format string to scan input
              );

  protected:
    public:
    //---------------------------------------------------------------
    //
    //
    virtual BYTE isNew( void )
    {
      if( isNewFlag )
      {
        isNewFlag = false;
        return( true );
      }
      return( false );
    }

    //---------------------------------------------------------------
    // Compare a string with parameter name
    // return: true, if cmdStr is equal to parameter name
    //         false otherwise
    //
    virtual BYTE isNameMatching( const char *cmdStr );

    //---------------------------------------------------------------
    virtual BYTE operator==( const char *valStr
                           );

    //---------------------------------------------------------------
    // Scan valueStr an set value
    // valueStr: String to read from
    //
    virtual void setValueByString( const char *valueStr ) = 0;

    //---------------------------------------------------------------
    // Get value string format
    // The value is printed into a string, using format
    //
    virtual const char *getValueByString( void ) = 0;

    //---------------------------------------------------------------
    //
    virtual void fill( cNetTransport::Socket &socket ) { socket.fill("..."); }

    //---------------------------------------------------------------
    //
    virtual void clear( void ) = 0;

  protected:
    //---------------------------------------------------------------
    BYTE        isNewFlag;
    const char *format;
    const char *formatScan;

  private:
    //---------------------------------------------------------------
    cHTTP_Page &page;
    const char *name;

    //---------------------------------------------------------------
    friend class cHTTP_Page;

}; //cHTTP_Para

#endif
