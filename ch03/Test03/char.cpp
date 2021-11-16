//char.cpp -- C++中的字符类型

/*
	普通的char类型
		单个字节，只能够表示256中不同的字符
	扩展的wchar_t类型
		对于汉字字符等一个字节存储不下的字符，不能使用char类型
		* 使用前缀L来表示宽字符常量和宽字符串
			如L'P'和L"tall"
	char16_t和char32_t
		* 使用前缀u表示char16_t字符常量和字符串常量
		* 使用前缀U表示char32_t字符常量和字符串常量
*/

#include <iostream>

using namespace std;
int main(void)
{
	char ch = 'A'; // 普通字符类型
	cout << "sizeof char: " << sizeof(char) << endl;
	cout << ch << endl;

	wchar_t wch = L'A';
	cout << "sizeof wchar_t: " << sizeof(wchar_t) << endl;
	cout << wch << endl; // 输出65而非A
	cout.put(wch);	// 使用cout.put可以确保输出字符而非其ascii码值
	cout << endl;
	wcout << wch << endl; // 使用wcout也可以正确地输出wchar_t类型字符

	// 打印Unicode字符"中国"
	cout << "\u4e2d\u56fd" << endl; // 出现乱码：“涓浗”

	cout << "Let them eat g\u00E2teau.\n";	// 出现乱码：“Let them eat g芒teau.”
}