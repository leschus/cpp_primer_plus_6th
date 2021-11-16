#include <iostream>
#include "sales.h"

namespace SALES
{
  Sales::Sales(const double sales[], int n) {
    // 这里假定传入的n值非负, 因此不对n为负值做特殊处理
		int n_fixed = n > kQuarters ? kQuarters : n;

		for (int i = n_fixed; i < kQuarters; i++) {
			sales_[i] = 0.0;
		}
		if (n_fixed == 0) {
			average_ = 0.0;
			max_ = 0.0;
			min_ = 0.0;
		}
		else {
			double sum = 0.0;
			min_ = max_ = sales[0];
			for (int i = 0; i < n_fixed; i++) {
				sales_[i] = sales[i];
				if(sales[i] > max_)
					max_ = sales[i];
				else if(sales[i] < min_)
					min_ = sales[i];
				sum += sales[i];
			}
			average_ = sum / n_fixed;
		}
  }

  void Sales::SetSales() {
    double ar[kQuarters];
		std::cout << "Enter the sales of " << kQuarters << " quarters:\n";
		for (int i = 0; i < kQuarters; i++) {
			std::cin >> ar[i];
		}
    *this = Sales(ar, kQuarters);
  }

  void Sales::ShowSales() {
    using std::cout;
		using std::endl;
		using std::ios_base;

		// 输出结果保留两位小数
		auto orig = cout.setf(ios_base::fixed, ios_base::floatfield);
		auto prec = cout.precision(2);

		cout << "sales for " << kQuarters << " quarters:\n";
		for (int i = 0; i < kQuarters; i++) {
			cout << sales_[i] << "\t";
		}
		cout << endl;
		cout << "Max: " << max_ << endl;
		cout << "Min: " << min_ << endl;
		cout << "Average: " << average_ << endl;

    // 复原浮点数输出格式
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
  }

} // namespace SALES
