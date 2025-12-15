#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"
#include "GameManager.h"
#include <Novice.h>

float Length(Vector2 vector) {
	return fabsf(vector.x) + fabsf(vector.y);
}

StageScene::~StageScene(){

}

void StageScene::Initialize(GameManager* gameManager) {
	gameManager_ = gameManager;
	player_ = std::make_unique<Player>();
	player_->Initialize(this);
	enemy_ = std::make_unique<Enemy>();
	enemy_->Initialize();
}

void StageScene::Update(const char* keys, const char* preKeys) {
	player_->Update(keys, preKeys);

	enemy_->Update();

	Circle enemyCollider = enemy_->GetCircle();
	for (auto& bullet : bullets_) {
		bullet->Update();
		Circle bulletCollider = bullet->GetCircle();
		if (enemyCollider.radius + bulletCollider.radius >=
			fabsf(Length(enemyCollider.position) - Length(bulletCollider.position))) {
			gameManager_->SetNextScene(std::make_unique<ClearScene>());
		}
	}

	std::erase_if(bullets_, [](const std::unique_ptr<Bullet>& bullet) {
		return bullet->IsDead();
		});
}

void StageScene::Draw() {
	player_->Draw();
	enemy_->Draw();
	for (auto& bullet : bullets_) {
		bullet->Draw();
	}
}

void StageScene::AddBullet(Vector2 position) {
	std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>();
	bullet->Initialize(position, Vector2{ 4.5f,0.0f });
	bullets_.push_back(std::move(bullet));
}