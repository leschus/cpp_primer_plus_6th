// C++11��֧�ֵĻ��ڷ�Χ��forѭ��

// ������ʽ��forѭ���ܼ�һ�ֳ�����ѭ�����񣺶����飨vector��array����ÿ��Ԫ��ִ����ͬ����

#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<int> vi{1, 4, 24, 32, 21};

	// ��ӡvi��ÿ��Ԫ�ص�ֵ
	for(int elem: vi)
	{
		cout << elem << endl;
	}

	// ��vi�е�ÿ��Ԫ��ִ�м�1����
	// ������Ҫ�޸�Ԫ��ֵ�������Ҫ��elemǰ���&�����÷��ţ�
	for(int &elem: vi)
	{
		elem += 1;
	}

	// ���Խ����ڷ�Χ��forѭ���ͳ�ʼ���б���ʹ��
	for(int x: {1, 2, 3, 4, 5})
	{
		cout << x << endl;
	}
}