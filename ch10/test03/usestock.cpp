#include "stock10.h"

int main()
{
	{
		Stock *pstock = new Stock("Bob Jones", 14, 22.1);
		pstock->show();
		
		// ʹ��new�����Ķ���, ����ʱҪ����ʹ��delete�ͷ��ڴ�
		delete pstock;
	}
	return 0;
}