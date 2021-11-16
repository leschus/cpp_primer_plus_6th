#include <iostream>
#include "golf.h"

// 非交互版本
void setgolf(golf &g, const char *name, int hc)
{
	int i=0;
	// while循环按序拷贝name中的字符到g.fullname中
	// 当字符串name的长度超过Len-1时, 将只拷贝前Len-1个字符至
	// g.fullname中, 多出的字符被截断
	while (i < Len - 1 && name[i])
	{
		g.fullname[i] = name[i];
		i++;
	}
	g.fullname[i] = '\0';

	g.handicap = hc;
}

// 交互版本
int setgolf(golf &g)
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "Enter the fullname: " << endl;
	char name[Len];
	char next;
	cin.get(name, Len);
	if(cin) // true, 说明没有输入空行
	{
		cin.get(next);
		//if(next == '\n') // 下一个字符为换行符, 说明输入的字符串长度没有超过Len-1
		//{
			//cout << "Enter the handicap: " << endl;
			//int hd;
			//cin >> hd;

			//setgolf(name, golf); // 调用非交互版本的setgolf()
		//}
		while(next != '\n') // 丢弃缓冲区中可能存在的剩余字符
		{
			cin.get(next);
		}

		cout << "Enter the handicap: " << endl;
		int hc;
		cin >> hc;
		
		setgolf(g, name, hc); // 调用非交互版本的setgolf()

		cin.get(next); // 有必要加上这句, 因为输入hc之后换行符留在缓冲区, 会导致下次设置name时读到
						// 该换行符继而仍未用户输入了空串导致函数直接返回0结束
		//if(next == '\n')
			//cout << "yes\n";

		return 1;
	}

	//cin.get(next); // 至于这里就没必要加这句了, 因为cin.get(char*, int)读到空行之后, 程序的逻辑也就结束了
					// 如果说不看程序逻辑, 后续要继续使用cin处理输入的话, 这里就需要添加该句, 且要用cin.clear()
					// 重置输入流
	//if(next == '\n')
		//cout << "yes\n";
	
	return 0; // 当name是空字符串时, 返回0
}

// 修改结构的handicap成员
void handicap(golf &g, int hc)
{
	g.handicap = hc;
}

// 打印结构变量的内容
void showgolf(const golf &g)
{
	std::cout << g.fullname << ": " << g.handicap << std::endl;
}