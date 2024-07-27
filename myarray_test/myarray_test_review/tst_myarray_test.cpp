#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include "myarray.h"

using namespace testing;
using namespace std;

TEST(myarray_test, init)
{
    MyArray<int, 3> arr1{1, 2, 3};
    MyArray<int, 3> arr2 = {1, 2, 3};
    MyArray<int, 3> arr3;
    arr3 = {1, 2, 3};
    MyArray<int, 3> arr4;
    arr4[0] = 1;
    arr4[1] = 2;
    arr4[2] = 3;

    ASSERT_EQ(arr1, arr2);
    ASSERT_EQ(arr2, arr3);
    ASSERT_EQ(arr3, arr4);
}

TEST(myarray_test, eq)
{
    MyArray<long, 4> arr1{1, 2, 3, 4};

    MyArray<long, 4> arr2 = {1, 2, 3, 4};

    MyArray<long, 4> arr3{1, 2, 3, 2};

    ASSERT_EQ(true, arr1 == arr2);

    ASSERT_EQ(false, arr2 == arr3);

    ASSERT_EQ(true, arr1 != arr3);
}

TEST(myarray_test, great_low)
{
    MyArray<float, 3> arr1 = {.1, .2, .3};
    MyArray<float, 3> arr2   {.1, .2, .31};
    MyArray<float, 3> arr3 = {.1, .19, .31};
    MyArray<float, 3> arr4 = {.1, .2, .2};

    ASSERT_EQ(true, arr1 < arr2);
    ASSERT_EQ(true, arr2 > arr3);

    ASSERT_EQ(false, arr1 < arr3);

    ASSERT_EQ(true, arr1 >= arr1);
    ASSERT_EQ(true, arr1 >= arr4);

    ASSERT_EQ(true, arr1 <= arr1);
    ASSERT_EQ(true, arr1 <= arr2);
}

TEST(myarray_test, size)
{
    MyArray<float, 3> arr1 = {.1, .2, .3};
    MyArray<float, 3> arr2   {.1, .2, .31};
    MyArray<float, 3> arr3 = {.1, .19, .31};
    MyArray<float, 3> arr4 = {.1, .2, .2};
    MyArray<short, 0> arr5;

    ASSERT_EQ(3, arr1.size());
    ASSERT_EQ(arr2.size(), arr2.max_size());
    ASSERT_EQ(false, arr3.empty());
    ASSERT_EQ(true, arr5.empty());
}

TEST(myarray_test, index)
{
    MyArray<float, 3> arr1 = {.1, .2, .3};
    MyArray<float, 3> arr2   {.1, .2, .31};
    MyArray<float, 3> arr3 = {.1, .19, .31};
    MyArray<float, 3> arr4 = {.1, .2, .2};

    ASSERT_FLOAT_EQ(arr1.at(1), arr1[1]);
    ASSERT_FLOAT_EQ(arr2.at(2), arr3[2]);

    ASSERT_ANY_THROW(arr4.at(3));
}

TEST(myarray_test, fill)
{
    MyArray<short, 5> arr1;
    arr1.fill(9);
    MyArray<short, 5> arr2{9, 9, 9, 9, 9};

    ASSERT_EQ(arr1, arr2);
}

TEST(myarray_test, swap)
{
    MyArray<float, 3> arr1 = {.1, .2, .3};
    MyArray<float, 3> arr2   {.1, .2, .31};
    MyArray<float, 3> arr3 = {.1, .19, .31};
    MyArray<float, 3> arr4 = {.1, .2, .2};

    arr1.swap(arr3);

    MyArray<float, 3> a{.1, .2, .3};
    MyArray<float, 3> b{.1, .19, .31};
    ASSERT_EQ(arr3, a);
    ASSERT_EQ(arr1, b);
}

TEST(myarray_test, front_back)
{
    MyArray<float, 3> arr1 = {.1, .21, .3};
    MyArray<float, 3> arr2   {.5, .2, .32};
    MyArray<float, 3> arr3 = {.6, .19, .31};
    MyArray<float, 3> arr4 = {.7, .2, .89};

    ASSERT_FLOAT_EQ(.1, arr1.front());
    ASSERT_FLOAT_EQ(.32, arr2.back());

    ASSERT_FLOAT_EQ(.6, *arr3.begin());
    ASSERT_FLOAT_EQ(.89, *(arr4.end() - 1));
}
