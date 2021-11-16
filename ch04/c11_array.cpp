// C++ arrayģ�����̽

// array�ĳ��ȹ̶�������ջ�з����ڴ棻
// ��Ч�ʺ�������ͬ����������Ͱ�ȫ
// ��vector��Ȼ�����鷽��Ͱ�ȫ������Ч��ƫ��

#include <iostream>
#include <array>

using namespace std;

int main(void)
{
	// ע��array��������ʽ
	// <>����������������һ��ָ��Ԫ�����ͣ��ڶ���ָ�������С
	array<int, 5> ai;
	array<double, 3> ad {1.1, 2.2, 3.3}; // ֧��ʹ���б��ʼ��

	array<int, 5> ai2;
	ai2 = ai; // ���Խ���array֮��ĸ�ֵ��ֻҪ���ǵ����ͺͳ�����ͬ����

	// ����˵array֮��ֻҪ����ͬ��size�Ϳ��Խ��и�ֵ������һ�£�
	cout << "sizeof int: " << sizeof(int) << endl;	// 4
	cout << "sizeof float: " << sizeof(float) << endl; // 4
	array<int, 3> ints = {1, 2, 3};
	array<float, 3> floats;
	//floats = ints;	// is this work?
					// ����Ǳ��벻ͨ����
					// ��no match for 'operator=' (operand types are 'std::array<float, 3>' and 'std::array<int, 3>')��
	cout << ints[0] << endl;
	cout << ints[-3] << endl; // ������ͨ�������Ǻ����������ڴ��������Ϊ
	// Ϊ����ʹ��[]��ʽ���������Աʱ���±�������⣬����ʹ��array���ṩ��at()����
	cout << ints.at(-3); // �ú�����鵽�±�Ƿ�ʱ�����жϳ���ִ��
	// ��Ȼat()�����˲����������������Ŀռ䣬����Ҳ������ִ��Ч�ʵ���ʹ��[]��ʽ���������Ա
	// ����˵��û����ȫ�İ취��
}