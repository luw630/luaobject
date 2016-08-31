// LuaCObject.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "luaobject.h"
extern void registerluaobject(lua_State *L);
extern luaobject* checkluaobject(lua_State* L, int index);
int _tmain(int argc, _TCHAR* argv[])
{
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	registerluaobject(L);
	
	if (luaL_dofile(L, "testobjcet.lua"))
	{
		printf("%s ", lua_tostring(L, -1));
		return 0;
	}
	//luaobject *lobject = checkluaobject(L,1);
	//printf("%d,     %d ",lobject->GetX(),lobject->GetY());
	//std::cout << "x: " << foo->x << " y: " << foo->y;
	lua_close(L);
	return 0;
}

