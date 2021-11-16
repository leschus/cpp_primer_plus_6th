// 在switch中使用枚举量

#include <iostream>
using namespace std;

enum {red = 1, blue, orange};

int main()
{
	int choice;
	cout << "enter 1~3 to choose a color. q/Q to quit\n";
	cin >> choice;

	// 下面两行用于测试如果输入一个字母而非数字会出现什么情况，
	// 结果显示，cin在本该读取数字的时候读取到一个字母会导致failbit位置1，且无论读取到什么字母，
	// 实际效果都相当于读到了一个数字0
	//cout << cin.fail() << endl; // 输出 1
	//cout << choice << endl; // 输出 0
	
	while(choice != 'q' && choice != 'Q')
	{
		switch(choice)
		{
			case red:
				cout << "red\n";
				break;
			case blue:
				cout << "blue\n";
				break;
			case orange:
				cout << "orange\n";
				break;
			default:
				cout << "not a choice\n";
		}
		cout << "enter 1~3 to choose a color. q/Q to quit\n";
		cin >> choice;
	}
	cout << "bye!\n";

}