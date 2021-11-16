// 任务内容：逐字符地读取来自文件或键盘地文本输入
//           将字符反显在屏幕上

// * 使用cin.get(char)函数，以避免直接使用cin会出现的问题

#include <iostream>
using namespace std;

int main(void)
{
	int count = 0; // 计数变量
	char ch; // 作为cin.get(char)的传入参数，保存每一次读取到的字符

	while(1)
	{
		cout << "----------------------------------\n";
		cout << "Enter characters; enter # to stop:\n";
		cin.get(ch);
		while(ch != '#')
		{
			cout << ch;
			count ++;
			cin.get(ch);
		}
		
		cout << endl << count << " characters read.\n";
		count = 0; // count归零
	}

	/*
		
		结果分析：
			----------------------------------
			Enter characters; enter # to stop:
			12345 678#91
			12345 678
			9 characters read.
			----------------------------------
			Enter characters; enter # to stop:
			91
			12#
			12
			5 characters read.
			----------------------------------
			Enter characters; enter # to stop:

		可以看到，cin.get(char)不再会跳过空白字符，使得第一次输入的回显结果是正确的（在'#'结束）
		但是，仍然存在前一次输入多余的字符会残留在缓冲区的问题，导致下一轮处理时程序会认为接收到了
		比实际上输入的字符更多的字符（第二轮只输入了12#，却被认为读入了5个字符，因为其中三个是上一
		轮剩余的，它们分别是'9', '1', '\n'）
	*/
	
}