// 使用下面这种方式避免一个源文件多次包含同一头文件
#ifndef DEFS_H_
#define DEFS_H_

/* 
	头文件中常包含以下内容
*/

// 函数原型
int add(int a, int b);

// 使用#define或const定义的符号常量
#define OK 1
const float pi = 3.14;

// 结构体声明
struct Point	// 一个二维坐标系中的点结构
{
	int x; // x坐标
	int y; // y坐标
};

// 类声明
class Cube // 立方体类
{
	public:
		Cube(int e);
		
		int getVolume(); // 得到体积

	private:
		int edge; // 立方体的棱长
};

// 模板
template <typename T>
void my_swap(T &a, T &b) // 交换函数的模板
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
//;


// 内联函数
inline double square(double x){ return x * x;}

#endif