#pragma once
#include "BaseScene.h"

class TitleScene : public BaseScene {
private:

public:
	~TitleScene() override;

	void Initialize(GameManager* gameManager) override;
	void Update(const char* keys, const char* preKeys) override;
	void Draw() override;
};