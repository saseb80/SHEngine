#include "Sprite.h"
#include "SDL_image.h"
#include "Platform.h"

void Sprite::LoadImagen(std::string name) {
	_name = name;
	SDL_Surface* loadedSurface = IMG_Load(name.c_str());
	_w = loadedSurface->w;
	_h = loadedSurface->h;
	_image = SDL_CreateTextureFromSurface(Platform::renderer, loadedSurface);
}

SDL_Texture* Sprite::GetTexture() {
	return _image;
}
int Sprite::GetWidth() {
	return _w;
}

int Sprite::GetHeight() {
	return _h;
}