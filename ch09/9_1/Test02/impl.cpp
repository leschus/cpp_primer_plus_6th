/*
	为头文件中的函数提供实现
*/
#include "defs.h"

int add(int a, int b)
{
	return a + b;
}

Cube::Cube(int e): edge(e) {

}

int Cube::getVolume() {
	return edge * edge * edge;
}

// 由于模板函数(类)不能分离编译，因此模板的声明和定义需要一起放在头文件中
// 而不是仅将模板声明放在头文件中，而将模板定义放在cpp文件中
// 听说如果编译器支持局部编译模式，则引入export关键字将能解决上述无法分离编译的问题（待验证）
//export template <typename T>
//void my_swap(T &a, T &b)
//{
	//T temp;
	//temp = a;
	//a = b;
	//b = temp;
//}

// 又听说使用模板的显式实例化可以解决上面的不能分离编译的问题
// 经测试还是不行
//template <typename T>
//void my_swap(T &a, T &b)
//{
	//T temp;
	//temp = a;
	//a = b;
	//b = temp;
//}
