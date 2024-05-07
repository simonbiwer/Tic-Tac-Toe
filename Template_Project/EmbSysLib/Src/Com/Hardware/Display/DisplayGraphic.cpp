//*******************************************************************
/*!
\file   DisplayGraphic.cpp
\author Thomas Breuer
\date   11.03.2011
*/

//*******************************************************************
#include "DisplayGraphic.h"


//*******************************************************************
//
// cHwDisplayGraphic
//
//*******************************************************************
//-------------------------------------------------------------------
cHwDisplayGraphic::cHwDisplayGraphic( cHwDisplayFont fontIn,
                                      BYTE           zoomIn )
: cHwDisplay( 10, 20 ), //!< \todo adapt to / calculate by font size
  font( fontIn ),
  zoom( zoomIn )
{
  BackColor  = Blue;
  PaintColor = Grey;
  TextColor  = White;

  xPos = 0;
  yPos = 0;
}

//-------------------------------------------------------------------
void cHwDisplayGraphic::setFont( cHwDisplayFont fontIn,
                                 BYTE           zoomIn )
{
  font = fontIn;
  zoom = zoomIn;
}

//-------------------------------------------------------------------
void cHwDisplayGraphic::setZoom( BYTE zoomIn )
{
  zoom = zoomIn;
}

//---------------------------------------------------------------
void cHwDisplayGraphic::setBackColor( WORD color )
{
  BackColor = color;
}

//---------------------------------------------------------------
void cHwDisplayGraphic::setPaintColor( WORD color )
{
  PaintColor = color;
}

//---------------------------------------------------------------
void cHwDisplayGraphic::setTextColor( WORD color )
{
  TextColor = color;
}

//---------------------------------------------------------------
void cHwDisplayGraphic::gotoPixelPos( WORD x,
                                      WORD y )
{
  xPos = x;
  yPos = y;
}

//---------------------------------------------------------------
void cHwDisplayGraphic::gotoTextPos( BYTE line,
                                     BYTE colum )
{
  xPos = colum * zoom * font.getCharWidth();
  yPos = line  * zoom * font.getCharHeight();
}

//---------------------------------------------------------------
void cHwDisplayGraphic::putChar( char ch )
{
  font.setChar( ch ); // select char

  setArea( xPos,     // set painting area
           yPos,
           zoom*font.getCharWidth(),
           zoom*font.getCharHeight() + 1 );

  for( BYTE j = 0; j < font.getCharHeight(); j++ )  // scan vert.
  {
     for( BYTE zoomY = 0; zoomY < zoom; zoomY++ )
     {
        for( BYTE i = 0 ; i < font.getCharWidth(); i++ ) // scan hor.
        {
          BYTE pixel = font.getPixel(i, j);             // what color?
          for( BYTE zoomX = 0; zoomX < zoom; zoomX++ )
          {
            setPixel( (pixel) ? TextColor : BackColor );
          }
        }
     }
  }
  xPos += (WORD)zoom*font.getCharWidth(); // emulate cursor increment
}

//---------------------------------------------------------------
void cHwDisplayGraphic::putPixel( WORD x,
                                  WORD y )
{
  setPixel( PaintColor, x, y );
}

//---------------------------------------------------------------
void cHwDisplayGraphic::putRectangle( WORD x,
                                      WORD y,
                                      WORD w,
                                      WORD h )
{
  setArea( x, y, w, h );          // set painting area

  for( WORD i = 0; i < h; i++ )   // scan vert.
  {
    for( WORD j = 0; j < w; j++ ) // scan hor.
    {
      setPixel( PaintColor );     // draw pixel
    }
  }
}

//---------------------------------------------------------------
void cHwDisplayGraphic::putBitmap( WORD        x,
                                   WORD        y,
                                   WORD        w,
                                   WORD        h,
                                   const WORD *bitmap )
{
  setArea( x, y, w, h );          // set painting area

  for( WORD i = 0; i < h; i++ )   // scan vert.
  {
    for( WORD j = 0; j < w; j++ ) // scan hor.
    {
      setPixel( *bitmap++ );      // draw pixel and set to next
    }
  }
}

//EOF
