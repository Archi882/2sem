#include"mсircle.h"

using namespace std;

Circle::Circle(const double radius) {
	if (radius <= 0) {
		cout << "Error" << endl;
		exit(1);
	}
	this->radius = radius;
}
double Circle::getLenght() const {
	return 2 * M_PI * radius;
}
double Circle::getArea() const {
	return M_PI * pow(radius, 2);
}