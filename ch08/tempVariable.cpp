#include <iostream>

using namespace std;

int do_something(int &r)
//int & do_something(int &r)
{
	return r;
}

void increase(int &x)
{
	x++;
}

int main()
{
	int a = 1;
	cout << "a = " << a << ", at " << &a << endl;
	
	// ���޸���do_something()�ķ���ֵΪ��������֮����������޷�����ͨ��
	// ��Ϊ�޸�֮��do_something(a)�ķ���ֵ�Ǳ���a�����ã���һ����ֵ���޷�
	// ��������һ����ֵ����rref
	int &&rref = do_something(a); // rref��һ����ֵ����
	cout << "rref = " << rref << ", at " << &rref << endl;

	/*
		  ���Խ����
			a = 1, at 0x61fe10
			rref = 1, at 0x61fe14
		  �����ʾ��rref�ĵ�ַ��a�ĵ�ַ����ͬ��˵��main()��ʹ��do_something()������
		����ֵ��ʱ��ʹ�õ���ϵͳ�Զ�������һ������a�ĸ���
		  ��������Ϊdo_something()�������β�r��a�����ã���ֱ�ӷ�����r������Ϊ����main()
		ʹ��do_something()�ķ���ֵ������ʹ��a��һ�����á�ʵ�������ڼ�ϵͳ������һ������
		��ʱ�������ڴ洢do_something()�ķ���ֵ��������ʱ����ֻ��ֵ��a��ͬ�����Ѿ�������
		��ͬ�ı����ˡ�

		  ���Ҫ�޸�do_something()ʹ��main()����do_something()�õ��ķ���ֵ��a�����ö���
		 һ��������ʱ��������Ҫ������������������Ϊ�������ͣ���int &
		  �Ӷ�����ԭ��Ϊ��
		  	int & do_something(int &r);
		
	*/
	
	// ��do_something()�ķ�������Ϊ����ʱ�����������ܱ���ͨ��
	/*
		������Ϣ��
			tempVariable.cpp:42:23: error: cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
			increase(do_something(a));
		           ~~~~~~~~~~~~^~~
			tempVariable.cpp:10:6: note:   initializing argument 1 of 'void increase(int&)'
			 void increase(int &x)
	*/
	//increase(do_something(a));
	//cout << "a = " << a << ", at " << &a << endl;

}