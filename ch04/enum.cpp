// C++�е�ö������

// ö�����Ϳ����������const����������

// ʾ���� enum spectrum {red, blue, orange, yellow, pink, purple};
// ����䶨����ö�����͵�����Ϊspectrum���������˸����͵�6�ֿ���ȡֵ���൱��6�����ų���
// Ĭ������£�ö�������ֵķ��ų����Ǵ�0��ʼ�ۼӵ�����ֵ
// ��ˣ�redֵΪ0��blueֵΪ1���������ơ�
// spectrumö����ֻ����6��ȡֵ�����Ҫ��������ȡֵ֮���һ��ֵ����spectrumö�ٱ�����������ִ���

#include <iostream>
using namespace std;


enum spectrum {Red, Blue, Orange, Yellow, Pink, Purple};

// ���Ŀ��ֻ��ʹ��ö��������һ�����ų�������û�����õ�ö��������������
// ���Զ���������ö������
// ��1��ʼ���Ӷ�����һ������1��Ӧ�������������7��Ӧ
enum {Monday = 1, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday};

// ���Դ������ֵ��ͬ��ö����
enum {One = 1, AnotherOne = 1, Two};

int main(void)
{
	spectrum band; // ����һ��ö�ٱ���
	
	band = Red; // �Ϸ���ö�ٱ�����ֵ
	//band = 1;	// �Ƿ��ĸ�ֵ����ʹ1��spectrumö�����͵�ȡֵ��Χ0~5֮��
				//// ��invalid conversion from 'int' to 'spectrum'��
	//band = 10;	// �Ƿ��ĸ�ֵ
	band = spectrum(1); // ʹ��ǿ������ת������ʵ�ֽ�int��ֵ��ö�ٱ���
	band = spectrum(10); // ��һ��������Χ��intֵǿ��ת������ö���������ᵼ�²�ȷ���Ľ��
						 // ��������У������ȷ�����band��ֵΪ10

	cout << "size of spectrum: " << sizeof(spectrum) << endl;	// �������4�������Ʋ�ö��������
																// �����ڲ��൱����Ϊһ��int�ڴ洢
	cout << band << endl;

	// ���������ʺ�ʹ��ö������������ÿһ��case
	int day;
	cout << "What day is today? (input a number, 1 implies Monday, 2 implies Tuesday...)\n";
	cin >> day;
	switch(day)
	{
		case Monday:
			cout << "Today is Monday, I have to go to work.\n";
			break;
		case Tuesday:
			cout << "Tuesday, 4 days to go.\n";
			break;
		case Wednesday:
			cout << "Wednesday, 3 days to go.\n";
			break;
		case Thursday:
			cout << "2 days to go.\n";
			break;
		case Friday:
			cout << "Finally, only have to struggle the last day.\n";
			break;
		case Saturday:
			cout << "Sleeped well, I'm free now.\n";
			break;
		case Sunday:
			cout << "A nice weekend.\n";
			break;
		default:
			cout << "default.\n";
	}

	// ����ֵ��ͬ��ö��������Ȼ�������Ʋ�ͬ������ͬ��Ϊswitch�е�����case
	// ��Ϊ����case֮��ֵ������ͬ
	// ���򱨴���duplicate case value��
	int num = 1;
	switch(num)
	{
		case One:
			cout << "case 1\n";
			break;
		//case AnotherOne:
			//cout << "another case 1\n";
			//break;
		case Two:
			cout << "case 2\n";
			break;
		default:
			cout << "default.\n";
	}


}