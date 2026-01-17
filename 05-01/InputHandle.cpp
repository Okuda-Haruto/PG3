#include "InputHandle.h"
#include "Novice.h"

void InputHandler::AssignMoveRightCommand() {
	ICommand* command = new MoveRightCommand;
	moveRightCommand_ = command;
}

void InputHandler::AssignMoveLeftCommand() {
	ICommand* command = new MoveLeftCommand;
	moveLeftCommand_ = command;
}

ICommand* InputHandler::HandleInput() {
	if (Novice::CheckHitKey(DIK_D)) {
		return moveRightCommand_;
	}
	if (Novice::CheckHitKey(DIK_A)) {
		return moveLeftCommand_;
	}

	return nullptr;
}