// ��Ӧ�鱾�����嵥6.16 readfile.cpp
// C++ ��ȡ�ı��ļ�������

// �����ܣ���ȡ�ı��ļ��е���ֵ��ͳ����ֵ����������ƽ��ֵ

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int SIZE = 60;

int main()
{
	char filename[SIZE];
	ifstream inFile;
	
	cout << "Enter the name of data file: ";
	cin.getline(filename, SIZE);
	inFile.open(filename);
	if (!inFile.is_open())
	{
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating...\n";
		exit(EXIT_FAILURE);
	}
	
	double value;			// �洢ÿһ�ζ�ȡ����ֵ
	double sum = 0.0;		// �ۼ���ֵ�ܺ�
	int count = 0;			// ͳ����ֵ����

	inFile >> value;
	while (inFile.good())
	{
		count ++;		
		sum += value;
		inFile >> value; // ��ȡ��һ��
	}

	// �ϲ���ѭ����ȡ�ı��Ĵ���ο��Լ�Ϊ��
	/*
		while (inFile >> value)
		{
			count ++;
			sum += value;
		}
	*/
	// ��ô����ԭ�����ڣ�inFile>>value���ؽ��ΪinFile����inFile��������Ҫboolֵ�ĵط�ʱ������ΪinFile.good()
	
	if (inFile.eof())
	{
		cout << "End of file reached.\n";
	}
	else if (inFile.fail())
	{
		cout << "Input terminated by data mismatch.\n";
	}
	else
	{
		cout << "Input terminated by unknown reason.\n";
	}

	if (count == 0)
	{
		cout << "No data processed.\n";
	}
	else
	{
		cout << "Items read: " << count << endl;
		cout << "Sum: " << sum << endl;
		cout << "Average: " << sum / count << endl;
	}

	inFile.close(); // �ر��ļ�
}