//*******************************************************************
/*!
\file   CmdPara.h
\author Thomas Breuer
\date   15.01.2013
*/

//*******************************************************************
#ifndef _CMD_PARA_H
#define _CMD_PARA_H

//*******************************************************************
#include "Module/Command/Cmd.h"

//*******************************************************************
/*!
\class cCmdPara

\brief Abstract class defining a command parameter
*/
class cCmdPara : private cList::Item
{
  public:
    //---------------------------------------------------------------
    /*! Defines behaviour of a parameter object
    */
    typedef enum
    {
      NORMAL = 0x00, //!< Normal parameter, read- and writeable
      RDONLY = 0x01, //!< Read only parameter
      MEMORY = 0x02, //!< The parameter is stored in a non volatile memory
      EVENT  = 0x04  //!< Normal parameter, but not marked as "new" by initialization
    } modeType;

 protected:
    //---------------------------------------------------------------
    // Instantiate a parameter object
    //
    cCmdPara( cCmd       &cmd,           // Reference to a cCmd object, which handles this parameter
              const char *name,          // Name of the parameter in a command string
              const char *format,        // Format string. Defines output, if parameter value is requested
              modeType    mode = NORMAL  // Behaviour
            );

  public:
    //---------------------------------------------------------------
    /*! Checks, if this parameter is updated
        \return
                - true:  Parameter is changed
                - false: No change
    */
    BYTE isNew( void );

 protected:
    //---------------------------------------------------------------
    // Mark a parameter as "new" and store value if applicable.
    // Call this function within the set()-methods of derived classes
    //
    virtual void touch( void );

    //---------------------------------------------------------------
    // Compare a string with parameter name
    // return: true, if cmdStr is equal to parameter name
    //         false otherwise
    //
    virtual BYTE isNameMatching( const char *cmdStr );

    //---------------------------------------------------------------
    // Check, if parameter is readonly
    // return: true, if readonly
    //         false otherwise
    //
    BYTE isReadOnly( void );

    //---------------------------------------------------------------
    // Allocate memory in the cDevMemory object
    //
    void allocate( void );

    //---------------------------------------------------------------
    // Store value in the cDevMemory object
    //
    void store( void );

    //---------------------------------------------------------------
    // Recall value from the cDevMemory object
    //
    void recall( void );

  protected:
    //---------------------------------------------------------------
    // Get value size
    // return: Sizeof value
    //
    virtual BYTE getSize( void ) = 0;

    //---------------------------------------------------------------
    // Get Pointer
    // return: Pointer to first BYTE of value
    //
    virtual BYTE *getPtr( void ) = 0;

    //---------------------------------------------------------------
    // Scan valueStr an set value
    // valueStr: String to read from
    //
    virtual void setValueByString( const char *valueStr ) = 0;

    //---------------------------------------------------------------
    // Get value string format
    // The value is printed into a string, using format
    //
    virtual const char *getValueByString( void ) = 0;

  protected:
    //---------------------------------------------------------------
    BYTE        isNewFlag;
    const char *format;

  private:
    //---------------------------------------------------------------
    cCmd       &cmd;
    const char *name;
    modeType    mode;
    WORD        offs;

    //---------------------------------------------------------------
    friend class cCmd;

}; //cCmdPara

#endif
