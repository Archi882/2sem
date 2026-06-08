#define _USE_MATH_DEFINES
#include "sphere.h"
#include <cmath>
#include <stdexcept>

using namespace std;

Sphere::Sphere(const Point& center, const double radius) : center(center), radius(radius)
{
    if (radius <= 0)
    {
        throw invalid_argument("Ошибка: радиус шара должен быть положительным.");
    }
}

Point Sphere::GetCenter() const
{
    return center;
}

double Sphere::GetRadius() const
{
    return radius;
}

double Sphere::SurfaceArea() const
{
    return 4.0 * M_PI * pow(radius,2);
}

double Sphere::Volume() const
{
    return (4.0 / 3.0) * M_PI * pow(radius,3);
}

string Sphere::ToString() const
{
    return "Sphere(center=(" +
        to_string(center.GetX()) + ", " +
        to_string(center.GetY()) + ", " +
        to_string(center.GetZ()) + "), radius=" +
        to_string(radius) + ")";
}

Sphere Sphere::Read(istream& in)
{
    Point center;
    double radius = 0.0;

    in >> center >> radius;
    if (!in)
    {
        throw runtime_error("Ошибка чтения шара из потока.");
    }

    return Sphere(center, radius);
}

ostream& operator<<(ostream& os, const Sphere& sphere)
{
    os << sphere.ToString();
    return os;
}