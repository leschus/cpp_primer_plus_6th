#include <iostream>
using namespace std;

int square(int x);

int main(void)
{
	double d;
	cout << "Input a double: ";
	cin >> d;
	
	int result = square(d);
	cout << "result: " << result << endl;
	return 0;
}

int square(int x)
{
	cout << "square() get param: " << x << endl;
	return x * x;
}

/*
	���Խ��
		Input a double: 2.5
		square() get param: 2
		result: 4
	���������C++�����ڴ������Ͳ����Ĵ������ʱ������ȷ�ؽ���ǿ������ת��
	�縡����2.5����ȷȡ��Ϊ2

	ע�⣺ת����ȷ��ǰ�������߶�����������

	�������Զ�����ת���������ܽ���������Ͳ�ƥ���������罫һ��ֵ����INT_MAX��
	��������������square()�����޷���ȷ�ؽ���ȡ������ʱ�ڱ���׶λ���־��档
	---�������ͼ���֮Ϊ����̬���ͼ�飨static type checking����
*/