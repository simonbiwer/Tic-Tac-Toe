#ifndef _JSON_ARRAY_H
#define _JSON_ARRAY_H


//*******************************************************************
/*!
\class
*/
//template <BYTE anz>
class cJSONarray : public cJSONcontainer //value
{
  public:
    //---------------------------------------------------------------
//    WORD anz;
//    DWORD offset;


    cJSONarray( cJSONcontainer **con, char *name = NULL)
    :cJSONcontainer( con,name)
    {
    }

//    cJSONarray( cJSONarray &arr)
//    :cJSONvalue( arr )
//    {
//    }

    //---------------------------------------------------------------
    virtual void print(cJSONstream &stream)
    {
      stream.printf("[");

      cJSONvalue *ptr = (cJSONvalue*)elements.getFirst();
      while( ptr )
      {
        ptr->print(stream);
        ptr = (cJSONvalue*)ptr->getNext();
        if( ptr )
          stream.printf(",");
      }
      stream.printf("]");
    }

    //---------------------------------------------------------------
    bool match(cJSONstream &stream)
    {
      BYTE c = 0;

      if( stream.get() != '[' )
        return( false );

      cJSONvalue *ptr = (cJSONvalue*)elements.getFirst();
      while( ptr )
      {
        if( !ptr->match(stream) )
          return( false );
        ptr = (cJSONvalue*)ptr->getNext();
        if( ptr && stream.get() != ',')
          return( false );
      }
      if( stream.get() != ']' )
        return( false );

      return( true );
    }

    //---------------------------------------------------------------
    void apply()
    {
      cJSONvalue *ptr = (cJSONvalue*)elements.getFirst();
      while( ptr )
      {
        ptr->apply();
        ptr = (cJSONvalue*)ptr->getNext();
      }
    }
};




#endif
