//*******************************************************************
/*!
\file   Port_MCU.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_PORT_MCU_H
#define _HW_PORT_MCU_H

//*******************************************************************
#include "Com/Hardware/Port/Port.h"

//*******************************************************************
/*! 
\class cHwPort_N

\brief Implementation of the GPIO

\example cHwPort.cpp
*/
class cHwPort_N : public cHwPort
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
    /*! Instantiate a port
        \param portId Port identification
    */
    cHwPort_N( PortId portId );

    //---------------------------------------------------------------
    virtual void setMode( MTYPE mask, Mode mode );

    //---------------------------------------------------------------
    virtual void setPinMode( BYTE pinId, Mode modeIn );

    //---------------------------------------------------------------
    virtual void set( MTYPE mask )
    {
      ptr->BSRR = mask;
    }

    //---------------------------------------------------------------
    virtual void set( MTYPE mask, MTYPE value )
    {
      ptr->BSRR = mask &  value;
      ptr->BSRR = (mask & ~value)<<16;
    }

    //---------------------------------------------------------------
    virtual void clr( MTYPE mask )
    {
      ptr->BSRR = mask<<16;
    }

    //---------------------------------------------------------------
    virtual MTYPE get( void )
    {
      return( ptr->IDR );
    }

  private:
    //---------------------------------------------------------------
    GPIO_TypeDef *ptr;

}; //cHwPort_N

#endif
