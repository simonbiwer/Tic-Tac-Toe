//*******************************************************************
/*!
\file   NetStd.cpp
\author Thomas Breuer
\date   11.03.2011
*/

//*******************************************************************
//==========================================
#if defined _MCU_TYPE_ATMEGA
//==========================================
WORD hton( const WORD in )
{
  return(  (((in>>8)&0xFF)   )
         | (((in   )&0xFF)<<8) );
}

DWORD hton( const DWORD in )
{
  return( (((in>>24)&0xFF)    )
         |(((in>>16)&0xFF)<< 8)
         |(((in>> 8)&0xFF)<<16)
         |(((in    )&0xFF)<<24) );
}

WORD ntoh( const WORD in )
{
  return( hton(in) );
}

DWORD ntoh( const DWORD in )
{
  return( hton(in) );
}

//==========================================
#elif defined _MCU_TYPE_LPC11UXX
//==========================================
WORD hton( const WORD in )
{
  return(  (((in>>8)&0xFF)   )
         | (((in   )&0xFF)<<8) );
}

DWORD hton( const DWORD in )
{
  return( (((in>>24)&0xFF)    )
         |(((in>>16)&0xFF)<< 8)
         |(((in>> 8)&0xFF)<<16)
         |(((in    )&0xFF)<<24) );
}

WORD ntoh( const WORD in )
{
  return( hton(in) );
}

DWORD ntoh( const DWORD in )
{
  return( hton(in) );
}

//==========================================
#elif defined _MCU_TYPE_LPC17XX
//==========================================
WORD hton( const WORD in )
{
  return(  (((in>>8)&0xFF)   )
         | (((in   )&0xFF)<<8) );
}

DWORD hton( const DWORD in )
{
  return( (((in>>24)&0xFF)    )
         |(((in>>16)&0xFF)<< 8)
         |(((in>> 8)&0xFF)<<16)
         |(((in    )&0xFF)<<24) );
}

WORD ntoh( const WORD in )
{
  return( hton(in) );
}

DWORD ntoh( const DWORD in )
{
  return( hton(in) );
}

//==========================================
#elif defined _MCU_TYPE_STM32L1XX
//==========================================
WORD hton( const WORD in )
{
  return(  (((in>>8)&0xFF)   )
         | (((in   )&0xFF)<<8) );
}

DWORD hton( const DWORD in )
{
  return( (((in>>24)&0xFF)    )
         |(((in>>16)&0xFF)<< 8)
         |(((in>> 8)&0xFF)<<16)
         |(((in    )&0xFF)<<24) );
}

WORD ntoh( const WORD in )
{
  return( hton(in) );
}

DWORD ntoh( const DWORD in )
{
  return( hton(in) );
}

//==========================================
#elif defined _MCU_TYPE_STM32F4XX
//==========================================
WORD hton( const WORD in )
{
  return(  (((in>>8)&0xFF)   )
         | (((in   )&0xFF)<<8) );
}

DWORD hton( const DWORD in )
{
  return( (((in>>24)&0xFF)    )
         |(((in>>16)&0xFF)<< 8)
         |(((in>> 8)&0xFF)<<16)
         |(((in    )&0xFF)<<24) );
}

WORD ntoh( const WORD in )
{
  return( hton(in) );
}

DWORD ntoh( const DWORD in )
{
  return( hton(in) );
}

//==========================================
#elif defined _MCU_TYPE_STM32L4XX
//==========================================
WORD hton( const WORD in )
{
  return(  (((in>>8)&0xFF)   )
         | (((in   )&0xFF)<<8) );
}

DWORD hton( const DWORD in )
{
  return( (((in>>24)&0xFF)    )
         |(((in>>16)&0xFF)<< 8)
         |(((in>> 8)&0xFF)<<16)
         |(((in    )&0xFF)<<24) );
}

WORD ntoh( const WORD in )
{
  return( hton(in) );
}

DWORD ntoh( const DWORD in )
{
  return( hton(in) );
}

//==========================================
#elif defined _MCU_TYPE_VIRTUAL
//==========================================
WORD hton( const WORD in )
{
  return( htons( in )  );
}

DWORD hton( const DWORD in )
{
  return( htonl( in ) );
}

WORD ntoh( const WORD in )
{
  return( ntohs(in) );
}

DWORD ntoh( const DWORD in )
{
  return( ntohl(in) );
}

//==========================================
#else
//  #error "config.h: device type not defined"
#endif
//==========================================


//==========================================
//*****************************************************************************
// The Ip checksum is calculated over the ip header only starting
// with the header length field and a total length of 20 bytes
// unitl ip.dst
// You must set the IP checksum field to zero before you start
// the calculation.
// len for ip is 20.
//
// For UDP/TCP we do not make up the required pseudo header. Instead we
// use the ip.src and ip.dst fields of the real packet:
// The udp checksum calculation starts with the ip.src field
// Ip.src=4bytes,Ip.dst=4 bytes,Udp header=8bytes + data length=16+len
// In other words the len here is 8 + length over which you actually
// want to calculate the checksum.
// You must set the checksum field to zero before you start
// the calculation.
// len for udp is: 8 + 8 + data length
// len for tcp is: 4+4 + 20 + option len + data length
//
// For more information on how this algorithm works see:
// http://www.netfor2.com/checksum.html
// http://www.msc.uky.edu/ken/cs471/notes/chap3.htm
// The RFC has also a C code example: http://www.faqs.org/rfcs/rfc1071.html
WORD Checksum( BYTE *buf, WORD len, DWORD initialSum = 0)//,uint8_t type)
{
   // type 0=ip
   //      1=udp
   //      2=tcp
   DWORD sum = initialSum;

   // build the sum of 16bit words
   while(len > 1)
   {
      sum += 0xFFFF & (((WORD)(*buf) << 8) | *(buf+1));
      buf += 2;
      len -= 2;
   }
   // if there is a byte left then add it (padded with zero)
   if (len > 0)
   {
      sum += ((WORD)(0xFF & *buf) << 8);
   }
   // now calculate the sum over the bytes in the sum
   // until the result is only 16bit long
   while (sum >> 16)
   {
      sum = (sum & 0xFFFF) + (sum >> 16);
   }
   // build 1's complement:
   return ((WORD)sum ^ 0xFFFF);
}


// EOF
