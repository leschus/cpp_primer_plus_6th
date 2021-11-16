#include "header.h"

// 给出Swap模板的定义
template <typename T> void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}