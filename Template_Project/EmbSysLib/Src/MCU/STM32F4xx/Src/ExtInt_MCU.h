//*******************************************************************
/*!
\file   ExtInt_MCU.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_EXTINT_MCU_H
#define _HW_EXTINT_MCU_H

//*******************************************************************
#include "Com/Hardware/Port/Port.h"
#include "Com/Hardware/Port/ExtInt.h"

//*******************************************************************
/*!
\class cHwExtInt_N

\brief

\example
*/
class cHwExtInt_N : public cHwExtInt
{
  public:
    //---------------------------------------------------------------
    /*! \enum PortId
        \brief GPIO port identification
    */
    typedef enum
    {
      PA = 0, //!< GPIO Port A
      PB,     //!< GPIO Port B
      PC,     //!< GPIO Port C
      PD,     //!< GPIO Port D
      PE,     //!< GPIO Port E
      PF,     //!< GPIO Port F
      PG,     //!< GPIO Port G
      PH,     //!< GPIO Port H
      PI,     //!< GPIO Port I
    } PortId;

  public:
    //---------------------------------------------------------------
    /*! Instantiate ...
        \param portId Port identification
    */
    cHwExtInt_N( cHwExtInt_N::PortId portId, BYTE pinId );

    virtual void enable();
    virtual void disable();
    virtual void setEdge( Edge edge);

    //---------------------------------------------------------------
    // Interrupt Service Routine (ISR) of timer interrupt.
    // This function must be public, because it is called
    // in extern "C"
    void isr_N( void );

static cHwExtInt_N *extIntPtr[16];

BYTE   pinId;
BYTE   portId;
IRQn_Type  irqNumber;

}; //cHwExtInt_N

#endif
