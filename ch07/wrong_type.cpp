#include <iostream>
using namespace std;

int square(int x);

int main(void)
{
	double d;
	cout << "Input a double: ";
	cin >> d;
	
	int result = square(d);
	cout << "result: " << result << endl;
	return 0;
}

int square(int x)
{
	cout << "square() get param: " << x << endl;
	return x * x;
}

/*
	测试结果
		Input a double: 2.5
		square() get param: 2
		result: 4
	结果表明，C++函数在处理类型不符的传入参数时，会正确地进行强制类型转换
	如浮点数2.5被正确取整为2

	注意：转换正确的前提是两者都是算术类型

	但这种自动类型转换并不总能解决所有类型不匹配的情况。如将一个值超出INT_MAX的
	浮点数传给函数square()，将无法正确地进行取整，有时在编译阶段会出现警告。
	---这种类型检查称之为“静态类型检查（static type checking）”
*/