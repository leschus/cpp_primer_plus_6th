#include "header.h"

// ����Swapģ��Ķ���
template <typename T> void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}