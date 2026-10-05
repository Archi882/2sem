#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <numbers>

/**
    @brief класс окружность
**/
class Circle {
private:
    // @brief радиус
    double radius;

    // @brief координаты центра окружности
    double x;
    double y;
    double z;

public:
    /**
        @brief конструктор
        @param radius - радиус
        @param x - координата центра по X
        @param y - координата центра по Y
        @param z - координата центра по Z
    **/
    Circle(const double radius, const double x, const double y, const double z);

    /**
        @brief расчет длины
        @return рассчитанное значение
    **/
    double getLenght() const;

    /**
        @brief расчет площади
        @return рассчитанное значение
    **/
    double getArea() const;

    /**
        @brief получение координаты X
    **/
    double getX() const;

    /**
        @brief получение координаты Y
    **/
    double getY() const;

    /**
        @brief получение координаты Z
    **/
    double getZ() const;
};
