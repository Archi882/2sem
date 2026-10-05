#include <iostream>
#include <string>
#include <cstdlib>
#include "sphere.h"

using namespace std;

/*
* @brief Считывает значение с клавиатуры
* @param report - строка информации
* @return считанное значение
*/

double getValue(const string& report = "");

/*
* @brief Считывает координаты точки
* @return точка
*/

Point getPoint();

/**
 * @brief Точка входа в программу
 * @return 0, если программа выполнена корректно
 */
int main()
{
    Point center = getPoint();
    double radius = getValue("Введите радиус шара: ");

    if (radius <= 0)
    {
        cout << "Ошибка, радиус должен быть положительным." << endl;
        exit(1);
    }

    Sphere sphere(center, radius);

    cout << sphere << endl;
    cout << "Площадь поверхности: " << sphere.SurfaceArea() << endl;
    cout << "Объем: " << sphere.Volume() << endl;

    return 0;
}

double getValue(string report)
{
    cout << report;
    double value = 0;
    cin >> value;

    if (cin.fail())
    {
        cout << "Ошибка, введено неверное значение." << endl;
        exit(1);
    }

    return value;
}

Point getPoint()
{
    double x = getValue("Введите x центра: ");
    double y = getValue("Введите y центра: ");
    double z = getValue("Введите z центра: ");

    return Point(x, y, z);
}