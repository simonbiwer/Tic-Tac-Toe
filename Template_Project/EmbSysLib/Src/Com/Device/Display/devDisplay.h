//*******************************************************************
/*!
\file   devDisplay.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   25.04.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _DEV_DISPLAY_H
#define _DEV_DISPLAY_H

//*******************************************************************
/*!
\class cDevDisplay

\brief Abstract class supporting character and graphic displays

\example cDevDisplayChar.cpp, cDevDisplayGraphic.cpp
*/
class cDevDisplay
{
  protected:
    //---------------------------------------------------------------
    // Initialize display
    //
    cDevDisplay( void );

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
    /*! Print a formated text string

        The string is printed on position (\a line, \a column) with
        at least \a minLen characters. Empty spaces are padded, if
        necessary. Beginning with the \b format parameter, this method is
        equal to the correspondent ANSI-C function
    */
    virtual void printf( BYTE        line,   //!< Line number
                         BYTE        column, //!< Column number of first character
                         BYTE        minLen, //!< Minimum number of characters to print
                         const char *format, //!< Format string as defined in ANSI-C
                         ...) = 0;
						 

}; //cDevDisplay

#endif
