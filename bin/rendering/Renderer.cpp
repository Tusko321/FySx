#include "Renderer.h"
#include <Logger.h>

Renderer::Renderer(SDL_Renderer* renderer) {
	this->renderer = NULL;

	this->renderer = renderer;

	if (this->renderer == NULL) {
		Logger::getLogger()->log(INFO, std::format("Failed to create renderer. SDL_ERROR: %s\n", SDL_GetError()).c_str());
	}
}

Renderer::~Renderer() {
	SDL_DestroyRenderer(renderer);
}

SDL_Renderer* Renderer::getSDLRenderer() {
	return renderer;
}