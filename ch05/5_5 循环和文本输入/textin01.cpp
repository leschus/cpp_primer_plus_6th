// �������ݣ����ַ��ض�ȡ�����ļ�����̵��ı�����
//           ���ַ���������Ļ��

// * ʹ��ԭʼ��cin�������룬���ض��ַ�'#'��Ϊ�������

#include <iostream>

using namespace std;

int main()
{
	int count = 0; // ͳ�ƴ����˶��ٸ��ַ�
	char ch;
	

	while(1) // �����һֱѭ��������ʹ��Ctrl-C�˳�
	{
		cout << "----------------------------------\n";
		cout << "Enter characters; enter # to stop:\n";
		// cout << "count: " << count << endl;
		cin >> ch; // ���յ�һ���ַ�
		while(ch != '#') // ����'#'���˳�ѭ��
		{
			cout << ch; // ����
			count ++; // ��������1
			cin >> ch; // ������һ���ַ�
		}

		cout << endl << count << " characters read.\n";
		count = 0; // count����
	}


/*
	���Խ����
		----------------------------------
		Enter characters; enter # to stop:
		12345 678#91							// ������12345 678#91
		12345678
		8 characters read.
		----------------------------------
		Enter characters; enter # to stop:
		9112#									// ������12#
		12
		4 characters read.
		----------------------------------
		Enter characters; enter # to stop:
	���Կ�����cin�����˿հ��ַ������»��Ժ�ʵ��������ƫ��
	���⣬��һ�������'#'��ʣ����ַ��������ڶ���ѭ��ʱ���������������з�����
	�Ӷ����µڶ���������Ȼֻ��������Ч�ַ�12ȴ����Ϊ��ȡ��4���ַ�
*/
}