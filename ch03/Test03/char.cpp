//char.cpp -- C++�е��ַ�����

/*
	��ͨ��char����
		�����ֽڣ�ֻ�ܹ���ʾ256�в�ͬ���ַ�
	��չ��wchar_t����
		���ں����ַ���һ���ֽڴ洢���µ��ַ�������ʹ��char����
		* ʹ��ǰ׺L����ʾ���ַ������Ϳ��ַ���
			��L'P'��L"tall"
	char16_t��char32_t
		* ʹ��ǰ׺u��ʾchar16_t�ַ��������ַ�������
		* ʹ��ǰ׺U��ʾchar32_t�ַ��������ַ�������
*/

#include <iostream>

using namespace std;
int main(void)
{
	char ch = 'A'; // ��ͨ�ַ�����
	cout << "sizeof char: " << sizeof(char) << endl;
	cout << ch << endl;

	wchar_t wch = L'A';
	cout << "sizeof wchar_t: " << sizeof(wchar_t) << endl;
	cout << wch << endl; // ���65����A
	cout.put(wch);	// ʹ��cout.put����ȷ������ַ�������ascii��ֵ
	cout << endl;
	wcout << wch << endl; // ʹ��wcoutҲ������ȷ�����wchar_t�����ַ�

	// ��ӡUnicode�ַ�"�й�"
	cout << "\u4e2d\u56fd" << endl; // �������룺��中国��

	cout << "Let them eat g\u00E2teau.\n";	// �������룺��Let them eat gâteau.��
}