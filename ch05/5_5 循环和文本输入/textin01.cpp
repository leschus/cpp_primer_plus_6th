// 任务内容：逐字符地读取来自文件或键盘地文本输入
//           将字符反显在屏幕上

// * 使用原始的cin进行输入，以特定字符'#'作为结束标记

#include <iostream>

using namespace std;

int main()
{
	int count = 0; // 统计处理了多少个字符
	char ch;
	

	while(1) // 程序会一直循环，除非使用Ctrl-C退出
	{
		cout << "----------------------------------\n";
		cout << "Enter characters; enter # to stop:\n";
		// cout << "count: " << count << endl;
		cin >> ch; // 接收第一个字符
		while(ch != '#') // 遇到'#'则退出循环
		{
			cout << ch; // 回显
			count ++; // 计数量加1
			cin >> ch; // 处理下一个字符
		}

		cout << endl << count << " characters read.\n";
		count = 0; // count归零
	}


/*
	测试结果：
		----------------------------------
		Enter characters; enter # to stop:
		12345 678#91							// 输入了12345 678#91
		12345678
		8 characters read.
		----------------------------------
		Enter characters; enter # to stop:
		9112#									// 输入了12#
		12
		4 characters read.
		----------------------------------
		Enter characters; enter # to stop:
	可以看出，cin忽略了空白字符，导致回显和实际输入有偏差
	另外，第一次输入的'#'后剩余的字符会留待第二轮循环时被处理（不包括换行符），
	从而导致第二次输入虽然只输入了有效字符12却被认为读取了4个字符
*/
}