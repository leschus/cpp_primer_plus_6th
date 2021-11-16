#include <stdio.h>

int square(int x);

int main(void)
{
	double d;
	printf("Input a double: ");
	scanf("%ld", &d);
	
	int result = square(d);
	printf("result: %d\n", result);
	return 0;
}

int square(int x)
{
	printf("square() get param: %d\n", x);
	return x * x;
}

/*
	测试结果：
		Input a double: 2.5
		square() get param: 0
		result: 0
	由结果看出，C语言中如果函数需要一个int类型而调用者传入了一个double类型，函数并不会
	正确地将double类型转换为int（如将2.5取整得到2），由此引发错误

	对此的解释是：函数实际上在处理传入的64位double值时，只取了它的前32位并将其解释为int
	值，由于double类型的2.5，其二进制表示前32位全是0，所以函数将传入参数当做0处理。
*/