// C++�����壨�����壩

// ��������Դ洢��ͬ���͵�ֵ
// ��ͬһʱ��ֻ���Դ洢һ�����͵�ֵ
// ������ռ���ڴ�ռ�Ĵ�С��������Ա�ĳ��Ⱦ���

#include <iostream>
using namespace std;

union One4All
{
	int int_val;
	double dbl_val; // double����Ϊ8�ֽڣ���Ҳ��������One4All�ĳ���
	long long_val;
};

// ��������Ƕ���ڽṹ����ʹ��
struct widget	// һ����Ʒ�ṹ����Ʒid����������Ҳ�������ַ���
{
	char brand[20]; // Ʒ��
	bool type; // ���ͣ�ȷ����Ʒid�ı�ʾ��ʽ, true��ʾ�����֣�false��ʾ���ַ���
	union id
	{
		long id_num; // �����ֱ�ʾ����Ʒid
		char id_char[20]; // ���ַ�����ʾ����Ʒid
	} id_val;
};

// Ҳ������һ�������ķ�ʽ��������Ƕ���ڽṹ����
// ������ʽ�£��������Ա����Ϊ��Ӧλ�ô��Ľṹ���Ա����
// �����������е�id_num��Ա��ֻ����prize.id_num���ɣ�������Ҫ
// ��prize.id_val.id_num (���������һ��widget�ṹ������Ϊprize);
//struct widget	// һ����Ʒ�ṹ����Ʒid����������Ҳ�������ַ���
//{
	//char brand[20]; // Ʒ��
	//bool type; // ���ͣ�ȷ����Ʒid�ı�ʾ��ʽ, true��ʾ�����֣�false��ʾ���ַ���
	//union // ����������
	//{
		//long id_num; // �����ֱ�ʾ����Ʒid
		//char id_char[20]; // ���ַ�����ʾ����Ʒid
	//};
//};

int main()
{
	One4All x;
	x.int_val = 10;
	cout << x.int_val << endl;

	x.dbl_val = 3.14;
	cout << x.dbl_val << endl;

	x.long_val = 65536;
	cout << x.long_val << endl;

	widget prize = 
	{
		"Nike",
		true,
		312, // id
	};

	if(prize.type)
	{
		cout << prize.id_val.id_num << endl;
	}
	else
	{
		cout << prize.id_val.id_char << endl;
	}
}
