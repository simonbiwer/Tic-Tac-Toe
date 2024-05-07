#ifndef _JSON_BOOLEAN_H
#define _JSON_BOOLEAN_H



//*******************************************************************
/*!
\class
*/
class cJSONboolean : public cJSONvalue
{
  public:
   // cJSONpair *pair;

    cJSONboolean( cJSONcontainer &obj, char *name, bool *valuePtrIn  )
    : cJSONvalue(obj,name)//,
    //value( valueIn)
    {
        value = valuePtrIn;
    }

    cJSONboolean( cJSONcontainer &arr, bool *valuePtrIn  )
    : cJSONvalue(arr)//,
  //  value( valueIn )
    {
        value = valuePtrIn;
    }

    ~cJSONboolean()
    {
    }

    //---------------------------------------------------------------
    virtual void print(cJSONstream &stream)
    {
      if( value )
      {
        stream.printf((*value)?"true":"false");
      }
      else
        stream.printf("---");
    }

    //---------------------------------------------------------------
    virtual bool match(cJSONstream &stream)
    {
      char *str = getItem(stream);
      if( str )
      {
        if( strcmp(str,"false") == 0 )
          temp = false;
        else if( strcmp(str,"true") == 0 )
          temp = true;
        else
          return( false );
        return( true );
      }
      return( false );
    }

    //---------------------------------------------------------------
    void apply()
    {
      if( value )
        *value = temp;
    }

    void operator=( bool x )
    {
      if( value )
        *value = x;
    }

    operator bool()
    {
      if( value )
        return( value );
      else
        return( false );
    }

    bool *value;
    bool temp;
};

#endif
