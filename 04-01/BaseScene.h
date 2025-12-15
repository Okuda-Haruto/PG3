#pragma once

class GameManager;

class BaseScene {
protected:
	GameManager* gameManager_ = nullptr;
public:
	virtual ~BaseScene() {};

	virtual void Initialize(GameManager* gameManager) = 0;
	virtual void Update(const char* keys,const char* preKeys) = 0;
	virtual void Draw() = 0;
};