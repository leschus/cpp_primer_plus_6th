// C++中的switch语句，用于文字菜单的设计

#include <iostream>
using namespace std;

void showmenu();

int main()
{
	int choice;

	showmenu();
	cin >> choice;

	while(choice != 5)
	{
		switch(choice)
		{
			case 1:
				cout << "\a\n";
				break;
			case 2:
				cout << "hello\n";
				break;
			case 3:
				cout << "you're beautiful\n";
				break;
			case 4:
				cout << "have a nice day\n";
				break;
			default:
				cout << "not a choice\n";
		}
		showmenu();
		cin >> choice;
	}
	
	cout << "Bye!\n";

	/*
		弊端：
		choice为int类型，因此输入为非数字（字母，标点）时会导致输入失效，进而会陷入死循环

		关于为什么会死循环，下面的内容摘自CSDN博客：
			当定义一个int变量，用cin输入时，如果输入的是一个字符，会发生以下4中情况：
			1.n的值变成0
			2.不匹配的输入被留在输入流中
			3.cin对象的一个错误标记被设置，即cin.fail()返回true
			4.对cin的方法调用返回false，即(cin>>n)返回的是false
			————————————————
			版权声明：本文为CSDN博主「乌鸦_在飞」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
			原文链接：https://blog.csdn.net/weixin_36796040/article/details/78529099
	*/
}

void showmenu()
{
	cout << "-------------------------------------------------------\n";
	cout << "input 1~4 to choose different actions. input 5 to quit.\n";
}