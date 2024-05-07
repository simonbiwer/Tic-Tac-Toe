//*******************************************************************
/*!
\file   Memory_MCU.cpp
\author Thomas Breuer
\date   25.02.2011
*/

//*******************************************************************
#include "Memory_MCU.h"

#include <conio.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>


//*******************************************************************
//
// cHwMemory_MCU
//
//*******************************************************************
//-------------------------------------------------------------------
cHwMemory_MCU::cHwMemory_MCU( char *filename, DWORD sizeIn, BYTE def )

: cHwMemory( sizeIn,    // size
             def ) // default value

{
  fh = open( filename, O_RDWR|O_CREAT|O_BINARY, S_IREAD|S_IWRITE );
//  ptr = (DWORD*)(&LPC_RTC->GPREG0);

if( fh <= 0)
    printf("Error open file %s\n", filename);

if( lseek( fh, 0, SEEK_END ) == 0) // empty file
  clear(0);

  if( size == 0 )
  {
    size = lseek( fh, 0, SEEK_END );
    if( size < 0 )
        size = 0;
  }
}

//-------------------------------------------------------------------
inline void cHwMemory_MCU::writeByte( DWORD addr, BYTE data )
{
  // write a single byte within a DWORD-Array
  //
/*
  DWORD *tmp  = ptr + (addr>>2);
  BYTE   offs = (addr&0x03)<<3;

  *tmp &= ~(0xFF<<offs);
  *tmp |=  (data<<offs);
*/
  if( fh )
  {
    lseek( fh, addr, SEEK_SET );
    ::write( fh, &data, 1 );
  }
}

//-------------------------------------------------------------------
inline BYTE cHwMemory_MCU::readByte( DWORD addr )
{
  BYTE data=0;
long l=-1,r=-1;
  if( fh
      && (l=lseek( fh, addr, SEEK_SET ))==(long)addr
      && (r=::read( fh, &data, 1 )) >=0    ) // Bug when reding 0x1A: read returns 0 instat of 1
  {
    return( data );
  }
  printf("\nread ERROR l=%ld r=%ld addr=%ld x%02x\n", l,r, addr,data);
  return( def );
}

//EOF
