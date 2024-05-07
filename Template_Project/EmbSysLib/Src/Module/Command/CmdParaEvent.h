//*******************************************************************
/*!
\file   CmdParaEvent.h
\author Thomas Breuer
\date   15.01.2013
*/

//*******************************************************************
#ifndef _CMD_PARA_EVENT_H
#define _CMD_PARA_EVENT_H

//*******************************************************************
#include "Module/Command/CmdParaType.h"

//*******************************************************************
/*!
\class cCmdParaEvent

\brief EVENT parameter

\example cCmd.cpp
*/
class cCmdParaEvent : public cCmdParaType<BYTE>
{
  public:
    //---------------------------------------------------------------
    /*! Instantiate a parameter object
    */
    cCmdParaEvent( cCmd       &cmd,  //!< Reference to a cCmd object, which handles this parameter
                   const char *name  //!< Name of the parameter in a command string
                 );

}; //cCmdParaEvent

#endif
