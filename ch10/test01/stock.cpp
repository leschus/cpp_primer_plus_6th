#include <iostream>
#include "stock.h"

inline void Stock::set_tot()
{
	total_val = shares * share_val;
}

void Stock::initialize(double val, int n)
{
	shares = n;
	share_val = val;

	set_tot();
}

// 像对输出格式的修改之类地, 尽量限定在实现文件中, 
// 因此, 在修改之前要保存原状态, 使用之后要使输出格式
// 恢复到原状态, 以避免影响其他地方地输出的格式
void Stock::show()
{
	//std::streamsize prec = std::cout.precision(2);
	//std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed);

	// 试试用auto自动判断类型可以吗
	// 编译通过, 说明可行
	auto prec = std::cout.precision(2);
	auto orig = std::cout.setf(std::ios_base::fixed);

	std::cout << "Shares: " << shares << std::endl
		 << "  Share Price: $" << share_val
		 << "  total value: $" << total_val << std::endl;
	
	std::cout.precision(prec);
	std::cout.setf(orig, std::ios_base::floatfield);

}