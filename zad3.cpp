#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

#include "vector.h"

using namespace std;

/**
 * @brief Пункты меню.
 */
enum MenuOption
{
    Exit       = 0,
    Show       = 1,
    Append     = 2,
    InsertAt   = 3,
    RemoveAt   = 4,
    FindItem   = 5,
    ShiftLeft  = 6,
    ShiftRight = 7,
    At         = 8
};

/**
 * @brief Считать целое число с клавиатуры.
 * @param prompt Подсказка.
 * @return Число.
 */
int ReadInt(const string& prompt)
{
    int value = 0;

    cout << prompt;
    cin >> value;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода. Повторите: ";
        cin >> value;
    }

    return value;
}

/**
 * @brief Считать индекс с клавиатуры.
 * @param prompt Подсказка.
 * @return Индекс.
 */
Vector::size_type ReadIndex(const string& prompt)
{
    int value = ReadInt(prompt);

    if (value < 0)
    {
        throw invalid_argument("Индекс не может быть отрицательным!");
    }

    return static_cast<Vector::size_type>(value);
}

/**
 * @brief Вывести меню.
 */
void ShowMenu()
{
    cout << "\nМеню:\n";
    cout << static_cast<int>(Show)       << " - показать коллекцию\n";
    cout << static_cast<int>(Append)     << " - добавить элемент в конец\n";
    cout << static_cast<int>(InsertAt)   << " - вставить элемент по индексу\n";
    cout << static_cast<int>(RemoveAt)   << " - удалить элемент по индексу\n";
    cout << static_cast<int>(FindItem)   << " - найти элемент\n";
    cout << static_cast<int>(ShiftLeft)  << " - сдвиг влево\n";
    cout << static_cast<int>(ShiftRight) << " - сдвиг вправо\n";
    cout << static_cast<int>(At)         << " - вывести элемент по индексу\n";
    cout << static_cast<int>(Exit)       << " - выход\n";
}

/**
 * @brief точка входа в программу
 * @return 0, если программа завершена корректно
 */
int main()
{
    int n = ReadInt("Введите количество элементов: ");

    while (n < 0)
    {
        cout << "Ошибка. Количество элементов не может быть отрицательным.\n";
        n = ReadInt("Введите количество элементов: ");
    }

    Vector v;

    for (size_t i = 0; i < static_cast<size_t>(n); ++i)
    {
        int value = ReadInt("Элемент [" + to_string(i) + "]: ");
        v.Insert(value);
    }

    cout << "\nНачальная коллекция: " << v.ToString() << endl;

    bool running = true;
    while (running)
    {
        ShowMenu();
        int choice = ReadInt("Ваш выбор: ");

        try
        {
            switch (choice)
            {
            case Show:
                cout << "Коллекция: " << v.ToString() << endl;
                cout << "Пустая: " << (v.Empty() ? "да" : "нет") << endl;
                break;

            case Append:
            {
                int value = ReadInt("Введите значение: ");
                v.Insert(value);
                cout << "Готово: " << v.ToString() << endl;
                break;
            }

            case InsertAt:
            {
                int value = ReadInt("Введите значение: ");
                auto index = ReadIndex("Введите индекс: ");
                v.Insert(value, index);
                cout << "Готово: " << v.ToString() << endl;
                break;
            }

            case RemoveAt:
            {
                auto index = ReadIndex("Введите индекс: ");
                v.RemoveAt(index);
                cout << "Готово: " << v.ToString() << endl;
                break;
            }

            case FindItem:
            {
                int value = ReadInt("Введите искомое значение: ");
                auto pos = v.Find(value);

                if (pos == Vector::npos)
                {
                    cout << "Элемент не найден.\n";
                }
                else
                {
                    cout << "Элемент найден. Индекс: " << pos << endl;
                }

                break;
            }

            case ShiftLeft:
            {
                auto count = ReadIndex("Введите количество позиций: ");
                v << count;
                cout << "Готово: " << v.ToString() << endl;
                break;
            }

            case ShiftRight:
            {
                auto count = ReadIndex("Введите количество позиций: ");
                v >> count;
                cout << "Готово: " << v.ToString() << endl;
                break;
            }

            case At:
            {
                auto index = ReadIndex("Введите индекс: ");
                cout << "Элемент: " << v[index] << endl;
                break;
            }

            case Exit:
                cout << "Выход.\n";
                running = false;
                break;

            default:
                cout << "Неизвестная команда. Выход.\n";
                return 0;
            }
        }
        catch (const exception& ex)
        {
            cout << "Ошибка: " << ex.what() << endl;
        }
    }

    return 0;
}
