#include "Cuadrado.h"

Cuadrado::Cuadrado() {

}

Cuadrado::Cuadrado(int x, int y, int width, int height) {
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderDrawRect(renderer, &rect);
}


Cuadrado::~Cuadrado() {

}

void Cuadrado::Draw() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderDrawRect(renderer, &rect);
}

void Cuadrado::Update() {
}