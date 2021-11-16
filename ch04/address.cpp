// 使用&取地址运算符获取变量的地址

#include <iostream>

using namespace std;

int main()
{
	int donuts = 6;
	double cups = 2.7;

	cout << "value of donuts: " << donuts
		 << ", and it's address: " << &donuts << endl;
	// 输出结果：“value of donuts: 6, and it's address: 0x61fe1c”
	// 结果表明，cout自动将地址以16进制格式输出了

	cout << "value of cups: " << cups
		 << ", and it's address: " << &cups << endl;
	// 输出结果：“value of cups: 2.7, and it's address: 0x61fe10”
	// 结果表明，cout自动将地址以16进制格式输出了
	// 另外，两者的地址值相差12，可见分配内存时并没有将两个变量分配在相邻的空间
	// （如果两者相邻，其地址应该相差4或者8）

}