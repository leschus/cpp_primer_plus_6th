// C++֧����������
// ���Խ���������С��ִ��Ƶ�ʸߵĺ�������Ϊ��������
// �Ӷ����Ա���Ƶ��������ɵ�ʱ�俪��
// ����Ӧ�أ�����������ʹ�ý����ӳ�����ڴ濪��
// ��Ϊÿһ�����ô�����Ҫ����һ�����������Ĵ��븱��

#include <iostream>

// declare a inline function
inline double square(double x) { return x * x;}

int main()
{
	using namespace std;
	double a, b;
	double c = 13.0;
	
	a = square(5.0);
	b = square(4.5 + 7.5); // can pass expessions
	
	// ����cout����ĸ�ʽ�����ɣ�����һЩ����Ϥ
	////cout << fixed;
	//cout.precision(2);
	////cout.setf(ios_base::showpoint);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	cout << "c = " << c << endl;
	cout << "c suqared = " << square(c) << endl;

	double x = 1.120;
	cout << "x = " << x << endl;
}
