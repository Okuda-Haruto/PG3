#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"
#include "GameManager.h"
#include <Novice.h>

TitleScene::~TitleScene() {

}

void TitleScene::Initialize(GameManager* gameManager) {
	gameManager_ = gameManager;
}

void TitleScene::Update(const char* keys, const char* preKeys) {

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		gameManager_->SetNextScene(std::make_unique<StageScene>());
	}
}

void TitleScene::Draw() {
	Novice::ScreenPrintf(640, 360, "Press Space Start");
}