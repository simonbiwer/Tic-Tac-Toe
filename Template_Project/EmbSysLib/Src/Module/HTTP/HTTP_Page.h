//*******************************************************************
/*!
\file   HTTP_Page.h
\author Thomas Breuer
\date   15.01.2013
*/

//*******************************************************************
#ifndef _HTTP_HTTP_PAGE_H
#define _HTTP_HTTP_PAGE_H

class cHTTP;

class cHTTP_Page : public cList::Item
{
  public:
    //---------------------------------------------------------------
    cHTTP_Page( cHTTP      &http,
                cHwMemory  &content
              );


    const char *name;
    cHwMemory  &content;

  public:
    void clear();

    void  createPage( cNetTransport::Socket &socket, char *name, char *type  );

    virtual void fillSocketJSON(cNetTransport::Socket &socket, char *name ) = 0;

    //void execute(char *cmd );

    void  setValue( char *str );
     char *parseCommand( char *str );

    BYTE isNew( void )
    {
      if( isNewFlag )
      {
        isNewFlag = false;
        return( true );
      }
      return( false );
    }

  private:
    public:
    virtual void update( void )
    {
    }

    cList paraList;

    char var[20];
    char val[20];

    char command[20];

    BYTE isNewFlag;


}; //cHTTP_Page



#endif
