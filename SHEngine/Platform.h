#pragma once
#include <string>
#include "SDL.h"
#include "Sprite.h"
#include "GameState.h"
#include "ListaT.h"
#include "Bitacora.h"
#include "StackAllocator.h"

class GameState;

class Platform{
private:
	SDL_Window* window;
	StackAllocator* SA;
public:

	Bitacora log;
	int width;
	int height;
	float lastmouseX;
	float lastmouseY;
	static SDL_Renderer* renderer;
	Platform(std::string name);
	~Platform();
	void RenderClear();
	void RenderImage(Sprite* image, int x, int y, float angle);
	void RenderPresent();

	//std::vector <SDL_Event>& GetFrameEvents();
	ListaT<SDL_Event>& GetFrameEvents();
	void CheckEvent(GameState* obj, bool (GameState::* f)(ListaT<int>* keyDowns, ListaT<int>* keyUps, bool* leftclick, float* mouseX, float* mouseY));

	void DrawRect(int x, int y, int w, int h);
private:
	void RenderTexture(Sprite* image, int x, int y, double a);

};