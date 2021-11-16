// using编译指令和using声明的区别

#include <iostream>
using namespace std;

namespace Jill
{
	double bucket(double n) { return n;}

	double fetch;

	struct Hill
	{
		int top, bottom;
	};
}

char fetch; // 位于全局名称空间中

int main()
{
	//using namespace Jill;

	////cin >> fetch; // 会报错, 编译器分不清这里是::fetch还是Jill::fetch

	//double fetch; // 不会报错,相当于函数内局部变量fetch隐藏了Jill::fetch
	//cin >> fetch; // 写数据到函数内局部变量fetch而非Jill::fetch
	//cin >> ::fetch; // 写数据到全局名称空间中的fetch (char类型)
	//cin >> Jill::fetch; // 写数据到Jill名称空间中的fetch


	using Jill::fetch;

	cin >> fetch;	// 不会报错, 相当于Jill::fetch隐藏了::fetch
	cout << fetch;
}