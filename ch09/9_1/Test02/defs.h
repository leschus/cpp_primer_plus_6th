// ʹ���������ַ�ʽ����һ��Դ�ļ���ΰ���ͬһͷ�ļ�
#ifndef DEFS_H_
#define DEFS_H_

/* 
	ͷ�ļ��г�������������
*/

// ����ԭ��
int add(int a, int b);

// ʹ��#define��const����ķ��ų���
#define OK 1
const float pi = 3.14;

// �ṹ������
struct Point	// һ����ά����ϵ�еĵ�ṹ
{
	int x; // x����
	int y; // y����
};

// ������
class Cube // ��������
{
	public:
		Cube(int e);
		
		int getVolume(); // �õ����

	private:
		int edge; // ��������ⳤ
};

// ģ��
template <typename T>
void my_swap(T &a, T &b) // ����������ģ��
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
//;


// ��������
inline double square(double x){ return x * x;}

#endif