// C++ ������������ı��ļ�

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream fout;
	fout.open("111.txt"); // open()��������һ��C����ַ�����Ϊ������������������ֵ��Ҳ������һ���ַ�����

	double wt = 21.8;
	fout << wt;
	char line[81] = "Objects are closer than they appear.";
	fout << line << endl;

	fout.close(); // ��ؼǵ�open()��close()����ʹ��
}