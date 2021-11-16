// C++中的逗号运算符

/* 
	1、用于将两个或更多的表达式放在一个for循环表达式中
		int i, j;
		for(i=0, j=1; i< 10; i++, j--){...}
	2、由逗号运算符组合起来的多个表达式在被计算时，总是从左向右计算
		这里的逗号被称作一个“顺序点”
		int a = 1, b = a * 2;

*/

#include <iostream>
using namespace std;

int main(void)
{
	int a = 1, b = a * 2; // 先将a初始化为1，再将b初始化为a的两倍，即2
	cout << a << ", " << b << endl;	

	int c;
	c = a, b, a + b; // 由于运算符优先级，这相当于`(c = a), b, a + b;`，因此结果c的值等于a的值
	cout << c << endl; // 1
	c = (a, b, a + b);
	cout << c << endl; // 3，这说明逗号表达式的值是最后一个表达式的值
}