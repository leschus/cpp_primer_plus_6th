// 返回引用类型的函数

#include <string>
#include <iostream>
using namespace std;

struct free_throws
{
	string name;
	int made;
	int attempts;
	float percent;
};

free_throws & clone(free_throws &ft);

int main()
{
	free_throws one = {"Bob", 4, 5, 80.0};

	free_throws &jolly = clone(one);
	cout << "jolly.name: " << jolly.name << endl;

}

free_throws & clone(free_throws &ft)
{
	free_throws *pt = new free_throws;
	cout << "pt: " << pt << endl;
	*pt = ft;
	return *pt;
}