//*******************************************************************
/*!
\file   RS485_MAX48x.h
\author Thomas Breuer
\date   14.10.2013
*/

//*******************************************************************
#ifndef _HW_RS485_MAX48X_H
#define _HW_RS485_MAX48X_H

//*******************************************************************
#include "Com/Hardware/UART.h"

//*******************************************************************
/*!
\class cHwRS485_MAX48x

\brief Abstract class supporting RS485 communicaion interface

\example cHwRS485_MAX48x.cpp
*/
template <class T> class cHwRS485_MAX48x : public T
{

  public:
    //---------------------------------------------------------------
    /*! Instantiate RS485 Interface\n
    */
    cHwRS485_MAX48x( cHwPort::Pin &pinIn
                   )

  : pin( pinIn )

    {
      pin.setMode( cHwPort::Out );
      pin.clr   ();
    }

  private:
    //-----------------------------------------------------------------
    //
    //
    virtual void isrTx( void )
    {
      if( T::txReady )
      {
        pin.set();
      }

      T::isrTx();

      if( T::txReady )
      {
        pin.clr();
      }
    }

  private:
    //---------------------------------------------------------------
    cHwPort::Pin &pin;

}; //cHwRS485_MAX48x

#endif
