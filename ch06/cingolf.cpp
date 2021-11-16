// 参照书上的程序清单6.14 cingolf.cpp

// 清除缓冲区多余字符时，书上说有另一种做法：一次丢弃一个单词而不是一整行（想想怎么做？--我是暂时没想出来反正）

#include <iostream>
using namespace std;

const int Max = 5;

int main()
{
	int golf[Max];
	cout << "Please enter your golf scores.\n";
	cout << "You must enter " << Max << " rounds.\n";
	int i;
	for(i = 0; i< Max; i++)
	{
		cout << "round #" << i + 1 << ": ";
		while (!(cin >> golf[i]))
		{
			cin.clear();
			while(cin.get() != '\n') // 书上说这种方式是一次删除一行，我觉得更准确地说是一次删除一个字符，直到碰到'\n'
			{
				continue;
			}
			cout << "Plese entera number: ";
		}
	}
}
