// C++中的枚举类型

// 枚举类型可以用于替代const常量的作用

// 示例： enum spectrum {red, blue, orange, yellow, pink, purple};
// 该语句定义了枚举类型的名称为spectrum，并给出了该类型的6种可能取值，相当与6个符号常量
// 默认情况下，枚举类型种的符号常量是从0开始累加的整数值
// 因此，red值为0，blue值为1，依此类推。
// spectrum枚举类只能由6种取值，如果要将这六种取值之外的一个值赋给spectrum枚举变量，将会出现错误

#include <iostream>
using namespace std;


enum spectrum {Red, Blue, Orange, Yellow, Pink, Purple};

// 如果目的只是使用枚举来定义一串符号常量，而没打算用到枚举类型声明变量
// 可以定义匿名的枚举类型
// 从1开始，从而星期一和数字1对应，星期天和数字7对应
enum {Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

// 可以创建多个值相同的枚举量
enum {One = 1, AnotherOne = 1, Two};

int main(void)
{
	spectrum band; // 声明一个枚举变量
	
	band = Red; // 合法的枚举变量赋值
	//band = 1;	// 非法的赋值，即使1在spectrum枚举类型的取值范围0~5之内
				//// “invalid conversion from 'int' to 'spectrum'”
	//band = 10;	// 非法的赋值
	band = spectrum(1); // 使用强制类型转换可以实现将int赋值给枚举变量
	band = spectrum(10); // 将一个超出范围的int值强制转换赋给枚举量，将会导致不确定的结果
						 // 这个例子中，最后正确输出了band的值为10

	cout << "size of spectrum: " << sizeof(spectrum) << endl;	// 这里输出4，可以推测枚举类型在
																// 程序内部相当于作为一个int在存储
	cout << band << endl;

	// 开关语句很适合使用枚举类型来处理每一个case
	int day;
	cout << "What day is today? (input a number, 1 implies Monday, 2 implies Tuesday...)\n";
	cin >> day;
	switch(day)
	{
		case Monday:
			cout << "Today is Monday, I have to go to work.\n";
			break;
		case Tuesday:
			cout << "Tuesday, 4 days to go.\n";
			break;
		case Wednesday:
			cout << "Wednesday, 3 days to go.\n";
			break;
		case Thursday:
			cout << "2 days to go.\n";
			break;
		case Friday:
			cout << "Finally, only have to struggle the last day.\n";
			break;
		case Saturday:
			cout << "Sleeped well, I'm free now.\n";
			break;
		case Sunday:
			cout << "A nice weekend.\n";
			break;
		default:
			cout << "default.\n";
	}

	// 对于值相同的枚举量，虽然它们名称不同，但不同作为switch中的两个case
	// 因为各个case之间值不能相同
	// 否则报错：“duplicate case value”
	int num = 1;
	switch(num)
	{
		case One:
			cout << "case 1\n";
			break;
		//case AnotherOne:
			//cout << "another case 1\n";
			//break;
		case Two:
			cout << "case 2\n";
			break;
		default:
			cout << "default.\n";
	}


}