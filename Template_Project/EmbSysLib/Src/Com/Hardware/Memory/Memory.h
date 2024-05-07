//*******************************************************************
/*!
\file   Memory.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_MEMORY_H
#define _HW_MEMORY_H

//*******************************************************************
/*! 
\class cHwMemory

\brief Abstract class supporting non volatile memory

This base class encapsulates non volatile memories, 
e.g. EEPROM, Flash-RAM  or battery buffered RAM

Derived classes should at least:
 - initialize the memory hardware access (but not the memory content)
 - implement \a writeByte() to write a data byte into the memory
 - implement \a readByte() to read a data byte from the memory
 
\example cHwMemory.cpp
*/
class cHwMemory
{
  protected:
    //---------------------------------------------------------------
    // Initialize memory access
    // size: Memory space
    // def:  Default value, used in clear() and read()
    //
    cHwMemory( DWORD size, 
               BYTE  def );

  public:
    //---------------------------------------------------------------
    /*! Unlock memory
    */
    virtual void unlock( void ) = 0;
    
    //---------------------------------------------------------------
    /*! Lock memory
    */
    virtual void lock( void ) = 0;
    
    //---------------------------------------------------------------
    /*! Write a data byte to the specified memory address
        \param addr Memory address
        \param data Data byte
    */
    virtual void write( DWORD addr, 
                        BYTE  data );
    
    //---------------------------------------------------------------
    /*! Read a data byte from a specified memory address
        \param  addr Memory address
        \return data byte
    */
    virtual BYTE read( DWORD addr );

    //---------------------------------------------------------------
    /*! Clear the complete memory by writing default
        \param offset Start address 
    */
    virtual void clear( DWORD offset = 0 );

    //---------------------------------------------------------------
    /*! Get memory size 
        \return Size of memory, unit: byte
    */
    virtual DWORD getSize( void );

    //---------------------------------------------------------------
    /*! Check, if memory is of type flash with block erase only
        \return true, if the memory is a flash memory
    */
    virtual bool isFlash( void );

  protected:
    //---------------------------------------------------------------
    // Writes a data byte to the memory hardware
    // addr: Memory address 
    // data: Stored data byte
    //
    virtual void writeByte( DWORD addr, 
                            BYTE  data ) = 0;

    //---------------------------------------------------------------
    // Reads a data byte from the memory hardware
    // addr:   Memory address
    // return: Recalled data byte
    //
    virtual BYTE readByte( DWORD addr ) = 0;

  protected:
    //---------------------------------------------------------------
    DWORD size;
    BYTE  def;
    bool  isFlashFlag;

}; //cHwMemory

#endif
