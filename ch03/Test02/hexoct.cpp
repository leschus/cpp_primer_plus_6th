// hexoct.cpp -- display values in hex and octal
#include <iostream>

int main(void)
{
	using namespace std;

	int a = 10;
	int b = 010;
	int c = 0x10;

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	cout << endl;

	// ����cout��8���Ƹ�ʽ�������
	cout << oct;
	cout << b << endl;

	// ����cout��16���Ƹ�ʽ�������
	cout << hex;
	cout << c << endl;

	// ʵ�����Կ���������Ϊhex, oct�ı�����ֻ�Ǳ����������޷���������cout<<hex���ı�cout�����ֵ�Ľ�����
	// ��Ϊ��ʱhex����˱�������cout<<hex�������Ӧ�ı����е�ֵ��
	// ����Ϊʲô�Կ��Խ�hex, oct�������������������ֳ�ͻ����ԭ�����
		/*{
		// �������ֿռ�std�ж�����hex, oct��ʶ������˲����ٽ�hex, oct����������
		int hex = 1, oct = 2; // ����
		cout << hex << ", " << oct << endl;
		}

		// ����cout��8���Ƹ�ʽ�������
		cout << oct;
		cout << b << endl;

		// ����cout��16���Ƹ�ʽ�������
		cout << hex;
		cout << c << endl;

		*/
}