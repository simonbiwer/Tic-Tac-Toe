//*******************************************************************
/*!
\file   CmdParaString.h
\author Thomas Breuer
\date   15.01.2013
*/

//*******************************************************************
#ifndef _CMD_PARA_STRING_H
#define _CMD_PARA_STRING_H

//*******************************************************************
#include "Module/Command/CmdParaType.h"

//*******************************************************************
#include <stdio.h>
#include <string.h>

//*******************************************************************
/*!
\class cCmdParaString

\brief String parameter

Parameter of this class have a string value

\example cCmd.cpp
*/
class cCmdParaString : public cCmdParaType<const char *>
{
  public :
    //---------------------------------------------------------------
    /*!  Instantiate a parameter object
    */
    cCmdParaString( cCmd       &cmd,              //!< Reference to a cCmd object, which handles this parameter
                    const char *name,             //!< Name of the parameter in a command string
                    const char *format,           //!< Format string. Defines output, if parameter value is requested
                    modeType    mode   = NORMAL,  //!< Behaviour
                    const char *strDef = 0        //!< Default string value
                  );

    //---------------------------------------------------------------
    using cCmdParaType<const char *>::operator=;

    //---------------------------------------------------------------
    /*! Set value
    */
    virtual void set( const char *str  //!< New string value
                    );

  private:
    //---------------------------------------------------------------
    virtual BYTE getSize( void );

    //---------------------------------------------------------------
    virtual BYTE *getPtr( void );

    //---------------------------------------------------------------
    virtual void setValueByString( const char *valueStr );

  private:
    //---------------------------------------------------------------
    char str[21];

}; //cCmdParaString

#endif
