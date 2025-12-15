#pragma once
#include "BaseScene.h"

class ClearScene : public BaseScene {
private:

public:
	~ClearScene() override;

	void Initialize(GameManager* gameManager) override;
	void Update(const char* keys, const char* preKeys) override;
	void Draw() override;
};