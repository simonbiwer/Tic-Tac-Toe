//*******************************************************************
/*!
\file   devMemory.h  
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   18.10.2013, 23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _DEV_MEMORY_H
#define _DEV_MEMORY_H

//*******************************************************************
#include "Com/Hardware/Memory/Memory.h"

//*******************************************************************
/*!
\class cDevMemory

\brief Access to a memory

\example cDevMemory.cpp
*/
class cDevMemory
{
  public:
    //---------------------------------------------------------------
    /*! Initialize memory access

        Using cHwMemory hardware
    */
    cDevMemory( cHwMemory &memIn,      //!< Reference to memory hardware
                WORD       addrIn = 0  //!< Base address
              );

    //---------------------------------------------------------------
    /*! Reserve memory area
        \return Memory address offset
    */
    WORD allocate( WORD size   //!< Size of area to reserve
                 );

    //---------------------------------------------------------------
    /*! Write data into memory
    */
    void write( BYTE *data, //!< Pointer to data array
                WORD  size, //!< Number of bytes in data array
                WORD  offs  //!< Memory address offset
              );

    //---------------------------------------------------------------
    /*! Read data from memory
    */
    void read( BYTE *data,  //!< Pointer to data array
               WORD  size,  //!< Number of bytes in data array
               WORD  offs   //!< Memory address offset
             );

    //---------------------------------------------------------------
    /*! Clear complete memory area (writing default)
    */
    void clear( void );

    //---------------------------------------------------------------
    /*! Set memory valid
    */
    void setValid( void );

    //---------------------------------------------------------------
    /*! Check, if memory is valid
        \return
                - true:  memory is ok
                - false: memory is not ok
    */
    BYTE isValid( void );

    BYTE isFlash( void )
    {
      return( mem.isFlash() );
    }


  private:
    //---------------------------------------------------------------
    WORD       addr;
    WORD       pos;
    cHwMemory &mem;

}; //cDevMemory

//*******************************************************************
/*!
\class cDevMemoryFragment

\brief Manage a memory fragment, specialized by the given class

\example cDevMemory.cpp
*/
template <class T> class cDevMemoryFragment
{
  public:
    //---------------------------------------------------------------
    /*! Initialize memory fragment
    */
    cDevMemoryFragment( cDevMemory &memIn  //!< Reference to memory device
                      )
    : mem( memIn )

    {
      offs = mem.allocate( sizeof( T )+1 );
    }

    //---------------------------------------------------------------
    /*! Check, if memory fragment is valid
        \return
                - true:  memory is ok
                - false: memory is not ok
    */
    BYTE isValid( void )
    {
      BYTE valid = 0;

      mem.read( &valid, sizeof( BYTE ), offs );
      return( ( valid == 0xAA ) ? true : false );
    }

    //---------------------------------------------------------------
    /*! Clear memory fragment
    */
    void clear( void )
    {
      BYTE valid = 0;
      mem.write( &valid, sizeof( BYTE ), offs );
    }

    //---------------------------------------------------------------
    /*! Read memory fragment

        Output data is leaved unattached, if memory fragment is unvalid
    */
    void operator>>( T &data //!< Reference to output data
                   )
    {
      if( isValid() )
      {
        mem.read( (BYTE*)&data, sizeof( T ), offs+1 );
      }
    }

    //---------------------------------------------------------------
    /*! Write memory fragment
    */
    void operator<<( const T &data //!< Reference to input data
                   )
    {
      BYTE valid = 0xAA;

      mem.write( (BYTE*)&data, sizeof( T ), offs+1 );
      mem.write( &valid, sizeof( BYTE ), offs );
    }

  private:
    //---------------------------------------------------------------
    cDevMemory &mem;
    WORD        offs;

};

#endif
