#ifndef _JSON_OBJECT_H
#define _JSON_OBJECT_H


//*******************************************************************
/*!
\class
*/
class cJSONobject : public cJSONcontainer
{
  public:
    //---------------------------------------------------------------
   // cList pairs;
//    char *rootName;

    //---------------------------------------------------------------
    cJSONobject(cList *objects)
    {
      if( objects )
        objects->add(this);
  //    rootName = name;
    }

    cJSONobject(cJSONcontainer **con, char *name = NULL)
    : cJSONcontainer(con,name)
    {
    //  rootName = NULL;
    }

    //---------------------------------------------------------------
   // cJSONobject(cJSONarray &arr);

    //---------------------------------------------------------------
    void print(cJSONstream &stream)
    {
      stream.printf("{");

      cJSONpair *ptr = (cJSONpair*)elements.getFirst();
      while( ptr )
      {
        ptr->print(stream);
        ptr = (cJSONpair*)ptr->getNext();
        if( ptr )
          stream.printf(",");
      }

      stream.printf("}");
    }

    //---------------------------------------------------------------
    bool match(cJSONstream &stream)
    {
      BYTE c = 0;

      if( stream.get() != '{' )
      {
        printf("match error: '{' expected\n");
        return( false );
      }

      cJSONpair *ptr = (cJSONpair*)elements.getFirst();
      while( ptr )
      {
        if( !ptr->match(stream) )
          return( false );
        ptr = (cJSONpair*)ptr->getNext();
        if( ptr && stream.get() != ',')
          {
            printf("match error: ',' expected\n");
            return( false );
          }
      }
      if( stream.get() != '}' )
          {
            printf("match error: '}' expected\n");
            return( false );
          }

      return( true );
    }

    //---------------------------------------------------------------
    void apply()
    {
      cJSONpair *ptr = (cJSONpair*)elements.getFirst();
      while( ptr )
      {
        ptr->apply();
        ptr = (cJSONpair*)ptr->getNext();
      }
    }

};
#endif
