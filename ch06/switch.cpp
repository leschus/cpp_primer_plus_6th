// C++�е�switch��䣬�������ֲ˵������

#include <iostream>
using namespace std;

void showmenu();

int main()
{
	int choice;

	showmenu();
	cin >> choice;

	while(choice != 5)
	{
		switch(choice)
		{
			case 1:
				cout << "\a\n";
				break;
			case 2:
				cout << "hello\n";
				break;
			case 3:
				cout << "you're beautiful\n";
				break;
			case 4:
				cout << "have a nice day\n";
				break;
			default:
				cout << "not a choice\n";
		}
		showmenu();
		cin >> choice;
	}
	
	cout << "Bye!\n";

	/*
		�׶ˣ�
		choiceΪint���ͣ��������Ϊ�����֣���ĸ����㣩ʱ�ᵼ������ʧЧ��������������ѭ��

		����Ϊʲô����ѭ�������������ժ��CSDN���ͣ�
			������һ��int��������cin����ʱ������������һ���ַ����ᷢ������4�������
			1.n��ֵ���0
			2.��ƥ������뱻������������
			3.cin�����һ�������Ǳ����ã���cin.fail()����true
			4.��cin�ķ������÷���false����(cin>>n)���ص���false
			��������������������������������
			��Ȩ����������ΪCSDN��������ѻ_�ڷɡ���ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
			ԭ�����ӣ�https://blog.csdn.net/weixin_36796040/article/details/78529099
	*/
}

void showmenu()
{
	cout << "-------------------------------------------------------\n";
	cout << "input 1~4 to choose different actions. input 5 to quit.\n";
}