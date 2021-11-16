// C++ ��������

// ����ǩ���е�const

#include <iostream>
using namespace std;

void dribble(char *bits);
void dribble(const char *cbits);
void dabble(char *bits);
void drivel(const char * bits);

int main()
{
	const char p1[20] = "How's the weather?";
	char p2[20] = "How's business?";

	//	��ϵ�����غ����м��н���const�����ĺ�����Ҳ�н��շ�const�����ĺ���ʱ
	//	����������Ϊconst���ͣ���ƥ�����const�����ĺ���
	//	����������Ϊ��const���ͣ���ƥ����շ�const���͵Ĳ�����ע�⣺���ﲢ����
	// ��Ϊ����const�����ĺ���Ҳ������շ�const���ͣ���ʹ�����������µĺ���ƥ��
	// ���ֶ��塣Ӧ����C++�ڲ������������µĺ���ƥ���趨�����ȼ�������Ѱ������
	// �ܹ�ֱ��ƥ���ϵģ�����û�в�ȥ�Ҿ�������ת������ƥ���ϵģ��Ͼ�����const�β�
	// ���շ�constʵ�Σ�����Ͻ���������ת������
	dribble(p1);
	dribble(p2);

	//dabble(p1);// ���벻ͨ�����޷�ʹ�÷�const�βν���constʵ��
	dabble(p2);
	
	drivel(p1);
	drivel(p2);
}

void dribble(char *bits)
{
	cout << "dribble with no const bits.\n";
}
void dribble(const char *cbits)
{
	cout << "dribble with const cbits.\n";
}
void dabble(char *bits)
{
	cout << "dabble with no const bits.\n";
}
void drivel(const char * bits)
{
	cout << "drivel with const bits.\n";
}
