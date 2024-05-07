//*******************************************************************
/*!
\file   HTTP_Para.cpp
\author Thomas Breuer
\date   15.01.2013
*/

//*******************************************************************
//
// cHTTP_Para
//
//*******************************************************************
//-------------------------------------------------------------------
cHTTP_Para::cHTTP_Para( cHTTP_Page       &pageIn,
                    const char *nameIn,
                    const char *formatIn,
                    const char *formatScanIn )

: page( pageIn )

{
  name   = nameIn;
  format = formatIn;
  formatScan = formatScanIn;
  isNewFlag = false;
  page.paraList.add( this ); // register this parameter to list
}

//-------------------------------------------------------------------
BYTE cHTTP_Para::isNameMatching( const char *cmdStr )
{
  return( strcmp( cmdStr, name ) == 0 );
}

//-------------------------------------------------------------------
BYTE cHTTP_Para::operator==( const char *valStr )
{
  if( strcmp( getValueByString(), valStr ) == 0 )
  {
    return( true );
  }
  return( false );
}

//EOF
