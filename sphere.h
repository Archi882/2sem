#pragma once

#include <iostream>
#include <string>
#include "point.h"

/**
 * @brief Класс шара в трехмерном пространстве
 */
class Sphere
{
public:
    /**
     * @brief Конструктор шара
     * @param center центр шара
     * @param radius радиус шара
     * @throw std::invalid_argument если радиус меньше или равен 0
     */
    Sphere(const Point& center = Point(), const double radius = 1.0);

    /**
     * @brief Получить центр шара
     * @return центр шара
     */
    Point GetCenter() const;

    /**
     * @brief Получить радиус шара
     * @return радиус шара
     */
    double GetRadius() const;

    /**
     * @brief Вычислить площадь поверхности шара
     * @return площадь поверхности
     */
    double SurfaceArea() const;

    /**
     * @brief Вычислить объем шара
     * @return объем
     */
    double Volume() const;

    /**
     * @brief Получить строковое представление шара
     * @return строка с описанием шара
     */
    std::string ToString() const;

    /**
     * @brief Считать шар из потока
     * @param in поток ввода
     * @return объект Sphere
     * @throw std::runtime_error если ввод некорректен
     */
    static Sphere Read(std::istream& in);

    /**
     * @brief Перегрузка оператора вывода шара в поток
     * @param os поток вывода
     * @param sphere шар
     * @return поток вывода
     */
    friend std::ostream& operator<<(std::ostream& os, const Sphere& sphere);

private:
    Point center; 
    double radius; 
};