// C++支持内联函数
// 可以将代码量较小但执行频率高的函数声明为内联函数
// 从而可以避免频繁调用造成的时间开销
// 但相应地，内联函数的使用将增加程序的内存开销
// 因为每一个调用处都需要保存一份内联函数的代码副本

#include <iostream>

// declare a inline function
inline double square(double x) { return x * x;}

int main()
{
	using namespace std;
	double a, b;
	double c = 13.0;
	
	a = square(5.0);
	b = square(4.5 + 7.5); // can pass expessions
	
	// 关于cout输出的格式化技巧，还有一些不熟悉
	////cout << fixed;
	//cout.precision(2);
	////cout.setf(ios_base::showpoint);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	cout << "c = " << c << endl;
	cout << "c suqared = " << square(c) << endl;

	double x = 1.120;
	cout << "x = " << x << endl;
}
