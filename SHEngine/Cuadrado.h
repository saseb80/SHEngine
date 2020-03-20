#pragma once
#include "GameObject.h"
#include "SDL.h"
#include "Platform.h"

class Cuadrado : public GameObject
{
public: 
	int width;
	int height;
	SDL_Rect rect;
	SDL_Surface* surface;
	Vector2 position;
	SDL_Renderer* renderer;

	Cuadrado();
	Cuadrado(int x, int y, int width, int height);
	void Update();
	void Draw();
	~Cuadrado();
};

