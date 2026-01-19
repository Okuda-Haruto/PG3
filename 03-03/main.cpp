#include <iostream>
#include <Windows.h>
#include <string>
#include <array>

class Drink {
protected:
	std::string name_;
public:
	~Drink() { printf("%sを捨てた。\n", name_.c_str()); };

	void Initialize(std::string name) { name_ = name; };
	virtual void Use() {}
};

class Water : public Drink {
	void Use() override { printf("%sは特に味はしない。\n", name_.c_str()); }
};

class Cider : public Drink {
	void Use() override { printf("%sは爽やかな甘みと強い炭酸がある。\n", name_.c_str()); }
};

class LemonJuice : public Drink {
	void Use() override { printf("%sは強い酸味がある。\n", name_.c_str()); }
};

int main() {
	std::array<Drink*, 3> drink;
	drink[0] = new Water;
	drink[1] = new Cider;
	drink[2] = new LemonJuice;

	printf("使用\n");

	drink[0]->Initialize("ミネラルウォーター");
	drink[1]->Initialize("三つ葉サイダー");
	drink[2]->Initialize("クレートレモン");

	for (int i = 0; i < 3; i++) {
		drink[i]->Use();
	}

	printf("\n破棄\n");

	for (int i = 0; i < 3; i++) {
		delete drink[i];
	}

	return 0;
}