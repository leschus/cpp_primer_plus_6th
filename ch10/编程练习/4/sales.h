namespace SALES
{
  const int kQuarters = 4;

  class Sales {
   public:
    Sales(const double sales[], int n);
    // 将数组ar中的min{4, n}个拷贝到s的sales成员中, 计算拷贝的这几个值的
    // 平均值/最大值/最小值, 并将结果赋给对应的成员. sales中没有被填充的剩余
	  // 项赋值为0.
    void SetSales();
    void ShowSales();

   private:
    double sales_[kQuarters];
    double average_;
    double max_;
    double min_;
  };
} // namespace SALES
