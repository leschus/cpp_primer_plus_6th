// C++11֧���Զ��Ƶ�����auto

// ��ʼ������ʱ����ʹ������auto���������ص�ָ���������ͣ����������ѱ����������Զ����óɺͳ�ʼֵ��ͬ

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	auto x = 10;	// int
	auto y = 1.0;	// double
	auto z = 3.14L;	// long double


	auto fract = 8.25f/2.5;
	cout << sizeof(fract) << endl;	// 8, ˵��fract��auto����Ϊdouble���ͣ�����Ԥ��
	cout << sizeof(float) << " " << sizeof(double) << " " << sizeof(long double) << endl; // 4 8 16

	vector<double> scores;
	// ʹ��auto������д������������
	auto pv = scores.begin(); // ������Ҫдvector<int>::iterator pv = scores.begin();   // :)
}