//*******************************************************************
/*!
\file   SharedMem.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _STD_SHARED_MEM_H
#define _STD_SHARED_MEM_H

//*******************************************************************
#include <string.h>

//*******************************************************************
/*!
\class cSharedMem

\brief Shared memory, locked memory read and write. 
The shared memory can be used for inter task communication

\example cSharedMem.cpp
*/
template <class T> class cSharedMem
{
  public:
    //---------------------------------------------------------------
    /*! Create a shared memory. The memory is zero initialized
    */
    cSharedMem( void )
    {
      memset( &speicher, 0, sizeof(T) );
    }

    //---------------------------------------------------------------
    /*! Write an object to the shared memory
        \param ref Reference to an object
    */
    void operator<<( const T &ref )
    {
      cSystem::disableInterrupt();
      speicher = ref;
      cSystem::enableInterrupt();
    }

    //---------------------------------------------------------------
    /*! Read from shared memory
        \param ref Reference to an object
    */
    void operator>>( T &ref )
    {
      cSystem::disableInterrupt();
      ref = speicher;
      cSystem::enableInterrupt();
    }

  private:
    //---------------------------------------------------------------
    T speicher;

}; //cSharedMem

#endif
