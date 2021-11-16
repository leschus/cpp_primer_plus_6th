// C++�е���ʽʵ������implicit instantiation������ʽʵ����(explicit instantiation)��
// ��ʽ���廯���ػ�, explicit specification��ͳ��Ϊ���廯���ػ�, specification��

// �Ƚ������ߵ�����

#include <iostream>
using namespace std;

template <typename T> void Swap(T &a, T &b); // һ����ͨģ��

struct job
{
	char name[20]; 
	float salary;
};

void show_job(const job j);

template <> void Swap<job>(job &a, job &b); // ���job�ṹ�����ʽ���廯����Ϊ��������job�ṹֻҪ��
											// �������ǵ�salary��Ա


template void Swap<double>(double &a, double &b); // Swapģ�����double������ʽʵ����


int main()
{
	int ia = 10, ib = 20;
	Swap(ia, ib);
	cout << "ia: " << ia << ", ib: " << ib << endl;

	job ja = {"Bob", 8888.8}, jb = {"Alice", 7777.7};
	Swap(ja, jb);
	show_job(ja);
	show_job(jb);
	
	double da = 1.23, db = 4.56;
	Swap(da, db);
	cout << "da: " << da << ", db: " << db << endl;

	// ��һ��ʹ����ʽʵ�����ķ�ʽ������Ҫר�Ŷ�Ŀ��������дһ��ģ������
	// ���磬��char����ʹ����ʽʵ������
	char ca = 'A', cb = 'Z';
	Swap<char>(ca, cb);
	cout << "ca: " << ca << ", cb: " << cb << endl;

	// �鱾��������ͬһ�ļ������뵥Ԫ����ʹ��ͬһ�����͵���ʽʵ��������ʽ���廯������
	// ������������job����ʹ����ʽʵ��������֮ǰ�Ѿ�ʹ����job���͵���ʽ���廯
	// Ȼ�����Խ����ʽ�������������������н׶Σ�
	// ʵ������������Swap���job����ʹ�õ�����ʽ���廯�İ汾���൱�����job����ʽʵ����
	// δ��Ч
	Swap<job>(ja, jb); // ���벻�����
	show_job(ja);	// 
	show_job(jb);
}

template <typename T> void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <> void Swap<job>(job &a, job &b) // ֻ����salary��Ա��ֵ
{
	job temp;
	temp.salary = a.salary;
	a.salary = b.salary;
	b.salary = temp.salary;
}

void show_job(const job j)
{
	cout << j.name << " gets salary: " << j.salary << endl;
}