// C++ 结构体

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct inflatable
{
	std::string name; // 结构体中使用string类对象作为成员
	char color[10];
	float volume;
	double price;
};

struct Duck
{
	string color;

	// C++结构体中可以定义成员函数
	// 结构体中的成员默认是public类型
	void fly()
	{
		cout << "I'm flying!\n";
	}

	void say()
	{
		cout << "my color is " << color << endl;
	}
};

// 位段结构
// 可以指定结构体成员占用的比特数
// 位段的数据成员必须是整型或者枚举型
// 位字段结构一般用于低级编程，一般来说，可以使用整型搭配位运算符代替位字段结构
struct BitFields
{
	unsigned int f1 : 4; // f1被分配了2字节空间，但它只用其中的4个比特
	unsigned int f2 : 2;
	unsigned int f3 : 2;
	bool f4 : 1; // 同样地，f4被分配了1字节的空间，但它只用其中的1个比特
	bool f5 : 1;
};


int main(void)
{
	// C++结构体变量声明时可以不用写struct，C结构必须写
	inflatable a = 
	{
		"sunflowers",
		"red",
		0.20,
		12.49
	};
	inflatable b;
	
	b = a;	// 结构体变量之间可以直接赋值
			// 其中的数组成员也会被赋值
	cout << b.name << ", " << b.color << ", "
		 << b.volume << ", " << b.price << endl;
	
	// 确认以下结构体的C风格字符串是否被正确地赋值了
	cout << "num_of_elems in b.color: " << strlen(b.color) << endl;
	cout << "size of b.color: " << sizeof(b.color) / sizeof(char) << endl;
	// 由此可以确认结构体之间赋值对于结构体中的C字符串会执行类似于strcpy的操作

	Duck d = {"yellow"};
	d.fly();
	
	// 定义结构体数组
	// 其初始化需要用到两层{}
	Duck ducks[] = 
	{
		{"red"},
		{"blue"},
		{"purple"}
	};
	int size = sizeof(ducks) / sizeof(Duck);

	cout << sizeof(ducks) << endl; // 96
	cout << sizeof(Duck) << endl;	// 32 -- 由此可见color成员作为string类型，Duck结构
									//存储的是它的地址(引用类型的特点)
	cout << "num of ducks: " << size << endl;

	for (int i=0; i < size; i++)
	{
		ducks[i].say();
	}

	BitFields bf = 
	{
		10, 3, 2, true, false
	};
	
	cout << "num of bytes of bf: " << sizeof(bf) << endl; // 8
	cout << "num of bytes of BitFields: " << sizeof(BitFields) << endl; // 8

	cout << "value of each field:\n";
	cout << "\tbf.f1: " << bf.f1 << endl;
	cout << "\tbf.f2: " << bf.f2 << endl;
	cout << "\tbf.f3: " << bf.f3 << endl;
	cout << "\tbf.f4: " << bf.f4 << endl;
	cout << "\tbf.f5: " << bf.f5 << endl;
	
}