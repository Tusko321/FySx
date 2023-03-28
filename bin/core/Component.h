#pragma once

class Component {
private:
	bool isActive = true;

public:
	Component();
	virtual ~Component();

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void FixedUpdate() = 0;

	void setActive(bool state);
};