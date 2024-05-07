#include "Module/JSON.h"
#include <typeinfo>

//cJSONvalue::cJSONvalue(cJSONarray &array)
//{
//  pair = NULL;
//  array.elements.add(this);
//
////  array.element = this;
//}
//
//cJSONvalue::cJSONvalue( cJSONobject &obj, char *name )
//    {
//      pair = new cJSONpair( name, *this );
//      obj.elements.add(pair);
//
//    }

cJSONvalue::cJSONvalue( cJSONcontainer &obj, char *name )
    {
      if( name  && typeid(obj)==typeid(cJSONobject) )
      {
        pair = new cJSONpair( name, *this );
      obj.elements.add(pair);

      }
      else if(typeid(obj)==typeid(cJSONarray))
      {
        pair = NULL;
      obj.elements.add(this);

      }



    }
