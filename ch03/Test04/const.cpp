//const.cpp -- c++中的const 限定符

/* const用于定义符号常量，相比于C中的#define方式，使用const定义常量有以下优势：
	1、const能够明确指出常量的数据类型
	2、使用C++的作用域规则可以将const常量作用范围限制在特定的函数或文件范围中
	3、可以定义更复杂类型的常量，如常量数组

	* 务必在声明时同时初始化常量
*/


#include <iostream>
using namespace std;

int main()
{
	const int Length = 10; // 命名技巧：首字母大写，或者全部大写（类似#define的命名特点）
	const char China[5] = "中国"; // const声明常量字符数组（数组内容不可变更）
									// 另外，这里数组长度为5，因为每个汉字占两个字节，一个字符串结束符'\0'占一个字节，共需五字节
	const int Numbers[3] = {1, 2, 3}; // 常量整型数组
	cout << China << endl;
	cout << Numbers[0] << ", " << Numbers[1] << ", " << Numbers[2] <<endl;
		
	char str[Length]; // 可以使用const值声明数组长度（C++支持，C不支持）


}