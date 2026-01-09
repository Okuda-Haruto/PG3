#pragma once
#include "StageSceneInputHandler.h"
#include "Selector.h"
#include "ISceneCommand.h"
#include <list>

class StageScene{
private:
	StageSceneInputHandler* inputHandler_ = nullptr;
	IStageSceneCommand* command_ = nullptr;
	std::list<IStageSceneCommand*> commandHistory_;
	std::list<IStageSceneCommand*>::iterator commandHistoryItr_;

	Selector* selector_;

public:
	StageScene();

	void Init();
	void Update();
	void Draw();
};