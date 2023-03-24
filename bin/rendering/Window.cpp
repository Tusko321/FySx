#include "Window.h"

Window::Window(int width, int height, const char* title) {
	window = NULL;

	this->width = width;
	this->height = height;
	aspectRatio = (float)width / (float)height;
	deltaTime = 0.0f;
	prevTime = 0;

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
			renderer = new Renderer(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED));
			
			if (renderer == NULL) {
				Logger::getLogger()->log(ERROR, std::format("Could not create renderer! SDL Error: {}\n", SDL_GetError()).c_str());
			}
			else {
				//Fill the renderer empty
				renderer->clear();

				//Run start
				start();

				//Update renderer
				renderer->present();

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
	bool quit = false;
	while (quit == false) {
		if (prevTime == 0) {
			prevTime = SDL_GetTicks64();
			continue;
		}
		Uint64 currentTime = SDL_GetTicks64();
		float deltaTime = (currentTime - prevTime) / 1000.0f;
		char c[32];
		sprintf_s(c, "%.16f", deltaTime);

		Logger::getLogger()->log(INFO, c);

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

		renderer->clear();

		//update
		//draw

		renderer->present();

		prevTime = currentTime;
	}
}

Window::~Window() {
	
}

void Window::clean() {
	delete renderer;
	SDL_DestroyWindow(window);
	SDL_Quit();
}