#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

int main() {
	std::vector <std::string> vec;

	// ファイルを開く
	std::ifstream file;
	file.open("PG3_2025_01_02.txt");

	// ファイルの内容を文字列ストリームにコピー
	std::stringstream LoadEnemyCommands_;
	LoadEnemyCommands_ << file.rdbuf();

	// ファイルを閉じる
	file.close();

	std::string word;

	while (std::getline(LoadEnemyCommands_, word,',')) {
		vec.push_back(word);
	}

	std::sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		printf("%s\n", vec[i].c_str());
	}

	return 0;
}