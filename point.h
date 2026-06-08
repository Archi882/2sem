#pragma once
#include <iostream>

/**
 * @brief Класс точки в трехмерном пространстве
 */
class Point
{
public:
    /**
     * @brief Конструктор точки
     * @param x координата X
     * @param y координата Y
     * @param z координата Z
     */
    Point(const double x = 0.0, const double y = 0.0, const double z = 0.0);

    /**
     * @brief Получить координату X
     * @return координата X
     */
    double GetX() const;

    /**
     * @brief Получить координату Y
     * @return координата Y
     */
    double GetY() const;

    /**
     * @brief Получить координату Z
     * @return координата Z
     */
    double GetZ() const;

    /**
     * @brief Оператор равенства
     * @param other другая точка
     * @return true, если точки равны
     */
    bool operator==(const Point& other) const;

    /**
     * @brief Оператор неравенства
     * @param other другая точка
     * @return true, если точки не равны
     */
    bool operator!=(const Point& other) const;

    /**
     * @brief Оператор меньше
     * @param other другая точка
     * @return true, если текущая точка меньше other
     */
    bool operator<(const Point& other) const;

    /**
     * @brief Оператор меньше или равно
     * @param other другая точка
     * @return true, если текущая точка меньше или равна other
     */
    bool operator<=(const Point& other) const;

    /**
     * @brief Оператор больше
     * @param other другая точка
     * @return true, если текущая точка больше other
     */
    bool operator>(const Point& other) const;

    /**
     * @brief Оператор больше или равно
     * @param other другая точка
     * @return true, если текущая точка больше или равна other
     */
    bool operator>=(const Point& other) const;

    /**
     * @brief Перегрузка оператора вывода в поток
     * @param os поток вывода
     * @param point точка
     * @return поток вывода
     */
    friend std::ostream& operator<<(std::ostream& os, const Point& point);

    /**
     * @brief Перегрузка оператора ввода из потока
     * @param is поток ввода
     * @param point точка
     * @return поток ввода
     */
    friend std::istream& operator>>(std::istream& is, Point& point);

private:
    double x; 
    double y; 
    double z; 
};