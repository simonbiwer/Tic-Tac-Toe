//*******************************************************************
/*!
\file   Disp_Virtual.cpp
\author Thomas Breuer
\date   14.02.2012
*/

//*******************************************************************
//
// cHwDisp_Virtual
//
//*******************************************************************
//-------------------------------------------------------------------
cHwDisp_Virtual::cHwDisp_Virtual( cNetAddr<4> addr, WORD port,
                                  cHwDisplayFont  fontIn,
                                  BYTE            zoomIn )

: cHwDisplayGraphic( fontIn, zoomIn ),
  client(addr, port)

{
//  socket.openDefault();
t=0;
  clear();
}

//-------------------------------------------------------------------
void cHwDisp_Virtual::clear( void )
{
//  client.execute( "I", 4, 1/*graphic*/, WIDTH, HEIGHT, BackColor );
transceive(GC, WIDTH, HEIGHT, BackColor);

}

//---------------------------------------------------------------
void cHwDisp_Virtual::setPixel( WORD color,
                                WORD x,
                                WORD y )
{
//  client.execute( "PA", 3, x, y, color );
transceive(GP, x, y, color);

}

//---------------------------------------------------------------
void cHwDisp_Virtual::setPixel( WORD color )
{
//  client.execute( "PR", 1, color );
transceive(GR, 0, 0, color);
}

//---------------------------------------------------------------
void cHwDisp_Virtual::setArea( WORD x,
                               WORD y,
                               WORD w,
                               WORD h )
{
//  client.execute( "A", 4, x, y, w, h );
transceive(GA, x, y, w,h);
}

//---------------------------------------------------------------
void cHwDisp_Virtual::putRectangle( WORD x,
                               WORD y,
                               WORD w,
                               WORD h )
{
transceive(GF, x, y, w,h,PaintColor);
}

//-------------------------------------------------------------------
void cHwDisp_Virtual::transceive( BYTE cmd, WORD x, WORD y, WORD c, WORD d, WORD color )
{
  Data data;

  data.cmd = cmd;
  data.x = x;
  data.y = y;
  data.c = c;
  data.d = d;
  data.color = color;
  //char str[32];
 // sprintf( str, "P%s,%u,%u,%u;", item, line,colum,c );
 // socket.clear();
 // socket.fill(str);
//  socket.send();
 client.transceive((BYTE*)&data, sizeof(Data),(BYTE*)&data, sizeof(Data));

  //for(long i=0;i<5000;i++);
}


//EOF
