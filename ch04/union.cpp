// C++共用体（联合体）

// 联合体可以存储不同类型的值
// 但同一时间只可以存储一种类型的值
// 联合体占用内存空间的大小由其最大成员的长度决定

#include <iostream>
using namespace std;

union One4All
{
	int int_val;
	double dbl_val; // double长度为8字节，这也是联合体One4All的长度
	long long_val;
};

// 将联合体嵌套在结构体中使用
struct widget	// 一种商品结构，商品id可能是数字也可能是字符串
{
	char brand[20]; // 品牌
	bool type; // 类型，确定商品id的表示方式, true表示用数字，false表示用字符串
	union id
	{
		long id_num; // 用数字表示的商品id
		char id_char[20]; // 用字符串表示的商品id
	} id_val;
};

// 也可以用一种匿名的方式将联合体嵌套在结构体中
// 这种形式下，联合体成员将成为相应位置处的结构体成员变量
// 访问联合体中的id_num成员，只需用prize.id_num即可，而不需要
// 用prize.id_val.id_num (这里假设有一个widget结构变量名为prize);
//struct widget	// 一种商品结构，商品id可能是数字也可能是字符串
//{
	//char brand[20]; // 品牌
	//bool type; // 类型，确定商品id的表示方式, true表示用数字，false表示用字符串
	//union // 匿名联合体
	//{
		//long id_num; // 用数字表示的商品id
		//char id_char[20]; // 用字符串表示的商品id
	//};
//};

int main()
{
	One4All x;
	x.int_val = 10;
	cout << x.int_val << endl;

	x.dbl_val = 3.14;
	cout << x.dbl_val << endl;

	x.long_val = 65536;
	cout << x.long_val << endl;

	widget prize = 
	{
		"Nike",
		true,
		312, // id
	};

	if(prize.type)
	{
		cout << prize.id_val.id_num << endl;
	}
	else
	{
		cout << prize.id_val.id_char << endl;
	}
}
