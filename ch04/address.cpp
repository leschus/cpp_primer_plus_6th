// ʹ��&ȡ��ַ�������ȡ�����ĵ�ַ

#include <iostream>

using namespace std;

int main()
{
	int donuts = 6;
	double cups = 2.7;

	cout << "value of donuts: " << donuts
		 << ", and it's address: " << &donuts << endl;
	// ����������value of donuts: 6, and it's address: 0x61fe1c��
	// ���������cout�Զ�����ַ��16���Ƹ�ʽ�����

	cout << "value of cups: " << cups
		 << ", and it's address: " << &cups << endl;
	// ����������value of cups: 2.7, and it's address: 0x61fe10��
	// ���������cout�Զ�����ַ��16���Ƹ�ʽ�����
	// ���⣬���ߵĵ�ֵַ���12���ɼ������ڴ�ʱ��û�н������������������ڵĿռ�
	// ������������ڣ����ַӦ�����4����8��

}