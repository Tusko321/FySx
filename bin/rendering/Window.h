#pragma once
#include <SDL.h>
#include <Logger.h>
#include <stdio.h>

class Window {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	int width, height;
	float aspectRatio;
	std::chrono::high_resolution_clock::time_point prevTime;
	float deltaTime;

	void start();
	void update();
public:
	Window(int width, int height, const char* title);
	~Window();

	void clean();
};