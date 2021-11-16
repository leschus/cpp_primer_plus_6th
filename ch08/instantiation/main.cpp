#include <iostream>

#include "header.h"

using namespace std;

int main()
{
	int ia = 10, ib = 20;
	Swap<int>(ia, ib);

	cout << "ia: " << ia << ", ib: " << ib << endl;
}

/*
	测试：
		编译命令：g++ main.cpp
		出错信息：“undefined reference to `void Swap<int>(int&, int&)'
					collect2.exe: error: ld returned 1 exit status”
		
		不知道是不是多文件编译不能简单地使用`g++ main.cpp`进行编译
		还是这种显式实例化模板的方式本身仍不能够解决模板分离编译的问题

		==> 待解决...
*/