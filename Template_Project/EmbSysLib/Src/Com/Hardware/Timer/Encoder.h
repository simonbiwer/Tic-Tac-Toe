//*******************************************************************
/*!
\file   Encoder.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_ENCODER_H
#define _HW_ENCODER_H

//*******************************************************************
#include "MCU/System.h"
#include "Com/Hardware/Port/Port.h"
#include "Com/Hardware/Timer/Timer.h"
#include "Com/Std/List.h"

//*******************************************************************
/*! 
\class cHwEncoder

\brief Abstract class supporting a quadratur encoder

\example cHwEncoder.cpp
*/
class cHwEncoder
{
  public:
    //---------------------------------------------------------------
    /*! \enum Mode
        \brief Define encoder operating modes
    */
    typedef enum
    {
      NORMAL  = 0x00, //!< Normal count direction
      REVERSE = 0x01  //!< Reverse count direction
    } Mode;

  protected:
    //---------------------------------------------------------------
    // Standard constructor
    // 
    cHwEncoder( Mode modeIn )
    {
      mode = modeIn;
    }

  public:
    //---------------------------------------------------------------
    /*! Get and reset counter
        \return Steps since last call of this function
    */
    virtual int get( void ) = 0;
  

  protected:
    //---------------------------------------------------------------
    Mode mode;

}; //cHwEncoder

//*******************************************************************
/*!
\class cHwEncoder_Emul

\todo Add documentation
*/
class cHwEncoder_Emul : public cHwEncoder, cList::Item
{
  public:
    //---------------------------------------------------------------
    cHwEncoder_Emul( cHwPort::Pin &pinAIn,
                     cHwPort::Pin &pinBIn,
                     cHwTimer     &timer,
                     Mode          modeIn )
    : cHwEncoder( modeIn ),
      pinA( pinAIn ),
      pinB( pinBIn )
      {
          pinA.setMode( cHwPort::InFL );
          pinB.setMode( cHwPort::InFL );
          timer.add( this );
          A_last = 0;
          B_last = 0;
          cnt    = 0;
      }

    //---------------------------------------------------------------
    virtual void update( void )
    {
      BYTE A_new = pinA.get();
      BYTE B_new = pinB.get();

      cSystem::disableInterrupt();
        
      if( A_new != A_last )
      {
          if( A_new == B_new )
          {
            cnt++;
          }
          else
          {
            cnt--;
          }
      }
      else if( B_new != B_last )
      {
          if( B_new != A_new )
          {
            cnt++;
          }
          else
          {
            cnt--;
          }
      }
      cSystem::enableInterrupt();
        
      A_last = A_new;
      B_last = B_new;
    }

    //---------------------------------------------------------------
    virtual int get( void )
    {
        cSystem::disableInterrupt();
        int ret = cnt;
        cnt = 0;
        cSystem::enableInterrupt();
        return( (mode&REVERSE)?ret:-ret );
    }

  private:
    //---------------------------------------------------------------
    cHwPort::Pin &pinA;
    cHwPort::Pin &pinB;
    BYTE A_last;
    BYTE B_last;

    int cnt;
};

#endif
