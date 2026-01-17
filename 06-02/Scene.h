#pragma once
#include <condition_variable>
#include <mutex>
#include <array>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

struct Scene {
private:
	std::mutex mutex_;
	std::condition_variable condition_;

	std::thread th_;

	bool exit_ = false;

	int flame_ = 0;

	std::array<std::array<int,5>,5> m;
public:
	~Scene();

	void Initialize();
	void Update();
	void Draw();

	void BackGround();
};