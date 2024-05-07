#ifndef _JSON_VALUE_H
#define _JSON_VALUE_H


class cJSONobject;

class cJSONarray;




class cJSONcontainer;

//*******************************************************************
/*!
\class
*/
class cJSONvalue : public cList::Item
{
  public:

    cJSONvalue()
    {
      pair = NULL;
    }

//    cJSONvalue( cJSONobject &obj, char *name );
//
//    cJSONvalue( cJSONarray &array );

    cJSONvalue( cJSONcontainer &container, char *name = NULL);

    ~cJSONvalue(  )
    {
      if( pair )
        delete pair;
    }

    cJSONpair *pair;


    //---------------------------------------------------------------
    virtual void print(cJSONstream &stream) = 0;
    virtual bool match(cJSONstream &stream) { return(true); }
    virtual void apply() = 0;

    //---------------------------------------------------------------
    virtual char *getItem(cJSONstream &stream, bool flag = false)
    {
      static char str[20+1];
      BYTE pos,c;
      while(1)
      {
        c = stream.get(flag);
        if(c == '"' )
          continue;

        if( c == ',' || c == '}' || c == ']' || c == 0 )
        {
          stream.pushBack( c );
          break;
        }
        str[pos++]= c;
      }
      str[pos] = 0;

      if( pos<20 )
      {
        return( str );
      }
      return( NULL );
    }
};

//*******************************************************************
/*!
\class
*/
class cJSONcontainer : public cJSONvalue
{
    public:
    cJSONcontainer(  )
    {
        parent = NULL;
    }

    cJSONcontainer( cJSONcontainer **container, char *name = NULL )
    : cJSONvalue( **container, name)
    {
        parent = *container;
        *container = this;
       //container.elements.add( this );
    }

    virtual void print(cJSONstream &stream) = 0;

     cList elements;
     cJSONcontainer *parent;

};

#endif
