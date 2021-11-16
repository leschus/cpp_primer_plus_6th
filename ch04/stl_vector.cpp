// C++ vector容器初探

// 使用vector将提高编程效率，但相应地，vector的运行效率低于数组

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> vi; // 元素类型为int的vector容器（空）
	
	int n;
	cout << "input n: ";
	cin >> n;
	
	vector<double> vd(n); // 元素类型为double的vector容器（大小为n）

	cout << "created an vector of " << n << " doubles.\n";

	// 可以对vector使用列表初始化
	vector<int> ints = {1, 2, 3, 4 ,5};	// 注意使用方式
										// 不要写成vector<int> ints(5) = {1, 2, 3, 4, 5};
	vector<int> ints2 = {1, 2, 3, 4, 5}; // 这种写法也是ok的
}