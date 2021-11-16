#include <iostream>
#include <cstring>

struct chaff
{
	char dross[20];
	int slag;
};

int main()
{
	char *placement = new char[sizeof(chaff) * 2];

	std::cout << "placement at: " << (void *)placement << std::endl;

	// 使用定位new运算符
	chaff *pp = new (placement) chaff[2];

	char str1[20] = "hello";
	char str2[20] = "world";

	std::cout << "pp[0] at " << (void *)pp << std::endl;
	std::cout << "pp[1] at " << (void *)(pp + 1) << std::endl;
	
	int s1 = 80, s2 = 99;
	strcpy(pp[0].dross, str1);
	pp[0].slag = s1;

	strcpy(pp[1].dross, str2);
	pp[1].slag = s2;

	for(int i=0; i< 2; i++)
	{
		std::cout << pp[i].dross << ": " << pp[i].slag << std::endl;
	}

	delete []placement; // 释放内存
	
}

/*
测试输出:

placement at: 0xe815f0
pp[0] at 0xe815f0				// 等于placement
pp[1] at 0xe81608				// 等于placement加上sizeof(chaff), 即0xe815f0加上十进制的24
hello: 80						
world: 99

*/