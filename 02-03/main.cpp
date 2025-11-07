#include <iostream>
#include <Windows.h>
#include <random>
#include <time.h>

void ShowResult(int roll,int userGuess) {
	printf("出力は%dでした。\n", roll);
	if (roll % 2 == userGuess) {
		printf("正解\n");
	} else {
		printf("不正解\n");
	}
}

void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess) {
	Sleep(delayMs);
	fn(roll, userGuess);
}

int main() {
	srand((unsigned)time(NULL));

	int userGuess;

	printf("半(奇数) = 1,丁(偶数) = 0\n");
	scanf_s("%d", &userGuess);

	int roll = rand() % 6 + 1;

	DelayReveal(ShowResult, 3000, roll, userGuess);

	return 0;
}