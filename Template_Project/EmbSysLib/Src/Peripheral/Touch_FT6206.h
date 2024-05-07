//*******************************************************************
/*!
\file   Touch_FT6206.h
\author Thomas Breuer
\date   03.04.2019
*/

//*******************************************************************
#ifndef _HW_TOUCH_FT6206_H
#define _HW_TOUCH_FT6206_H

//*******************************************************************
#include "Com/Hardware/I2C/I2Cmaster.h"
#include "Com/Hardware/Display/Touch.h"

//*******************************************************************
/*!
\class cHwTouch_FT6206

\brief Touch screen controller FT6206 with I2C interface

\example cHwTouch.cpp
*/
class cHwTouch_FT6206 : public cHwTouch
{
  public:
    //---------------------------------------------------------------
    /*! Initialize touch screen controller
        \param i2c    Reference to the I2C-object, which is connected 
                      to the touch controller
        \param width  Display width [pixel]
        \param height Display height [pixel]
    */
    cHwTouch_FT6206( cHwI2Cmaster &i2c );

    //---------------------------------------------------------------
    /*! Update coordinates and flags. This method must be called to 
        read new data from the touch controller
    */
    virtual void update( void );

  private:
    //---------------------------------------------------------------
    static const BYTE hwAddr = 0x54;
	  static const WORD WIDTH  = 800;
	  static const WORD HEIGHT = 480;
	
	  cHwI2Cmaster::Device i2c;

}; //cHwTouch_FT6206;

#endif
