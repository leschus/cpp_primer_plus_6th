// using����ָ���using����������

#include <iostream>
using namespace std;

namespace Jill
{
	double bucket(double n) { return n;}

	double fetch;

	struct Hill
	{
		int top, bottom;
	};
}

char fetch; // λ��ȫ�����ƿռ���

int main()
{
	//using namespace Jill;

	////cin >> fetch; // �ᱨ��, �������ֲ���������::fetch����Jill::fetch

	//double fetch; // ���ᱨ��,�൱�ں����ھֲ�����fetch������Jill::fetch
	//cin >> fetch; // д���ݵ������ھֲ�����fetch����Jill::fetch
	//cin >> ::fetch; // д���ݵ�ȫ�����ƿռ��е�fetch (char����)
	//cin >> Jill::fetch; // д���ݵ�Jill���ƿռ��е�fetch


	using Jill::fetch;

	cin >> fetch;	// ���ᱨ��, �൱��Jill::fetch������::fetch
	cout << fetch;
}