//*******************************************************************
/*!
\file   DisplayFont.h
\author Thomas Breuer
\date   21.03.2012
*/

//*******************************************************************
#ifndef _HW_DISPLAY_FONT_H
#define _HW_DISPLAY_FONT_H

//*******************************************************************
class cHwDisplayFontProperties;

//*******************************************************************
/*! 
\class cHwDisplayFont

\brief Font manager

This class mangages the display font. Supports bitmap fonts only. 
The font is defined by cHwDisplayFontProperties and cHwDisplayFontData

\see cHwDisplayGraphic
*/
class cHwDisplayFont
{
  public:
    //---------------------------------------------------------------
    /*! Instantiate a font object 
        \remark Use with cHwDisplayFontData only
        \param prop Pointer to font properties
        \param data Pointer to font data  
     */ 
     cHwDisplayFont( void ) {}

    cHwDisplayFont( const cHwDisplayFontProperties *prop, 
                     const BYTE                     *data );
     
    //---------------------------------------------------------------
    /*! Get the width of a character
        \return Character width in pixel       
     */
    BYTE getCharWidth( void ) const;
      
    //---------------------------------------------------------------
    /*! Get the height of a character
        \return Character height in pixel       
     */
    BYTE getCharHeight( void ) const;
      
    //---------------------------------------------------------------
    /*! Set the ASCII code of the character, which is handled in the 
        next call of getPixel()
        \param c  Character code
     */
    void setChar( BYTE c );
      
    //---------------------------------------------------------------
    /*! Check, if the pixel at the given Position is set in the 
        selected character 
        \see setChar()
        \param x  Horizontal position within character bitmap
        \param y  Vertical position within character bitmap
        \return 
                - true: Pixel is set
                - false Pixel is not set
     */
    BYTE getPixel( BYTE x, 
                   BYTE y );
    
  private:
    //---------------------------------------------------------------
    const cHwDisplayFontProperties *prop;
    const BYTE                     *data;
    const BYTE                     *selected;

}; //cHwDisplayFont

//*******************************************************************
/*! 
\class cHwDisplayFontProperties

\brief POD covering font properties
*/
class cHwDisplayFontProperties
{
  public:
    //---------------------------------------------------------------
    BYTE firstId;      //!< First ASCII code of the font
    BYTE lastId;       //!< Last ASCII code of the font
    BYTE bytePerChar;  //!< Number of memory bytes per character
    BYTE charWidth;    //!< Width of a character in pixel
    BYTE charHeight;   //!< Height of a character in pixel

}; //cHwDisplayFontProperties

//*******************************************************************
/*! 
\class cHwDisplayFontData

\brief POD covering font properties and data

\remark Use cHwDisplayFont to access the font
*/
template <WORD NUM_OF_CHAR, BYTE BYTE_PER_CHAR> class cHwDisplayFontData
{
  public:
    //---------------------------------------------------------------
    cHwDisplayFontProperties prop;
    BYTE                     data[NUM_OF_CHAR  ]
                                 [BYTE_PER_CHAR];  

    //---------------------------------------------------------------
    /*! Convert properties and data 
     * 
     */
    operator cHwDisplayFont( void ) const
    {
      return( cHwDisplayFont( &prop, (BYTE*)data ) );
    } 
      
}; //cHwDisplayFontData

#endif
