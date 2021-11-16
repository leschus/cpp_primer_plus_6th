// C++ �ṹ��

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct inflatable
{
	std::string name; // �ṹ����ʹ��string�������Ϊ��Ա
	char color[10];
	float volume;
	double price;
};

struct Duck
{
	string color;

	// C++�ṹ���п��Զ����Ա����
	// �ṹ���еĳ�ԱĬ����public����
	void fly()
	{
		cout << "I'm flying!\n";
	}

	void say()
	{
		cout << "my color is " << color << endl;
	}
};

// λ�νṹ
// ����ָ���ṹ���Առ�õı�����
// λ�ε����ݳ�Ա���������ͻ���ö����
// λ�ֶνṹһ�����ڵͼ���̣�һ����˵������ʹ�����ʹ���λ���������λ�ֶνṹ
struct BitFields
{
	unsigned int f1 : 4; // f1��������2�ֽڿռ䣬����ֻ�����е�4������
	unsigned int f2 : 2;
	unsigned int f3 : 2;
	bool f4 : 1; // ͬ���أ�f4��������1�ֽڵĿռ䣬����ֻ�����е�1������
	bool f5 : 1;
};


int main(void)
{
	// C++�ṹ���������ʱ���Բ���дstruct��C�ṹ����д
	inflatable a = 
	{
		"sunflowers",
		"red",
		0.20,
		12.49
	};
	inflatable b;
	
	b = a;	// �ṹ�����֮�����ֱ�Ӹ�ֵ
			// ���е������ԱҲ�ᱻ��ֵ
	cout << b.name << ", " << b.color << ", "
		 << b.volume << ", " << b.price << endl;
	
	// ȷ�����½ṹ���C����ַ����Ƿ���ȷ�ظ�ֵ��
	cout << "num_of_elems in b.color: " << strlen(b.color) << endl;
	cout << "size of b.color: " << sizeof(b.color) / sizeof(char) << endl;
	// �ɴ˿���ȷ�Ͻṹ��֮�丳ֵ���ڽṹ���е�C�ַ�����ִ��������strcpy�Ĳ���

	Duck d = {"yellow"};
	d.fly();
	
	// ����ṹ������
	// ���ʼ����Ҫ�õ�����{}
	Duck ducks[] = 
	{
		{"red"},
		{"blue"},
		{"purple"}
	};
	int size = sizeof(ducks) / sizeof(Duck);

	cout << sizeof(ducks) << endl; // 96
	cout << sizeof(Duck) << endl;	// 32 -- �ɴ˿ɼ�color��Ա��Ϊstring���ͣ�Duck�ṹ
									//�洢�������ĵ�ַ(�������͵��ص�)
	cout << "num of ducks: " << size << endl;

	for (int i=0; i < size; i++)
	{
		ducks[i].say();
	}

	BitFields bf = 
	{
		10, 3, 2, true, false
	};
	
	cout << "num of bytes of bf: " << sizeof(bf) << endl; // 8
	cout << "num of bytes of BitFields: " << sizeof(BitFields) << endl; // 8

	cout << "value of each field:\n";
	cout << "\tbf.f1: " << bf.f1 << endl;
	cout << "\tbf.f2: " << bf.f2 << endl;
	cout << "\tbf.f3: " << bf.f3 << endl;
	cout << "\tbf.f4: " << bf.f4 << endl;
	cout << "\tbf.f5: " << bf.f5 << endl;
	
}