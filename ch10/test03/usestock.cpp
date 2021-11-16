#include "stock10.h"

int main()
{
	{
		Stock *pstock = new Stock("Bob Jones", 14, 22.1);
		pstock->show();
		
		// 使用new创建的对象, 结束时要主动使用delete释放内存
		delete pstock;
	}
	return 0;
}