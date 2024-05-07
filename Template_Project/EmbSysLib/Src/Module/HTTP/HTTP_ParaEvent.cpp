//*******************************************************************
/*!
\file   HTTP_ParaEvent.cpp
\author Thomas Breuer
\date   15.01.2013
*/

//*******************************************************************
//
// cCmdParaType
//
//*******************************************************************
//-------------------------------------------------------------------
cHTTP_ParaEvent::cHTTP_ParaEvent( cHTTP_Page        &page,
                            const char  *name,
                            //const char  *format,
                            //modeType     mode,
                            const char *texteIn[],
                            BYTE         defIn )

: cHTTP_ParaType<BYTE>( page, name, "%s", "%s",  defIn )

{
  texte = texteIn;

  for( numOfItems = 0; texte[numOfItems]; numOfItems++ );

  value = (defIn < numOfItems) ? defIn : 0;

    isNewFlag = false;

}

//-------------------------------------------------------------------
void cHTTP_ParaEvent::clear( void )
{
  value = 0;

 // cCmdPara::touch();
}

//-------------------------------------------------------------------
void cHTTP_ParaEvent::set( BYTE idxIn )
{
  value = (idxIn < numOfItems) ? idxIn : value;

//  cCmdPara::touch();
}

//-------------------------------------------------------------------
const char *cHTTP_ParaEvent::getString( void )
{
  return( texte[value] );
}

//-------------------------------------------------------------------
void cHTTP_ParaEvent::setValueByString(const char *valueStr)
{
  for( BYTE i = 0; i < numOfItems; i++ )
  {
    if( strncmp( valueStr, texte[i], strlen( texte[i]) ) == 0 )
    {
      value = i;
      isNewFlag = true;
    }
  }
  isNewFlag = true;
}

//-------------------------------------------------------------------
const char *cHTTP_ParaEvent::getValueByString( void )
{
  static char str[20];

  snprintf( str, 19, format, texte[value] );

  return( str );
}

//EOF
