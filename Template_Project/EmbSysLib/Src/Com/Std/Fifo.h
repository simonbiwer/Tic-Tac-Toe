//*******************************************************************
/*!
\file   Fifo.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _STD_FIFO_H
#define _STD_FIFO_H

#include "MCU/System.h"

//*******************************************************************
/*!
\class cFifo

\brief First-In-First-Out memory

The FIFO can be used for inter task communication

\example cFifo.cpp
*/
template <class T> class cFifo
{
  public:
    //---------------------------------------------------------------
    /*! Create a FIFO and allocate it's memory
        \param sizeIn FIFO size (max number of objects stored in FIFO)
    */
    cFifo( BYTE sizeIn )
    {
      in   = 0;
      out  = 0;
      anz  = 0;
      size = sizeIn;
      if( size > 0 )
      {
        speicher = new T[size];
      }
    }

    //---------------------------------------------------------------
    /*! Checks, if FIFO is full
        \return
                - true, if FIFO is full
                - false, if FIFO is not full
    */
    BYTE isFull( void )
    {
      BYTE ret;

      cSystem::disableInterrupt();
      ret = ( anz >= size );
      cSystem::enableInterrupt();

      return( ret );
    }

    //---------------------------------------------------------------
    /*! Checks, if FIFO is empty
        \return
                - true, if FIFO is empty
                - false, if FIFO is not empty
    */
    BYTE isEmpty( void )
    {
      BYTE ret;

      cSystem::disableInterrupt();
      ret = ( anz == 0 );
      cSystem::enableInterrupt();

      return(ret);
    }

    //---------------------------------------------------------------
    /*! Get number of objects, currently stored in the FIFO
        \return Number of objects
    */
    BYTE getCount( void )
    {
      BYTE ret;

      cSystem::disableInterrupt();
      ret = anz;
      cSystem::enableInterrupt();

      return(ret);
    }

    //---------------------------------------------------------------
    /*! Get FIFO size
        \return FIFO size
    */
    BYTE getSize( void )
    {
      return( size );
    }

    //---------------------------------------------------------------
    /*! Write an object to the FIFO
        \param ref Reference to an object
        \return
                - true, if succeeded
                - false, if FIFO is full, object not written
    */
    BYTE operator<<( const T &ref )
    {
      BYTE ret = 0;

      cSystem::disableInterrupt();
      if( anz < size )
      {
        speicher[in] = ref;
        in = (in < size-1) ? in+1 : 0;
        anz++;
        ret = 1;
      }
      cSystem::enableInterrupt();

      return( ret );
    }

    //---------------------------------------------------------------
    /*! Read an object from FIFO
        \param ref Referenc to an object
        \return
                - true, if succeeded
                - false, if FIFO is empty, no object read
    */
    BYTE operator>>( T &ref )
    {
      BYTE ret = 0;

      cSystem::disableInterrupt();
      if( anz != 0 )
      {
        ref = speicher[out];
        out = (out < size-1) ? out+1 : 0;
        anz--;
        ret = 1;
      }
      cSystem::enableInterrupt();

      return( ret );
    }

  private:
    //---------------------------------------------------------------
    T    *speicher;
    BYTE  in;
    BYTE  out;
    BYTE  anz;
    BYTE  size;

}; //cFifo

#endif
