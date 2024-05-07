#ifndef _JASON_BASE_H
#define _JASON_BASE_H

class cJSONbase
{
protected:
  cList list;

  cJSONbase()
  {
    top = actual = new cJSONobject(&list);

  }

  cJSONcontainer *top;
  cJSONcontainer  *actual;

  void END()
  {
      actual = actual->parent;
  }

  void OBJ(char *name)
  {
     new cJSONobject( &actual, name );
  }

  void ARRAY(char *name)
  {
     new cJSONarray( &actual, name );
  }

  void BOOL(char *name, bool *ptr)
  {
     new cJSONboolean( *actual, name, ptr );
  }
  void BOOL(bool *ptr)
  {
     new cJSONboolean( *actual, ptr );
  }

  template <class T> void NUM(char *name,T *ptr)
  {
      new cJSONnumber<T,0>( *actual, name, ptr );
  }
  template <class T> void NUM(T *ptr)
  {
      new cJSONnumber<T,0>( *actual, ptr );
  }

public:
  void print(cJSONstream &stream)
  {
     top->print(stream);
  }
  bool match(cJSONstream &stream)
  {
     if( top->match(stream) )
     {
         top->apply();
         return( true );
     }
     return( false);
  }
};

#endif // _JASON_BASE_H
