// 在C++文件中使用C语言函数

#include <iostream>
using namespace std;

// 按照C语言约定查询sum()函数的符号表示
extern "C" int sum(int a, int b);

int main()
{
	int ia, ib;
	cout << "input two ints: \n";
	cin >> ia >> ib;

	cout << "Sum of " << ia << " and " << ib << ": "
		 << sum(ia, ib) << endl;
}

/*
	测试过程:
		编译时,不能直接使用命令: g++ main.cpp c_func.c
		会找不到sum()的定义
	
		正确的编译方式(应该不是最简的):
			* 先编译c_func.c得到目标文件(c_func.o)
			* 再编译main.cpp同时链接c_func.o

			* 命令如下:
				* g++  -c c_func.c			// 告诉编译器只编译不链接, 生成.o文件
				* g++ main.cpp c_func.o		
		
*/