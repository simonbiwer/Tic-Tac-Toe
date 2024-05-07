//*******************************************************************
/*!
\file   CmdPara.cpp
\author Thomas Breuer
\date   15.01.2013
*/

//*******************************************************************
//
// cCmdPara
//
//*******************************************************************
//-------------------------------------------------------------------
cCmdPara::cCmdPara( cCmd       &cmdIn,
                    const char *nameIn,
                    const char *formatIn,
                    modeType    modeIn )

: cmd( cmdIn )

{
  name   = nameIn;
  format = formatIn;
  mode   = modeIn;
  offs   = 0;

  if( mode == MEMORY && cmd.mem == NULL )
  {
    mode = NORMAL;
  }

  if( mode == EVENT )
  {
    isNewFlag = false;
  }
  else
  {
    isNewFlag = true;
  }

  cmd.paraList.add( this ); // register this parameter to list
}

//-------------------------------------------------------------------
BYTE cCmdPara::isNameMatching( const char *cmdStr )
{
  return( strcmp( cmdStr, name ) == 0 );
}

//-------------------------------------------------------------------
BYTE cCmdPara::isNew( void )
{
  if( isNewFlag )
  {
    isNewFlag = false;
    return( true );
  }
  else
  {
    return( false );
  }
}

//-------------------------------------------------------------------
void cCmdPara::touch( void )
{
  isNewFlag = true;
  if( cmd.mem && !cmd.mem->isFlash() )
  {
    store();
  }
}

//-------------------------------------------------------------------
BYTE cCmdPara::isReadOnly( void )
{
  return( mode == RDONLY );
}

//-------------------------------------------------------------------
void cCmdPara::allocate( void )
{
  if( mode == MEMORY && cmd.mem )
  {
    offs = cmd.mem->allocate( getSize() );
  }
}

//-------------------------------------------------------------------
void cCmdPara::store( void )
{
  if( mode == MEMORY && cmd.mem )
  {
    cmd.mem->write( getPtr(), getSize(), offs );
  }
}

//-------------------------------------------------------------------
void cCmdPara::recall( void )
{
  if( mode == MEMORY && cmd.mem && cmd.mem->isValid() )
  {
    cmd.mem->read( getPtr(), getSize(), offs );
    isNewFlag = true;
  }
}

//EOF
