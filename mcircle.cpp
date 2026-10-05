#include "mcircle.h"

using namespace std;

Circle::Circle(const double radius, const double x, const double y, const double z)
    : radius(radius), x(x), y(y), z(z) {
    if (radius <= 0) {
        cout << "Error" << endl;
        exit(1);
    }
}

double Circle::getLenght() const {
    return 2 * M_PI * radius;
}

double Circle::getArea() const {
    return M_PI * pow(radius, 2);
}

double Circle::getX() const {
    return x;
}

double Circle::getY() const {
    return y;
}

double Circle::getZ() const {
    return z;
}
