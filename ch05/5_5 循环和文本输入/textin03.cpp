// �������ݣ����ַ��ض�ȡ�����ļ�����̵��ı�����
//           ���ַ���������Ļ��

// * ʹ��cin.get(char), ͬʱ����EOF����־һ�ζ�ȡ�Ľ���

// cin���߻���EOF��־���Ӷ��ж��Ƿ񵽴����ļ�β
// ��⵽EOFʱ��cin��������־λ����Ϊ1��eofbit��failbit)
// ��������־λ����ͨ��cin.eof()��cin.fail()��ȡ

// ������ģ��EOF�ķ�ʽ����ͬƽ̨�в��
//	* Windows�����У�Ctrl+Z Enter
//	* Unix�����У�Ctrl+D

#include <iostream>
using namespace std;

int main()
{
	int count = 0;
	char ch;
	
	while(1)
	{
		cout << "-----------------------------------------------\n";
		cout << "Enter characters, ended with <CTRL>+<Z><ENTER>:\n"; // ��Windowsƽ̨��ʹ��ctrl+z��enter��ģ��EOF
		cin.get(ch); // ��ȡ��һ���ַ�
		while(cin.fail() == false) // failbitû�б���1��˵��û�ж�ȡ��EOF
		{
			cout << ch; // ����
			count ++;
			cin.get(ch); // ��ȡ��һ���ַ�
		}
		cout << endl << count << " characters read.\n";
		count = 0;
		//cin.get(); // ��ȡ��һ��δ����Ļ��з�
					 // �����ԣ�ʹ��cin.get()�޷���ֹˢ�����鱾����˵�����EOF�󽫹رն�����Ľ�һ����ȡ�����º�����
					 // cin.get()��cin.get(ch)������Ч��
					 // ����취֮һ�ǣ�ʹ��cin.clear()����������
		cin.clear(); // ����������
	}

	/*
		���Խ��������һ�㣺��Windows������ʹ��Ctrl+Z Enterģ��EOFʱ��������һ�е��������룬���򽫲���Ч
	*/

	/*
		��һ���أ��Ż�����ı�д��ʽ������cin.get(char)��������ֵ��һ��cin���󣬶�istream���ṩ�˽�istream������cin��
	ת��Ϊboolֵ�ĺ�������cin��������Ҫboolֵ�ĵط�ʱ���ú��������Զ����á���cinִ�е����һ�ζ�ȡ�ɹ�����boolֵΪ
	true, ����Ϊfalse������ȡ��EOF��ζ�Ŷ�ȡʧ�ܣ�
	
	��ˣ���ȡ���ֵ�ѭ������Ը�дΪ��
		while(cin.get(ch))
		{
			...
		}
	*/
}