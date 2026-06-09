#include <iostream>
#include <limits>
#include <stdexcept>

#include "vector.h"

using namespace std;

/**
 * @brief Считать целое число с клавиатуры.
 * @param prompt Подсказка.
 * @return Число.
 */
int ReadInt(const string& prompt)
{
    int value = 0;

    while (true)
    {
        cout << prompt;
        cin >> value;

        if (!cin.fail())
        {
            return value;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода. Повторите.\n";
    }
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
    cout << "1 - показать коллекцию\n";
    cout << "2 - добавить элемент в конец\n";
    cout << "3 - вставить элемент по индексу\n";
    cout << "4 - удалить элемент по индексу\n";
    cout << "5 - найти элемент\n";
    cout << "6 - сдвиг влево\n";
    cout << "7 - сдвиг вправо\n";
    cout << "8 - вывести элемент по индексу\n";
    cout << "0 - выход\n";
}

/**
 * @brief точка входа в программу
 * @return 0, если программа завершена корректно
 */
int main()
{
    cout << "Введите количество элементов: ";
    int n = 0;
    cin >> n;

    while (cin.fail() || n < 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка. Введите корректное число: ";
        cin >> n;
    }

    Vector v;

    for (int i = 0; i < n; ++i)
    {
        int value = ReadInt("Элемент [" + to_string(i) + "]: ");
        v.Insert(value);
    }

    cout << "\nНачальная коллекция: " << v.ToString() << endl;

    while (true)
    {
        ShowMenu();
        int choice = ReadInt("Ваш выбор: ");

        try
        {
            switch (choice)
            {
            case 1:
                cout << "Коллекция: " << v.ToString() << endl;
                cout << "Пустая: " << (v.Empty() ? "да" : "нет") << endl;
                break;

            case 2:
            {
                int value = ReadInt("Введите значение: ");
                v.Insert(value);
                cout << "Готово: " << v.ToString() << endl;
                break;
            }

            case 3:
            {
                int value = ReadInt("Введите значение: ");
                auto index = ReadIndex("Введите индекс: ");
                v.Insert(value, index);
                cout << "Готово: " << v.ToString() << endl;
                break;
            }

            case 4:
            {
                auto index = ReadIndex("Введите индекс: ");
                v.RemoveAt(index);
                cout << "Готово: " << v.ToString() << endl;
                break;
            }

            case 5:
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

            case 6:
            {
                auto count = ReadIndex("Введите количество позиций: ");
                v << count;
                cout << "Готово: " << v.ToString() << endl;
                break;
            }

            case 7:
            {
                auto count = ReadIndex("Введите количество позиций: ");
                v >> count;
                cout << "Готово: " << v.ToString() << endl;
                break;
            }

            case 8:
            {
                auto index = ReadIndex("Введите индекс: ");
                cout << "Элемент: " << v[index] << endl;
                break;
            }

            case 0:
                cout << "Выход.\n";
                return 0;

            default:
                cout << "Неизвестная команда.\n";
                break;
            }
        }
        catch (const exception& ex)
        {
            cout << "Ошибка: " << ex.what() << endl;
        }
    }
}