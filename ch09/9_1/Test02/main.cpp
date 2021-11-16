#include <iostream>
#include "defs.h"

using namespace std;

int main(void)
{
	add(1, 2);

	Point point;

	Cube cube(5);
	cout << cube.getVolume() << endl; // 125

	int a = 10, b = 5;
	my_swap(a, b);
	// my_swap<int>(a, b); // ʹ��ģ�����ʽʵ����
	cout << a << ", " << b << endl; // 5, 10

	cout << square(10) << endl; // 100

	return 0;
}
