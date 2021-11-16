// 4.2 字符串

/*
	1、C风格字符串
		* 以空字符\0结尾的char数组
		* 常用声明与初始化方式:
			char str[] = "abcdefg";
			即，使用字符串常量来初始化，字符数组长度由编译器自行计算（[]留空）
		* 任意两个由空白字符分隔的字符串常量都将自动拼接成一个
			"Hello, " "World!" ==(等价于)== "Hello, World!"
		
	2、基于string类库的字符串
*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	// strlen()和sizeof()作用于C字符串时的区别
	// 前者计算得到的是字符数组中存储的字符串的长度（不包含空字符\0）
	// 后者是得到字符数组所占的字节数
	const int Size = 15;
	char name[Size] = "Leschus";
	
	cout << strlen(name) << endl;	// 7
	cout << sizeof(name) << endl;	// 15

	char name2[Size];
	// 从控制台获取用户输入的字符串用于初始化C字符串
	cout << "What's your name?\n";
	cin >> name2; // 仅支持用户输入一个单词，如"Bob"；输入多个单词将会出问题
	//cin.get(); // 测试发现，cin读取输入后也会把换行符残留在输入缓冲区中
	cout << "Hello, " << name2 << ".\n";

	//	使用cin获取用户输入有一个弊端：遇到空白字符（空格、制表符、换行符）
	// 就会结束。这导致cin只能获取一个单词而非一个词组或句子
	
	//	有效获取包含空格的字符串时，需要使用getline()或者get()，它们每次
	// 读取一行输入

	// cin.getline()
	// 遇到换行符时结束，从而可以读取一行
	//		getline()接收两个参数：		
	//			参数1：用于保存输入字符串的数组名
	//			参数2：要读取的字符数。
	//		getline()在读取到给定的字符数或者遇到换行符之后，停止读取
	char name3[Size];
	cout << "What's your name?\n";
	cin.getline(name3, Size); // 可以读取多个单词，如"Micheal Jackson"
	cout << "Hello, " << name3 << ".\n";

	//	getline()读取到换行符并停止读取后，不会将换行符保存到字符数组中，而
	// 是将换行符替换为空字符，作为C字符串的结束标记

	// cin.get()
	//	与cin.getline()不同的是，cin.get()在和cin.getline()一样接收两个参数并
	// 读取一行输入时，碰到换行符并结束读取后把换行符留在输入缓冲区中。这会导
	// 致下一次读取时会碰到这个“残留的”换行符而误认为读到了该行的行尾
	// 解决这一现象的方法是，使用不带参数的cin.get()，用它来读取缓冲区中的那
	// 个残留的换行符后，在接着用cin.get()读取新的一行

	char name4[Size];
	char homeland[Size];
	cout << "What's your name?\n";
	cin.get(name4, Size);
	cin.get(); // 读取残留在输入缓冲区中的换行符
	cout << "Where is you homeland?\n";
	cin.get(homeland, Size);
	cout << "Hello, " << name4 << ", so you're from " << homeland << ".\n";

	// 可以使用cin.get(name4, Size).get();的拼接方式简化代码，
	// 原理在于cin.get()函数返回一个cin对象，可继续对它调用get()方法

}