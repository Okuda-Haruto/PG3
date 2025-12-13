#include <iostream>
#include <Windows.h>

class Enemy {
private:
	void Contact();
	void Shooting();
	void Breakaway();
	
	bool isAlive;
public:
	void (Enemy::* state_)();

	void Initialize();
	void Update();

	bool IsAlive() { return isAlive; }
};

void Enemy::Contact() {
	printf("接敵\n");
	state_ = &Enemy::Shooting;
}

void Enemy::Shooting() {
	printf("射撃\n");
	state_ = &Enemy::Breakaway;
}

void Enemy::Breakaway() {
	printf("離脱\n");
	isAlive = false;
}

void Enemy::Initialize() {
	state_ = &Enemy::Contact;
	isAlive = true;
}

void Enemy::Update() {
	(this->*state_)();
}

int main() {
	Enemy* enemy = new Enemy;
	enemy->Initialize();

	while (enemy->IsAlive()) {
		enemy->Update();
	}

	return 0;
}