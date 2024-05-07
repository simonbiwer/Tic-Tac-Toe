#ifndef _JSON_STREAM_H
#define _JSON_STREAM_H

#include <stdarg.h>
class cJSONstream
{
  BYTE pushBackChar;

public:
  cJSONstream()
  {
    pushBackChar = 0;
  }

public:
  void printf(const char *format, ... )
  {
    va_list argzeiger;

    va_start ( argzeiger, format );
      char str[100+2];
      vsnprintf(str,99,format,argzeiger);
      for(WORD i=0;i<99 & str[i]!=0;i++)
        setByte( str[i] );
    va_end   ( argzeiger );
  }

/*
    virtual void xprint(const char *format,va_list argzeiger)
    {
      ::printf(str);
    //  file.set (str);
    }
*/

public:
   virtual BYTE get( bool flag = false )
  {
    BYTE c=0;
    if( pushBackChar )
    {
      BYTE temp = pushBackChar;
      pushBackChar = 0;
      return( temp );
    }

    while( 1 )
    {
      if( !getByte( &c ) )
        break;
      if( flag )
      {
        if( c <= ' ' )
          c = ' ';
        break;
      }
      else
      {
        if( c > ' ' )
          break;
      }
    }
    return( c );
  }
  virtual void pushBack( BYTE c )
  {
    pushBackChar = c;
  }

private:
  //virtual void xprint(const char *format, va_list argzeiger) = 0;
  virtual BYTE getByte( BYTE *c) = 0;
  virtual BYTE setByte( BYTE  c) = 0;


};
#endif
