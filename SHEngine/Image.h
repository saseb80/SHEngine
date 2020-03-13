#pragma once
#include "SDL.h"
#include <iostream>

class Image
{
private:
	SDL_Texture* _image;
	std::string _name;
	int _w;
	int _h;
public:
	void LoadImagen(std::string name);
	SDL_Texture* GetTexture();
	int GetWidth();
	int GetHeight();
};