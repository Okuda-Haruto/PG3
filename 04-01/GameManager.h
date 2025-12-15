#pragma once
#include "BaseScene.h"
#include <memory>

class GameManager {
private:
	std::unique_ptr<BaseScene> nowScene_ = nullptr;
	std::unique_ptr<BaseScene> nextScene_ = nullptr;

	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };

public:

	void Initialize();
	void Update();
	void Draw();

	void SetNextScene(std::unique_ptr<BaseScene> scene) { nextScene_ = std::move(scene); }
};