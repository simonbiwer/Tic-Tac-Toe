// lua.hpp
// Lua header files for C++
// <<extern "C">> not supplied automatically because Lua also compiles as C++

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

int pmain (lua_State *L) ;

class cLua
{
  public:
    cLua( void *p)
    {
      L = luaL_newstate( );  /* create state */
      luaL_setParent(L,p);
    }
    ~cLua()
    {
      lua_close(L);
    }

    struct lua_State *L;

    void l_message (const char *pname, const char *msg)
    {
      if (pname)
        lua_writestringerror("%s: ", pname);
      lua_writestringerror("%s\n", msg);
    }

    int report (lua_State *L, int status)
    {
      if (status != LUA_OK)
      {
        const char *msg = lua_tostring(L, -1);
        l_message("cLua", msg);
        lua_pop(L, 1);  /* remove message */
      }
      return status;
    }

    int run(char* file)
    {
      int status, result;
      char *lua_argv[] ={"lua","",NULL};
      lua_argv[1] = file;
      if (L == NULL)
      {
        l_message("cLua", "cannot create state: not enough memory");
        return EXIT_FAILURE;
      }
      lua_pushcfunction(L, &pmain);  /* to call 'pmain' in protected mode */
      lua_pushinteger(L, /*argc*/2);  /* 1st argument */
      lua_pushlightuserdata(L, lua_argv); /* 2nd argument */
      status = lua_pcall(L, 2, 1, 0);  /* do the call */
      result = lua_toboolean(L, -1);  /* get result */
      report(L, status);
      return (result && status == LUA_OK) ? EXIT_SUCCESS : EXIT_FAILURE;
    }

    float call(char *cmd)
    {
      if (luaL_loadstring(L, cmd) || lua_pcall(L,0,1,0) )
      {
        printf("ERROR %s %s\n",cmd,lua_tostring(L,-1));
      }
      int isnum;
      float r = lua_tonumberx(L,-1, &isnum );
       lua_pop(L,1);
      return(r);
    }

    int registerFunction(char *name, int (*ptr)(lua_State *L) )
    {
      lua_pushcfunction(L, ptr );
      lua_setglobal(L, name);
    }
};
