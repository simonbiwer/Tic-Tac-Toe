//*******************************************************************
/*!
\file   DAC.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_DAC_H
#define _HW_DAC_H

//*******************************************************************
/*!
\class cHwDAC

\brief Abstract class supporting the digital to analog converter (DAC)

This class is an interface to the DAC hardware. The given value is
immediately converted to a analog output. Multiple channels are
supported (limited by hardware). Independently of the resolution of
the used DAC, a 16 bit value is expected

Derived classes should at least:
 - initialize the DAC hardware
 - implement the set() method to set a sample value

\example cHwDAC.cpp
*/
class cHwDAC
{
  protected:
    //---------------------------------------------------------------
    //
    //
    cHwDAC( BYTE numIn );

  public:
    //---------------------------------------------------------------
    /*! Select a channel and set the value to convert
        \param value

        \param value Converted value (16 bit)
        \param ch    Channel number
    */
    virtual void set( WORD value,
                      BYTE ch = 0 ) = 0;

    //---------------------------------------------------------------
    /*! Enables a DAC-Channel
        \param ch Channel ID (0,...)
    */
    virtual void enable( BYTE ch = 0 ) = 0;

    //---------------------------------------------------------------
    /*! Get number of channels supported by the device
        \return Number of channels
    */
    virtual BYTE getNumberOfChannels( void );

  protected:
    //---------------------------------------------------------------
    BYTE  numOfChannels;  // number of supported channels

}; //cHwDAC

#endif
