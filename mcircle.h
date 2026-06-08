#pragma once
#define _USE_MATH_DEFINES
#include<cmath>
#include<iostream>
#include<numbers>

/**
	@brief   класс окружность
**/
class Circle {
private:
	// @brief радиус
	double radius;
	double x;
	double y;
	double z;
public:
	/**
		@brief конструктор
		@param radius - радиус
	**/
	Circle(const double radius);

	/**
		@brief рассчет длины
		@return рассчитанное значение
	**/
	double getLenght() const;

	/**
		@brief  рассчет площади
		@return рассчитанное значение
	**/
	double getArea() const;

}; 