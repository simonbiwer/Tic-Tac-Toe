//*******************************************************************
/*!
\file   devDisplayChar.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   25.04.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _DEV_DISPLAY_CHAR_H
#define _DEV_DISPLAY_CHAR_H

//*******************************************************************
#include "Com/Hardware/Display/Display.h"
#include "Com/Device/Display/devDisplay.h"

//*******************************************************************
/*!
\class cDevDisplayChar

\brief Character display

\warning This is a draft. The string length must not exceed 30 characters

\example cDevDisplayChar.cpp
*/
class cDevDisplayChar : public cDevDisplay
{
  public:
    //---------------------------------------------------------------
    /*! Initialize display

        Using cHwDisplay hardware
        \param display Reference to a cHwDisplay object
    */
    cDevDisplayChar( cHwDisplay &display );

    //---------------------------------------------------------------
    /*! Clear display
    */
    virtual void clear( void );

    //---------------------------------------------------------------
    /*! Refresh display
    */
    virtual void refresh( void );

    //---------------------------------------------------------------
    /*! Print a text string

        The string is printed on position (\a line, \a column).
        \param line   Line number
        \param column Column number of first character
        \param str    String to print
    */
    virtual void printf( BYTE        line, 
                         BYTE        column,
                         const char *str );

    //---------------------------------------------------------------
    /*! Print a formated text string

        The string is printed on position (\a line, \a column) with
        at least \a minLen characters. Empty spaces are padded, if
        necessary. Beginning with the \b format parameter, this method is
        equal to the correspondent ANSI-C function
        \param line   Line number
        \param column Column number of first character
        \param minLen Minimum number of characters to print
        \param str    String to print
    */
    virtual void printf( BYTE        line,
                         BYTE        column,
                         BYTE        minLen,
                         const char *format,
                         ... );

  private:
    //---------------------------------------------------------------
    cHwDisplay &display;

}; //cDevDisplayChar

#endif
