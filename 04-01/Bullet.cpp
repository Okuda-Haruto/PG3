#include "Bullet.h"
#include "Novice.h"

void Bullet::Initialize(Vector2 position, Vector2 velocity) {
	position_ = position;
	velocity_ = velocity;
	circle_.radius = 12.0f;
	circle_.position = position_;
	lifeTime_ = 0.0f;
	isDead_ = false;
}

void Bullet::Update() {

	lifeTime_ += 1.0f / 60.0f;
	if (lifeTime_ > kMaxLiftTime) {
		isDead_ = true;
	}

	position_.x += velocity_.x;
	position_.y += velocity_.y;

	circle_.position = position_;
}

void Bullet::Draw() {
	if (!isDead_) {
		Novice::DrawTriangle(
			int(circle_.position.x - circle_.radius), int(circle_.position.y - circle_.radius),
			int(circle_.position.x - circle_.radius), int(circle_.position.y + circle_.radius),
			int(circle_.position.x + circle_.radius), int(circle_.position.y),
			0xFFFFFFFF, kFillModeSolid);
	}
}