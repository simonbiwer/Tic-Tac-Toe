//*******************************************************************
/*!
\file   DisplayGraphic.h
\author Thomas Breuer
\date   10.03.2011
*/

//*******************************************************************
#ifndef _HW_DISPLAY_GRAPHIC_H
#define _HW_DISPLAY_GRAPHIC_H

//*******************************************************************
#include "Display.h"
#include "DisplayFont.h"

//*******************************************************************
/*!
\class cHwDisplayGraphic

\brief Abstract class supporting graphic displays

This class is derived from \a cHwDisplay and adds some basic
methods to draw graphic primitives. \n
The position is given relative to the upper left
corner with coordinates x (=colum) and y (=line).\n
Colors are coded in 16 bit:  RRRR.RGGG.GGGB.BBBB\n
  - Bit 15 - 11 red
  - Bit 10 -  6 green
  - Bit  5 -  0 blue

Derived classes should at least:
  - initialize the hardware
  - implement cHwDisplay::clear() to clear the display and fill it
    with background color
  - implement setArea() and setPixel()

\see cHwDisplay
\example cHwDisplayGraphic.cpp
*/
    #define RGB2COLOR(red,green,blue)                    \
      (    ((blue  >> 3) <<  0)   /* 5 bit,  0.. 4   */  \
         | ((green >> 2) <<  5)   /* 6 bit,  5..10   */  \
         | ((red   >> 3) << 11)   /* 5 bit, 11..15   */  \
      )
class cHwDisplayGraphic : public cHwDisplay
{
  public:
    //---------------------------------------------------------------
    /*! Predefined color map
    */
    //*******************************************************************
    //
    // color coding: rrrrr gggggg bbbbb
    //
    //*******************************************************************

    /*! Predefined colors
    */
    typedef enum
    {
      //                     Red Green Blue
      Black     = RGB2COLOR(   0,    0,   0 ),  //!< -
      Navy      = RGB2COLOR(   0,   48,  96 ),  //!< -
      DarkGreen = RGB2COLOR(   0,  128,   0 ),  //!< -
      DarkCyan  = RGB2COLOR(   0,  128, 128 ),  //!< -
      Maroon    = RGB2COLOR( 128,    0,   0 ),  //!< -
      Purple    = RGB2COLOR( 128,    0, 128 ),  //!< -
      Olive     = RGB2COLOR( 128,  196,   0 ),  //!< -
      Grey      = RGB2COLOR( 192,  192, 192 ),  //!< -
      DarkGrey  = RGB2COLOR( 128,  128, 128 ),  //!< -
      Blue      = RGB2COLOR(   0,    0, 255 ),  //!< -
      Green     = RGB2COLOR(   0,  255,   0 ),  //!< -
      Cyan      = RGB2COLOR(   0,  255, 255 ),  //!< -
      Red       = RGB2COLOR( 255,    0,   0 ),  //!< -
      Magenta   = RGB2COLOR( 255,    0, 255 ),  //!< -
      Yellow    = RGB2COLOR( 255,  255,   0 ),  //!< -
      White     = RGB2COLOR( 255,  255, 255 ),   //!< -
      DarkBlue  = RGB2COLOR(   0,    0, 192 ),  //!< -

    } colorPredefined;

  //  #undef RGB2COLOR

  protected:
    //---------------------------------------------------------------
    // Initialize hardware and set font type and font zoom size
    // font:  Character font used in cHwDisplay::putChar()
    // zoom:  Zoom size of character
    //
    cHwDisplayGraphic( cHwDisplayFont font,
                       BYTE           zoom = 1 );

  public:
    //---------------------------------------------------------------
    /*! Set a new font type and font zoom size
        \param font Character font used in cHwDisplay::putChar()
        \param zoom Zoom size of character
    */
    virtual void setFont( cHwDisplayFont font,
                          BYTE           zoom = 1 );

    //---------------------------------------------------------------
    /*! Set font zoom size. The actual font is not changed
        \param zoom Zoom size of character
    */
    virtual void setZoom(BYTE zoom = 1);

    //---------------------------------------------------------------
    /*! Set background color, which is used in clear() und putChar()
        \param color Background Color
    */
    virtual void setBackColor( WORD color );

