// Gem-Strike.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "SDL.h"
#include "GameState.h"
#include "GameStateManager.h"
#include "Game.h"
#include <time.h>
#include "SimpleIni.h"
#include "Bitacora.h"
#include "StackAllocator.h"

int main(int argc, char* argv[]) {
	
	Bitacora l;
	l.ImprimirConsola("SHENGINE");
	GameStateManager* manager = new GameStateManager();
	manager->SetState(new Game());
	manager->GameLoop();
	delete manager;
	return 0;
}
