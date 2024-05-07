//*******************************************************************
/*!
\file   Cmd.cpp
\author Thomas Breuer
\date   15.01.2013
*/

//*******************************************************************
#include "Module/Command/Cmd.h"

//*******************************************************************
//
// cCmd
//
//*******************************************************************
//-------------------------------------------------------------------
const char *cCmd::EOS = ";\r\n";

//-------------------------------------------------------------------
cCmd::cCmd( cDevTextIO_UART &comIn,
            cDevMemory      *memIn )

: com( comIn )

{
  mem      = memIn;
  firstRun = true;
}

//-------------------------------------------------------------------
void cCmd::update( void )
{
  //! \todo Bereichsüberschreitung abfangen!
  char  cmdStr[32]   = "";
  char  valueStr[32] = "";
  BYTE  items        = 0;
  BYTE  len          = 0;
  char *str;

  if( firstRun )
  {
    firstRun = false;
    recallAll();
    isNewFlag = true;
  }
  else
  {
    isNewFlag = false;
  }

  str = com.getString();

  if( str )
  {
    len = strlen( str );
  }

  if( len == 1 ) // single character?
  {
    strcpy( cmdStr, str );
    items = 1;
  }
  else if( len > 1) // long string?
  {
    char tmp;
    items = sscanf( str, "%[^;\r\n=: ] %c %[^;\r\n]", cmdStr,&tmp,valueStr );
  }

  if( items )
  {
    cCmdPara *ptr = (cCmdPara*)paraList.getFirst();

    while( ptr )
    {
      // check all cCmdPara objects in list
      if( ptr->isNameMatching( cmdStr ) )
      {
        if( valueStr[0] != '?' )
        {
          if( ptr->isReadOnly() )
          {
            com.printf( "!%s const\r\n", cmdStr );
          }
          else
          {
            ptr->setValueByString( valueStr ); // interpret string
            ptr->touch();                    // value changed
            isNewFlag = true;
          }
        }
        else
        {
          com.printf( ">%s=%s\r\n", cmdStr, ptr->getValueByString() );  //! \todo Begrenzung erforderlich!
        }
        return;
      }
      ptr = (cCmdPara*)ptr->getNext();
    }
    com.printf( "!%s?\r\n", cmdStr ); // unknown command received
  }
}

//-------------------------------------------------------------------
BYTE cCmd::isNew( void )
{
  return( isNewFlag );
}

//-------------------------------------------------------------------
void cCmd::clear( void )
{
  if( mem )
  {
    mem->clear();
  }
}

//-------------------------------------------------------------------
void cCmd::recallAll( void )
{
  if( mem )
  {
    if( !mem->isValid() ) // flash only ???
    {
      mem->clear();
    }

    cCmdPara *ptr = (cCmdPara*)paraList.getFirst();
    while( ptr )
    {
      ptr->allocate();
      if( mem->isValid() )
      {
        ptr->recall(); // read value from memory
      }
      else
      {
        ptr->store(); // store default value
      }
      ptr = (cCmdPara*)ptr->getNext();
    }
    mem->setValid();
  }
}

//-------------------------------------------------------------------
void cCmd::store( void )
{
  if( mem )
  {
    mem->clear();

    cCmdPara *ptr = (cCmdPara*)paraList.getFirst();
    while( ptr )
    {
      ptr->store(); // store default value
      ptr = (cCmdPara*)ptr->getNext();
    }
    mem->setValid();
    com.printf( "!stored\r\n" ); //
  }
}
//EOF
