#include <iostream>
#include <Windows.h>
#include <list>
#include <vector>

int main() {
	std::list<const char*> lst{
	"Tokyo","Kanda","Akihabara","Okachimachi","Ueno","Uguisudani","Nippori","Tabata","Komagome",
	"Otsuka","Ikebukuro","Mejiro","Takadanobaba","Shin-Okubo","Shinjuku","Yoyogi","Harajuku","Shibuya",
	"Ebisu","Meguro","Gotanda","Osaki","Sinagawa","Tamachi","Hamamatsucho","Shimbasi","Yurakucho"};
	std::list<const char*>::iterator itr;

	//1970年にある各駅を表示
	printf("1970");
	for (itr = lst.begin(); itr != lst.end(); itr++) {
		printf("\n%s", *itr);
	}

	//西日暮里を追加
	for (itr = lst.begin(); itr != lst.end(); itr++) {
		//田端の前
		if (*itr == "Tabata") {
			itr = lst.insert(itr, "Nishi-Nippori");
			break;
		}
	}

	//2019年にある各駅を表示
	printf("\n\n2019");
	for (itr = lst.begin(); itr != lst.end(); itr++) {
		printf("\n%s", *itr);
	}

	//高輪ゲートウェイを追加
	for (itr = lst.begin(); itr != lst.end(); itr++) {
		//田町の前
		if (*itr == "Tamachi") {
			itr = lst.insert(itr, "Takanawa Gateway");
			break;
		}
	}

	//2022年にある各駅を表示
	printf("\n\n2022");
	for (itr = lst.begin(); itr != lst.end(); itr++) {
		printf("\n%s", *itr);
	}

	return 0;
}