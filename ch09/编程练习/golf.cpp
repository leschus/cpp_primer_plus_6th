#include <iostream>
#include "golf.h"

// �ǽ����汾
void setgolf(golf &g, const char *name, int hc)
{
	int i=0;
	// whileѭ�����򿽱�name�е��ַ���g.fullname��
	// ���ַ���name�ĳ��ȳ���Len-1ʱ, ��ֻ����ǰLen-1���ַ���
	// g.fullname��, ������ַ����ض�
	while (i < Len - 1 && name[i])
	{
		g.fullname[i] = name[i];
		i++;
	}
	g.fullname[i] = '\0';

	g.handicap = hc;
}

// �����汾
int setgolf(golf &g)
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "Enter the fullname: " << endl;
	char name[Len];
	char next;
	cin.get(name, Len);
	if(cin) // true, ˵��û���������
	{
		cin.get(next);
		//if(next == '\n') // ��һ���ַ�Ϊ���з�, ˵��������ַ�������û�г���Len-1
		//{
			//cout << "Enter the handicap: " << endl;
			//int hd;
			//cin >> hd;

			//setgolf(name, golf); // ���÷ǽ����汾��setgolf()
		//}
		while(next != '\n') // �����������п��ܴ��ڵ�ʣ���ַ�
		{
			cin.get(next);
		}

		cout << "Enter the handicap: " << endl;
		int hc;
		cin >> hc;
		
		setgolf(g, name, hc); // ���÷ǽ����汾��setgolf()

		cin.get(next); // �б�Ҫ�������, ��Ϊ����hc֮���з����ڻ�����, �ᵼ���´�����nameʱ����
						// �û��з��̶���δ�û������˿մ����º���ֱ�ӷ���0����
		//if(next == '\n')
			//cout << "yes\n";

		return 1;
	}

	//cin.get(next); // ���������û��Ҫ�������, ��Ϊcin.get(char*, int)��������֮��, ������߼�Ҳ�ͽ�����
					// ���˵���������߼�, ����Ҫ����ʹ��cin��������Ļ�, �������Ҫ��Ӹþ�, ��Ҫ��cin.clear()
					// ����������
	//if(next == '\n')
		//cout << "yes\n";
	
	return 0; // ��name�ǿ��ַ���ʱ, ����0
}

// �޸Ľṹ��handicap��Ա
void handicap(golf &g, int hc)
{
	g.handicap = hc;
}

// ��ӡ�ṹ����������
void showgolf(const golf &g)
{
	std::cout << g.fullname << ": " << g.handicap << std::endl;
}