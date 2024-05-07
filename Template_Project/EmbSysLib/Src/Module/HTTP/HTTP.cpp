//*******************************************************************
/*!
\file   HTTP.cpp
\author Thomas Breuer
\date   06.02.2014
*/

#include "HTTP.h"

//*******************************************************************
//
// cHTTP
//
//*******************************************************************
//-------------------------------------------------------------------
cHTTP::cHTTP( cNetTCP &tcp,
              WORD     port )

 : socket( tcp, *this, broadcastAddr, port )

{
  socket.openDefault();
  page = NULL;
}

//-------------------------------------------------------------------
void cHTTP::OnReceive( void )
{
  char c;
  char str[30+1];
  BYTE pos;

setTimeout( 5 /* sec*/ );

  while( socket.get( &c ) )
  {
    if( c == '/')
    {
      break;
    }
  }

  // Parse GET-command: page name
  pos = 0;
  while( socket.get( &c ) )
  {
    if( c == '?' || c == ' ')
    {
      break;
    }
    if( pos < 30 )
    {
      str[pos++] = c;
    }
  }
  str[pos++] = 0;

  if( strlen( str ) == 0 )
  {
    strcpy( str, "index.html" );
  }

  char pageName[20+1] = "";
  char typeName[10+1] = "";

  char *pch1 = strtok(str,"/");
  char *pch2 = strtok( NULL,"");

  if( pch2 )
  {
    strncpy( typeName,pch1,10);
    strncpy( pageName,pch2,20);
    }
  else if( pch1 )
  {
    strncpy( typeName,"",10);
    strncpy( pageName,pch1,20);
  }

  // page found?
  if( page )
  {
    if( c == '?' )  // end of page name
    {
      page->clear();

      // Parse parameter
      pos = 0;
      while( socket.get( &c ) /*&& pos < 20-1*/)
      {
        if( pos>=20-1 || c == '&' || c == ' ' ) // end of parameter or parameter list?
        {
          str[pos]=0;
          pos=0;

          page->setValue( str );

          if( c == ' ') // end of parameter list?
          {
            break;
          }
        }
        else
        {
          str[pos++] = (c=='+')?' ':c;
        }
      }
    }
    page->update();
    page->createPage( socket, pageName, typeName );
  }
  else
  {
    while( socket.get( &c ) /*&& pos < 20-1*/)
    {
//printf("%c",c);
    }
    socket.close( );
  }
//printf("\n");

}

//-------------------------------------------------------------------
void cHTTP::OnTimeout( void )
{
  socket.close( );

}

//-------------------------------------------------------------------
void cHTTP::OnError( void )
{
//  socket.close( );
 // printf("Error timeout\r\n");
}



//-------------------------------------------------------------------
/*
void cHTTP::addPage( cHTTP_Page *page )
{
  pageList.add( page );
}
*/
//EOF
