// C++11所支持的基于范围的for循环

// 这种形式的for循环能简化一种常见的循环任务：对数组（vector、array）的每个元素执行相同操作

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> vi{1, 4, 24, 32, 21};

	// 打印vi中每个元素的值
	for(int elem: vi)
	{
		cout << elem << endl;
	}

	// 对vi中的每个元素执行加1操作
	// 由于需要修改元素值，因此需要在elem前添加&（引用符号）
	for(int &elem: vi)
	{
		elem += 1;
	}

	// 可以将基于范围的for循环和初始化列表结合使用
	for(int x: {1, 2, 3, 4, 5})
	{
		cout << x << endl;
	}
}