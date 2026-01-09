#include "StageScene.h"
#include "Novice.h"

StageScene::StageScene() {

}

void StageScene::Init() {
	selector_ = new Selector();
	inputHandler_ = new StageSceneInputHandler();
}

void StageScene::Update() {
	//入力処理
	inputHandler_->UpdateKeyState();

	//get command Type
	if (selector_->GetSelectMode() == SELECTOR) {
		command_ = inputHandler_->SelectorHandleInput(selector_);
	} else if (selector_->GetSelectMode() == UNIT) {
		command_ = inputHandler_->UnitHandleInput(selector_->GetSelectedUnitAddress());
		if (inputHandler_->CheckUndoStatus()) {
			if (commandHistoryItr_ != commandHistory_.begin()) {
				--commandHistoryItr_;
				command_ = *commandHistoryItr_;
				this->command_->Exec();
				return;
			}
		}
	}

	//set command
	if (this->command_) {
		this->command_->Exec();
		if (commandHistory_.empty()) {
			commandHistory_.push_back(this->command_);
			commandHistoryItr_ = commandHistory_.end();
		} else if (commandHistoryItr_ == commandHistory_.end()) {
			commandHistory_.push_back(this->command_);
			commandHistoryItr_ = commandHistory_.end();
		} else {
			*commandHistoryItr_ = this->command_;
			commandHistoryItr_++;
		}
	}
}

void StageScene::Draw() {

	for (int i = 0; i < 1280 / 32; i++) {
		Novice::DrawLine(i * 32, 0, i * 32, 720, WHITE);
	}
	for (int i = 0; i < 720 / 32; i++) {
		Novice::DrawLine(0, i * 32, 1280, i * 32, WHITE);
	}

	selector_->Draw();
	for (int i = 0; i < 5; i++) {
		selector_->GetUnitAddress()[i].Draw();
	}
}