#ifndef _JSON_NAME_H
#define _JSON_NAME_H

//*******************************************************************
/*!
\class
*/
class cJSONname
{
  public:
    //---------------------------------------------------------------
    cJSONname(const char *nameIn)
    {
      strncpy(name, nameIn, 20);
    }

    //---------------------------------------------------------------
    void print(cJSONstream &stream)
    {
      stream.printf("\"%s\"",name);
    }

    //---------------------------------------------------------------
    bool match(cJSONstream &stream)
    {
      if( stream.get() != '"' )
        return( false );

      for( int i=0;i< strlen(name);i++)
        if( stream.get() != name[i] )
          return( false );

      if( stream.get() != '"' )
        return( false );

      return( true );
    }

    //---------------------------------------------------------------
    char name[20+1];
};

#endif
