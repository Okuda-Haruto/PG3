#pragma once
#include "BaseScene.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include <list>
#include <memory>

float Length(Vector2 vector);

class StageScene : public BaseScene {
private:
	std::unique_ptr<Player> player_;
	std::unique_ptr<Enemy> enemy_;
	std::list<std::unique_ptr<Bullet>> bullets_;

public:
	~StageScene() override;

	void Initialize(GameManager* gameManager) override;
	void Update(const char* keys, const char* preKeys) override;
	void Draw() override;

	void AddBullet(Vector2 position);
};