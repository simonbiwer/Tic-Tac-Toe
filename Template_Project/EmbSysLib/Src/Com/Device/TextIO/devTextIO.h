//*******************************************************************
/*!
\file   devTextIO.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _DEV_TEXT_IO_H
#define _DEV_TEXT_IO_H

//*******************************************************************
/*!
\class cDevTextIO

\brief Abstract class supporting textual IO

The derived class has to implement a \b get() and a \b set() method.

Then this class uses the \b get() method of derived class as data  
input. The input is bufferd in a string until input buffer is full 
(\b inBufSize) or a received character matches one of the characters 
in the \b eos string. The string is complete also if the first 
reading matches a character in the \b key string or it is detected
as ESC-sequence or as a function key code. 
Key codes (e.g. arrow key) and ESC sequences are konverted to a 
single byte (= 0x80|keyCode). The first call to \b getString() after 
an input is complete will return a pointer to the input string.

The \b printf() method is conform to the ANSI-C function and uses the 
\b set() method of derived class. The length of the output string is 
limited to \b outBufSize.

\example cDevTextIO.cpp
*/
class cDevTextIO
{
  protected:
    //---------------------------------------------------------------
    // Initialize a TextIO device
    cDevTextIO( BYTE        inBufSize,    // Size of input buffer
                BYTE        outBufSize,   // Size of output buffer
                const char *eos = "\n\r", // Defines end-of-string characters
                const char *key = ""      // Defines single key characters
              );

  public:
    //---------------------------------------------------------------
    /*! Read and interprete input data

        Each call to this function will initiate a reading from the
        hardware as far as new data is available. ESC sequences or 
        function key codes are converted:
  
        <table border>
        <tr><td><b>Key </b></td> <td><b>Code</b></td> <td><b>Output</b></td></tr>
        <tr><td>   up      </td> <td>   0x41    </td> <td>   0xC1      </td></tr>
        <tr><td>   down    </td> <td>   0x42    </td> <td>   0xC2      </td></tr>
        <tr><td>   right   </td> <td>   0x43    </td> <td>   0xC3      </td></tr>
        <tr><td>   left    </td> <td>   0x44    </td> <td>   0xC4      </td></tr>
        </table>
 
        \return Pointer to last received string or NULL
    */
    char *getString( void );

    //---------------------------------------------------------------
    /*! Print a string

        The syntax of this method is compatible to the same named
        ANSI-C function

        \warning The string length must not exceed \b outBufSize!
    */
    virtual void printf( const char *format, //!< Format string as defined in ANSI-C
                         ...                 //!< Additional arguments
                       );

  protected:
    //---------------------------------------------------------------
    virtual void set( BYTE *str, BYTE size ) = 0;
    
    //---------------------------------------------------------------
    virtual bool get( BYTE *c ) = 0;
    
  private:
    //---------------------------------------------------------------
    char       *strIn;
    char       *strOut;
    BYTE        inBufSize;
    BYTE        outBufSize;
    BYTE        idx;
    const char *eos;
    const char *key;
    BYTE        escape;
    BYTE        last;

}; //cDevTextIO

#endif
