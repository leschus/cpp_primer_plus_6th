// cctypes.cpp -- ʹ��cctypeͷ�ļ��еĺ���

// ���ܣ���ȡ��������ֱ������EOF��ͳ�ƶ�ȡ�����и������ַ��ĸ���
/*
	�õ��ĺ�����
		isalpha()  �Ƿ�����ĸ
		isdigit()  �Ƿ�������
		ispunct()  �Ƿ��Ǳ�����
		isspace()  �Ƿ��Ǳ�׼�հ��ַ�
		// iscntrl()  �Ƿ��ǿ����ַ�
*/
#include <iostream>
#include <cctype> // ���� #include <ctype.h>
using namespace std;

int main()
{
	int alphas = 0;
	int digits = 0;
	int puncts = 0;
	int spaces = 0;
	int others = 0;

	char ch;
	while(cin.get(ch))
	{
		if (isalpha(ch))
		{
			alphas ++;
		}
		else if (isdigit(ch))
		{
			digits ++;
		}
		else if (ispunct(ch))
		{
			puncts ++;
		}
		else if (isspace(ch))
		{
			spaces ++;
		}
		else 
		{
			others ++;
		}
	}

	cout << alphas << " letters, "
		 << digits << " digits, "
		 << puncts << " punctuations, "
		 << spaces << " whitespaces, "
		 << others << " others.\n";

	/*
		// output of the test		
			12345
			abcde
			,./
			\n
			^Z
			6 letters, 5 digits, 4 punctuations, 4 whitespaces, 0 others.

			it turns out that when you input '\n' in the commandline, it won't be recognised as LF/NL.
	*/


}