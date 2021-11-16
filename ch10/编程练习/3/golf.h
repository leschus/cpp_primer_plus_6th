// 定义Golf类

class Golf {
 public:
  Golf(const char *name = "Unknown", int hc = 0);
  // 以交互方式设置对象的数据成员
  // 在用户尝试将姓名设置为空串时退出并返回0
  int SetGolf();
  void set_handicap(int hc);
  void Show();

 private:
  static const int kLen_ = 40;
  char fullname_[kLen_];
  int handicap_;
};