// C++中的动态内存管理
//		* 涉及到new, delete
//		* 了解静态联编（static binding）和动态联编（dynamic binding）

#include <iostream>

using namespace std;


int main(void)
{
	// 使用new为单个实体分配内存
	// new和delete配套使用
	double *pd = new double;
	cout << "sizeof pd: " << sizeof(pd) << endl; // 指针pd的长度：8（64位系统）
	cout << "pd: " << pd << endl; // new完后pd的值
	*pd = 3.14;
	delete pd;
	cout << "pd: " << pd << endl; // delete之后pd的值

	// 使用new []为动态数组分配内存
	// new [] 和delete []配套使用
	int size = 10;
	int *psome = new int [size];
	cout << "psome: " << psome << endl; // new完后psome的值
	
	for (int i=0; i<size; i++)
	{
		psome[i] = i;
	}
	delete [] psome;
	cout << "psome: " << psome << endl; // delete之后psome的值
	
	/*
		输出结果：
		pd: 0xf815f0
		pd: 0xf815f0
		psome: 0xf815f0
		psome: 0xf815f0
		结果表明delete之后指针的值并没有改变，看来只是指针所指向的内存空间被“释放”，
		即这片内存空间在此后可以再次被分配给其他数据对象了。
	*/

	/*
		补充知识：
			delete[]在释放动态数组的空间时如何知道数组多长？
			答：C++设计了这样的机制：new[]分配动态数组时，会多分配一小片空间（如4字节）
			用以保存数组长度，这一小片空间位于所分配空间的开头处。例如，char * pc = new char[10]分配了起始
			地址为0x32100000的一片空间，空间大小为14字节而非10，则它会将0x3210000~0x32100003这四个字节保留，
			用于存储数组长度，而将0x32100004作为new的返回值赋给pc。
			delete[]时，它会从pc-4的位置读取到数组长度，继而就知道要释放多少个数组元素的空间了
	*/

	//	遗留问题：delete[]在处理基本数据类型的动态数组（int数组）和引用类型的动态数组（如string类对象数组）时
	// 有何区别？


	// 使用动态数组（可以用普通数组的方式访问动态数组中的元素）
	// 由此可以体会C/C++中数组名和指针是如何基本等效的
	int *pNums = new int[3];
	pNums[0] = 11;
	pNums[1] = 22;
	pNums[2] = 33;
	cout << "first element of pNums: " << pNums[0] << endl;

	int nums[3] {11, 22, 33};

	// 但有一点区别是，数组名的值不能被修改，而指针可以
	pNums += 1; // OK
	//nums += 1; // Wrong! -- "incompatible types in assignment of 'int' to 'int [3]"

	//	另外一点区别在于；对数组名使用sizeof得到的是数组的长度，而对指针使用sizeof得到的是指针的长度，
	// 即使这指针指向了一个数组
	cout << "sizeof nums: " << sizeof(nums) << endl;	// 12，数组长度为3*4=12
	cout << "sizeof pNums: " << sizeof(pNums) << endl;	// 4，指针占8字节，因为是64位系统



	cout << "pNums[0]: " << pNums[0] << endl;  // 22
	// 从上述结果来看，pNums值加1产生的效果是pNums由原先的指向第一个元素11转而指向了第二个
	// 元素22，由于int本身应该占4个字节，即算式中的“加1”实际产生了“内存地址加4”的效果，这
	// 说明C++对指针类型的算术运算进行了特殊处理，将指针所指的数据类型也考量在内。
	//
	// 总结来说：将指针变量加1后，其增加的值等于指向的类型占用的字节数


	pNums -= 1; // reset value of pNums;
	delete [] pNums; // free the memory


}