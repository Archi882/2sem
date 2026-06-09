#include "point.h"
#include <cmath>
#include <limits>

Point::Point(const double x, const double y, const double z) : x(x), y(y), z(z)
{
}

double Point::GetX() const
{
    return x;
}

double Point::GetY() const
{
    return y;
}

double Point::GetZ() const
{
    return z;
}

bool Point::operator==(const Point& other) const
{
    return (std::abs(x - other.x) < std::numeric_limits<double>::epsilon() &&
        std::abs(y - other.y) < std::numeric_limits<double>::epsilon() &&
        std::abs(z - other.z) < std::numeric_limits<double>::epsilon());
}

bool Point::operator!=(const Point& other) const
{
    return !(*this == other);
}

bool Point::operator<(const Point& other) const
{
    if (x != other.x)
    {
        return x < other.x;
    }
    if (y != other.y)
    {
        return y < other.y;
    }
    return z < other.z;
}

bool Point::operator<=(const Point& other) const
{
    return (*this < other || *this == other);
}

bool Point::operator>(const Point& other) const
{
    return !(*this <= other);
}

bool Point::operator>=(const Point& other) const
{
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const Point& point)
{
    os << point.x << " " << point.y << " " << point.z;
    return os;
}

std::istream& operator>>(std::istream& is, Point& point)
{
    is >> point.x >> point.y >> point.z;
    return is;
}