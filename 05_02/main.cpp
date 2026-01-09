#include <Novice.h>
#include <StageScene.h>
#include <time.h>
#include <random>

const char kWindowTitle[] = "LC1A_05_オクダハルト_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	unsigned int currentTime = int(time(nullptr));

	srand(currentTime);

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	StageScene* stageScene = new StageScene;
	stageScene->Init();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		///
		/// ↓更新処理ここから
		///

		stageScene->Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		stageScene->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

	}

	delete stageScene;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
