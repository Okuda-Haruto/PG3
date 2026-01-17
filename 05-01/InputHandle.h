#pragma once
#include "Command.h"

class InputHandler {
public:
	ICommand* HandleInput();

	void AssignMoveRightCommand();
	void AssignMoveLeftCommand();
private:
	ICommand* moveRightCommand_;
	ICommand* moveLeftCommand_;

};
