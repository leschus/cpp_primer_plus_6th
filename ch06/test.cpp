#include <iostream>

using namespace std;

// ���������뷽ʽ���ܹ���ȷ������ȡһ����ĸ��һ��int�����С������

/*
	�������������뷽ʽ�����ȣ�ch��������Ϊint�ͣ���
		1��cin >> ch;
		2��cin.get(ch);
		3��ch = cin.get(); 
*/

int main()
{
	int ch = 1;

	//cin.get(ch); // �����У����벻ͨ��
	//ch = cin.get(); // ���У�������int�����е�����ĸ��ASCIIֵ
	cin >> ch; // �����У����۶�ȡ��ʲô��ĸ��ch���յ�ֵ��Ϊ0����failbit����1�����º����޷��ٶ�ȡ������
	cout << ch << endl;
	cout << cin.eof() << ", " << cin.fail() << endl;
}