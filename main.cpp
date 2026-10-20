#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream> 
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
    cout << "--- Ввод координат точки ---" << endl;
    Point center = getPoint();

    cout << "Вы ввели точку с координатами: (" 
         << center.GetX() << ", " 
         << center.GetY() << ", " 
         << center.GetZ() << ")" << endl;

    cout << "Проверка operator<< для Point: " << center << endl;

    Point sameCenter(center.GetX(), center.GetY(), center.GetZ());
    if (center == sameCenter) {
        cout << "Точки равны (operator==)." << endl;
    }
    if (center != Point(0, 0, 0)) {
        cout << "Точка не является началом координат (operator!=)." << endl;
    }

    cout << "\n--- Создание шара ---" << endl;
    double radius = getValue("Введите радиус шара: ");

    if (radius <= 0)
    {
        cout << "Ошибка, радиус должен быть положительным." << endl;
        exit(1);
    }

    Sphere sphere(center, radius);

    cout << "Радиус шара: " << sphere.GetRadius() << endl;
    Point c = sphere.GetCenter();
    cout << "Центр шара (через GetCenter): (" << c.GetX() << ", " << c.GetY() << ", " << c.GetZ() << ")" << endl;

    cout << "Строковое представление (ToString): " << sphere.ToString() << endl;
    cout << "Вывод через operator<<: " << sphere << endl;

    cout << "Площадь поверхности: " << sphere.SurfaceArea() << endl;
    cout << "Объем: " << sphere.Volume() << endl;

    cout << "\n--- Демонстрация чтения из строкового потока ---" << endl;
    
    istringstream pointStream("1.5 2.5 3.5");
    Point pFromStream;
    pointStream >> pFromStream;
    cout << "Точка, прочитанная через operator>>: " << pFromStream << endl;

    istringstream sphereStream("10 20 30 5.0"); 
    Sphere sFromStream = Sphere::Read(sphereStream);
    cout << "Шар, прочитанный через Sphere::Read: " << sFromStream << endl;

    return 0;
}

double getValue(const string& report)
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
