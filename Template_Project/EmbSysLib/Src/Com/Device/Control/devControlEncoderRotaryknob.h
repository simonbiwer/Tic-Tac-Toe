//*******************************************************************
/*!
\file   devControlEncoderRotaryKnob.h
\author Thomas Breuer
\date   12.04.2011
*/

//*******************************************************************
#ifndef _DEV_CONTROL_ENCODER_ROTARYKNOB_H
#define _DEV_CONTROL_ENCODER_ROTARYKNOB_H

//*******************************************************************
#include "Com/Device/Control/devControlEncoder.h"

//*******************************************************************
/*!
\class   cDevControlEncoderRotaryKnob

Implementierung eines Encoders vom Typ Drehknopf.

Der Drehknopf besteht aus zwei Tasten, die bei einer Drehung
zeitversetzt bet�tigt werden, sowie einer zentralen Best�tigungstaste.

\example cDevControlEncoder.cpp
*/
class cDevControlEncoderRotaryKnob : public cDevControlEncoder
{
  public:
    //---------------------------------------------------------------
    /*! Instantiate a rotary knob
    */
    cDevControlEncoderRotaryKnob( cDevDigital *btnLeft,   //!< Zeiger auf Taste "links"
                                  cDevDigital *btnRight,  //!< Zeiger auf Taste "rechts"
                                  cDevDigital *btnCtrl,   //!< Zeiger auf zentrale Best�tigungstaste (optional)
                                  cHwTimer *timerPtr = 0  //!<  Timer f�r periodische Aktualisierung (optional)
                                );

  private:
    //---------------------------------------------------------------
	  virtual tEvent getIncrement( void );

  private:
    //---------------------------------------------------------------
    cDevDigital *btnLeft;
    cDevDigital *btnRight;
};

#endif
