// C++�еĶ�̬�ڴ����
//		* �漰��new, delete
//		* �˽⾲̬���ࣨstatic binding���Ͷ�̬���ࣨdynamic binding��

#include <iostream>

using namespace std;


int main(void)
{
	// ʹ��newΪ����ʵ������ڴ�
	// new��delete����ʹ��
	double *pd = new double;
	cout << "sizeof pd: " << sizeof(pd) << endl; // ָ��pd�ĳ��ȣ�8��64λϵͳ��
	cout << "pd: " << pd << endl; // new���pd��ֵ
	*pd = 3.14;
	delete pd;
	cout << "pd: " << pd << endl; // delete֮��pd��ֵ

	// ʹ��new []Ϊ��̬��������ڴ�
	// new [] ��delete []����ʹ��
	int size = 10;
	int *psome = new int [size];
	cout << "psome: " << psome << endl; // new���psome��ֵ
	
	for (int i=0; i<size; i++)
	{
		psome[i] = i;
	}
	delete [] psome;
	cout << "psome: " << psome << endl; // delete֮��psome��ֵ
	
	/*
		��������
		pd: 0xf815f0
		pd: 0xf815f0
		psome: 0xf815f0
		psome: 0xf815f0
		�������delete֮��ָ���ֵ��û�иı䣬����ֻ��ָ����ָ����ڴ�ռ䱻���ͷš���
		����Ƭ�ڴ�ռ��ڴ˺�����ٴα�������������ݶ����ˡ�
	*/

	/*
		����֪ʶ��
			delete[]���ͷŶ�̬����Ŀռ�ʱ���֪������೤��
			��C++����������Ļ��ƣ�new[]���䶯̬����ʱ��������һСƬ�ռ䣨��4�ֽڣ�
			���Ա������鳤�ȣ���һСƬ�ռ�λ��������ռ�Ŀ�ͷ�������磬char * pc = new char[10]��������ʼ
			��ַΪ0x32100000��һƬ�ռ䣬�ռ��СΪ14�ֽڶ���10�������Ὣ0x3210000~0x32100003���ĸ��ֽڱ�����
			���ڴ洢���鳤�ȣ�����0x32100004��Ϊnew�ķ���ֵ����pc��
			delete[]ʱ�������pc-4��λ�ö�ȡ�����鳤�ȣ��̶���֪��Ҫ�ͷŶ��ٸ�����Ԫ�صĿռ���
	*/

	//	�������⣺delete[]�ڴ�������������͵Ķ�̬���飨int���飩���������͵Ķ�̬���飨��string��������飩ʱ
	// �к�����


	// ʹ�ö�̬���飨��������ͨ����ķ�ʽ���ʶ�̬�����е�Ԫ�أ�
	// �ɴ˿������C/C++����������ָ������λ�����Ч��
	int *pNums = new int[3];
	pNums[0] = 11;
	pNums[1] = 22;
	pNums[2] = 33;
	cout << "first element of pNums: " << pNums[0] << endl;

	int nums[3] {11, 22, 33};

	// ����һ�������ǣ���������ֵ���ܱ��޸ģ���ָ�����
	pNums += 1; // OK
	//nums += 1; // Wrong! -- "incompatible types in assignment of 'int' to 'int [3]"

	//	����һ���������ڣ���������ʹ��sizeof�õ���������ĳ��ȣ�����ָ��ʹ��sizeof�õ�����ָ��ĳ��ȣ�
	// ��ʹ��ָ��ָ����һ������
	cout << "sizeof nums: " << sizeof(nums) << endl;	// 12�����鳤��Ϊ3*4=12
	cout << "sizeof pNums: " << sizeof(pNums) << endl;	// 4��ָ��ռ8�ֽڣ���Ϊ��64λϵͳ



	cout << "pNums[0]: " << pNums[0] << endl;  // 22
	// ���������������pNumsֵ��1������Ч����pNums��ԭ�ȵ�ָ���һ��Ԫ��11ת��ָ���˵ڶ���
	// Ԫ��22������int����Ӧ��ռ4���ֽڣ�����ʽ�еġ���1��ʵ�ʲ����ˡ��ڴ��ַ��4����Ч������
	// ˵��C++��ָ�����͵�����������������⴦����ָ����ָ����������Ҳ�������ڡ�
	//
	// �ܽ���˵����ָ�������1�������ӵ�ֵ����ָ�������ռ�õ��ֽ���


	pNums -= 1; // reset value of pNums;
	delete [] pNums; // free the memory


}