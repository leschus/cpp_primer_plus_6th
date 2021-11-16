// 4.1 数组 

/*

	1、数组声明时需要提供：元素的数据类型、数组名、数组中的元素个数
	2、数组元素个数在声明时要以整型常量、整型常量表达式或const整数值给出，不能是变量
		* 有一种技巧（使用new运算符）可以避开这种限制。
	3、编译器不会检查数组下标是否溢出，程序开发者要对下标的有效性负责
	4、使用{}方式初始化数组元素可以提高效率
		* 例如 int numbers[3] = {11, 22, 33};
		* 只能在定义数组的时候进行初始化，此后就不能再初始化了
	5、sizeof运算符作用于数组名时，将得到整个数组所占的字节数；而作用于数组元素时，将得到单个元素所占的字节数。
		* 例如对于上述numbers数组，sizeof(numbers) ==> 12; sizeof(numbers[0]) ==> 4;
	6、不能将一个数组直接赋给另一个数组

*/
#include <iostream>
using namespace std;

int main(void)
{
	int numbers[3] = {11, 22, 33};
	
	cout << sizeof(numbers) << endl;	// 12
	cout << sizeof(numbers[0]) << endl; // 4
	
	int cards[4] = {3, 6, 8, 10};
	//int hand[4] = cards; // 错误

	// 初始化数组时[]内留空，而让编译器自己计算数组大小
	int things[] = {1, 3, 5, 7};	// 编译器将分配大小为4个int的空间给数组
	// 再用代码获取到数组长度
	int num_elements = sizeof(things) / sizeof(int); // 4
	cout << "num of elements: " << num_elements << endl;
	
	// C++11新特性
	// 使用列表初始化可以省略等号
	int earnings[4] {1200, 1800, 1300, 2000};
	// 列表为空表示将元素全部初始化为0
	int count[10] = {};
	// 列表初始化禁止类型隐性的缩窄转换（大容量转小容量）
	//long plifs[] = {23, 31, 3.1}; // 错误，因为float到long是缩窄转换


}