#ifndef _JSON_PAIR_H
#define _JSON_PAIR_H

class cJSONvalue;
//*******************************************************************
/*!
\class
*/
class cJSONpair : public cList::Item
{
  public:
    //---------------------------------------------------------------
    cJSONpair(char *nameIn, cJSONvalue &valueIn);
    void print(cJSONstream &stream);
    bool match(cJSONstream &stream);
    void apply();

    cJSONname nam;
    cJSONvalue &val;
};

#endif
