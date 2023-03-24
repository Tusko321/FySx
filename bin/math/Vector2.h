#pragma once

#include <cmath>

struct Vector2 {
	float x, y;

	Vector2() {
		x = 0.0f;
		y = 0.0f;
	}

	Vector2(float x, float y) {
		this->x = x;
		this->y = y;
	}

	Vector2(Vector2 &vector) {
		this->x = vector.x;
		this->y = vector.y;
	}

	const inline float magnitude() {
		return (x * x) + (y * y);
	}

	const inline float sqrMagnitude() {
		return sqrtf((x * x) + (y * y));
	}
};