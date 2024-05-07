#include <stdio.h>
#include <string.h>

//*******************************************************************
/*
  usage:
    int main(int argc, char *argv[])
    {
     Option fileName (argc,argv,"F", "");
     Option x        (argc,argv,"x", "0.0");
     ...

  command line:
    example.exe -F filename -x 3.1415
*/
class Option
{
  public:
    //---------------------------------------------------------------
    char value[256];
    char *name;
    bool  isSetFlag;

    //---------------------------------------------------------------
    Option(int argc, char **argv, char *nameIn, char *defaultIn = NULL)
    {
        scan(argc, argv, nameIn, defaultIn);
    }

    //---------------------------------------------------------------
    Option()
    {
      strcpy(value,"");
      name  = "";
      isSetFlag = false;
    }

    void scan(int argc, char **argv, char *nameIn, char *defaultIn )
    {
      if(defaultIn)
        strncpy(value,defaultIn,255);
      else
        strncpy(value,"",255);
      name  = nameIn;
      isSetFlag = false;
      for(int i=1;i<argc;i++)
      {
         if(argv[i][0]=='-' && strcmp(&argv[i][1],name)==0)
         {
            isSetFlag = true;
            if( defaultIn )
              strncpy(value,argv[i+1],255);
            break;
         }
     }

//     if( isSetFlag == false )
//     {
//       if( argc >= 2 && strlen(name)==0)
//       {
//         isSetFlag = true;
//         strncpy(value,argv[argc],255);
//       }
//     }
     print();
    }

#if wxUSE_GUI
    void scan(int argc, wxChar **argv, char *nameIn, char *defaultIn)
    {

//
//        if( argc >=2 && argv[1])
//                {
//                    wxString a;
//                    a = argv[1];
//                  strcpy(portName, a.mb_str());
//                }


      strncpy(value,defaultIn,255);
      name  = nameIn;
      isSetFlag = false;
      for(int i=1;i<argc;i++)
      {
         wxString a;
         a = argv[i];
         char astr[256];

         strncpy(astr,a.mb_str(),255);
         if(astr[0]=='-' && strcmp(&astr[1],name)==0)
         {
         a = argv[i+1];
         strncpy(astr,a.mb_str(),255);

            isSetFlag = true;
            strncpy(value,astr,255);

            break;
         }
     }
     print();

    }
#endif // 0

    void print()
    {
        if( strlen(value) >0 )
              printf("-%s = %s", name, value);
            else
              printf("-%s", name);

            if( !isSetFlag )
                printf(" (default)");
            printf("\n");

            fflush(stdout);
    }

    //---------------------------------------------------------------
    bool isSet()
    {
      return( isSetFlag );
    }

    //---------------------------------------------------------------
    operator float()
    {
      float x = 0;
      sscanf(value,"%f",&x);
      return(x);
    }

    //---------------------------------------------------------------
    operator int()
    {
      int x = 0;
      sscanf(value,"%d",&x);
      return(x);
    }

    operator unsigned()
    {
      unsigned x = 0;
      if( value[0]=='0' && (value[1] =='x' || value[1]=='X') )
        sscanf(value,"%x",&x);
      else
        sscanf(value,"%u",&x);
      return(x);
    }

    //---------------------------------------------------------------
    operator char*()
    {
      return(value);
    }
};



