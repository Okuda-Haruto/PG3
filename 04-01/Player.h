#pragma once
#include "Circle.h"

class StageScene;

class Player {
private:
	Vector2 position_{};
	Vector2 velocity_{};
	Circle circle_{};

	StageScene* stageScene_ = nullptr;
public:
	void Initialize(StageScene* stageScene);
	void Update(const char* keys, const char* preKeys);
	void Draw();

	Circle GetCircle() { return circle_; }
};