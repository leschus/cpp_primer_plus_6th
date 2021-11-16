// 测试
// 使用cin读取输入碰到换行符后，读取结束，换行符是否停留在输入缓冲区中

#include <iostream>

int main(void)
{
	using namespace std;

	const int Size = 20;

	char str1[Size];
	char str2[Size];

	cout << "Input str1: \n";
	cin >> str1;

	cout << "Input str2: \n";
	cin >> str2;

	cout << "str1: " << str1 << endl
		 << "str2: " << str2 << endl;

}