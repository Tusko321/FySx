#pragma once

#include <SDL.h>

class Renderer {
private:
	SDL_Renderer* renderer;
public:
	Renderer(SDL_Renderer* renderer);
	~Renderer();

	void render();
	void clear();
	void present();

	SDL_Renderer* getSDLRenderer() const;
};