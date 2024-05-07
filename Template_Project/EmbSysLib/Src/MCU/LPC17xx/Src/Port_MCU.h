//*******************************************************************
/*!
\file   Port_MCU.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   08.09.2016

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
      P0 = 0, //!< GPIO Port 0
      P1,     //!< GPIO Port 1
      P2,     //!< GPIO Port 2
      P3,     //!< GPIO Port 3
      P4      //!< GPIO Port 4
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
    virtual void setPinMode( BYTE pinId, Mode mode );








    //---------------------------------------------------------------
    virtual void set( MTYPE mask )
    {
      ptr->FIOSET = mask;
    }

    //---------------------------------------------------------------
    virtual void set( MTYPE mask, MTYPE value )
    {
      ptr->FIOSET = mask &  value;
      ptr->FIOCLR = mask & ~value;
    }
 
    //---------------------------------------------------------------
    virtual void clr( MTYPE mask )
    {
      ptr->FIOCLR = mask;
    }

    //---------------------------------------------------------------
    virtual MTYPE get( void )
    {
      return( ptr->FIOPIN );
    }

  private:
    //---------------------------------------------------------------
    volatile LPC_GPIO_TypeDef *ptr;

}; //cHwPort_N

#endif
