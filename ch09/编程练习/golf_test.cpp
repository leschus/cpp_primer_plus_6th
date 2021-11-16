#include <iostream>
#include "golf.h"

const int Size = 3;

int main()
{
	golf members[Size];

	int i = 0, res;
	do
	{	std::cout << ">>> Turn #" << i + 1 << std::endl;
		res = setgolf(members[i]);
		i++;
	}
	while (res && i < Size); // 循环在members数组被填满或者用户将姓名设置为空字符串时退出

	if (!res) // 如果是因为将姓名设置为空串而退出, 则退出循环时i多加了1, 应减去
	{
		i--;
	}

	std::cout << i << " member(s) processed.\n";

	for (int j = 0; j < i ; j++)
	{
		showgolf(members[j]);
	}

	std::cout << "\nTHE END\n";
}