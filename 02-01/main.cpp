#include <iostream>

template<typename T>
T Min(T t1, T t2) {
	if (t1 < t2) {
		return static_cast<T>(t1);
	}
	return static_cast<T>(t2);
}

int main() {

	int i1 = 1, i2 = 5;
	float f1 = 4.0f, f2 = 1.5f;
	double d1 = 6.2, d2 = 0.8;

	printf("%d\n", Min<int>(i1, i2));
	printf("%f\n", Min<float>(f1, f2));
	printf("%lf\n", Min<double>(d1, d2));

	return 0;
}