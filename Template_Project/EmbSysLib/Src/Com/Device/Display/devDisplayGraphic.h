//*******************************************************************
/*!
\file   devDisplayGraphic.h
\author Thomas Breuer
\date   10.05.2011
*/

//*******************************************************************
#ifndef _DEV_DISPLAY_GRAPHIC_H
#define _DEV_DISPLAY_GRAPHIC_H
#define _DEV_DISPLAY_GRAPHIC_C

//*******************************************************************
#include "Com/Hardware/Display/DisplayGraphic.h"
#include "Com/Device/Display/devDisplay.h"

//*******************************************************************
/*!
\class cDevDisplayGraphic

\brief Graphic display

\warning This is a draft. The string length must not exceed 30 characters

The screen coordinates are zero in the upper left corner.
- 'x': left to right
- 'y': top to bottom

Colors are 16 bit RGB. Some colors are predefined
in \b cHwDisplayGraphic::colorPredefined

\example cDevDisplayGraphic.cpp
*/
class cDevDisplayGraphic : public cDevDisplay
{
  public:
    //---------------------------------------------------------------
    /*! Initialize display

        Using cHwDisplayGraphic hardware
    */
    cDevDisplayGraphic( cHwDisplayGraphic &display //!< Referenz auf Hardware
                      );

    //---------------------------------------------------------------
    /*! Clear display
    */
    virtual void clear( void );

    //---------------------------------------------------------------
    /*! Refresh display
    */
    virtual void refresh( void );

    //---------------------------------------------------------------
    /*! Print a formated text string

        /todo Kommentar ueberarbeiten, Vererbung (cDevDisplay, cDevDisplayChar) besser nutzen
  
        The string is printed on position (\a line, \a column) with
        at least \a minLen characters. Empty spaces are padded, if
        necessary. Beginning with the \b format parameter, this method is
        equal to the correspondent ANSI-C function
    */
    virtual void printf( BYTE        line,   //!< Line number
                         BYTE        column, //!< Column number of first character
                         BYTE        minLen, //!< Minimum number of characters to print
                         const char *format, //!< Format string as defined in ANSI-C
                         ...);

    //---------------------------------------------------------------
    /*! Set a new font and zoom factor
    */
    virtual void setFont( cHwDisplayFont font,     //!< Font object
                          BYTE           zoom = 1  //!< Font zoom factor
                        );

    //---------------------------------------------------------------
    /*! Set a new zoom factor
    */
    virtual void setZoom( BYTE zoom = 1 //!< Font zoom factor
                        );

    //---------------------------------------------------------------
    /*! Set background color
    */
    virtual void setBackColor( WORD color //!< RGB color
                             );

    //---------------------------------------------------------------
    /*! Set Text color
    */
    virtual void setTextColor( WORD color  //!< RGB color
                             );

    //---------------------------------------------------------------
    /*! Draw a text string
    */
    virtual void drawText( WORD        x,  //!< X-position
                           WORD        y,  //!< Y-position
                           const char *str //!< String to print
                          );

    //---------------------------------------------------------------
    /*! Draw a formated text string

        The string is printed on position (\a x, \a y) with
        at least \a minLen characters. Empty spaces are padded, if
        necessary. Beginning with the \b format parameter, this method is
        equal to the ANSI-C function 'printf'
    */
    virtual void drawText( WORD        x,      //!< X-position
                           WORD        y,      //!< Y-position
                           BYTE        minLen, //!< Minimum number of characters to print
                           const char *format, //!< Format string as defined in ANSI-C
                           ... );

    //---------------------------------------------------------------
    /*! Draw a single pixel
    */
    virtual void drawPixel( WORD x,     //!< X-position
                            WORD y,     //!< Y-position
                            WORD color  //!< RGB color
                          );

    //---------------------------------------------------------------
    /*! Draw a filled rectangle
    */
    virtual void drawRectangle( WORD x,    //!< X-position (left)
                                WORD y,    //!< Y-position (top)
                                WORD w,    //!< Width
                                WORD h,    //!< Height
                                WORD color //!< RGB color
                              );

    //---------------------------------------------------------------
    /*! Draw a open rectangle (frame)
    */
    virtual void drawFrame( WORD x,    //!< X-position (left)
                            WORD y,    //!< Y-position (top)
                            WORD w,    //!< Width
                            WORD h,    //!< Height
                            WORD th,   //!< Thickness
                            WORD color //!< RGB color
                          );

    //---------------------------------------------------------------
    /*! Draw a filled circle
    */
    virtual void drawCircle( WORD x,    //!< X-position (left)
                             WORD y,    //!< Y-position (top)
                             WORD r,    //!< Radius
                             WORD color //!< RGB color
                           );

    //---------------------------------------------------------------
    /*! Draw a line
    */
    virtual void drawLine( WORD x0,   //!< start X-position
                           WORD y0,   //!< start Y-position
                           WORD x1,   //!< end X-position
                           WORD y1,   //!< end Y-position
                           WORD th,   //!< Thickness
                           WORD color //!< RGB color
                         );

    //---------------------------------------------------------------
    /*! Draw a bitmap picture

        Format: 16 bits per pixel
        \todo Get w and h from bitmap
    */
    virtual void drawBitmap( WORD        x,     //!< X-position (left)
                             WORD        y,     //!< Y-position (top)
                             WORD        w,     //!< Width
                             WORD        h,     //!< Height
                             const WORD *bitmap //!< Pointer to pixel array
                           );

    //---------------------------------------------------------------
    /*!
        \todo comment
    */
    virtual cHwDisplayFont getDefaultFont( void );
														 
    //---------------------------------------------------------------
		WORD getWidth( void )
		{
			return( display.getWidth() );
		}

    //---------------------------------------------------------------
		WORD getHeight( void )
		{
			return( display.getHeight() );
		}

  private:
    //---------------------------------------------------------------
    cHwDisplayGraphic &display;

}; //cDevDisplayGraphic

#endif
