#pragma once

#include "Component.h"

class Object {
private:
	char* name;
	Component** components;
public:
	Object();
	virtual ~Object();

	bool hasComponent(Component*);
	bool addComponent(Component*);
	bool removeComponent(Component*);

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void FixedUpdate() = 0;
};