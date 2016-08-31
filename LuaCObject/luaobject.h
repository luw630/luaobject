#ifndef _LUAOBJECT_H_
#define _LUAOBJECT_H_
extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

class luaobject
{
public:
	luaobject(int x,int y);
	~luaobject(void);
	int AddSum();
	int GetX(){return m_x;};
	int GetY(){return m_y;};

private:
	int m_x;
	int m_y;
};

#endif