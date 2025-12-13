#include <cstdio>
#include <cmath>
#include <array>

class IShape {
protected:
	float area = 0.0f;
public:
	virtual void Size() = 0;
	virtual void Draw() = 0;
};

class Circle : public IShape {
private: 
	float radius = 2.0f;
public:
	void Size() override;
	void Draw() override;
};

void Circle::Size() {
	area = radius * radius * std::acosf(-1.0f);
}

void Circle::Draw() {
	printf("%f\n", area);
}

class Rectangle : public IShape {
private:
	float scale = 2.0f;
public:
	void Size() override;
	void Draw() override;
};

void Rectangle::Size() {
	area = scale * scale;
}

void Rectangle::Draw() {
	printf("%f\n", area);
}

int main() {
	std::array<IShape*, 2> shape;
	shape[0] = new Circle;
	shape[1] = new Rectangle;

	for (int i = 0; i < 2; i++) {
		shape[i]->Size();

		shape[i]->Draw();
	}

	return 0;
}