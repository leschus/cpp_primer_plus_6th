// waiting.cpp -- 在循环中使用clock() ，实现延时效果

#include <iostream>
#include <ctime>	// ctime中定义了clock()函数、clock_t类型以及CLOCK_PER_SEC常量

int main()
{
	using namespace std;

	cout << "Enter the delay time (in seconds): ";
	float secs;
	cin >> secs;
	clock_t delay = secs * CLOCKS_PER_SEC; // 将秒数转换为CLOCK数
	cout << "starting\a\n"; // 使用\a作为提示音
	clock_t start = clock();
	while (clock() - start < delay)
	{
		// 循环体内不需要做任何事
	}
	cout << "done \a\n";

}
