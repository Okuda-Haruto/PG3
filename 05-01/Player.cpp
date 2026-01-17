#include "Player.h"
#include "Novice.h"

void Player::Initialize() {
	pos = { 100,100 };
}

void Player::Update() {

}

void Player::Draw() {
	Novice::DrawBox(int(pos.x), int(pos.y), 32, 32, 0.0f, WHITE, kFillModeSolid);
}

void Player::MoveRight() {
	pos.x += speed;
}

void Player::MoveLeft() {
	pos.x -= speed;
}