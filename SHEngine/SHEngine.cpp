// Gem-Strike.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "SDL.h"
#include "GameState.h"
#include "GameStateManager.h"
#include "Game.h"
#include <time.h>
#include "SimpleIni.h"

int main(int argc, char* argv[]) {

	CSimpleIniA ini;
	ini.SetUnicode();
	ini.LoadFile("C:\SHEngine\config.ini");
	const char* pVal = ini.GetValue("Resolution", "height", "default");
	const char* pVal2 = ini.GetValue("RESOLUTION", "width", "default");
	std::cout << pVal<<std::endl;
	std::cout << pVal2<<std::endl;
	//ini.SetValue("section", "key", "newvalue");

	GameStateManager* manager = new GameStateManager();
	manager->SetState(new Game());
	manager->GameLoop();
	delete manager;
	return 0;
}
