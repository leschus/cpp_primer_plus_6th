// 任务内容：逐字符地读取来自文件或键盘地文本输入
//           将字符反显在屏幕上

// * 使用cin.get(char), 同时利用EOF来标志一次读取的结束

// cin工具会检测EOF标志，从而判断是否到达了文件尾
// 检测到EOF时，cin将两个标志位均置为1（eofbit和failbit)
// 这两个标志位可以通过cin.eof()和cin.fail()获取

// 命令行模拟EOF的方式（不同平台有差别）
//	* Windows命令行：Ctrl+Z Enter
//	* Unix命令行：Ctrl+D

#include <iostream>
using namespace std;

int main()
{
	int count = 0;
	char ch;
	
	while(1)
	{
		cout << "-----------------------------------------------\n";
		cout << "Enter characters, ended with <CTRL>+<Z><ENTER>:\n"; // 在Windows平台，使用ctrl+z和enter来模拟EOF
		cin.get(ch); // 读取第一个字符
		while(cin.fail() == false) // failbit没有被置1，说明没有读取到EOF
		{
			cout << ch; // 回显
			count ++;
			cin.get(ch); // 读取下一个字符
		}
		cout << endl << count << " characters read.\n";
		count = 0;
		//cin.get(); // 读取上一轮未处理的换行符
					 // 经测试，使用cin.get()无法阻止刷屏。书本解释说，检测EOF后将关闭对输入的进一步读取，导致后续的
					 // cin.get()，cin.get(ch)都不起效了
					 // 解决办法之一是，使用cin.clear()重置输入流
		cin.clear(); // 重置输入流
	}

	/*
		测试结果还发现一点：即Windows命令行使用Ctrl+Z Enter模拟EOF时，必须在一行的行首输入，否则将不奏效
	*/

	/*
		进一步地，优化代码的编写形式，由于cin.get(char)函数返回值是一个cin对象，而istream类提供了将istream对象（如cin）
	转换为bool值的函数。当cin出现在需要bool值的地方时，该函数将被自动调用。当cin执行的最后一次读取成功，该bool值为
	true, 否则为false。（读取到EOF意味着读取失败）
	
	因此，读取部分的循环体可以改写为：
		while(cin.get(ch))
		{
			...
		}
	*/
}