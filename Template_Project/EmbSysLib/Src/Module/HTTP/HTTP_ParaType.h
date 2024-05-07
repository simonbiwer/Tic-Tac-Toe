//*******************************************************************
/*!
\file   HTTP_ParaType.h
\author Thomas Breuer
\date   15.05.2014
*/

//*******************************************************************
#ifndef _HTTP_PARA_TYPE_H
#define _HTTP_PARA_TYPE_H

//*******************************************************************
#include "Module/HTTP/HTTP_Para.h"

//*******************************************************************
#include <stdio.h>

//*******************************************************************
/*!
\class cHTTP_ParaType

\brief Template class to define a parameter with basic data types

\example cHTTP.cpp
*/
template <class T> class cHTTP_ParaType : public cHTTP_Para
{
  public:
    //---------------------------------------------------------------
    /*! Instantiate a parameter object
    */
    cHTTP_ParaType( cHTTP_Page &page,         //!< Reference to a cCmd object, which handles this parameter
                    const char *name,         //!< Name of the parameter in a command string
                    const char *format,       //!< Format string. Defines output, if parameter value is requested
                    const char *formatScan,   //!< Format string to scan input
                    T           valueDef = 0  //!< Default value
                  )

    : cHTTP_Para( page, name, format, formatScan ),
      value( valueDef )

    {
    }

    //---------------------------------------------------------------
    /*!
    */
    virtual void clear( void )
    {
    }

    //---------------------------------------------------------------
    /*! Get current parameter value
        \return value
    */
    virtual T get( void )
    {
      return( value );
    }

    //---------------------------------------------------------------
    /*! Get current parameter value
        \return value
    */
    virtual operator T()
    {
      return( get() );
    }

    //---------------------------------------------------------------
    /*! Set current parameter value

        Set value, store and mark parameter as "new"
    */
    virtual void set( T x //!< New value
                    )
    {
      value     = x;
    }

    //---------------------------------------------------------------
    /*! Set current parameter value

        Set value, store and mark parameter as "new"
    */
    virtual void operator=( T x //!< New value
                          )
    {
      set( x );
    }

  private:
    //---------------------------------------------------------------
    virtual void setValueByString( const char *valueStr )
    {
      sscanf( valueStr, formatScan, &value );
      isNewFlag = true;
    }

    //---------------------------------------------------------------
    virtual const char *getValueByString( void )
    {
      static char str[21];
      snprintf( str, 19, format, value );
      return( str );
    }

  protected:
    //---------------------------------------------------------------
    T value;

}; //cHTTP_ParaType

#endif
