//*******************************************************************
/*!
\file   Cmd.h
\author Thomas Breuer
\date   15.01.2013
*/

//*******************************************************************
#ifndef _CMD_H
#define _CMD_H

//*******************************************************************
/*!
\class cCmd

\brief A string oriented command manager

This class defines a command manager, which uses a cDevComUART device
to read commands and to set various parameters. Each parameter has a
name and a data type. Parameter objects has to been instantiate from
a class derived from \b cCmdPara.\n
A command is a character string with following formats:\n
  - \c ParameterName = \c value
  - \c ParameterName = ?
  - \c ParameterName

If a \c value is given and the appropriate parameter is not read-only,
the parameter is set to \c value and the parameter is marked as "new".\n
The question mark will prompt the command manager to write back the
actual value of the named parameter.\n
If the parameterName is followed neither by a \c value nor a \c ?, then
the parameter is left unchanged but is marked as "new".

Within the application, every parameter can be polled to check, if it
is "new", or to get / set its value.

A \b cDevMemory object can be used to store and recall parameters (optional)

A parameter object can have one of the attributes defined in \b cCmdPara::modeType.

\see cCmdPara

\example cCmd.cpp
*/
class cCmd
{
  public:
    //---------------------------------------------------------------
    /*! Intantiate a command interface
    */
    cCmd( cDevTextIO_UART &uart,       //!< Reference to communication interface
          cDevMemory      *mem = NULL  //!< Pointer to a memory device (optional)
        );

    //---------------------------------------------------------------
    /*! Read and execute command
    */
    virtual void update( void );

    //---------------------------------------------------------------
    /*! Check, if a command was received and a parameter was touched
        \return
                - true:  A new command is pending
                - false: No command received
    */
    BYTE isNew( void );

   //---------------------------------------------------------------
    /*! Clear the memory in the cDevMemory object
    */
    void clear( void );

   //---------------------------------------------------------------
    /*!
    */
    void store( void );

  public:
    //---------------------------------------------------------------
    /*! End Of String characters

        The \b cDevComUART object requests a strings defining
        end-of-string characters. Here a default character set is defined
    */
    static const char *EOS;

  private:
    //---------------------------------------------------------------
    // Recall parameter from memory (if applicable).
    // If Memory is not valid, set parameters to default and store
    void recallAll( void );

  private:
    //---------------------------------------------------------------
    cDevTextIO_UART &com;
    cDevMemory      *mem;
    cList            paraList;
    BYTE             firstRun;
    BYTE             isNewFlag;

    //---------------------------------------------------------------
    friend class cCmdPara;

}; //cCmd

#endif
