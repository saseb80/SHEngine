#include "Lua.h"
Lua* Lua::ptr = nullptr;
struct Sprite
{
	int x = 0, y = 0;
	void MoveObject(int x, int y) {
		this->x += x;
		this->y += y;
	}

};

inline int lua_HostFunction(lua_State* lua) {
	float a = (float)lua_tonumber(lua, 1);
	float b = (float)lua_tonumber(lua, 2);
	cout << "[C++] HostFunction(" << a << ")(" << b << ") has been called\n";
	float c = a * b;
	lua_pushnumber(lua, c);
	return 1;
}
Lua::Lua() {
	lua_state = luaL_newstate();
	luaL_openlibs(lua_state);
}

Lua::~Lua() {
	lua_close(lua_state);
}


Lua* Lua::GetPTR() {
	if (!ptr)
		ptr = new Lua();

	return ptr;
}

lua_State* Lua::GetState() {
	return lua_state;
}

void Lua::SetState(lua_State* state) {
	try {
		lua_state = state;
	}
	catch (...) {

	}
}

void Lua::Test(string fileName) {
	try {
		lua_state = luaL_newstate();
		luaL_openlibs(lua_state);
		if (CheckLua(lua_state, luaL_dofile(lua_state, fileName.c_str()))) { //Checa si este file existe dentro de lua


			auto lua_CreateObject = [](lua_State* lua) -> int {
				Sprite* sprite = (Sprite*)lua_newuserdata(lua, sizeof(Sprite*));
				return 1;
			};

			auto lua_MoveObject = [](lua_State* lua)-> int {
				int state = -3;
				Sprite* sprite = (Sprite*)lua_touserdata(lua, -4);
				sprite->x = sprite->y = 0;
				lua_pop(lua, state); state++;
				lua_Number vecX = lua_tonumber(lua, state);
				lua_pop(lua, state); state++;
				lua_Number vecY = lua_tonumber(lua, state);
				lua_pop(lua, state); state++;
				sprite->MoveObject((int)vecX, (int)vecY);
				return 0;
			};

			lua_register(lua_state, "CreateSprite", lua_CreateObject);
			lua_getglobal(lua_state, "CreateLuaSprite");
			lua_getglobal(lua_state, "sprite");

			if (lua_isfunction(lua_state, -1)) {
				if (CheckLua(lua_state, lua_pcall(lua_state, 0, 1, 0))) {
					if (lua_isuserdata(lua_state, -1)) {
						Sprite* spr = (Sprite*)lua_touserdata(lua_state, -1);
						cout << "Se obtuvo un sprite de LUA en la posicion: " << spr->x << ", " << spr->y << "\n";
					}
				}

			}
		}
		else {
			throw(fileName);
		}
		lua_close(lua_state);
	}
	catch (string str) {
		cout << "The file: " << str << " doesn't exist\n";
	}
	catch (...) {

	}

}


void Lua::TestCallFunctionFromCPP(string fileName) {
	const char* c = fileName.c_str();

	lua_register(lua_state, "HostFunction", lua_HostFunction);
	if (CheckLua(lua_state, luaL_dofile(lua_state, fileName.c_str()))) {

		lua_getglobal(lua_state, "DoAThing");
		if (lua_isfunction(lua_state, -1)) {
			lua_pushnumber(lua_state, 3.4f);
			lua_pushnumber(lua_state, 9.1f);
			if (CheckLua(lua_state, lua_pcall(lua_state, 2, 1, 0))) {
				cout << (float)lua_tonumber(lua_state, -1) << endl;
			}
		}

	}
	lua_close(lua_state);
}

void Lua::Lua_MoveObject(string fileName) {
	try {
		if (CheckLua(lua_state, luaL_dofile(lua_state, fileName.c_str()))) {
			if (lua_isfunction(lua_state, -1)) {

			}
		}
	}
	catch (...) {

	}
}

void Lua::Lua_CreatePrimitve(string fileName) {
}


bool Lua::CheckLua(lua_State* l, int r) {
	try {

		if (r != LUA_OK) {
			throw(false);
		}
		return true;
	}
	catch (bool b) {
		string errorMSG = lua_tostring(l, -1);
		cout << errorMSG << endl;
	}
	return false;
}
