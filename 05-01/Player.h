#pragma once
#include "Vector2.h"

class Player {
private:
	const float speed = 4.0f;
	Vector2 pos = {};
public:
	void Initialize();
	void Update();
	void Draw();

	void MoveRight();
	void MoveLeft();
};