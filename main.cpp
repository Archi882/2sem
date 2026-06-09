
#define _USE_MATH_DEFINES
#include<cmath>
#include<iostream>
#include<numbers>
#include"mсircle.h"
using namespace std;



/**
* @breaf считывает сторону треугольника с клавиатуры
* @param report - строка информации
* @return считанное знаначение
*/
double getRadius( const string report = "");

/**
* @breaf точка входа в программу
* @return 0, если программа выполнена корректно
*/
int main() {
	double radius = getRadius("Enter radius: ");
	double x = getRadius("Enter x: ");
	double y = getRadius("Enter y: ");
	double z = getRadius("Enter z: ");
	Circle myCircle(radius);
	cout << "Lenght is " << myCircle.getLenght() << endl;
	cout << "Area is " << myCircle.getArea() << endl;
	cout << "Coordinates are: " << x << " " << y << " " << z << " " << endl;
	return 0;
}


double getRadius(const string report) {
	cout << report << endl;
	double radius = 0;
	cin >> radius;
	if (cin.fail()) {
		cout << "Error\n";
		exit(1);
	}
	return radius;
}