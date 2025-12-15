#pragma once
#include "Circle.h"

class Enemy {
private:
	Vector2 position_{};
	Circle circle_{};
public:
	void Initialize();
	void Update();
	void Draw();

	Circle GetCircle() { return circle_; }
};