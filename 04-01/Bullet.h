#pragma once
#include "Circle.h"

class Bullet {
private:
	Vector2 position_{};
	Vector2 velocity_{};
	Circle circle_{};

	const float kMaxLiftTime = 3.0f;
	float lifeTime_;
	bool isDead_;
public:
	void Initialize(Vector2 position,Vector2 velocity);
	void Update();
	void Draw();

	Circle GetCircle() { return circle_; }
	bool IsDead() { return isDead_; }
};