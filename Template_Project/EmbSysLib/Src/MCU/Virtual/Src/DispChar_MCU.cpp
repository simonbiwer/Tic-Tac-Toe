//*******************************************************************
/*!
\file   DispChar_Virtual.cpp
\author Thomas Breuer
\date   10.03.2011
*/



//*******************************************************************
//
// cHwDispChar_Virtual
//
//*******************************************************************
//-------------------------------------------------------------------
cHwDispChar_Virtual::cHwDispChar_Virtual( cNetAddr<4> addr, WORD port )

: cHwDisplay( NUM_OF_LINE, NUM_OF_COLUM ),
//  socket( sysNet.udp, *this, addr, port ),
  client( addr, port )

{
//  socket.openDefault();

  line  = 0;
  colum = 0;

  clear();
}

//-------------------------------------------------------------------
void cHwDispChar_Virtual::clear( void )
{
//  client.execute( "I", 4, 0 /*text*/, NUM_OF_COLUM, NUM_OF_LINE, 0 );
  Data data;

  data.cmd = 0;
  data.column = NUM_OF_COLUM;
  data.line   = NUM_OF_LINE;
  client.transceive( (BYTE*)&data, sizeof(Data),(BYTE*)&data, sizeof(Data));
//putString("CC",NUM_OF_COLUM, NUM_OF_LINE, 0);
}

//-------------------------------------------------------------------
void cHwDispChar_Virtual::refresh( void )
{
}

//---------------------------------------------------------------
void cHwDispChar_Virtual::gotoTextPos( BYTE lineIn,
                                       BYTE columIn )
{
  line  = lineIn;
  colum = columIn;
}

//---------------------------------------------------------------
void cHwDispChar_Virtual::putChar( char c )
{
  if(    line  < NUM_OF_LINE
      && colum < NUM_OF_COLUM )
  {
    Data data;

    data.cmd = 1;
    data.line = line;
    data.column = colum;
    data.c  = c;
  client.transceive( (BYTE*)&data, sizeof(Data),(BYTE*)&data, sizeof(Data));

   // putString("CW",line, colum, c);
    colum++; // emulate cursor increment
  }
}

//-------------------------------------------------------------------
/*
void cHwDispChar_Virtual::putString( const char *item, WORD line, WORD colum, char c)
{
  char str[32];
  sprintf( str, "P%s,%u,%u,%u;", item, line,colum,c );

  client.send( (BYTE*)str, strlen(str));
  while( client.receive((BYTE*)str,31) == 0 );
  //socket.clear();
  //socket.fill(str);
  //socket.send();
}
*/
//EOF
