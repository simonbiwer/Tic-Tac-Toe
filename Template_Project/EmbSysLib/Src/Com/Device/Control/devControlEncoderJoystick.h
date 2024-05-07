//*******************************************************************
/*!
\file   devControlEncoderJoystick.h
\author Thomas Breuer
\date   12.04.2011
*/

//*******************************************************************
#ifndef _DEV_CONTROL_ENCODER_JOYSTICK_H
#define _DEV_CONTROL_ENCODER_JOYSTICK_H

//*******************************************************************
#include "Com/Device/Control/devControlEncoder.h"

//*******************************************************************
/*!
\class cDevControlEncoderJoystick

Implementierung eines Encoders vom Typ Joystick.

Der Joystick besteht aus zwei Richtungstasten, die alternativ
betätigt werden können sowie einer zentralen Bestätigungstaste.

\example cDevControlEncoder.cpp
*/
class cDevControlEncoderJoystick : public cDevControlEncoder
{
  public:
    //---------------------------------------------------------------
    /*! Initialisiert Joystic

        Nach Ablauf der Wiedeholungszeit \b repeatTime wird bei
        dauernd gedrückter Taste das Ereignis wiederholt
        (0: keine Wiederholung).
    */
	  cDevControlEncoderJoystick( cDevDigital *btnLeft,       //!< Zeiger auf Taste "links"
                         cDevDigital *btnRight,      //!< Zeiger auf Taste "rechts"
                         cDevDigital *btnCtrl,       //!< Zeiger auf zentrale Bestätigungstaste (optional)
                         cHwTimer    *timerPtr = 0,  //!< Timer für periodische Aktualisierung (optional)
                         WORD         repeatTime = 0 //!< Wiederholungszeit in [ms], (optional)
                       );

  private:
    //---------------------------------------------------------------
	  virtual tEvent getIncrement( void );

  private:
    //---------------------------------------------------------------
    WORD         timerStart;
    WORD         timerCnt;
    cDevDigital *btnLeft;
    cDevDigital *btnRight;

};

#endif
