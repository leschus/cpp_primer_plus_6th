/*
	Ϊͷ�ļ��еĺ����ṩʵ��
*/
#include "defs.h"

int add(int a, int b)
{
	return a + b;
}

Cube::Cube(int e): edge(e) {

}

int Cube::getVolume() {
	return edge * edge * edge;
}

// ����ģ�庯��(��)���ܷ�����룬���ģ��������Ͷ�����Ҫһ�����ͷ�ļ���
// �����ǽ���ģ����������ͷ�ļ��У�����ģ�嶨�����cpp�ļ���
// ��˵���������֧�־ֲ�����ģʽ��������export�ؼ��ֽ��ܽ�������޷������������⣨����֤��
//export template <typename T>
//void my_swap(T &a, T &b)
//{
	//T temp;
	//temp = a;
	//a = b;
	//b = temp;
//}

// ����˵ʹ��ģ�����ʽʵ�������Խ������Ĳ��ܷ�����������
// �����Ի��ǲ���
//template <typename T>
//void my_swap(T &a, T &b)
//{
	//T temp;
	//temp = a;
	//a = b;
	//b = temp;
//}
