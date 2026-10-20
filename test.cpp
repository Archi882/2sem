#include "CppUnitTest.h"
#include "/Users/archi/source/repos/Задание 3/vector.h"
#include <utility> // для std::move
#include <stdexcept>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
    TEST_CLASS(VectorTests)
    {
    public:

        /**
         * @brief Проверка конструктора по умолчанию.
         */
        TEST_METHOD(DefaultConstructor_Test)
        {
            Vector v;
            Assert::IsTrue(v.Empty());
            Assert::AreEqual(static_cast<Vector::size_type>(0), v.Size());
            Assert::AreEqual(std::string("[]"), v.ToString());
        }

        /**
         * @brief Проверка конструктора со списком инициализации.
         */
        TEST_METHOD(InitializerListConstructor_Test)
        {
            Vector v{ 1, 2, 3 };
            Assert::AreEqual(static_cast<Vector::size_type>(3), v.Size());
            Assert::AreEqual(std::string("[1, 2, 3]"), v.ToString());
        }

        /**
         * @brief Проверка конструктора копирования.
         */
        TEST_METHOD(CopyConstructor_Test)
        {
            Vector a{ 5, 6, 7 };
            Vector b(a); 
            Assert::AreEqual(std::string("[5, 6, 7]"), b.ToString());
        }

        /**
         * @brief Проверка конструктора перемещения.
         */
        TEST_METHOD(MoveConstructor_Test)
        {
            Vector a{ 5, 6, 7 };
            Vector b(std::move(a)); 
            Assert::AreEqual(std::string("[5, 6, 7]"), b.ToString());
            Assert::IsTrue(a.Empty()); 
        }

        /**
         * @brief Проверка оператора копирующего присваивания.
         */
        TEST_METHOD(CopyAssignment_Test)
        {
            Vector a{ 1, 2 };
            Vector b{ 9, 9, 9 };
            b = a; 
            Assert::AreEqual(std::string("[1, 2]"), b.ToString());
        }

        /**
         * @brief Проверка оператора перемещающего присваивания.
         */
        TEST_METHOD(MoveAssignment_Test)
        {
            Vector a{ 1, 2 };
            Vector b;
            b = std::move(a); 
            Assert::AreEqual(std::string("[1, 2]"), b.ToString());
            Assert::IsTrue(a.Empty());
        }

        /**
         * @brief Проверка добавления в конец.
         */
        TEST_METHOD(InsertEnd_Test)
        {
            Vector v{ 1, 2 };
            v.Insert(3); 
            Assert::AreEqual(std::string("[1, 2, 3]"), v.ToString());
        }

        /**
         * @brief Проверка вставки по индексу и удаления.
         */
        TEST_METHOD(InsertRemoveAtIndex_Test)
        {
            Vector v{ 1, 3, 5 };
            v.Insert(2, 1);
            Assert::AreEqual(std::string("[1, 2, 3, 5]"), v.ToString());

            v.RemoveAt(2);
            Assert::AreEqual(std::string("[1, 2, 5]"), v.ToString());
            
            v.RemoveAt(0);
            v.RemoveAt(0);
            v.RemoveAt(0);
            Assert::IsTrue(v.Empty());
            Assert::AreEqual(std::string("[]"), v.ToString());
        }

        /**
         * @brief Проверка поиска элемента.
         */
        TEST_METHOD(Find_Test)
        {
            Vector v{ 10, 20, 30 };
            Assert::AreEqual(static_cast<Vector::size_type>(1), v.Find(20));
            Assert::AreEqual(Vector::npos, v.Find(100));
        }

        /**
         * @brief Проверка оператора [] (чтение и запись).
         */
        TEST_METHOD(IndexOperator_Test)
        {
            Vector v{ 7, 8, 9 };
            Assert::AreEqual(8, v[1]); 
            v[1] = 88;                
            Assert::AreEqual(88, v[1]);
        }

        /**
         * @brief Проверка константного оператора [].
         */
        TEST_METHOD(ConstIndexOperator_Test)
        {
            const Vector v{ 7, 8, 9 };
            Assert::AreEqual(8, v[1]); 
        }

        /**
         * @brief Проверка сдвигов (обычные и с превышением размера).
         */
        TEST_METHOD(ShiftOperators_Test)
        {
            Vector v{ 1, 2, 3, 4 };
            v << 2;
            Assert::AreEqual(std::string("[3, 4, 0, 0]"), v.ToString());

            v >> 1;
            Assert::AreEqual(std::string("[0, 3, 4, 0]"), v.ToString());

            v << 10;
            Assert::AreEqual(std::string("[0, 0, 0, 0]"), v.ToString());
        }

        /**
         * @brief Проверка исключений при выходе за границы.
         */
        TEST_METHOD(OutOfRangeExceptions_Test)
        {
            Vector v{ 1, 2, 3 };

            Assert::ExpectException<std::out_of_range>([&v]() {
                v[5];
            });

            Assert::ExpectException<std::out_of_range>([&v]() {
                v.Insert(10, 10); 
            });

            Assert::ExpectException<std::out_of_range>([&v]() {
                v.RemoveAt(10);
            });
        }
    };
}
