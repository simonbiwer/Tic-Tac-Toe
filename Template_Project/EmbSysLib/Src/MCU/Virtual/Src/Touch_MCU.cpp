//*******************************************************************
/*!
\file   Touch_Virtual.cpp
\author Thomas Breuer
\date   11.03.2013
*/

//*******************************************************************
//
// cHwTouch_Virtual
//
//*******************************************************************
//-------------------------------------------------------------------
cHwTouch_Virtual::cHwTouch_Virtual( cNetAddr<4> addr, WORD port,
                                    WORD        width,
                                    WORD        height )
: cHwTouch( width, height ),
  //client( clientIn )
  client(addr, port)

{
}

//-------------------------------------------------------------------
void cHwTouch_Virtual::update( void )
{
  Data data;

  data.cmd = 100;

  WORD x;
  WORD y;
  WORD touched;

  //client.request("X", &x);
  //client.request("Y", &y);
  //client.request("T", &touched);

  client.transceive( (BYTE*)&data, sizeof(Data),(BYTE*)&data, sizeof(Data) );
  xPos = data.x;
  yPos = data.y;

  isTouchedFlag = ( data.c ) ? true : false;
}

//EOF
