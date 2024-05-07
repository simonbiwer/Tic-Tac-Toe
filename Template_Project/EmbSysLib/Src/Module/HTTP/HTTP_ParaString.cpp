//*******************************************************************
/*!
\file   CmdParaString.cpp
\author Thomas Breuer
\date   15.01.2013
*/

//*******************************************************************
//
// cHTTP_ParaString
//
//*******************************************************************
//-------------------------------------------------------------------
cHTTP_ParaString::cHTTP_ParaString( cHTTP_Page       &page,
                                const char *name,
                                const char *format,
                                //modeType    mode,
                                const char *strDef )

: cHTTP_ParaType<const char *>( page, name, format, format, str /* must not be strDef !*/ )

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
void cHTTP_ParaString::clear( void )
{
  strncpy( str, "", 20 );

// cCmdPara::touch();
}

//-------------------------------------------------------------------
void cHTTP_ParaString::set( const char *strIn )
{
  strncpy( str, strIn, 20 );

// cCmdPara::touch();
}


//-------------------------------------------------------------------
void cHTTP_ParaString::setValueByString( const char *valueStr )
{
  strncpy(str, valueStr, 20);
  isNewFlag = true;
}

//EOF
