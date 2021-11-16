#include <iostream>
#include "sales.h"

int main()
{
	using namespace SALES;

	Sales s;

	setSales(s);

	showSales(s);
}

/*
≤‚ ‘ ‰≥ˆ:

Enter the sales of 4 quarters:
100 200 300 400
sales for 4 quarters:
100.00  200.00  300.00  400.00
Max: 400.00
Min: 100.00
Average: 250.00

*/