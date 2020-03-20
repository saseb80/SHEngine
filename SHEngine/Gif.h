#pragma once
#include "ListaT.h"
#include "Sprite.h"

class Gif : public GameObject
{
public:
	Gif();
	Gif(bool loop);
	~Gif();
	void update();
	void SetVelocity(int vel);
	Sprite currentFrame;
	void AddImage(std::string i);
private:
	Sprite* image;
	ListaT<Sprite> ImageList;
	int index = 0;
	Uint32 _lastFrameTime = SDL_GetTicks() + _vel;;
	int _vel;
	bool _finish = false;
	bool _loop = false;
};