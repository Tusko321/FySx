#pragma once

#include <cmath>

struct Vector2Int {
	int x;
	int y;

	Vector2Int() {
		x = 0;
		y = 0;
	}

	Vector2Int(int x, int y) {
		this->x = x;
		this->y = y;
	}

	Vector2Int(Vector2Int& copy) {
		x = copy.x;
		y = copy.y;
	}

	const inline float magnitude() {
		return (x * x) + (y * y);
	}

	const inline float sqrMagnitude() {
		return sqrtf((x * x) + (y * y));
	}
};