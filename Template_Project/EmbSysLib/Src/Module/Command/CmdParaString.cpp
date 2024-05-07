//*******************************************************************
/*!
\file   CmdParaString.cpp
\author Thomas Breuer
\date   15.01.2013
*/

//*******************************************************************
//
// cCmdParaString
//
//*******************************************************************
//-------------------------------------------------------------------
cCmdParaString::cCmdParaString( cCmd       &cmd,
                                const char *name,
                                const char *format,
                                modeType    mode,
                                const char *strDef )

: cCmdParaType<const char *>( cmd, name, format, mode, str /* must not be strDef !*/ )

{
  if( strDef )
  {
    strncpy( str, strDef, 20 ); //< \todo magic number!
  }
  else
  {
    strncpy( str, "", 20 );
  }
}

//-------------------------------------------------------------------
void cCmdParaString::set( const char *strIn )
{
  strncpy( str, strIn, 20 );

  cCmdPara::touch();
}

//-------------------------------------------------------------------
BYTE cCmdParaString::getSize( void )
{
  return( 20 );
}

//-------------------------------------------------------------------
BYTE *cCmdParaString::getPtr( void )
{
  return( (BYTE*)&str[0] );
}

//-------------------------------------------------------------------
void cCmdParaString::setValueByString( const char *valueStr )
{
  strncpy(str, valueStr, 20);
}

//EOF
