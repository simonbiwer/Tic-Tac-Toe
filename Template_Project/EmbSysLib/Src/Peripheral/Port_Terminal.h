//*******************************************************************
/*!
\file   Port_Terminal.h
\author Thomas Breuer
\date   08.03.2011
*/

//*******************************************************************
#ifndef _HW_PORT_TERMINAL_H
#define _HW_PORT_TERMINAL_H

//*******************************************************************
#include "Com/Hardware/UART.h"
#include "Com/Hardware/Port.h"
#include "Com/Hardware/Timer.h"

//*******************************************************************
/*!
\class cHwPort_Terminal

\brief Digital I/O terminal

This class emulates a digital I/O on an uart/tty terminal

Reading and writing via UART is time expensive, therefor the data are
buffered and can be refreshed with \b update(). Alternative an auto reresh
can be initiate by a timer.

The update()-function performs a read/write from/to the port with
interrupt disabled.

\warning If a timer refresh is used AND a port is configured as output,
then the refresh intervall must be sufficient to empty UART bufers

\warning A call to update() may overwrite port data unintentionally

\todo Funktioniert in Vebindung mit mehreren cDevPort nur, wenn Timer verwendet wird!
      Grund: update() wird bei jedem cDevPort::get() aufgerufen und überschreibt letztes Ergeignis
      Prüfen, ob dieser Effekt mit "latch = latch & lock;" in update() zusammenhängt!

\todo Mehrere Instanzen mit derselben Schnittstelle, damit auch 8-Bit Controller mehr als 8 bit unterstützen

\example cHwPort_Terminal.cpp
*/
class cHwPort_Terminal : public cHwPort , cList::Item
{
  public:

    /*! Nummer des Bits, das eine Taste repräsentiert
    */
    typedef enum
    {
      LEFT  = 0x01, //!< left key
      RIGHT = 0x02, //!< right key
      UP    = 0x04, //!< up key
      DOWN  = 0x08, //!< down key
      ENTER = 0x10, //!< enter
      PLUS  = 0x20, //!< plus (+)
      MINUS = 0x40, //!< minus (-)
      BLANK = 0x80, //!< space

      // alternate keys
      NUM_1 = 0x80, //!< num key 1
      NUM_2 = 0x40, //!< num key 2
      NUM_3 = 0x20, //!< num key 3
      NUM_4 = 0x10, //!< num key 4
      NUM_5 = 0x08, //!< num key 5
      NUM_6 = 0x04, //!< num key 6
      NUM_7 = 0x02, //!< num key 7
      NUM_8 = 0x01, //!< num key 8

    } KEY_BIT;

    //---------------------------------------------------------------
  	/*! Initialize port
        \param uart Reference to UART interface
        \param lock Bit mask, defines which bits are NOT reseted with
                    next call to update()
        \param tPtr Pointer to timer object, auto refresh (optional)
	  */
    cHwPort_Terminal( cHwUART  &uart,
                      MTYPE     lock,
                      cHwTimer *tPtr = 0 );

    //---------------------------------------------------------------
    /*! Refresh port data
    */
    virtual void update();

    //---------------------------------------------------------------
    virtual void setMode( MTYPE mask, Mode mode );

    //---------------------------------------------------------------
    virtual void setPinMode( BYTE pinId, Mode modeIn );

    //---------------------------------------------------------------
    virtual void set( MTYPE mask );

    //---------------------------------------------------------------
    virtual void set( MTYPE mask, MTYPE value );

    //---------------------------------------------------------------
    virtual void clr( MTYPE mask );

    //---------------------------------------------------------------
    virtual MTYPE get( void );

  private:
    //---------------------------------------------------------------
    cHwUART  &uart;
    cHwTimer *tPtr;

    MTYPE latch;
    MTYPE out;
    MTYPE dir;
    MTYPE lock;
    MTYPE last;
    BYTE  escape;

}; //cHwPort_Terminal

#endif
