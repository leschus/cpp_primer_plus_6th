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

// ��������ʽ���޸�֮���, �����޶���ʵ���ļ���, 
// ���, ���޸�֮ǰҪ����ԭ״̬, ʹ��֮��Ҫʹ�����ʽ
// �ָ���ԭ״̬, �Ա���Ӱ�������ط�������ĸ�ʽ
void Stock::show()
{
	//std::streamsize prec = std::cout.precision(2);
	//std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed);

	// ������auto�Զ��ж����Ϳ�����
	// ����ͨ��, ˵������
	auto prec = std::cout.precision(2);
	auto orig = std::cout.setf(std::ios_base::fixed);

	std::cout << "Shares: " << shares << std::endl
		 << "  Share Price: $" << share_val
		 << "  total value: $" << total_val << std::endl;
	
	std::cout.precision(prec);
	std::cout.setf(orig, std::ios_base::floatfield);

}