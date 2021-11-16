// 对应书本程序清单6.16 readfile.cpp
// C++ 读取文本文件中内容

// 程序功能：读取文本文件中的数值，统计数值个数并计算平均值

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
	
	double value;			// 存储每一次读取到的值
	double sum = 0.0;		// 累计数值总和
	int count = 0;			// 统计数值个数

	inFile >> value;
	while (inFile.good())
	{
		count ++;		
		sum += value;
		inFile >> value; // 读取下一个
	}

	// 上部分循环读取文本的代码段可以简化为：
	/*
		while (inFile >> value)
		{
			count ++;
			sum += value;
		}
	*/
	// 这么做的原理在于，inFile>>value返回结果为inFile，而inFile被用在需要bool值的地方时，其结果为inFile.good()
	
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

	inFile.close(); // 关闭文件
}