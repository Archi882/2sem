#define _USE_MATH_DEFINES
#include "CppUnitTest.h"
#include "/Users/archi/source/repos/задание 2//Point.h"
#include "/Users/archi/source/repos/задание 2//Sphere.h"
#include <sstream>
#include <string>
#include <stdexcept>
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
    TEST_CLASS(PointTests)
    {
    public:

        // --- Конструкторы ---

        TEST_METHOD(Point_DefaultConstructor_Test)
        {
            Point p;
            Assert::AreEqual(0.0, p.GetX(), 0.0001);
            Assert::AreEqual(0.0, p.GetY(), 0.0001);
            Assert::AreEqual(0.0, p.GetZ(), 0.0001);
        }

        TEST_METHOD(Point_ParameterizedConstructor_Test)
        {
            Point p(1.0, 2.0, 3.0);
            Assert::AreEqual(1.0, p.GetX(), 0.0001);
            Assert::AreEqual(2.0, p.GetY(), 0.0001);
            Assert::AreEqual(3.0, p.GetZ(), 0.0001);
        }

        // --- Геттеры ---

        TEST_METHOD(Point_GetX_Test)
        {
            Point p(7.5, 0.0, 0.0);
            Assert::AreEqual(7.5, p.GetX(), 0.0001);
        }

        TEST_METHOD(Point_GetY_Test)
        {
            Point p(0.0, -2.5, 0.0);
            Assert::AreEqual(-2.5, p.GetY(), 0.0001);
        }

        TEST_METHOD(Point_GetZ_Test)
        {
            Point p(0.0, 0.0, 42.0);
            Assert::AreEqual(42.0, p.GetZ(), 0.0001);
        }

        // --- Операторы сравнения ---

        TEST_METHOD(Point_Equality_Test)
        {
            Point p1(1, 2, 3);
            Point p2(1, 2, 3);
            Assert::IsTrue(p1 == p2);
        }

        TEST_METHOD(Point_Inequality_Test)
        {
            Point p1(1, 2, 3);
            Point p2(3, 2, 1);
            Assert::IsTrue(p1 != p2);
        }

        // --- Оператор вывода ---

        TEST_METHOD(Point_Output_Test)
        {
            Point p(1.5, 2.5, 3.5);
            std::ostringstream os;
            os << p;
            Assert::AreEqual(std::string("1.5 2.5 3.5"), os.str());
        }

        // --- Оператор ввода ---

        TEST_METHOD(Point_Input_Test)
        {
            std::istringstream is("4 5 6");
            Point p;
            is >> p;
            Assert::AreEqual(4.0, p.GetX(), 0.0001);
            Assert::AreEqual(5.0, p.GetY(), 0.0001);
            Assert::AreEqual(6.0, p.GetZ(), 0.0001);
        }
    };

    TEST_CLASS(SphereTests)
    {
    public:

        // --- Конструктор ---

        TEST_METHOD(Sphere_Constructor_Valid_Test)
        {
            Sphere s(Point(1, 2, 3), 5.0);
            Assert::AreEqual(5.0, s.GetRadius(), 0.0001);
            Assert::AreEqual(1.0, s.GetCenter().GetX(), 0.0001);
            Assert::AreEqual(2.0, s.GetCenter().GetY(), 0.0001);
            Assert::AreEqual(3.0, s.GetCenter().GetZ(), 0.0001);
        }

        TEST_METHOD(Sphere_Constructor_InvalidRadius_Test)
        {
            Assert::ExpectException<std::invalid_argument>([]()
            {
                Sphere s(Point(0, 0, 0), -1.0);
            });
        }

        // --- Геттеры ---

        TEST_METHOD(Sphere_GetCenter_Test)
        {
            Sphere s(Point(1, 2, 3), 1.0);
            Point c = s.GetCenter();
            Assert::AreEqual(1.0, c.GetX(), 0.0001);
            Assert::AreEqual(2.0, c.GetY(), 0.0001);
            Assert::AreEqual(3.0, c.GetZ(), 0.0001);
        }

        TEST_METHOD(Sphere_GetRadius_Test)
        {
            Sphere s(Point(0, 0, 0), 2.5);
            Assert::AreEqual(2.5, s.GetRadius(), 0.0001);
        }

        // --- Площадь и объем ---

        TEST_METHOD(Sphere_SurfaceArea_Test)
        {
            Sphere s(Point(0, 0, 0), 1);
            double expected = 4.0 * M_PI;
            double actual = s.SurfaceArea();
            Assert::AreEqual(expected, actual, 0.0001);
        }

        TEST_METHOD(Sphere_Volume_Test)
        {
            Sphere s(Point(0, 0, 0), 1);
            double expected = (4.0 / 3.0) * M_PI;
            double actual = s.Volume();
            Assert::AreEqual(expected, actual, 0.0001);
        }

        // --- Строковое представление ---

        TEST_METHOD(Sphere_ToString_Test)
        {
            Sphere s(Point(1, 2, 3), 5);
            std::string result = s.ToString();
            Assert::IsTrue(result.find("Sphere") != std::string::npos);
            Assert::IsTrue(result.find("radius") != std::string::npos);
        }

        // --- Чтение из потока ---

        TEST_METHOD(Sphere_Read_Test)
        {
            std::istringstream is("1 2 3 4");
            Sphere s = Sphere::Read(is);
            Assert::AreEqual(1.0, s.GetCenter().GetX(), 0.0001);
            Assert::AreEqual(2.0, s.GetCenter().GetY(), 0.0001);
            Assert::AreEqual(3.0, s.GetCenter().GetZ(), 0.0001);
            Assert::AreEqual(4.0, s.GetRadius(), 0.0001);
        }

        TEST_METHOD(Sphere_Read_Invalid_Test)
        {
            std::istringstream is("abc");
            Assert::ExpectException<std::runtime_error>([]()
            {
                // создаём поток внутри лямбды, т.к. он не копируется
                std::istringstream bad("abc");
                Sphere::Read(bad);
            });
        }

        // --- Оператор вывода ---

        TEST_METHOD(Sphere_Output_Test)
        {
            Sphere s(Point(0, 0, 0), 1);
            std::ostringstream os;
            os << s;
            Assert::IsTrue(os.str().find("Sphere") != std::string::npos);
        }
    };
}
