// ��switch��ʹ��ö����

#include <iostream>
using namespace std;

enum {red = 1, blue, orange};

int main()
{
	int choice;
	cout << "enter 1~3 to choose a color. q/Q to quit\n";
	cin >> choice;

	// �����������ڲ����������һ����ĸ�������ֻ����ʲô�����
	// �����ʾ��cin�ڱ��ö�ȡ���ֵ�ʱ���ȡ��һ����ĸ�ᵼ��failbitλ��1�������۶�ȡ��ʲô��ĸ��
	// ʵ��Ч�����൱�ڶ�����һ������0
	//cout << cin.fail() << endl; // ��� 1
	//cout << choice << endl; // ��� 0
	
	while(choice != 'q' && choice != 'Q')
	{
		switch(choice)
		{
			case red:
				cout << "red\n";
				break;
			case blue:
				cout << "blue\n";
				break;
			case orange:
				cout << "orange\n";
				break;
			default:
				cout << "not a choice\n";
		}
		cout << "enter 1~3 to choose a color. q/Q to quit\n";
		cin >> choice;
	}
	cout << "bye!\n";

}