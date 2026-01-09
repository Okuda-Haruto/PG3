#pragma once
#include "ISceneCommand.h"
#include "Selector.h"
#include "Unit.h"

class StageSceneInputHandler {
private:
	char keys_[256] = {0};
	char preKeys_[256] = { 0 };

	Selector* selector_;
	Unit* selectedUnit_;

public:
	StageSceneInputHandler();
	void UpdateKeyState();

	IStageSceneCommand* SelectorHandleInput(Selector* selector);
	IStageSceneCommand* UnitHandleInput(Unit* unit);

	bool CheckUndoStatus();
};