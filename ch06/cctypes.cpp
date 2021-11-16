// cctypes.cpp -- 使用cctype头文件中的函数

// 功能：读取键盘输入直到遇到EOF，统计读取内容中各类型字符的个数
/*
	用到的函数：
		isalpha()  是否是字母
		isdigit()  是否是数字
		ispunct()  是否是标点符号
		isspace()  是否是标准空白字符
		// iscntrl()  是否是控制字符
*/
#include <iostream>
#include <cctype> // 或者 #include <ctype.h>
using namespace std;

int main()
{
	int alphas = 0;
	int digits = 0;
	int puncts = 0;
	int spaces = 0;
	int others = 0;

	char ch;
	while(cin.get(ch))
	{
		if (isalpha(ch))
		{
			alphas ++;
		}
		else if (isdigit(ch))
		{
			digits ++;
		}
		else if (ispunct(ch))
		{
			puncts ++;
		}
		else if (isspace(ch))
		{
			spaces ++;
		}
		else 
		{
			others ++;
		}
	}

	cout << alphas << " letters, "
		 << digits << " digits, "
		 << puncts << " punctuations, "
		 << spaces << " whitespaces, "
		 << others << " others.\n";

	/*
		// output of the test		
			12345
			abcde
			,./
			\n
			^Z
			6 letters, 5 digits, 4 punctuations, 4 whitespaces, 0 others.

			it turns out that when you input '\n' in the commandline, it won't be recognised as LF/NL.
	*/


}