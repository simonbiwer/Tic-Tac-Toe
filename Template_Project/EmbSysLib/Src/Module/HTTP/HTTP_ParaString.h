//*******************************************************************
/*!
\file   HTTP_ParaString.h
\author Thomas Breuer
\date   15.01.2013
*/

//*******************************************************************
#ifndef _HTTP_PARA_STRING_H
#define _HTTP_PARA_STRING_H

//*******************************************************************
#include "Module/HTTP/HTTP_ParaType.h"

//*******************************************************************
#include <stdio.h>
#include <string.h>

//*******************************************************************
/*!
\class cHTTP_ParaString

\brief String parameter

Parameter of this class have a string value

\example cHTTP.cpp
*/
class cHTTP_ParaString : public cHTTP_ParaType<const char *>
{
  public :
    //---------------------------------------------------------------
    /*!  Instantiate a parameter object
    */
    cHTTP_ParaString( cHTTP_Page       &page,              //!< Reference to a cCmd object, which handles this parameter
                    const char *name,             //!< Name of the parameter in a command string
                    const char *format,           //!< Format string. Defines output, if parameter value is requested
                    //modeType    mode   = NORMAL,  //!< Behaviour
                    const char *strDef = 0        //!< Default string value
                  );

    //---------------------------------------------------------------
    using cHTTP_ParaType<const char *>::operator=;

    //---------------------------------------------------------------
    /*! Set value
    */
    virtual void clear( void );

    //---------------------------------------------------------------
    /*! Set value
    */
    virtual void set( const char *str  //!< New string value
                    );

  private:
    //---------------------------------------------------------------
    ///virtual BYTE getSize( void );

    //---------------------------------------------------------------
    //virtual BYTE *getPtr( void );

    //---------------------------------------------------------------
    virtual void setValueByString( const char *valueStr );

  private:
    public:
    //---------------------------------------------------------------
    char str[21];

}; //cHTTP_ParaString

#endif
