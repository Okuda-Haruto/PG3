#include "StageSceneInputHandler.h"
#include "Novice.h"
#include "SelectorCommand.h"
#include "UnitCommand.h"

StageSceneInputHandler::StageSceneInputHandler() {
	Novice::GetHitKeyStateAll(keys_);
}

void StageSceneInputHandler::UpdateKeyState() {
	// キー入力を受け取る
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);
}

IStageSceneCommand* StageSceneInputHandler::SelectorHandleInput(Selector* selector) {
	IStageSceneCommand* command = nullptr;
	selector_ = selector;

	int x = selector_->GetMapX(), y = selector_->GetMapY();

	if ((keys_[DIK_D] && !preKeys_[DIK_D]) || (keys_[DIK_RIGHT] && !preKeys_[DIK_RIGHT])) {
		x++;
		command = new SelectorMoveCommand(selector_, x, y);
	} else if ((keys_[DIK_A] && !preKeys_[DIK_A]) || (keys_[DIK_LEFT] && !preKeys_[DIK_LEFT])) {
		x--;
		command = new SelectorMoveCommand(selector_, x, y);
	}
	if ((keys_[DIK_S] && !preKeys_[DIK_S]) || (keys_[DIK_DOWN] && !preKeys_[DIK_DOWN])) {
		y++;
		command = new SelectorMoveCommand(selector_, x, y);
	} else if ((keys_[DIK_W] && !preKeys_[DIK_W]) || (keys_[DIK_UP] && !preKeys_[DIK_UP])) {
		y--;
		command = new SelectorMoveCommand(selector_, x, y);
	}
	if (keys_[DIK_SPACE] && !preKeys_[DIK_SPACE]) {
		command = new SelectUnitCommand(selector_);
	}
	return command;
}

IStageSceneCommand* StageSceneInputHandler::UnitHandleInput(Unit* unit) {
	IStageSceneCommand* command = nullptr;
	selectedUnit_ = unit;

	int x = selectedUnit_->GetMapX(), y = selectedUnit_->GetMapY();

	if ((keys_[DIK_D] && !preKeys_[DIK_D]) || (keys_[DIK_RIGHT] && !preKeys_[DIK_RIGHT])) {
		x++;
		command = new UnitMoveCommand(selectedUnit_, x, y);
	} else if ((keys_[DIK_A] && !preKeys_[DIK_A]) || (keys_[DIK_LEFT] && !preKeys_[DIK_LEFT])) {
		x--;
		command = new UnitMoveCommand(selectedUnit_, x, y);
	}
	if ((keys_[DIK_S] && !preKeys_[DIK_S]) || (keys_[DIK_DOWN] && !preKeys_[DIK_DOWN])) {
		y++;
		command = new UnitMoveCommand(selectedUnit_, x, y);
	} else if ((keys_[DIK_W] && !preKeys_[DIK_W]) || (keys_[DIK_UP] && !preKeys_[DIK_UP])) {
		y--;
		command = new UnitMoveCommand(selectedUnit_, x, y);
	}

	if (keys_[DIK_SPACE] && !preKeys_[DIK_SPACE]) {
		command = new UnitMoveEndCommand(selectedUnit_, selector_);
	}

	return command;
}

bool StageSceneInputHandler::CheckUndoStatus() {
	if ((keys_[DIK_LCONTROL] || keys_[DIK_RCONTROL]) && keys_[DIK_S] && !preKeys_[DIK_S]) {
		return true;
	}
	return false;
}