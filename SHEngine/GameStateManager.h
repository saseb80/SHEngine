#pragma once
#include "GameState.h"
#include "Platform.h"
#include "StackT.h"
#include "BItacora.h"

class GameState;

class GameStateManager
{
private:
	StackT<GameState*> states;
	Platform* platform;
	Bitacora log;
public:
	GameStateManager();
	~GameStateManager();
	void GameLoop();
	void SetState(GameState* state);
	void RealaseState();
};