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
	while (res && i < Size); // ѭ����members���鱻���������û�����������Ϊ���ַ���ʱ�˳�

	if (!res) // �������Ϊ����������Ϊ�մ����˳�, ���˳�ѭ��ʱi�����1, Ӧ��ȥ
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