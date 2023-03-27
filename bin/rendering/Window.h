#pragma once
#include <SDL.h>
#include <Logger.h>
#include <stdio.h>
#include "Renderer.h"

class Window {
private:
	SDL_Window* window;
	Renderer* renderer;

	int width, height;
	float aspectRatio;
	Uint64 prevTime;
	float deltaTime;

	void start();
	void update();
public:
	Window(int width, int height, const char* title);
	~Window();

	void clean();
};