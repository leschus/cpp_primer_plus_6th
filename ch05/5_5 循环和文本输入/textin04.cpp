/*
	接textin03.cpp
	
	C++ cin对象有一个和C中getchar()函数相同工作方式的成员函数，即cin.get()。
	在使用ch = cin.get()替换cin.get(ch)时，大多数情况是没差别的；但在处理EOF条件时，cin.get()返回的字符没有可以和
	EOF对应的。C++的处理方式是，cin.get()会返回一个用符号常量EOF表示的特殊值，该值不等于任何一个有效的字符值。因此，
	通常将该值设置为-1，因为ASCII中不存在-1的值。这也导致声明变量ch时需要用int类型，而不是char类型。这是为了避免
	有些系统中char类型默认是没有符号的，从而无法将非负值ch和定义为-1的符号常量EOF划等号。例子如下：
		char ch; // 某些系统中，char类型默认为unsigned char
		ch = cin.get(); // 当碰到EOF条件时，cin.get()返回符号常量EOF代表的值，通常为-1，这意味着值为-1的int字面值被
						// 赋给unsigned char变量ch，ch的值将等于255
		while(ch != EOF) // 此时，循环进入条件ch != EOF由于执行的是unsigned char和int的比较，执行自动类型转换时将ch
						 // 提升为int类型，unsigned char类型的255变为int类型的255, 和int类型的EOF（值为-1）比较，当
						 // 然结果是不等于，从而循环仍会进入。达不到“碰到EOF条件则停止处理输入”的效果
		{
			...
		}
	相反，如果将ch定义为int类型，则语句ch = cin.get()和表达式ch != EOF都不会有隐式类型转换，从而在遇到EOF条件时ch被
	正确赋值为-1，在执行循环条件判断时顺利退出循环。
		
*/

#include <iostream>
using namespace std;

int main()
{
	char ch;
	ch = cin.get();  // 这里输入Ctrl+Z Enter模拟EOF条件
	cout << (ch & 0xff) << endl;  // 输出255，说明ch的二进制表示为1000 0000
	cout << (EOF & 0xff) << endl; // 输出255，说明EOF的二进制表示也为1000 0000

	cout << ch << endl; // 无输出，这意味着没有对应的ASCII字符或者是不可打印字符？
	cout << (int)ch << endl; // 强制转换为int类型输出为-1
	cout << EOF << endl; // 输出-1，说明EOF值为-1
	bool flag = (ch == EOF); // flag为true，说明ch和EOF比较时，ch执行自动类型转换得到的是值为-1的int值而非值为255
							 // 这可以解释为，本机的char类型默认为signed char，而signed char提升为int类型时，执行
							 // 的是符号扩展；而unsigned char提升为int类型时，执行的是无符号拓展							 
	cout << flag << endl;

	cout << "-------------------------------------------------\n";

	// 验证以下上面关于有符号/无符号扩展的推测
	signed char ch01 = 0xff;
	unsigned char ch02 = 0xff;
	char ch00 = 0xff;
	cout << (int)ch01 << ", " << ((int)ch01 & 0xffffffff) << endl; // 预期输出：-1, 4294967295
	cout << (int)ch02 << ", " << ((int)ch02 & 0xffffffff) << endl; // 预期输出：255, 255
	cout << (int)ch00 << ", " << ((int)ch00 & 0xffffffff) << endl; // 预期输出：-1, 4294967295
	/*
		实际输出符合预期。
		比较两次输出的第二个值：
		4294967295对应十六进制0xffff ffff ffff ffff, 说明(int)ch01执行的是符号位扩展
		255对应十六进制0x0000 0000 0000 00ff, 说明(int)ch02执行的是无符号扩展（0扩展）
		
		第三行输出和第一行相同，说明系统内部char就是signed char
	*/
	
	cout << "-------------------------------------------------\n";

	int chh;
	cin.clear(); // 下面进行另一个测试，在此之前，需要重置输入流，因为之前处理过EOF导致输入流关闭了。
	chh = cin.get();
	cout.put(chh); // 书本上说ch声明为int则输出字符时必须使用cin.put(char(chh)); 试试不进行强制类型转换会怎样
				   // 测试结果表明不进行转换也可行
	//cout.put(char(chh));



	/*
		下面是当前文件测试时整个的输出：
			^Z							// 键盘输入
			255
			255
			?
			-1
			-1
			1
			-------------------------------------------------
			-1, 4294967295
			255, 255
			-1, 4294967295
			-------------------------------------------------
			A							// 键盘输入
			A
		
	*/
}