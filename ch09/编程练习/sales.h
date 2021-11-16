namespace SALES
{
	const int QUARTERS = 4;

	struct Sales
	{
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	};

	// 将数组ar中的min{4, n}个拷贝到s的sales成员中, 
	// 计算拷贝的这几个值的平均值/最大值/最小值, 并
	// 将结果赋给对应的成员. sales中没有被填充的剩余
	// 项赋值为0
	void setSales(Sales &s, const double ar[], int n);

	// 交互式地输入4个值存储到s地sales成员中, 接着计算它们
	// 的平均值/最大值/最小值, 并赋给对应的成员
	void setSales(Sales &s);

	// 打印s的信息
	void showSales(const Sales &s);
}