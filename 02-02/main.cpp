#include <iostream>
#include <Windows.h>

int ReflexivePay(int hour,int pay) {
	if (hour > 1) {
		return ReflexivePay(hour - 1, pay * 2 - 50);
	} else {
		return pay;
	}
}

int main() {
	SetConsoleOutputCP(65001);

	//一般
	int general = 0;
	int generalPay = 1226;
	//再帰
	int recursive = 0;
	int recursivePay = 100;
	//時間
	int hour = 1;

	while(true)  {
		printf("%d時間\n", hour);
		general += generalPay;
		recursivePay = ReflexivePay(hour, 100);
		recursive += recursivePay;
		printf("一般: %4d,再帰: %4d\n", generalPay, recursivePay);
		printf("一般: %4d,再帰: %4d\n",general,recursive);
		if (general < recursive) {
			break;
		}
		hour++;
	}

	return 0;
}