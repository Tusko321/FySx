#include "Renderer.h"
#include <Logger.h>

Renderer::Renderer(SDL_Renderer* renderer) {
	this->renderer = renderer;

	if (this->renderer == NULL) {
		Logger::getLogger()->log(INFO, std::format("Failed to create renderer. SDL_ERROR: %s\n", SDL_GetError()).c_str());
	}
}

Renderer::~Renderer() {
	SDL_DestroyRenderer(renderer);
}

void Renderer::render() {

}

void Renderer::clear() {
	//Fill the renderer empty
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
}

void Renderer::present() {
	//Update renderer
	SDL_RenderPresent(renderer);
}

SDL_Renderer* Renderer::getSDLRenderer() {
	return renderer;
}