#include "StdAfx.h"
#include "luaobject.h"


luaobject::luaobject(int x,int y):m_x(x),m_y(y)
{
}


luaobject::~luaobject(void)
{
}

int luaobject::AddSum(  )
{
	return m_x + m_y;
}

luaobject* checkluaobject(lua_State* L, int index)
{
	return *((luaobject **) luaL_checkudata(L, index, "Lua_luaobject"));
// 	void* ud = 0;
// 	luaL_checktype(L, index, LUA_TUSERDATA);
// 	lua_getfield(L, index, "__index");
// 	ud = luaL_checkudata(L, index, "luaobject");;  
// 
// 	return *((luaobject**)ud);
}


// Functions that will create/destroy MyClass instances
static int newluaobject(lua_State* L)
{
	int n = lua_gettop(L); // Number of arguments
	if (n != 2)
		return luaL_error(L, "Got %d arguments, expected 2 (class, x)", n);
	// First argument is now a table that represent the class to instantiate

	// Allocate memory for a pointer to to object
	luaobject** s = (luaobject**)lua_newuserdata(L, sizeof(luaobject*));

	int x = luaL_checknumber(L, 1);
	int y = luaL_checknumber(L, 2);
	*s = new luaobject(x,y);

	luaL_getmetatable(L, "Lua_luaobject");
	lua_setmetatable(L, -2);
	

	return 1;
}

static int doSomethingluaobject(lua_State* L)
{
	luaobject* c = checkluaobject(L, 1);
	if (c)
	{
		lua_pushnumber(L,c->AddSum());
		return	1;
	}
	return 0;
}

static int ReleaseObject(lua_State* L)
{
	luaobject* c = checkluaobject(L, 1);
	if (c)
	{
		delete c;
		return	1;
	}
	return 0;
}

static const luaL_Reg luaobjectFuncs[] = {
	{ "new", newluaobject },
	{ NULL, NULL }
};

// Functions that will show up in our Lua environment
static const luaL_Reg gMyClassFuncs[] = {
	// Creation
	{ "new", newluaobject },
	{ "AddSum", doSomethingluaobject },
	{ "delete", ReleaseObject },
	{ NULL, NULL }
};

// Registers the class for use in Lua
//register Point to Lua
void registerluaobject(lua_State *L)
{
	luaL_newmetatable(L, "Lua_luaobject");
	luaL_register(L, 0, gMyClassFuncs);
	lua_pushvalue(L, -1);
	lua_setfield(L, -1, "__index");
	lua_setglobal(L, "Luaobject");
	// Register the base class for instances of Sprite
}

