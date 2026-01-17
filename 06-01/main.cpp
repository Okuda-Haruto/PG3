#include <stdio.h>
#include <thread>

void ThreadNum(int num) {
	printf("thread %d\n", num);
}

int main() {

	std::thread th1(ThreadNum, 1);
	th1.join();

	std::thread th2(ThreadNum, 2);
	th2.join();

	std::thread th3(ThreadNum, 3);
	th3.join();

	return 0;
}