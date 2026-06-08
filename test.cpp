#define _USE_MATH_DEFINES
#include "CppUnitTest.h"
#include "/Users/archi/source/repos/задание 2//Point.h"
#include "/Users/archi/source/repos/задание 2//Sphere.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
    TEST_CLASS(PointTests)
    {
    public:

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

        TEST_METHOD(Point_Compare_Test)
        {
            Point p1(0, 0, 0);
            Point p2(1, 0, 0);

            Assert::IsTrue(p1 < p2);
        }
    };

    TEST_CLASS(SphereTests)
    {
    public:

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

        TEST_METHOD(Sphere_ToString_Test)
        {
            Sphere s(Point(1, 2, 3), 5);

            std::string result = s.ToString();

            Assert::IsTrue(result.find("Sphere") != std::string::npos);
            Assert::IsTrue(result.find("radius") != std::string::npos);
        }
    };
}