#include "Enemy.h"
#include "Novice.h"

void Enemy::Initialize() {
	position_ = {1000,360};
	circle_.radius = 32.0f;
	circle_.position = position_;
}

void Enemy::Update() {

}

void Enemy::Draw() {
	Novice::DrawEllipse(int(circle_.position.x), int(circle_.position.y), int(circle_.radius), int(circle_.radius), 0.0f, 0xFF0000FF, kFillModeSolid);
}