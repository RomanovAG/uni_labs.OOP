#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "D:\Labs\OOP\lab2\conchoidnicomed.h"
//#include "D:/Labs/OOP/build-lab2_lib-Desktop_Qt_5_15_1_MinGW_32_bit-Debug/liblab2_lib.a"

using namespace testing;

TEST(lab2_tests, defaultConstructor)
{
    ConchoidNicomed a;
    ASSERT_DOUBLE_EQ(0, a.getL());
    ASSERT_DOUBLE_EQ(0, a.getA());
}

TEST(lab2_tests, initConstructor)
{
    ConchoidNicomed a(0);
    ASSERT_DOUBLE_EQ(0, a.getL());
    ASSERT_DOUBLE_EQ(0, a.getA());
    ConchoidNicomed b(1, 2);
    ASSERT_DOUBLE_EQ(1, b.getL());
    ASSERT_DOUBLE_EQ(2, b.getA());
    ConchoidNicomed c(0.5, -10);
    ASSERT_DOUBLE_EQ(0.5, c.getL());
    ASSERT_DOUBLE_EQ(-10, c.getA());
    ASSERT_ANY_THROW(ConchoidNicomed d(-0.01, 100));
}

TEST(lab2_tests, set)
{
    ConchoidNicomed a;
    a.setL(1.123);
    a.setA(-0.987);
    ASSERT_DOUBLE_EQ(1.123, a.getL());
    ASSERT_DOUBLE_EQ(-0.987, a.getA());
}

TEST(lab2_tests, get)
{
    ConchoidNicomed a(2.34);
    ASSERT_DOUBLE_EQ(2.34, a.getL());
    ASSERT_DOUBLE_EQ(-0, a.getA());
    ConchoidNicomed b(21.34, -32);
    ASSERT_DOUBLE_EQ(21.34, b.getL());
    ASSERT_DOUBLE_EQ(-32, b.getA());
}

TEST(lab2_tests, returnY)
{
    ConchoidNicomed a(0.5, 1);
    double y1 = 0, y2 = 0;
    double x = 0.6;
    a.returnY(x, y1, y2);
    ASSERT_DOUBLE_EQ(0.45, y1);
    ASSERT_DOUBLE_EQ(-0.45, y2);
    a.returnY(1.3, &y1, nullptr);
    ASSERT_NEAR(1.7333333, y1, 0.00001);
    ASSERT_DOUBLE_EQ(-0.45, y2);
}

TEST(lab2_tests, returnR)
{
    ConchoidNicomed a(0.5, 1);
    double r1 = 0, r2 = 0;
    a.returnR(45, &r1, &r2);
    ASSERT_NEAR(1.4036, r1, 0.001);
    ASSERT_NEAR(2.4036, r2, 0.001);
}

TEST(lab2_tests, returnCurvRads)
{
    ConchoidNicomed a(0.5, 1);
    double r_A = 0, r_C = 0, r_O = 0;
    a.returnCurvRads(r_A, r_C, r_O);
    ASSERT_DOUBLE_EQ(r_A, r_A);
    ASSERT_DOUBLE_EQ(r_C, r_C);
}

TEST(lab2_tests, returnArea)
{
    ConchoidNicomed a(0.5, 1);
    ConchoidNicomed b(1.5, 1);
    ASSERT_NEAR(0, a.returnArea(), 0.01);
    ASSERT_NEAR(0.1232, b.returnArea(), 0.01);
}

TEST(lab2_tests, returnIP)
{
    ConchoidNicomed a(0.5, 1);
    ConchoidNicomed b(1.5, 1);
    double x1 = 0;
    double x2 = 0;
    double x3 = 0;
    double x4 = 0;
    double y1 = 0;
    double y2 = 0;
    double y3 = 0;
    double y4 = 0;
    a.returnIP(&x1, &x2, &x3, &x4);
    a.returnY(x1, &y1, nullptr);
    a.returnY(x2, nullptr, &y2);
    a.returnY(x3, &y3, nullptr);
    a.returnY(x4, nullptr, &y4);
    ASSERT_NEAR(1.38, x1, 0.01);
    ASSERT_NEAR(1.38, x2, 0.01);
    ASSERT_NEAR(0.57, x3, 0.01);
    ASSERT_NEAR(0.57, x4, 0.01);
    ASSERT_NEAR(1.18, y1, 0.01);
    ASSERT_NEAR(-1.18, y2, 0.01);
    ASSERT_NEAR(0.338, y3, 0.01);
    ASSERT_NEAR(-0.338, y4, 0.01);
}
