#include <iostream>
#include "sales.h"

namespace SALES
{
	void setSales(Sales &s, const double ar[], int n)
	{
		// 这里假定传入的n值非负, 因此不对n为负值做特殊处理
		int n_fixed = n > QUARTERS ? QUARTERS : n;
		
		for (int i = n_fixed; i < QUARTERS; i++)
		{
			s.sales[i] = 0.0;
		}

		if (n_fixed == 0)
		{
			s.average = 0.0;
			s.max = 0.0;
			s.min = 0.0;
		}
		else
		{
			double sum = 0.0;
			s.min = s.max = ar[0];
			for (int i = 0; i < n_fixed; i++)
			{
				s.sales[i] = ar[i];
				
				if(ar[i] > s.max)
					s.max = ar[i];
				else if(ar[i] < s.min)
					s.min = ar[i];
				
				sum += ar[i];
			}

			s.average = sum / n_fixed;
		}	
	}

	void setSales(Sales &s)
	{
		double ar[QUARTERS];
		std::cout << "Enter the sales of " << QUARTERS << " quarters:\n";
		for (int i = 0; i < QUARTERS; i++)
		{
			std::cin >> ar[i];
		}

		setSales(s, ar, QUARTERS);
	}

	void showSales(const Sales &s)
	{
		using std::cout;
		using std::endl;
		using std::ios_base;

		// 输出结果保留两位小数
		cout.setf(ios_base::fixed);
		cout.precision(2);

		cout << "sales for " << QUARTERS << " quarters:\n";
		for (int i = 0; i < QUARTERS; i++)
		{
			cout << s.sales[i] << "\t";
		}
		cout << endl;

		cout << "Max: " << s.max << endl;
		cout << "Min: " << s.min << endl;
		cout << "Average: " << s.average << endl;
	}
}