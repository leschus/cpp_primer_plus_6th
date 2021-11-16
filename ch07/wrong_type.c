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
	���Խ����
		Input a double: 2.5
		square() get param: 0
		result: 0
	�ɽ��������C���������������Ҫһ��int���Ͷ������ߴ�����һ��double���ͣ�����������
	��ȷ�ؽ�double����ת��Ϊint���罫2.5ȡ���õ�2�����ɴ���������

	�Դ˵Ľ����ǣ�����ʵ�����ڴ������64λdoubleֵʱ��ֻȡ������ǰ32λ���������Ϊint
	ֵ������double���͵�2.5��������Ʊ�ʾǰ32λȫ��0�����Ժ����������������0����
*/