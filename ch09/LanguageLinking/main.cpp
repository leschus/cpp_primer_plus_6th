// ��C++�ļ���ʹ��C���Ժ���

#include <iostream>
using namespace std;

// ����C����Լ����ѯsum()�����ķ��ű�ʾ
extern "C" int sum(int a, int b);

int main()
{
	int ia, ib;
	cout << "input two ints: \n";
	cin >> ia >> ib;

	cout << "Sum of " << ia << " and " << ib << ": "
		 << sum(ia, ib) << endl;
}

/*
	���Թ���:
		����ʱ,����ֱ��ʹ������: g++ main.cpp c_func.c
		���Ҳ���sum()�Ķ���
	
		��ȷ�ı��뷽ʽ(Ӧ�ò�������):
			* �ȱ���c_func.c�õ�Ŀ���ļ�(c_func.o)
			* �ٱ���main.cppͬʱ����c_func.o

			* ��������:
				* g++  -c c_func.c			// ���߱�����ֻ���벻����, ����.o�ļ�
				* g++ main.cpp c_func.o		
		
*/