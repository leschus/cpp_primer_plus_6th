// waiting.cpp -- ��ѭ����ʹ��clock() ��ʵ����ʱЧ��

#include <iostream>
#include <ctime>	// ctime�ж�����clock()������clock_t�����Լ�CLOCK_PER_SEC����

int main()
{
	using namespace std;

	cout << "Enter the delay time (in seconds): ";
	float secs;
	cin >> secs;
	clock_t delay = secs * CLOCKS_PER_SEC; // ������ת��ΪCLOCK��
	cout << "starting\a\n"; // ʹ��\a��Ϊ��ʾ��
	clock_t start = clock();
	while (clock() - start < delay)
	{
		// ѭ�����ڲ���Ҫ���κ���
	}
	cout << "done \a\n";

}
