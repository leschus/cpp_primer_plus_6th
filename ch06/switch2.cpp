// ��switch.cpp
// �Ż�choiceΪintʱ�Ƿ����뵼�³�����ѭ��������
// ��ΰ�choice����Ϊchar����


#include <iostream>
using namespace std;

void showmenu();

int main()
{
	char choice;
	
	showmenu();
	cin >> choice;

	while(choice != 'q' && choice != 'Q')
	{
		switch(choice)
		{
			case '1':
				cout << "\a\n";
				break;
			case '2':
				cout << "hello\n";
				break;
			case '3':
				cout << "you're beautiful\n";
				break;
			case '4':
				cout << "have a nice day\n";
				break;
			default:
				cout << "not a choice\n";
		}
		showmenu();
		cin >> choice;
	}

	cout << "Bye!\n";
}

void showmenu()
{
	cout << "-------------------------------------------------------\n";
	cout << "input 1~4 to choose different actions. input q or Q to quit.\n";
}