#pragma once

class Selector;

class Unit {
private:
	int mapX_ = 0;
	int mapY_ = 0;
	int mapSize_ = 32;
	int id = 0;
	bool isSelected_ = false;

public:
	Unit() = default;
	void Init(int idref);
	void Update();
	void Draw();

	void Move(int x, int y);
	void MoveEnd(Selector* selector);

	int GetMapX() { return mapX_; }
	int GetMapY() { return mapY_; }

	void SetIsSelected(bool isSelected) { isSelected_ = isSelected; }
};