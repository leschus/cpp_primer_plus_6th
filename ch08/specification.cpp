// C++中的隐式实例化（implicit instantiation）、显式实例化(explicit instantiation)、
// 显式具体化（特化, explicit specification）统称为具体化（特化, specification）

// 比较这三者的区别

#include <iostream>
using namespace std;

template <typename T> void Swap(T &a, T &b); // 一个普通模板

struct job
{
	char name[20]; 
	float salary;
};

void show_job(const job j);

template <> void Swap<job>(job &a, job &b); // 针对job结构体的显式具体化，因为交换两个job结构只要求
											// 交换它们的salary成员


template void Swap<double>(double &a, double &b); // Swap模板针对double类型显式实例化


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

	// 另一种使用显式实例化的方式，不需要专门对目标类型另写一遍模板声明
	// 比如，对char类型使用显式实例化：
	char ca = 'A', cb = 'Z';
	Swap<char>(ca, cb);
	cout << "ca: " << ca << ", cb: " << cb << endl;

	// 书本描述：在同一文件（或翻译单元）中使用同一种类型的显式实例化和显式具体化将出错
	// 例如下属语句对job类型使用显式实例化，而之前已经使用了job类型的显式具体化
	// 然而测试结果显式，并不会出错（编译和运行阶段）
	// 实际运行起来，Swap针对job类型使用的是显式具体化的版本，相当于针对job的显式实例化
	// 未生效
	Swap<job>(ja, jb); // 编译不会出错
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

template <> void Swap<job>(job &a, job &b) // 只交换salary成员的值
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