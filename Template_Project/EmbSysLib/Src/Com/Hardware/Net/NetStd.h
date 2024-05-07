//*******************************************************************
/*!
\file   NetStd.h
\author Thomas Breuer
\date   11.03.2011

\brief Standard include file

\par Content:

*/

//*******************************************************************
#ifndef _NET_STD_H
#define _NET_STD_H

#include "string.h"
#include <stdio.h>

//*******************************************************************
template <BYTE size> class cNetAddr
{
  public:
    //-----------------------------------------------------------
    BYTE operator==(const cNetAddr &x) const
    {
      return( memcmp(addr, x.addr, size) == 0 );
    }

    //-----------------------------------------------------------
    void operator=(BYTE *addrIn)
    {
      BYTE i=0;
      while(i < size)
      {
        addr[i] = addrIn[i];
        i++;
       }
    }

    //-----------------------------------------------------------
    void operator=(char *addrIn)
    {
        WORD tmp[4] = {0,0,0,0};
        sscanf((char*)addrIn,"%hu.%hu.%hu.%hu", &tmp[0],&tmp[1],&tmp[2],&tmp[3]);
        for(BYTE i=0;i<4;i++)
            addr[i] = tmp[i];
    }

    //-----------------------------------------------------------
    operator char *()
    {
     static char tmp[16] = "";
        sprintf(tmp,"%u.%u.%u.%u", addr[0],addr[1],addr[2],addr[3]);
        return( tmp );
    }

    //-----------------------------------------------------------
    void operator=(DWORD addrIn)
    {
      BYTE i=0;
      while(i < size)
      {
        addr[i] = (addrIn>>(8*i))&0xFF;
        i++;
       }
    }

    //-----------------------------------------------------------
    operator DWORD()
    {
      return( (DWORD)(*((DWORD*)addr)) );
    }

  public:
    //-----------------------------------------------------------
    BYTE addr[size];

};

WORD hton( const WORD in );
DWORD hton( const DWORD in );

WORD ntoh( const WORD in );
DWORD ntoh( const DWORD in );

#pragma pack(1)
template <class T> class cNetTYPE
{
  public:
    T data;

    void operator=(T x)
    {
      data = hton( x );
    }

    operator T()
    {
      return( ntoh(data) );
    }
};
#pragma pack(8)

typedef BYTE            cNetBYTE;
typedef cNetTYPE<WORD>  cNetWORD;
typedef cNetTYPE<DWORD> cNetDWORD;

const cNetAddr<4> zeroAddr = {{0,0,0,0}};
const cNetAddr<6> zeroAddrPhy = {{0,0,0,0,0,0}};
const cNetAddr<4> broadcastAddr = {{255,255,255,255}};
const cNetAddr<6> broadcastAddrPhy = {{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF}};

WORD Checksum(BYTE *buf, WORD len, DWORD initialSum);

#endif
