#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "D:\Labs\OOP\lab3\binary1.cpp"
#include "D:\Labs\OOP\lab3\binary2.cpp"
#include "D:\Labs\OOP\lab3\binary3.cpp"

using namespace testing;

TEST(lab3_test, defaultConstructor)
{
    ASSERT_NO_THROW(Binary1 a);
    ASSERT_NO_THROW(Binary2 a);
    ASSERT_NO_THROW(Binary3 a);
}

TEST(lab3_test, longConstructor)
{
    ASSERT_NO_THROW(Binary1 a(1));
    ASSERT_NO_THROW(Binary2 a(2));
    ASSERT_NO_THROW(Binary3 a(3));
}

TEST(lab3_test, stringConstructor)
{
    ASSERT_NO_THROW(Binary1 a("11"));
    ASSERT_NO_THROW(Binary2 a("1.1100", true));
    ASSERT_ANY_THROW(Binary3 a("012"));
}

TEST(lab3_test, setLong)
{
    Binary1 a, b;
    ASSERT_NO_THROW(a.set(-4););
    b.set(-4);
    ASSERT_EQ(a.get(), b.get());

    Binary2 c, d;
    ASSERT_NO_THROW(c.set(12););
    d.set(12);
    ASSERT_EQ(c.get(), d.get());

    Binary3 e, f;
    ASSERT_NO_THROW(e.set(-5););
    f.set(-5);
    ASSERT_EQ(e.get(), f.get());
}

TEST(lab3_test, setString) //?
{
    Binary1 a, b;
    ASSERT_NO_THROW(a.set(-4););
    b.set(-4);
    ASSERT_EQ(a.get(), b.get());

    Binary2 c, d;
    ASSERT_NO_THROW(c.set(12););
    d.set(12);
    ASSERT_EQ(c.get(), d.get());

    Binary3 e, f;
    ASSERT_NO_THROW(e.set(-5););
    f.set(-5);
    ASSERT_EQ(e.get(), f.get());
}

TEST(lab3_test, print)
{
    Binary1 a(1);
    Binary2 b(2);
    Binary3 c(3);
    ASSERT_NO_THROW(a.print(std::cout));
    ASSERT_NO_THROW(b.print(std::cout << " "));
    ASSERT_NO_THROW(c.print(std::cout << " "));
    std::cout << "\n";
}

TEST(lab3_test, twosComplement)
{
    Binary1 a(228);
    Binary2 b(1337);
    Binary3 c(420);
    char buf[80];
    ASSERT_NO_THROW(a.twosComplement(buf, 80));
    ASSERT_NO_THROW(b.twosComplement(buf, 80));
    ASSERT_ANY_THROW(c.twosComplement(buf, 2));
}

TEST(lab3_test, add)
{
    ASSERT_EQ(666, (Binary1(333).add(Binary1(333))).get());
    ASSERT_EQ(0, (Binary2(5553535) + Binary2(-5553535)).get());
    ASSERT_EQ(-1, (Binary3(888) + Binary3(-889)).get());
}

TEST(lab3_test, preIncrement)
{
    ASSERT_EQ(666, Binary1(665).preIncrement().get());
    ASSERT_EQ(0, (++Binary2(-1)).get());
    ASSERT_EQ(-1, (++Binary3(-2)).get());
}

TEST(lab3_test, postDecrement)
{
    ASSERT_EQ(665, Binary1(665).postDecrement().get());
    ASSERT_EQ(-1, (Binary2(-1)--).get());
    ASSERT_EQ(-2, (Binary3(-2)--).get());
}

TEST(lab3_test, getSign)
{
    ASSERT_EQ(-1, Binary1(-42).getSign());
    ASSERT_EQ(1, Binary2(42).getSign());
    ASSERT_EQ(1, Binary3(-0).getSign());
}
