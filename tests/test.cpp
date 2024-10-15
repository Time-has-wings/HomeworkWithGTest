#include <gtest/gtest.h>
#include "../include/ch4_homework/MyArray.h"
#include <iostream>
using namespace std;

// 测试 MyArray 类的带参数构造函数
TEST(MyArrayTest, ParameterizedConstructor)
{
    MyArray a(5);
    EXPECT_EQ(a.length(), 5);
}

// 测试 MyArray 类的拷贝构造函数
TEST(MyArrayTest, CopyConstructor)
{
    MyArray a(5);
    MyArray b(a);
    EXPECT_EQ(b.length(), 5); // 假设 MyArray 类有一个 length() 方法
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(a.get(i), b.get(i)); // 假设 MyArray 类有一个 operator[] 方法
    }
}

// 测试 MyArray 类的移动构造函数
TEST(MyArrayTest, MoveConstructor)
{
    MyArray a(5);
    MyArray b(std::move(a));
    EXPECT_EQ(b.length(), 5); // 假设 MyArray 类有一个 length() 方法
    EXPECT_EQ(a.length(), 0); // 移动后 a 的大小应为 0
}

// 测试 MyArray 类的拷贝赋值运算符
TEST(MyArrayTest, CopyAssignment)
{
    MyArray a(5);
    MyArray b;
    b = a;
    EXPECT_EQ(b.length(), 5); // 假设 MyArray 类有一个 length() 方法
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(a.get(i), b.get(i)); // 假设 MyArray 类有一个 operator[] 方法
    }
}

// 测试 MyArray 类的移动赋值运算符
TEST(MyArrayTest, MoveAssignment)
{
    MyArray a(5);
    MyArray b;
    b = std::move(a);
    EXPECT_EQ(b.length(), 5); // 假设 MyArray 类有一个 length() 方法
    EXPECT_EQ(a.length(), 0); // 移动后 a 的大小应为 0
}

// 测试 MyArray 类的元素访问
TEST(MyArrayTest, ElementAccess)
{
    MyArray a(5);
    for (int i = 0; i < 5; ++i)
    {
        a.get(i) = i * 10; // 假设 MyArray 类有一个 operator[] 方法
    }
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_EQ(a.get(i), i * 10); // 假设 MyArray 类有一个 operator[] 方法
    }
}

// 主函数
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}