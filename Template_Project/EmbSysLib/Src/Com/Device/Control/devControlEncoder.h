//*******************************************************************
/*!
\file   devControlEncoder.h
\author Thomas Breuer
\date   12.04.2011
*/

//*******************************************************************
#ifndef _DEV_CONTROL_ENCODER_H
#define _DEV_CONTROL_ENCODER_H

//*******************************************************************
#include "Com/Hardware/Timer/Timer.h"
#include "Com/Device/Digital/devDigital.h"

//*******************************************************************
/*!
\class   cDevControlEncoder

Abstract class for encoder (user interface)

Ein Encoder ist ein richtungssenitiver Inkremeltalgeber
(z.B. Joystick, Drehknopf). Zus�tzlich kann eine zentrale
Best�tigungstaste vorhanden sein. Ein cDevControlEncoder-Objekt wertet die
angeschlossene Hardware aus und schreibt ggf. das Event in ein FIFO.
Das FIFO kann asynchron ausgelesen werden.

\example cDevControlEncoder.cpp
*/
class cDevControlEncoder : public cList::Item
{
  public:
    //---------------------------------------------------------------
    /*! Encoder-Event
    */
	  typedef enum
    {
      NONE = 0, //!< Kein Ereignis
      LEFT,     //!< Bet�tigung in Richtung "links"
      RIGHT,    //!< Bet�tigung in Richtung "rechts"
      CTRL_DWN, //!< Bet�tigung der zentralen Best�tigungstaste
      CTRL_UP,  //!< Loslassen der zentralen Best�tigungstaste
      NUMITEMS

	  } tEvent;

  protected:
    //---------------------------------------------------------------
    // Konstruktor
    //
    // timer: HW-Timer, der update()-Mehode periodisch aufruft (optional)
    //
    cDevControlEncoder( cDevDigital *btnCtrlIn,
                 cHwTimer    *timer = 0 );

  public:
    //---------------------------------------------------------------
    /*! Liefert asynchron die im FIFO gespeicherten Encoder-Events
        \return aktuelles Ereignis
    */
    tEvent get( void );

    //---------------------------------------------------------------
    /*! update()-Methode, der von timer periodisch aufgerufen wird.
        Pr�ft die Zust�nde des Encoders (z.B. Joystick) und tr�gt
        Ereignis in FIFO ein
    */
 	  virtual void update( void );

  protected:
    //---------------------------------------------------------------
    // Das F�llen des FIFO's wird in der Oberklasse cDevControlEncoder
    // durchgef�hrt. Die abgeleiteten Klasse liefern mit den
    // folgenden get...()-Metoden nur die Events.
    // Timing: Beide get...()-Methoden werden in update() genau
    //         einmal aufgerufen.
    //
    //---------------------------------------------------------------
    // Pr�ft Ctrl-Button.
    // Die Default-Implementierung liefert das Event CTRL_DWN
		// bzw. CTRL_UP, wenn Button gedr�ckt/losgelassen wurde,
		// ansonsten NONE.
    // Die Methode kann �berschrieben werden.
    //
	  virtual tEvent getCtrl( void );

    //---------------------------------------------------------------
    // Pr�ft Inkrement (Rechts/Links).
    // Liefert je nach Ereignis LEFT, RIGHT, NONE
    // Abstrakte Methode, die von abgeleiteter Klasse implementiert
    // werden muss.
	  virtual tEvent getIncrement( void ) = 0;

  private:
    //---------------------------------------------------------------
    cFifo<tEvent> fifo;
    cDevDigital  *btnCtrl;

};

#endif
