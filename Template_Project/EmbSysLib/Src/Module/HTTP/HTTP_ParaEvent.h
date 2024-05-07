//*******************************************************************
/*!
\file   HTTP_ParaEvent.h
\author Thomas Breuer
\date   15.01.2013
*/

//*******************************************************************
#ifndef _HTTP_PARA_EVENT_H
#define _HTTP_PARA_EVENT_H

//*******************************************************************
#include "Module/HTTP/HTTP_ParaType.h"

//*******************************************************************
/*!
\class cHTTP_ParaEvent

\brief Parameter with a list of values

The cCmdParaList class defines a parameter, which value is set by a string.
The value is than the index of the list item, that machtes the input string.

\example cCmd.cpp
*/
class cHTTP_ParaEvent : public cHTTP_ParaType<BYTE>
{
  public:
    //---------------------------------------------------------------
    /*! Instantiate a parameter object
    */
    cHTTP_ParaEvent( cHTTP_Page        &page,     //!< Reference to a cCmd object, which handles this parameter
                  const char  *name,    //!< Name of the parameter in a command string
                  //const char  *format,  //!< Format string. Defines output, if parameter value is requested
                  //modeType     mode,    //!< Behaviour
                  const char  *texte[], //!< NULL terminated list
                  BYTE         def = 0  //!< Default value
                );

    //---------------------------------------------------------------
    using cHTTP_ParaType<BYTE>::operator=;

    //---------------------------------------------------------------
    // 
    //
    virtual void clear( void );

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

}; //cHTTP_ParaEvent

#endif
