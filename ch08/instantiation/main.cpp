#include <iostream>

#include "header.h"

using namespace std;

int main()
{
	int ia = 10, ib = 20;
	Swap<int>(ia, ib);

	cout << "ia: " << ia << ", ib: " << ib << endl;
}

/*
	���ԣ�
		�������g++ main.cpp
		������Ϣ����undefined reference to `void Swap<int>(int&, int&)'
					collect2.exe: error: ld returned 1 exit status��
		
		��֪���ǲ��Ƕ��ļ����벻�ܼ򵥵�ʹ��`g++ main.cpp`���б���
		����������ʽʵ����ģ��ķ�ʽ�����Բ��ܹ����ģ�������������

		==> �����...
*/