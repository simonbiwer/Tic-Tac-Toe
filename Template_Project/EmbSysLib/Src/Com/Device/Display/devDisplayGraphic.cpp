//*******************************************************************
/*!
\file   devDisplayGraphic.cpp
\author Thomas Breuer
\date   10.05.2011
*/

//*******************************************************************
#include <stdio.h>
#include <stdarg.h>
#include <math.h>

//*******************************************************************
//
// cDevDisplayGraphic
//
//*******************************************************************
//-------------------------------------------------------------------
cDevDisplayGraphic::cDevDisplayGraphic( cHwDisplayGraphic &displayIn )

: display( displayIn )

{
  clear();
}

//-------------------------------------------------------------------
void cDevDisplayGraphic::clear( void )
{
  //! \todo which color?
  display.clear();
}

//-------------------------------------------------------------------
void cDevDisplayGraphic::refresh( void )
{
  display.refresh();
}

//-------------------------------------------------------------------
void cDevDisplayGraphic::printf( BYTE        line,
                                 BYTE        column,
                                 BYTE        minLen,
                                 const char *format,
                                 ... )
{
  BYTE i;

  //! \todo: string-klasse verwenden oder string-Groesse als Parameter/Template?
  char str[31]; // ein paar Zeichen als Reserve

  va_list argzeiger;
  va_start( argzeiger, format );
  vsprintf( str, format, argzeiger );
  va_end  ( argzeiger );

  display.gotoTextPos( line, column );

  // Zeichenweise an Display uebertragen
  for( i = 0; str[i] != 0; i++ )
  {
    display.putChar( str[i] );
  }

  // Rest mit Leerzeichen ueberschreiben
  for( /* no init*/ ; i < minLen; i++)
  {
    display.putChar( ' ' );
  }
}

//-------------------------------------------------------------------
void cDevDisplayGraphic::setFont( cHwDisplayFont font,
                                  BYTE           zoom )
{
  display.setFont( font, zoom );
};

//-------------------------------------------------------------------
void cDevDisplayGraphic::setZoom( BYTE zoom )
{
  display.setZoom( zoom );
};

//-------------------------------------------------------------------
void cDevDisplayGraphic::setBackColor( WORD color )
{
  display.setBackColor( color );
}

//-------------------------------------------------------------------
void cDevDisplayGraphic::setTextColor( WORD color )
{
  display.setTextColor( color );
}

//-------------------------------------------------------------------
void cDevDisplayGraphic::drawText( WORD        x,
                                   WORD        y,
                                   BYTE        minLen,
                                   const char *format,
                                   ... )
{
  BYTE i;

  //! \todo: string-klasse verwenden oder string-Groesse als Parameter/Template?
  char str[31]; // ein paar Zeichen als Reserve

  va_list argzeiger;
  va_start( argzeiger, format );
  vsprintf( str, format, argzeiger );
  va_end  ( argzeiger );

  display.gotoPixelPos( x, y );

  // Zeichenweise an Display uebertragen
  for( i = 0; str[i] != 0; i++ )
  {
    display.putChar( str[i] );
  }

  // Rest mit Leerzeichen ueberschreiben
  for( /*no init*/; i < minLen; i++ )
  {
    display.putChar( ' ' );
  }
}

//-------------------------------------------------------------------
void cDevDisplayGraphic::drawText( WORD        x,
                                   WORD        y,
                                   const char *str )
{
  BYTE i;

  display.gotoPixelPos( x, y );

  // Zeichenweise an Display uebertragen
  for( i = 0; str[i] != 0; i++ )
  {
    display.putChar( str[i] );
  }
}

//-------------------------------------------------------------------
void cDevDisplayGraphic::drawPixel( WORD x,
                                    WORD y,
                                    WORD color )
{
   display.setPaintColor( color );
   display.putPixel( x, y );
}

//-------------------------------------------------------------------
void cDevDisplayGraphic::drawRectangle( WORD x,
                                        WORD y,
                                        WORD w,
                                        WORD h,
                                        WORD color )
{
   display.setPaintColor( color );
   display.putRectangle( x, y, w, h );
}

//-------------------------------------------------------------------
void cDevDisplayGraphic::drawFrame( WORD x,
                                    WORD y,
                                    WORD w,
                                    WORD h,
                                    WORD th,
                                    WORD color )
{
  // horizontal
  drawRectangle( x, y     , w, th, color );
  drawRectangle( x, y+h-th, w, th, color );

  // vertikal
  drawRectangle( x,      y, th, h, color );
  drawRectangle( x+w-th, y, th, h, color );
}

//-------------------------------------------------------------------
void cDevDisplayGraphic::drawCircle( WORD x0,
                                     WORD y0,
                                     WORD r,
                                     WORD color )
{
  for( WORD x = 0; x <= r; x++ )
  {
    int h = (int)sqrt( (float)r*r-(float)x*x );
    drawRectangle( x0+x, y0-h, 1, 2*h, color );
    drawRectangle( x0-x, y0-h, 1, 2*h, color );
  }
}

//-------------------------------------------------------------------
void cDevDisplayGraphic::drawLine( WORD x0,
                                   WORD y0,
                                   WORD x1,
                                   WORD y1,
                                   WORD th,
                                   WORD color )
{
  long t;
  int  x;
  int  y;
  int  dx = (int)x1-x0;
  int  dy = (int)y1-y0;

  if( dy == 0 ) // horizontal
  {
    x0 = (x0 < x1) ? x0 : x1;
    y0 = (y0 < y1) ? y0 : y1;
    drawRectangle( x0, y0-th/2, abs(dx), th, color );
  }
  else if( dx == 0 ) // vertikal
  {
    x0 = (x0 < x1) ? x0 : x1;
    y0 = (y0 < y1) ? y0 : y1;
    drawRectangle(x0-th/2, y0, th, abs(dy), color );
  }
  else if( abs(dx) <= abs(dy) )
  {
    for( t = abs(dy); t >= 0; t-- )  // t = 1 downto 0
    {
      x = x0 + t*dx/abs(dy);         // x = x0+dx downto x0
      y = y0 + ( (dy>0) ? +t : -t ); // y = y0+dy downto y0
      for( int i = th; i >= 0; i-- )
      {
        drawPixel( x+i, y, color );
      }
    }
  }
  else
  {
    for( t = abs(dx); t >= 0; t-- )  // t = 1 downto 0
    {
      x = x0 + ( (dx>0) ? +t : -t ); // x = x0+dx downto x0
      y = y0 + t*dy/abs(dx);         // y = y0+dy downto y0
      for( int i = th; i >= 0; i-- )
      {
        drawPixel( x, y+i, color );
      }
    }
  }
}

//-------------------------------------------------------------------
void cDevDisplayGraphic::drawBitmap( WORD        x,
                                     WORD        y,
                                     WORD        w,
                                     WORD        h,
                                     const WORD *bitmap )
{
  display.putBitmap( x, y, w, h, bitmap );
}

//-------------------------------------------------------------------
cHwDisplayFont cDevDisplayGraphic::getDefaultFont( void )
{
  return( display.getDefaultFont() );
}

//EOF
