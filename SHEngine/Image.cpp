#include "Image.h"
#include "SDL_image.h"
#include "Platform.h"

void Image::LoadImagen(std::string name) {
	_name = name;
	SDL_Surface* loadedSurface = IMG_Load(name.c_str());
	_w = loadedSurface->w;
	_h = loadedSurface->h;
	_image = SDL_CreateTextureFromSurface(Platform::renderer, loadedSurface);
}

SDL_Texture* Image::GetTexture() {
	return _image;
}
int Image::GetWidth() {
	return _w;
}

int Image::GetHeight() {
	return _h;
}