//*******************************************************************
/*!
\file   Touch_ADS7846.h
\author Thomas Breuer
\date   10.03.2013
*/

//*******************************************************************
#ifndef _HW_TOUCH_ADS7846_H
#define _HW_TOUCH_ADS7846_H

//*******************************************************************
#include "Com/Hardware/SPImaster.h"
#include "Com/Hardware/Touch.h"

//*******************************************************************
/*!
\class cHwTouch_ADS7846

\brief Touch screen controller ADS7846

\example cHwTouch.cpp
*/
class cHwTouch_ADS7846 : public cHwTouch
{
  public:
    //---------------------------------------------------------------
    /*! Initialize touch screen controller
        \param spi    Reference to the SPI-object, which is connected 
                      to the touch controller
        \param width  Display width [pixel]
        \param height Display height [pixel]
    */
  cHwTouch_ADS7846( cHwSPImaster::Device &spi, 
                      WORD                width,
                      WORD                height );

    //---------------------------------------------------------------
    /*! Update coordinates and flags. This method must be called to 
        read new data from the touch controller
    */
    virtual void update( void );

  private:
    //---------------------------------------------------------------
    // Read data from SPI
    // ch: Data channel due to the transfer protocoll of ADS7846
    int readData( BYTE ch );

  private:
    //---------------------------------------------------------------
    cHwSPImaster::Device  spi;


}; //cHwTouch_ADS7846;

#endif
