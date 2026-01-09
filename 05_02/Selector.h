#pragma once
#include "Unit.h"

enum SELECTOR_MODE {
	SELECTOR,
	UNIT
};

class Selector {
private:
	int mapX_;
	int mapY_;
	int mapSize_;

	int selectMode_;

	Unit* unit_;
	Unit* selectedUnit_;

public:
	Selector();

	void Init();
	void Update();
	void Draw();

	void Move(int x, int y);
	void SelectUnit();

	int GetSelectMode() { return selectMode_; }
	Unit* GetSelectedUnitAddress() { return selectedUnit_; }
	Unit* GetUnitAddress() { return unit_; }
	int GetMapX() { return mapX_; }
	int GetMapY() { return mapY_; }

	void SetSelectedUnit(Unit* selectedUnit) { selectedUnit_ = selectedUnit; }
	void SetMap(int x, int y) { mapX_ = x; mapY_ = y; }
	void SetSelectMode(int selectMode) { selectMode_ = selectMode; }
	
};