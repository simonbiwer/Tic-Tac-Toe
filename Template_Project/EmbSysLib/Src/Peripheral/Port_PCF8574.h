//*******************************************************************
/*!
\file   Port_PCF8574.h
\author Thomas Breuer
\date   11.03.2011
*/

//*******************************************************************
#ifndef _HW_PORT_PCF8574_H
#define _HW_PORT_PCF8574_H

//*******************************************************************
#include "Com/Hardware/I2Cmaster.h"
#include "Com/Hardware/Port.h"
#include "Com/Hardware/Timer.h"

//*******************************************************************
/*! 
\class cHwPort_PCF8574

\brief Implementation of the digital port expander PCF8574 (I2C-device)

Reading and writing via I2C is time expensive, therefor the data are 
buffered and can be refreshed with \b update(). Alternative an auto reresh 
can be initiate by a timer.

The update()-function performs a read/write from/to the port with 
interrupt disabled. 

\example cHwPort_PCF8574.cpp
*/
class cHwPort_PCF8574 : public cHwPort , cList::Item
{
  public:
    //---------------------------------------------------------------
    /*! Initialize PCF8574
        \param i2c    Reference to I2C interface
        \param hwAddr Slave address of PCF8574
        \param tPtr   Pointer to timer object, auto reresh (opional)
    */
    cHwPort_PCF8574( cHwI2Cmaster &i2c, 
                     BYTE           hwAddr,
                     cHwTimer      *tPtr = 0 );

    //---------------------------------------------------------------
    /*! Refresh port data 
    */
    virtual void update( void );

    //---------------------------------------------------------------
    virtual void setDir( MTYPE mask );

    //---------------------------------------------------------------
    virtual void clrDir( MTYPE mask );

    //---------------------------------------------------------------
    virtual void set( MTYPE mask );

    //---------------------------------------------------------------
    virtual void set( MTYPE mask, MTYPE value );

    //---------------------------------------------------------------
    virtual void clr( MTYPE mask );

    //---------------------------------------------------------------
    virtual MTYPE get( void );

  private:
    //---------------------------------------------------------------
    cHwI2Cmaster::Device  i2c;
    cHwTimer             *tPtr;

    MTYPE         valueIn;
    MTYPE         valueOut;
    MTYPE         dir;

    //---------------------------------------------------------------
    static const BYTE baseAdr = 0x40;
    static const BYTE maskAdr = 0x07;

}; //cHwPortPCF8574

#endif
