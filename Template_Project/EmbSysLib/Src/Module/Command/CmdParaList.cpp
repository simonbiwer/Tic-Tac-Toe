//*******************************************************************
/*!
\file   CmdParaList.cpp
\author Thomas Breuer
\date   15.01.2013
*/

//*******************************************************************
//
// cCmdParaType
//
//*******************************************************************
//-------------------------------------------------------------------
cCmdParaList::cCmdParaList( cCmd        &cmd,
                            const char  *name,
                            const char  *format,
                            modeType     mode,
                            const char *texteIn[],
                            BYTE         defIn )

: cCmdParaType<BYTE>( cmd, name, format, mode, defIn )

{
  texte = texteIn;

  for( numOfItems = 0; texte[numOfItems]; numOfItems++ );

  value = (defIn < numOfItems) ? defIn : 0;
}

//-------------------------------------------------------------------
void cCmdParaList::set( BYTE idxIn )
{
  value = (idxIn < numOfItems) ? idxIn : value;

  cCmdPara::touch();
}

//-------------------------------------------------------------------
const char *cCmdParaList::getString( void )
{
  return( texte[value] );
}

//-------------------------------------------------------------------
void cCmdParaList::setValueByString(const char *valueStr)
{
  for( BYTE i = 0; i < numOfItems; i++ )
  {
    if( strncmp( valueStr, texte[i], strlen( texte[i]) ) == 0 )
    {
      value = i;
    }
  }
}

//-------------------------------------------------------------------
const char *cCmdParaList::getValueByString( void )
{
  static char str[20];

  snprintf( str, 19, format, texte[value] );

  return( str );
}

//EOF
