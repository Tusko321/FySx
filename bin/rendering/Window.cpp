#include "Window.h"

Window::Window(int width, int height, const char* title) {
	window = NULL;
	renderer = NULL;

	this->width = width;
	this->height = height;
	aspectRatio = (float)width / (float)height;
	deltaTime = 0.0f;
	prevTime = std::chrono::high_resolution_clock::now();

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		Logger::getLogger()->log(ERROR, std::format("SDL failed to initialize. SDL_ERROR: %s\n", SDL_GetError()).c_str());
	}
	else {
		//Create window
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

		if (window == NULL) {
			Logger::getLogger()->log(ERROR, std::format("Failed to create a window. SDL_ERROR: %s\n", SDL_GetError()).c_str());
		}
		else {
			//Get window renderer
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			
			if (renderer == NULL) {
				Logger::getLogger()->log(ERROR, std::format("Could not create renderer! SDL Error: {}\n", SDL_GetError()).c_str());
			}
			else {
				//Fill the renderer empty
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
				SDL_RenderClear(renderer);

				//Run start
				start();

				//Update renderer
				SDL_RenderPresent(renderer);

				//Enter update loop
				update();
			}
		}
	}
}

void Window::start() {

}

void Window::update() {
	SDL_Event e;
	std::chrono::high_resolution_clock::time_point timeNow;
	bool quit = false;
	while (quit == false) {
		timeNow = std::chrono::high_resolution_clock::now();
		deltaTime = (timeNow - prevTime).count() / static_cast<float>(1e+9);
		prevTime = timeNow;

		float fps = (1.0f / deltaTime) * static_cast<float>(1000);
		char s[64];
		sprintf_s(s, "%.16f", fps);
		Logger::getLogger()->log(INFO, s);

		//input
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_WINDOWEVENT) {
				if (e.window.event == SDL_WINDOWEVENT_RESIZED) {
					width = e.window.data1;
					height = e.window.data2;
					aspectRatio = (float)width / (float)height;
				}
			}

			if (e.type == SDL_QUIT)
				quit = true;
		}

		//Fill the renderer empty
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

		//update
		//draw

		//Update renderer
		SDL_RenderPresent(renderer);
	}
}

Window::~Window() {
	clean();
}

void Window::clean() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}