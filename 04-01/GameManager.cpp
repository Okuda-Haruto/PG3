#include "GameManager.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"
#include "Novice.h"


void GameManager::Initialize() {
	nowScene_ = std::make_unique<TitleScene>();
	nowScene_->Initialize(this);
}

void GameManager::Update() {
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);

	if (nextScene_) {
		nowScene_.reset();

		nowScene_ = std::move(nextScene_);
		nowScene_->Initialize(this);
	}

	nowScene_->Update(keys_, preKeys_);

}

void GameManager::Draw() {
	nowScene_->Draw();
}