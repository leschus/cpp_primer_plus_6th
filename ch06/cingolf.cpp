// �������ϵĳ����嵥6.14 cingolf.cpp

// ��������������ַ�ʱ������˵����һ��������һ�ζ���һ�����ʶ�����һ���У�������ô����--������ʱû�����������

#include <iostream>
using namespace std;

const int Max = 5;

int main()
{
	int golf[Max];
	cout << "Please enter your golf scores.\n";
	cout << "You must enter " << Max << " rounds.\n";
	int i;
	for(i = 0; i< Max; i++)
	{
		cout << "round #" << i + 1 << ": ";
		while (!(cin >> golf[i]))
		{
			cin.clear();
			while(cin.get() != '\n') // ����˵���ַ�ʽ��һ��ɾ��һ�У��Ҿ��ø�׼ȷ��˵��һ��ɾ��һ���ַ���ֱ������'\n'
			{
				continue;
			}
			cout << "Plese entera number: ";
		}
	}
}
