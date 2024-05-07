//*******************************************************************
/*!
\file   CmdParaType.h
\author Thomas Breuer
\date   15.01.2013
*/

//*******************************************************************
#ifndef _CMD_PARA_TYPE_H
#define _CMD_PARA_TYPE_H

//*******************************************************************
#include "Module/Command/CmdPara.h"

//*******************************************************************
#include <stdio.h>

//*******************************************************************
/*!
\class cCmdParaType

\brief Template class to define a parameter with basic data types

\example cCmd.cpp
*/
template <class T> class cCmdParaType : public cCmdPara
{
  public:
    //---------------------------------------------------------------
    /*! Instantiate a parameter object
    */
    cCmdParaType( cCmd       &cmd,               //!< Reference to a cCmd object, which handles this parameter
                  const char *name,              //!< Name of the parameter in a command string
                  const char *format,            //!< Format string. Defines output, if parameter value is requested
                  modeType    mode     = NORMAL, //!< Behaviour
                  T           valueDef = 0       //!< Default value
                )

    : cCmdPara( cmd, name, format, mode ),
      value( valueDef )

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

      cCmdPara::touch();
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
    virtual BYTE getSize( void )
    {
      return( sizeof( T ) );
    }

    //---------------------------------------------------------------
    virtual BYTE *getPtr( void )
    {
      return( (BYTE*)&value );
    }

    //---------------------------------------------------------------
    virtual void setValueByString( const char *valueStr )
    {
      sscanf( valueStr, format, &value );
    }

    //---------------------------------------------------------------
    virtual const char *getValueByString( void )
    {
      static char str[20];

      snprintf( str, 19, format, value );

      return( str );
    }

  protected:
    //---------------------------------------------------------------
    T value;

}; //cCmdParaType

#endif
