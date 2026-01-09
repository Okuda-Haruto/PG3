#include "Unit.h"
#include <random>
#include "Novice.h"
#include "Selector.h"

void Unit::Init(int idref) {
	id = idref;
	mapX_ = rand() % mapSize_;
	mapY_ = rand() % mapSize_;
	isSelected_ = false;
}

void Unit::Update() {

}

void Unit::Draw() {
	if (isSelected_){
		Novice::DrawBox(32 * mapX_ + 4, 32 * mapY_ + 4, 24, 24, 0, 0xFFAAAAFF, kFillModeSolid);
	} else {
		Novice::DrawBox(32 * mapX_ + 4, 32 * mapY_ + 4, 24, 24, 0, WHITE, kFillModeSolid);
	}
}

void Unit::Move(int x, int y) {
	mapX_ = x;
	mapY_ = y;
	mapX_ = min(mapSize_, max(mapX_, 0));
	mapY_ = min(mapSize_, max(mapY_, 0));
}

void Unit::MoveEnd(Selector* selector) {
	selector->SetSelectedUnit(nullptr);
	selector->SetMap(mapX_, mapY_);
	selector->SetSelectMode(SELECTOR);
	isSelected_ = false;
}