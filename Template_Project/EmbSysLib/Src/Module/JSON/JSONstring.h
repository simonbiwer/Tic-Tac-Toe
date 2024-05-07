#ifndef _JSON_STRING_H
#define _JSON_STRING_H


//*******************************************************************
/*!
\class
*/
class cJSONstring : public cJSONvalue
{
  public:

    cJSONstring( cJSONobject &obj, char *name, char *valueIn = "" )
    : cJSONvalue(obj,name)
    {
      strncpy( value, valueIn, 20 );
    }

    cJSONstring( cJSONarray &arr, char *valueIn = "" )
    : cJSONvalue(arr)
    {
      strncpy( value, valueIn, 20 );
    }

    ~cJSONstring()
    {
    }

    //---------------------------------------------------------------
    virtual void print(cJSONstream &stream)
    {
      stream.printf("\"%s\"",value);
    }

    //---------------------------------------------------------------
    virtual bool match(cJSONstream &stream)
    {
      if( stream.get() != '"' )
        return( false );

      char *str = getItem(stream, true );
      if( str )
      {
        strncpy( temp, str, 20 );
      temp[20]=0;
        return( true );
      }
      return( false );
    }

    //---------------------------------------------------------------
    void apply()
    {
      strncpy( value, temp, 20 );
      value[20]=0;
    }

    virtual void operator=(const char *str)
    {
      strncpy( value, str, 20 );
      value[20]=0;
    }

    void printf(const char *format, ... )
    {
      va_list argzeiger;

      va_start ( argzeiger, format );
      vsnprintf( value,20,format,argzeiger);
      va_end   ( argzeiger );
      value[20]=0;
    }

    char value[20+2];
    char temp[20+2];
};
#endif
