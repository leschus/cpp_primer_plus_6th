// C++ array模板类初探

// array的长度固定，并从栈中分配内存；
// 其效率和数组相同，但更方便和安全
// 而vector虽然比数组方便和安全，但是效率偏低

#include <iostream>
#include <array>

using namespace std;

int main(void)
{
	// 注意array的声明方式
	// <>里由两个参数，第一个指明元素类型，第二个指明数组大小
	array<int, 5> ai;
	array<double, 3> ad {1.1, 2.2, 3.3}; // 支持使用列表初始化

	array<int, 5> ai2;
	ai2 = ai; // 可以进行array之间的赋值，只要它们的类型和长度相同即可

	// 书上说array之间只要有相同的size就可以进行赋值，测试一下：
	cout << "sizeof int: " << sizeof(int) << endl;	// 4
	cout << "sizeof float: " << sizeof(float) << endl; // 4
	array<int, 3> ints = {1, 2, 3};
	array<float, 3> floats;
	//floats = ints;	// is this work?
					// 结果是编译不通过：
					// “no match for 'operator=' (operand types are 'std::array<float, 3>' and 'std::array<int, 3>')”
	cout << ints[0] << endl;
	cout << ints[-3] << endl; // 编译能通过，但是很明显这是内存溢出的行为
	// 为避免使用[]方式访问数组成员时的下标溢出问题，可以使用array类提供的at()函数
	cout << ints.at(-3); // 该函数检查到下标非法时，将中断程序执行
	// 虽然at()保障了不会意外访问数组外的空间，但这也导致其执行效率低于使用[]方式访问数组成员
	// 所以说，没有万全的办法。
}