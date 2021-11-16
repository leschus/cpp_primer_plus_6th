// C++11支持自动推导类型auto

// 初始化声明时，若使用类型auto，则无需特地指定变量类型，编译器将把变量的类型自动设置成和初始值相同

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	auto x = 10;	// int
	auto y = 1.0;	// double
	auto z = 3.14L;	// long double


	auto fract = 8.25f/2.5;
	cout << sizeof(fract) << endl;	// 8, 说明fract被auto设置为double类型，符合预期
	cout << sizeof(float) << " " << sizeof(double) << " " << sizeof(long double) << endl; // 4 8 16

	vector<double> scores;
	// 使用auto避免书写过长的类型名
	auto pv = scores.begin(); // 不再需要写vector<int>::iterator pv = scores.begin();   // :)
}