    //---------------------------------------------------------------
    /*! Set painting color, which is used in putPixel() and
        putRectangle()
        \param color Farbwert gem. Tabelle \b colorPredefined
    */
    virtual void setPaintColor( WORD color );

    //---------------------------------------------------------------
    /*! Set text color, wich is used in cHwDisplay::putChar()
        \param color Text color
    */
    virtual void setTextColor( WORD color );

    //---------------------------------------------------------------
    /*! Set position of next character
        \param x Horiontal position in pixel coordinates
        \param y Vertical position in pixel coordinates
    */
    virtual void gotoPixelPos(WORD x,
                              WORD y);

    //---------------------------------------------------------------
    /*! Set position of next character
        \param line Horiontal position in character coordinates
        \param colum Vertical position in character coordinates
    */
    virtual void gotoTextPos( BYTE line,
                              BYTE colum );

    //---------------------------------------------------------------
    /*! Put character at actual position and auto increment colum for
        next character
        \param c  Character (ASCII code)
    */
    virtual void putChar( char c );

    //---------------------------------------------------------------
    /*! Paint a pixel in actual painting color
        \param x Horiontal position in pixel coordinates
        \param y Vertical position in pixel coordinates
    */
    virtual void putPixel( WORD x,
                           WORD y );

    //---------------------------------------------------------------
    /*! Paint a filled rectangle in actual painting color
        \param x Horiontal position in pixel coordinates
        \param y Vertical position in pixel coordinates
        \param w Width
        \param h Height
    */
    virtual void putRectangle( WORD x,
                               WORD y,
                               WORD w,
                               WORD h );

    //---------------------------------------------------------------
    /*! Draw a bitmap\n
        Format: 16 bits per pixel
        \param x Horiontal position in pixel coordinates (left)
        \param y Vertical position in pixel coordinates (top)
        \param w Width of bitmap
        \param h Height of bitmap
        \param bitmap Pointer to bitmap data
    */
    virtual void putBitmap( WORD        x,
                            WORD        y,
                            WORD        w,
                            WORD        h,
                            const WORD *bitmap );
    
    //---------------------------------------------------------------
		// TODO: write comment
    virtual void refresh( void ) 
    {
    }

    //---------------------------------------------------------------
    /*! /todo comment
    */
    virtual cHwDisplayFont getDefaultFont( void )
    {
      return( font );
    }
		
		//---------------------------------------------------------------
    /*! Get horizontal display size
        \return Number of pixel
    */
    virtual WORD getWidth( void )
		{
			return( Hsize );
		}

    //---------------------------------------------------------------
    /*! Get vertical display size
        \return Number of pixel
    */
    virtual WORD getHeight( void )
		{
			return( Vsize );
		}



  private:
    //---------------------------------------------------------------
    // Set painting area. The next calls to setPixel(BYTE color) will
    // draw a pixel in this area with auto increment of horizontal
    // and vertical coordinates
    // x:  Horiontal position in pixel coordinates (left)
    // y:  Vertical position in pixel coordinates (top)
    // w:  Width
    // h:  Height
    //
    virtual void setArea( WORD x,
                          WORD y,
                          WORD w,
                          WORD h ) = 0;

    //---------------------------------------------------------------
    // Draw a pixel at absolute position
    // color:  Pixel color
    // x:      Horiontal position in pixel coordinate
    // y:      Vertical position in pixel coordinate
    //
    virtual void setPixel( WORD color,
                           WORD x,
                           WORD y      ) = 0;

    //---------------------------------------------------------------
    // Draw a pixel at relative position within the area defined by
    // setArea(). The horizontal and vertical position is incremented
    // automatically (horizontal, vertical at end of line)
    // color: Pixel color
    //
    virtual void setPixel( WORD color ) = 0;

  protected:
    //---------------------------------------------------------------
    WORD xPos;
    WORD yPos;
	
	  DWORD Hsize;
	  DWORD Vsize;

    //---------------------------------------------------------------
    cHwDisplayFont font;
    BYTE           zoom;

    //---------------------------------------------------------------
    WORD BackColor;
    WORD PaintColor;
    WORD TextColor;

}; //cHwDisplayGraphic

#endif
