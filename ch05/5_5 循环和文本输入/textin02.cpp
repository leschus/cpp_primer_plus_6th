// �������ݣ����ַ��ض�ȡ�����ļ�����̵��ı�����
//           ���ַ���������Ļ��

// * ʹ��cin.get(char)�������Ա���ֱ��ʹ��cin����ֵ�����

#include <iostream>
using namespace std;

int main(void)
{
	int count = 0; // ��������
	char ch; // ��Ϊcin.get(char)�Ĵ������������ÿһ�ζ�ȡ�����ַ�

	while(1)
	{
		cout << "----------------------------------\n";
		cout << "Enter characters; enter # to stop:\n";
		cin.get(ch);
		while(ch != '#')
		{
			cout << ch;
			count ++;
			cin.get(ch);
		}
		
		cout << endl << count << " characters read.\n";
		count = 0; // count����
	}

	/*
		
		���������
			----------------------------------
			Enter characters; enter # to stop:
			12345 678#91
			12345 678
			9 characters read.
			----------------------------------
			Enter characters; enter # to stop:
			91
			12#
			12
			5 characters read.
			----------------------------------
			Enter characters; enter # to stop:

		���Կ�����cin.get(char)���ٻ������հ��ַ���ʹ�õ�һ������Ļ��Խ������ȷ�ģ���'#'������
		���ǣ���Ȼ����ǰһ�����������ַ�������ڻ����������⣬������һ�ִ���ʱ�������Ϊ���յ���
		��ʵ����������ַ�������ַ����ڶ���ֻ������12#��ȴ����Ϊ������5���ַ�����Ϊ������������һ
		��ʣ��ģ����Ƿֱ���'9', '1', '\n'��
	*/
	
}