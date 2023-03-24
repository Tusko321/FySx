#pragma once

#include <Bounds.h>
#include <SDL.h>

class Camera : public Bounds {
public:
	Camera(int width, int height) : Bounds(0.0f, 0.0f, width, height) {}
	virtual ~Camera() {}

	void setDimensions(float, float);
	Vector2 getDimensions() {
		return size;
	}

	Vector2 getPosition() {
		return position;
	}

	SDL_Rect getBox() {
		return { (int)position.x, (int)position.y, (int)size.x, (int)size.y };
	}
};