#include <iostream>

using namespace std;

// 检测各种输入方式，能够正确处理“读取一个字母到一个int变量中”的情况

/*
	测试了三种输入方式（首先，ch都被声明为int型）：
		1、cin >> ch;
		2、cin.get(ch);
		3、ch = cin.get(); 
*/

int main()
{
	int ch = 1;

	//cin.get(ch); // 不可行，编译不通过
	//ch = cin.get(); // 可行，保存在int变量中的是字母的ASCII值
	cin >> ch; // 不可行，无论读取到什么字母，ch最终的值都为0，且failbit被置1，导致后续无法再读取输入流
	cout << ch << endl;
	cout << cin.eof() << ", " << cin.fail() << endl;
}