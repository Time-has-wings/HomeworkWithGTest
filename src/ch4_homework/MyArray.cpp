
#include "../../include/ch4_homework/MyArray.h"
#include <iostream>
using namespace std;

MyArray::MyArray(int size) : size(size), p(new int[size]) { cout << "MyArray constructor" << endl; }

MyArray::MyArray(const MyArray &old) : size(old.size), p(new int[size])
{
	for (int i = 0; i < size; i++)
	{
		p[i] = old.p[i];
	}
	cout << "MyArray copy constructor" << endl;
}

MyArray &MyArray::operator=(const MyArray &rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	delete[] p;
	size = rhs.size;
	*(const_cast<int **>(&p)) = new int[size];
	for (int i = 0; i < size; i++)
	{
		p[i] = rhs.p[i];
	}
	cout << "MyArray operator=" << endl;
	return *this;
}

MyArray::MyArray(MyArray &&old) noexcept : size(old.size), p(old.p)
{
	old.size = 0;
	*(const_cast<int **>(&old.p)) = nullptr;
	cout << "MyArray move constructor" << endl;
}

MyArray &MyArray::operator=(MyArray &&rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	delete[] p;
	size = rhs.size;
	*(const_cast<int **>(&p)) = rhs.p;
	rhs.size = 0;
	*(const_cast<int **>(&rhs.p)) = nullptr;
	cout << "MyArray move=" << endl;
	return *this;
}

MyArray::~MyArray()
{
	delete[] p;
	cout << "MyArray destructor" << endl;
}

int MyArray::length()
{
	return size;
}

int &MyArray::get(int index)
{
	return p[index];
}