#pragma once
#include "InputHandle.h"
#include "Command.h"
#include "Player.h"

class Scene {
private:
	InputHandler* inputHandler_ = nullptr;
	ICommand* iCommand_ = nullptr;
	Player* player_;

public:
	void Initialize();
	void Update();
	void Draw();
};