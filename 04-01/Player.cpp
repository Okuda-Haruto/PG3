#include "Player.h"
#include "Novice.h"
#include "StageScene.h"

Vector2 Normalize(Vector2 vector) {
	Vector2 a{};
	float length{};
	length = Length(vector);

	if (length == 0) {
		return a;
	}

	if (vector.x != 0.0f) {
		a.x = vector.x / length;
	}
	if (vector.y != 0.0f) {
		a.y = vector.y / length;
	}

	return a;
}

void Player::Initialize(StageScene* stageScene) {
	position_ = {200,360};
	velocity_ = {};
	circle_.position = position_;
	circle_.radius = 32.0f;

	stageScene_ = stageScene;
}

void Player::Update(const char* keys, const char* preKeys) {
	velocity_ = {};
	if (keys[DIK_W]) {
		velocity_.y -= 1.0f;
	}
	if (keys[DIK_S]) {
		velocity_.y += 1.0f;
	}
	if (keys[DIK_D]) {
		velocity_.x += 1.0f;
	}
	if (keys[DIK_A]) {
		velocity_.x -= 1.0f;
	}

	if (Length(velocity_) != 0.0f) {
		velocity_ = Normalize(velocity_);
		position_.x += velocity_.x;
		position_.y += velocity_.y;
	}

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		stageScene_->AddBullet(position_);
	}

	circle_.position = position_;
}

void Player::Draw() {
	Novice::DrawEllipse(int(circle_.position.x), int(circle_.position.y), int(circle_.radius), int(circle_.radius), 0.0f, 0xFFFFFFFF, kFillModeSolid);
}