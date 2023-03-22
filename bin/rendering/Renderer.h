#pragma once

#include <SDL.h>

class Renderer {
private:
	SDL_Renderer* renderer;
public:
	Renderer(SDL_Renderer* renderer);
	~Renderer();

	SDL_Renderer* getSDLRenderer();
};