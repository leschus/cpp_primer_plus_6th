// C++ 将内容输出到文本文件

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream fout;
	fout.open("111.txt"); // open()函数接收一个C风格字符串作为参数，它可以是字面值，也可以是一个字符数组

	double wt = 21.8;
	fout << wt;
	char line[81] = "Objects are closer than they appear.";
	fout << line << endl;

	fout.close(); // 务必记得open()和close()配套使用
}