//*******************************************************************
/*!
\file   HTTP_ParaFunction.h
\author Thomas Breuer
\date   31.05.2017
*/

//*******************************************************************
#ifndef _HTTP_PARA_FUNCTION_H
#define _HTTP_PARA_FUNCTION_H

//*******************************************************************
/*!
\class cHTTP_ParaFunction

\brief ...


\example ...
*/
class cHTTP_ParaFunction : public cHTTP_Para
{
  public:
    //---------------------------------------------------------------
    /*! Instantiate a parameter object
    */
    cHTTP_ParaFunction( cHTTP_Page        &page,     //!< Reference to a cCmd object, which handles this parameter
                  const char  *name )
    : cHTTP_Para( page, name, NULL, NULL )
    {

    }

    //---------------------------------------------------------------
    //
    //
    virtual void clear( void )
    {

    }

    //---------------------------------------------------------------
    //
    virtual void fill( cNetTransport::Socket &socket ) { socket.fill("!!!"); }

  private:
    //---------------------------------------------------------------
    virtual void setValueByString( const char *valueStr )
    {

    }

//---------------------------------------------------------------
    virtual const char *getValueByString( void )
    {
      return( "xxx" );
    }

}; //cHTTP_ParaEvent

#endif
