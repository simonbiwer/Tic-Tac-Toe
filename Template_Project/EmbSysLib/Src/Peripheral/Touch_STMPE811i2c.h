//*******************************************************************
/*!
\file   Touch_STMPE811i2c.h
\author Thomas Breuer
\date   10.03.2013
*/

//*******************************************************************
#ifndef _HW_TOUCH_STMPE811_I2C_H
#define _HW_TOUCH_STMPE811_I2C_H

//*******************************************************************
#include "Com/Hardware/I2C/I2Cmaster.h"
#include "Com/Hardware/Display/Touch.h"

//*******************************************************************
/*!
\class cHwTouch_STMPE811i2c

\brief Touch screen controller STMPE811, using I2C interface

\example cHwTouch.cpp
*/
class cHwTouch_STMPE811i2c : public cHwTouch
{
  public:
    //---------------------------------------------------------------
    /*! Initialize touch screen controller
        \param i2c    Reference to the I2C-object, which is connected 
                      to the touch controller
        \param addr   I2C device (sub-)address of the touch 
                      controller (0 or 1)
        \param width  Display width [pixel]
        \param height Display height [pixel]
    */
    cHwTouch_STMPE811i2c( cHwI2Cmaster &i2c, 
                          BYTE          addr, 
                          WORD          width, 
                          WORD          height );

    //---------------------------------------------------------------
    /*! Update coordinates and flags. This method must be called to 
        read new data from the touch controller
    */
    virtual void update( void );

  private:
    //---------------------------------------------------------------
  cHwI2Cmaster::Device i2c;

}; //cHwTouch_STMPE811i2c;

#endif
