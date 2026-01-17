#include "Scene.h"
#include "Novice.h"
#include <thread>
#include <cassert>

Scene::~Scene() {
	exit_ = true;
	th_.join();
}

void Scene::Initialize() {
	exit_ = false;
	flame_ = 0;

	th_ = std::thread(&Scene::BackGround,this);
}

void Scene::Update() {

	if (flame_ <= 120) {
		flame_++;
	}

	if (flame_ == 120) {
		condition_.notify_all();
	}
}

void Scene::Draw() {
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m[i].size(); j++) {
			if (m[i][j] == 1) {
				Novice::DrawBox(32 * i, 32 * j, 32, 32, 0.0f, WHITE, kFillModeSolid);
			} else {
				Novice::DrawBox(32 * i, 32 * j, 32, 32, 0.0f, BLACK, kFillModeSolid);
			}
		}
	}
}

void Scene::BackGround() {
	while (!exit_) {
		{
			std::unique_lock<std::mutex> uniqueLock(mutex_);
			condition_.wait(uniqueLock);

			std::ifstream file;
			file.open("Mapchip.csv");
			assert(file.is_open());

			std::stringstream stream;
			stream << file.rdbuf();

			file.close();

			std::string line;

			for (int i = 0; i < m.size(); i++) {
				getline(stream, line);
				std::istringstream line_stream(line);

				for (int j = 0; j < m[i].size(); j++) {
					std::string word;
					getline(line_stream, word, ',');
					m[j][i] = std::atoi(word.c_str());
				}
			}
		}
	}
}