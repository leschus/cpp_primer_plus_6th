// C++ 函数重载

// 函数签名中的const

#include <iostream>
using namespace std;

void dribble(char *bits);
void dribble(const char *cbits);
void dabble(char *bits);
void drivel(const char * bits);

int main()
{
	const char p1[20] = "How's the weather?";
	char p2[20] = "How's business?";

	//	当系列重载函数中既有接收const参数的函数，也有接收非const参数的函数时
	//	如果传入参数为const类型，则匹配接收const参数的函数
	//	如果传入参数为非const类型，则匹配接收非const类型的参数（注意：这里并不会
	// 因为接收const参数的函数也允许接收非const类型，就使得这种情形下的函数匹配
	// 出现二义。应该是C++内部对这种情形下的函数匹配设定了优先级，优先寻找类型
	// 能够直接匹配上的，如若没有才去找经过类型转换可以匹配上的（毕竟，用const形参
	// 接收非const实参，算得上进行了类型转换）。
	dribble(p1);
	dribble(p2);

	//dabble(p1);// 编译不通过。无法使用非const形参接收const实参
	dabble(p2);
	
	drivel(p1);
	drivel(p2);
}

void dribble(char *bits)
{
	cout << "dribble with no const bits.\n";
}
void dribble(const char *cbits)
{
	cout << "dribble with const cbits.\n";
}
void dabble(char *bits)
{
	cout << "dabble with no const bits.\n";
}
void drivel(const char * bits)
{
	cout << "drivel with const bits.\n";
}
