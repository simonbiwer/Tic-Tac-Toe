//*******************************************************************
/*!
\file   HTTP_ParaOption.h
\author Thomas Breuer
\date   15.01.2013
*/

//*******************************************************************
#ifndef _HTTP_PARA_OPTION_H
#define _HTTP_PARA_OPTION_H

//*******************************************************************
#include "Module/HTTP/HTTP_ParaType.h"

//*******************************************************************
#include <stdio.h>

//*******************************************************************
/*!
\class cHTTP_ParaOption

\brief Template class to define a parameter with basic data types

\example cHTTP.cpp
*/
class cHTTP_ParaOption : public cHTTP_ParaType<BYTE>
{
  public:
    //---------------------------------------------------------------
    /*! Instantiate a parameter object
    */
    cHTTP_ParaOption( cHTTP_Page       &page,               //!< Reference to a cCmd object, which handles this parameter
                  const char *name,              //!< Name of the parameter in a command string
                  //const char *format,            //!< Format string. Defines output, if parameter value is requested
                  //modeType    mode     = NORMAL, //!< Behaviour
                  BYTE           valueDef = 0       //!< Default value
                )

    : cHTTP_ParaType<BYTE>( page, name, "%hhd", "%hhd", valueDef )

    {
    }

    //---------------------------------------------------------------
    /*! Get current parameter value
        \return value
    */
    virtual void clear( void )
    {
      //value = 0;
    }

    //---------------------------------------------------------------
    virtual void setValueByString( const char *valueStr )
    {
      if( strcmp(valueStr,"on" ) == 0 )
        value = 1;
      else
        value = 0;
    }

    virtual const char *getValueByString( void )
    {
      if( value )
	return( "on" );
      else
	return( "off" );

    }




}; //cCmdParaType

#endif
