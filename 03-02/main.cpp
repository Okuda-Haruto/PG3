#include <iostream>
#include <Windows.h>

template <typename T1,typename T2>
class Compare {
public:
	T1 a;
	T2 b;

	// コンストラクタ
	Compare(T1 t1, T2 t2) { a = t1; b = t2; }

	// メンバ関数
	T1 Min() {
		if (a > b) {
			return static_cast<T1>(b);
		}
		return a;
	}
};

int main() {
	Compare<int, int>		II(3, 5);
	Compare<int, float>		IF(3, 2.5f);
	Compare<int, double>	ID(3, 2.4);
	Compare<float, float>	FF(2.5f, 1.9f);
	Compare<float, double>	FD(2.5f, 2.4);
	Compare<double, double> DD(2.4, 5.1);

	printf("int,int: %d\n", II.Min());
	printf("int,float: %d\n", IF.Min());
	printf("int,double: %d\n", ID.Min());
	printf("float,float: %f\n", FF.Min());
	printf("float,double: %f\n", FD.Min());
	printf("double,double: %lf\n", DD.Min());

	return 0;
}