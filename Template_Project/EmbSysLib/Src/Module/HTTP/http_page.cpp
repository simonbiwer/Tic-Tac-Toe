//*******************************************************************
/*!
\file   HTTP_Page.cpp
\author Thomas Breuer
\date   06.02.2014
*/


extern cDevTextIO_UART  com;


#pragma pack(1)
class cPageDescriptor
{
  public:
    char name[32+1];
    //char      kennung;
    DWORD  laenge;
    DWORD  offset;
};

//*******************************************************************
//
// cHTTP_Page
//
//*******************************************************************
//-------------------------------------------------------------------
cHTTP_Page::cHTTP_Page( cHTTP      &http,
                        cHwMemory  &contentIn )

: content( contentIn )

{
  http.page = this;
  isNewFlag = false;
}

//-------------------------------------------------------------------
void cHTTP_Page::clear( void )
{
}

//-------------------------------------------------------------------
void cHTTP_Page::createPage( cNetTransport::Socket &socket, char *name, char *type )
{
  DWORD i=0;
  char c;
  char tmp[20];
  BYTE kennung = false;

  socket.clear( );

  short anzahl = ((short)content.read(1)<<8) | content.read(0);

  DWORD ptr=0;
  cPageDescriptor pd;

  for( short p=0; p< anzahl; p++)
  {
    for(int i=0;i<(int)sizeof(cPageDescriptor);i++)
    {
      *((BYTE*)&pd + i) = content.read(sizeof(anzahl)+p*sizeof(cPageDescriptor)+i);
    }

    if( strcmp(pd.name, name ) == 0 )
    {
      ptr = pd.offset;
       break;
    }
  }

//  const char *ext = strrchr ( name, '.' );

  if( strcmp(type,"json") == 0 )
  {
    fillSocketJSON(socket, name );
  }

  else
  {
    if( strcmp(type,"raw") == 0 )
  {
    kennung = true;
  }

    if( !kennung )
    {
      char h[128];
    //  socket.clear();
      sprintf(h,"HTTP/1.1 200 OK\nContent-Length: %lu\n\n",pd.laenge);
      socket.fill( h);
    }

  while(  ptr && i< (DWORD)pd.laenge )
  {
    c = content.read(ptr+i);
    i++;

    if( /*pd.*/kennung && c == '$' )
    {
      BYTE pos = 0;
      while( pos < 20-1 && (c=content.read(ptr+i))!=0 )
      {
        i++;
        //c = ptr[i++];
        tmp[pos++] = c;
        if( c == ')')
        {
          break;
        }
      }
      tmp[pos] = 0;

      if( c == ')' )
      {
        socket.fill( parseCommand( tmp ) );
      }
    }
    else
    {
      socket.fill( c );
    }
  }
  }
  socket.close( );

  isNewFlag = true;
}

//-------------------------------------------------------------------
void cHTTP_Page::setValue( char *str )
{
  cHTTP_Para *ptr = (cHTTP_Para*)paraList.getFirst();

  strcpy(val,"");
  if( sscanf(str, "%[^=]=%[^&]",var,val) < 1 )
  {
    return;
  }
  while( ptr )
  {
    if( ptr->isNameMatching( var ) )
    {
      ptr->setValueByString( val );
//      ptr->touch();                    // value changed
//      isNewFlag = true;
      break;
    }
    ptr = (cHTTP_Para*)ptr->getNext();
  }
}

//-------------------------------------------------------------------
char * cHTTP_Page::parseCommand( char *str )
{
  strcpy( val,"+++");
  char cmd[20];

  strcpy(cmd,"");

  if( sscanf(str, "%3s(%[^),],%[^)])",cmd,var,val) > 1 )
  {
    cHTTP_Para *ptr = (cHTTP_Para*)paraList.getFirst();

    while( ptr )
    {
      if( ptr->isNameMatching( var ) )
      {
        if( strncmp( cmd, "VAR", 3 ) == 0 )
        {
          return( (char*)ptr->getValueByString() );
        }
        else if( strncmp( cmd, "CHK", 3 ) == 0 )
        {
          return( (char*)(( *ptr == val ) ? "checked"  : "") );
        }
        else if( strncmp( cmd, "SEL", 3 ) == 0 )
        {
          return( (char*)(( *ptr == val ) ? "selected" : "") );
        }
        else
        {
          return( (char*)"???" );
        }
      }

      ptr = (cHTTP_Para*)ptr->getNext();
    }
  }
  return( val );
}
//EOF
