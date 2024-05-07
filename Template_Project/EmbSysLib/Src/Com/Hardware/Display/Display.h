//*******************************************************************
/*!
\file   Display.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   05.04.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_DISPLAY_H
#define _HW_DISPLAY_H

//*******************************************************************
/*! 
\class cHwDisplay

\brief Abtract class supporting display hardware

This class provides some basic methods to clear the display and to
print characters 

\example cHwDisplay.cpp
*/
class cHwDisplay
{
  protected:
    //---------------------------------------------------------------
    // 
    //
    cHwDisplay( BYTE numberOfLinesIn,
                BYTE numberOfColumnsIn );

  public:
    //---------------------------------------------------------------
    /*! Clear display
    */
    virtual void clear( void ) = 0;

    //---------------------------------------------------------------
    /*! Refresh display
    */
    virtual void refresh( void ) = 0;

    //---------------------------------------------------------------
    /*! Set position of next character, relativ to upper left corner
        \param line  Line number (0,...)
        \param column Column number (0,...)
    */
    virtual void gotoTextPos( BYTE line, 
                              BYTE column ) = 0;

    //---------------------------------------------------------------
    /*! Put character at actual position and auto increment column 
        for next character
        \param c  Character (ASCII code)
    */
    virtual void putChar( char c ) = 0;

    //---------------------------------------------------------------
    /*! Get number of lines supported by the display
        \return Number of lines
    */
    virtual BYTE getNumberOfLines( void );

    //---------------------------------------------------------------
    /*! Get number of columns supported by the display
        \return Number of columns
    */
    virtual BYTE getNumberOfColumns( void );

  protected:
    //---------------------------------------------------------------
    WORD numberOfLines;
    WORD numberOfColumns;

}; //cHwDisplay

#endif
