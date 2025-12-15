#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"
#include "GameManager.h"
#include <Novice.h>

ClearScene::~ClearScene() {

}

void ClearScene::Initialize(GameManager* gameManager) {
	gameManager_ = gameManager;
}

void ClearScene::Update(const char* keys, const char* preKeys) {

	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		gameManager_->SetNextScene(std::make_unique<TitleScene>());
	}
}

void ClearScene::Draw() {
	Novice::ScreenPrintf(640, 360, "Press Space Title");
}