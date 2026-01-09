#include "Selector.h"
#include "Novice.h"

Selector::Selector() {
	Init();
}

void Selector::Init() {
	mapX_ = 2;
	mapY_ = 2;
	mapSize_ = 32;
	selectMode_ = SELECTOR;

	selectedUnit_ = nullptr;
	unit_ = new Unit[5];
	for (int i = 0; i < 5; i++) {
		unit_[i] = Unit();
		unit_[i].Init(i);
	}
}

void Selector::Update() {

}

void Selector::Draw() {
	if (selectMode_ == SELECTOR) {
		Novice::DrawBox(32 * mapX_, 32 * mapY_, 32, 32, 0, RED, kFillModeWireFrame);
	}
}

void Selector::Move(int x, int y) {
	mapX_ = x;
	mapY_ = y;
	mapX_ = min(mapSize_, max(mapX_, 0));
	mapY_ = min(mapSize_, max(mapY_, 0));
}

void Selector::SelectUnit() {
	for (int i = 0; i < 5; i++) {
		if (unit_[i].GetMapX() == mapX_ && unit_[i].GetMapY() == mapY_) {
			selectedUnit_ = &unit_[i];
			selectedUnit_->SetIsSelected(true);
			selectMode_ = UNIT;
			return;
		}
	}
}