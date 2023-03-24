#pragma once

#include <Vector2.h>

struct Bounds {
	Vector2 position;
	Vector2 size;

	Bounds(){
		position = Vector2();
		size = Vector2();
	}

	Bounds(Vector2 position, Vector2 size) {
		this->position = position;
		this->size = size;
	}

	Bounds(float x, float y, float w, float h) {
		this->position = Vector2(x, y);
		this->size = Vector2(w, h);
	}

	Bounds(Bounds& copy) {
		position = copy.position;
		size = copy.size;
	}
};