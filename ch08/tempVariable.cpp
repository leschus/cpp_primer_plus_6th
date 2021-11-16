#include <iostream>

using namespace std;

int do_something(int &r)
//int & do_something(int &r)
{
	return r;
}

void increase(int &x)
{
	x++;
}

int main()
{
	int a = 1;
	cout << "a = " << a << ", at " << &a << endl;
	
	// 当修改了do_something()的返回值为引用类型之后，下面语句无法编译通过
	// 因为修改之后do_something(a)的返回值是变量a的引用，是一个左值，无法
	// 将它赋给一个右值引用rref
	int &&rref = do_something(a); // rref是一个右值引用
	cout << "rref = " << rref << ", at " << &rref << endl;

	/*
		  测试结果：
			a = 1, at 0x61fe10
			rref = 1, at 0x61fe14
		  结果显示，rref的地址和a的地址不相同，说明main()在使用do_something()函数的
		返回值的时候，使用的是系统自动创建的一个变量a的副本
		  并不能因为do_something()函数的形参r是a的引用，且直接返回了r，就认为后续main()
		使用do_something()的返回值就是在使用a的一个引用。实际上这期间系统创建了一个匿名
		临时变量用于存储do_something()的返回值，而该临时变量只是值和a相同，但已经是两个
		不同的变量了。

		  如果要修改do_something()使得main()调用do_something()得到的返回值是a的引用而非
		 一个匿名临时变量，需要将函数返回类型声明为引用类型，即int &
		  从而函数原型为：
		  	int & do_something(int &r);
		
	*/
	
	// 当do_something()的返回类型为引用时，下述语句才能编译通过
	/*
		出错信息：
			tempVariable.cpp:42:23: error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
			increase(do_something(a));
		           ~~~~~~~~~~~~^~~
			tempVariable.cpp:10:6: note:   initializing argument 1 of 'void increase(int&)'
			 void increase(int &x)
	*/
	//increase(do_something(a));
	//cout << "a = " << a << ", at " << &a << endl;

}