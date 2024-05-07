//*******************************************************************
/*!
\file   CmdParaList.h
\author Thomas Breuer
\date   15.01.2013
*/

//*******************************************************************
#ifndef _CMD_PARA_LIST_H
#define _CMD_PARA_LIST_H

//*******************************************************************
#include "Module/Command/CmdParaType.h"

//*******************************************************************
/*!
\class cCmdParaList

\brief Parameter with a list of values

The cCmdParaList class defines a parameter, which value is set by a string.
The value is than the index of the list item, that machtes the input string.

\example cCmd.cpp
*/
class cCmdParaList : public cCmdParaType<BYTE>
{
  public:
    //---------------------------------------------------------------
    /*! Instantiate a parameter object
    */
    cCmdParaList( cCmd        &cmd,     //!< Reference to a cCmd object, which handles this parameter
                  const char  *name,    //!< Name of the parameter in a command string
                  const char  *format,  //!< Format string. Defines output, if parameter value is requested
                  modeType     mode,    //!< Behaviour
                  const char  *texte[], //!< NULL terminated list
                  BYTE         def = 0  //!< Default value
                );

    //---------------------------------------------------------------
    using cCmdParaType<BYTE>::operator=;

    //---------------------------------------------------------------
    // Set value by index, limited to number of list items
    //
    virtual void set( BYTE idx );

    //---------------------------------------------------------------
    /*! Get a pointer to the list item corresponding to value
        \return Pointer to list item string
    */
    const char *getString( void );

  private:
    //---------------------------------------------------------------
    virtual void setValueByString( const char *valueStr );

    //---------------------------------------------------------------
    virtual const char *getValueByString( void );

  private:
    //---------------------------------------------------------------
     const char **texte;
     BYTE  numOfItems;

}; //cCmdParaList

#endif
