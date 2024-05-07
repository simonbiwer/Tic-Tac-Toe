#include "Module/JSON.h"

//*******************************************************************
cJSONpair::cJSONpair(char *nameIn, cJSONvalue &valueIn )
: nam(nameIn), val( valueIn )
{

}

//*******************************************************************
void cJSONpair::print(cJSONstream &stream)
{
  nam.print(stream);
  stream.printf(":");
  val.print(stream);
}

//*******************************************************************
bool cJSONpair::match(cJSONstream &stream)
{
  if( !nam.match(stream) )
    return( false );

  if( stream.get() != ':' )
    return( false );

  if( !val.match(stream) )
    return( false );

  return( true );
}


//*******************************************************************
void cJSONpair::apply()
{
  val.apply();
}
