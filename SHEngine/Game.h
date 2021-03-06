#pragma once
#include "GameState.h"
#include "Text.h"
#include "Bitacora.h"
#include "Cuadrado.h"
#include "StackAllocator.h"

class Game : public GameState
{
private:
	Platform* platform;
	GameStateManager* manager;
	Bitacora log;
	Cuadrado* sqre;
	StackAllocator* stackA;

public:
	Game();
	~Game();
	void Init(Platform* platform, GameStateManager* manager) override;
	void Draw() override;
	bool Input(ListaT<int>* keyDowns, ListaT<int>* keyUps, bool* leftclick, float* mouseX, float* mouseY) override;
	void Update() override;
	void Close() override;
};

