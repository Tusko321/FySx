#pragma once

class Object {
private:
	char* name;
public:
	virtual void start();
	virtual void update(float deltaTime);
	virtual void fixedUpdate(float deltaTimeFixed);
};