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

	Bounds(Bounds& copy) {
		position = copy.position;
		size = copy.size;
	}
};