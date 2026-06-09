#pragma once

#include <cstddef>
#include <initializer_list>
#include <string>

/**
 * @brief Коллекция целых чисел на основе динамического массива (вектор).
 */
class Vector
{
public:
    using size_type = std::size_t;
    static constexpr size_type npos = static_cast<size_type>(-1);

    /**
     * @brief Конструктор по умолчанию.
     */
    Vector();

    /**
     * @brief Конструктор со списком инициализации.
     * @param values Начальные значения.
     */
    Vector(std::initializer_list<int> values);

    /**
     * @brief Конструктор копирования.
     * @param other Вектор-источник.
     */
    Vector(const Vector& other);

    /**
     * @brief Конструктор перемещения.
     * @param other Вектор-источник.
     */
    Vector(Vector&& other) noexcept;

    /**
     * @brief Деструктор.
     */
    ~Vector();

    /**
     * @brief Оператор копирующего присваивания.
     * @param other Вектор-источник.
     * @return Ссылка на текущий объект.
     */
    Vector& operator=(const Vector& other);

    /**
     * @brief Оператор перемещающего присваивания.
     * @param other Вектор-источник.
     * @return Ссылка на текущий объект.
     */
    Vector& operator=(Vector&& other) noexcept;

    /**
     * @brief Доступ к элементу по индексу.
     * @param index Индекс элемента.
     * @return Ссылка на элемент.
     */
    int& operator[](size_type index);

    /**
     * @brief Доступ к элементу по индексу.
     * @param index Индекс элемента.
     * @return Константная ссылка на элемент.
     */
    const int& operator[](size_type index) const;

    /**
     * @brief Сдвиг коллекции влево.
     * @param count Количество позиций.
     * @return Ссылка на текущий объект.
     */
    Vector& operator<<(size_type count);

    /**
     * @brief Сдвиг коллекции вправо.
     * @param count Количество позиций.
     * @return Ссылка на текущий объект.
     */
    Vector& operator>>(size_type count);

    /**
     * @brief Добавить элемент в конец.
     * @param value Значение.
     */
    void Insert(int value);

    /**
     * @brief Вставить элемент по индексу.
     * @param value Значение.
     * @param index Индекс вставки.
     */
    void Insert(int value, size_type index);

    /**
     * @brief Удалить элемент по индексу.
     * @param index Индекс.
     */
    void RemoveAt(size_type index);

    /**
     * @brief Найти элемент.
     * @param value Значение для поиска.
     * @return Индекс или npos.
     */
    size_type Find(int value) const noexcept;

    /**
     * @brief Проверка на пустоту.
     * @return true если пусто.
     */
    bool Empty() const noexcept;

    /**
     * @brief Получить количество элементов.
     * @return Размер.
     */
    size_type Size() const noexcept;

    /**
     * @brief Преобразовать в строку.
     * @return Строка.
     */
    std::string ToString() const;

private:
    int* data_;
    size_type size_;
    size_type capacity_;

    void Reserve(size_type newCapacity);
};