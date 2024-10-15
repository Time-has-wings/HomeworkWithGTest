#include <iostream>
#include "../../include/ch4_homework/MyArray.h"

int main()
{
    // 使用默认构造函数
    MyArray array1;
    std::cout << "Default constructed array length: " << array1.length() << std::endl;

    // 使用带参数构造函数
    MyArray array2(5);
    std::cout << "Parameterized constructed array length: " << array2.length() << std::endl;

    // 设置元素值
    for (int i = 0; i < array2.length(); ++i)
    {
        array2.get(i) = i * 10;
    }

    // 访问元素值
    std::cout << "Array2 elements: ";
    for (int i = 0; i < array2.length(); ++i)
    {
        std::cout << array2.get(i) << " ";
    }
    std::cout << std::endl;

    // 使用拷贝构造函数
    MyArray array3(array2);
    std::cout << "Copy constructed array length: " << array3.length() << std::endl;

    // 访问拷贝构造的元素值
    std::cout << "Array3 elements (copied from array2): ";
    for (int i = 0; i < array3.length(); ++i)
    {
        std::cout << array3.get(i) << " ";
    }
    std::cout << std::endl;

    // 使用移动构造函数
    MyArray array4(std::move(array2));
    std::cout << "Move constructed array length: " << array4.length() << std::endl;
    std::cout << "Array2 length after move: " << array2.length() << std::endl;

    // 使用拷贝赋值运算符
    MyArray array5;
    array5 = array3;
    std::cout << "Copy assigned array length: " << array5.length() << std::endl;

    // 访问拷贝赋值的元素值
    std::cout << "Array5 elements (copied from array3): ";
    for (int i = 0; i < array5.length(); ++i)
    {
        std::cout << array5.get(i) << " ";
    }
    std::cout << std::endl;

    // 使用移动赋值运算符
    MyArray array6;
    array6 = std::move(array3);
    std::cout << "Move assigned array length: " << array6.length() << std::endl;
    std::cout << "Array3 length after move: " << array3.length() << std::endl;

    return 0;
}