#include "CppUnitTest.h"
#include "/Users/archi/source/repos/Задание 3/vector.h"
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
         * @brief Проверка вставки и удаления.
         */
        TEST_METHOD(InsertRemove_Test)
        {
            Vector v{ 1, 3, 5 };
            v.Insert(2, 1);
            Assert::AreEqual(std::string("[1, 2, 3, 5]"), v.ToString());

            v.RemoveAt(2);
            Assert::AreEqual(std::string("[1, 2, 5]"), v.ToString());
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
         * @brief Проверка оператора [].
         */
        TEST_METHOD(IndexOperator_Test)
        {
            Vector v{ 7, 8, 9 };
            Assert::AreEqual(8, v[1]);
            v[1] = 88;
            Assert::AreEqual(88, v[1]);
        }

        /**
         * @brief Проверка сдвигов.
         */
        TEST_METHOD(ShiftOperators_Test)
        {
            Vector v{ 1, 2, 3, 4 };
            v << 2;
            Assert::AreEqual(std::string("[3, 4, 0, 0]"), v.ToString());

            v >> 1;
            Assert::AreEqual(std::string("[0, 3, 4, 0]"), v.ToString());
        }

        /**
         * @brief Проверка копирования и перемещения.
         */
        TEST_METHOD(CopyMove_Test)
        {
            Vector a{ 5, 6, 7 };

            Vector b = a;
            Assert::AreEqual(std::string("[5, 6, 7]"), b.ToString());

            Vector c = std::move(a);
            Assert::AreEqual(std::string("[5, 6, 7]"), c.ToString());
        }
    };
}