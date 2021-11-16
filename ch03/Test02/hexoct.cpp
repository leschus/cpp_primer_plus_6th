// hexoct.cpp -- display values in hex and octal
#include <iostream>

int main(void)
{
	using namespace std;

	int a = 10;
	int b = 010;
	int c = 0x10;

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	cout << endl;

	// 告诉cout以8进制格式输出整数
	cout << oct;
	cout << b << endl;

	// 告诉cout以16进制格式输出整数
	cout << hex;
	cout << c << endl;

	// 实际上仍可以声明名为hex, oct的变量，只是变量声明后，无法再用类似cout<<hex来改变cout输出数值的进制了
	// 因为此时hex变成了变量名，cout<<hex将输出相应的变量中的值。
	// 具体为什么仍可以将hex, oct用作变量名而不报名字冲突错误，原因待查
		/*{
		// 由于名字空间std中定义了hex, oct标识符，因此不能再将hex, oct用作变量名
		int hex = 1, oct = 2; // 报错
		cout << hex << ", " << oct << endl;
		}

		// 告诉cout以8进制格式输出整数
		cout << oct;
		cout << b << endl;

		// 告诉cout以16进制格式输出整数
		cout << hex;
		cout << c << endl;

		*/
}