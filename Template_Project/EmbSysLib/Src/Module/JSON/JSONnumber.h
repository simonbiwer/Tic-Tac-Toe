#ifndef _JSON_NUMBER_H
#define _JSON_NUMBER_H



//*******************************************************************
/*!
\class
*/
template <typename T,BYTE p> class cJSONnumber : public cJSONvalue
{
  public:
    T *value;
    float temp;

    //---------------------------------------------------------------
    cJSONnumber(cJSONcontainer &arr, T *valuePtrIn )
    : cJSONvalue( arr )//,
     // value( valueIn )
    {
        value = valuePtrIn;
    }

    cJSONnumber( cJSONcontainer &obj, char *name, T *valuePtrIn )
    : cJSONvalue( obj, name )//,
      //value( valueIn )
    {
        value = valuePtrIn;
    }

    ~cJSONnumber()
    {
    }

    //---------------------------------------------------------------
    virtual void print(cJSONstream &stream)
    {
      if( value )
      {
            char fmt[10];
            sprintf(fmt,"%%.%uf",p);
            stream.printf(fmt,(float)(*value));
      }
      else
      {
             stream.printf("---");
      }
    }

    //---------------------------------------------------------------
    virtual bool match(cJSONstream &stream)
    {
      char *str = getItem(stream);
      if( str )
      {
        if( sscanf(str,"%f",&temp) != 1 )
          return( false );
        return( true );
      }
      return( 0 );
    }

    //---------------------------------------------------------------
    void apply()
    {
      if( value )
        *value = (T)temp;
    }

    virtual void operator=(const T x)
    {
      if( value )
        *value = x;
    }
};
#endif
