// 定义Person类
// 存储firstname和lastname, 并提供两种显示姓名的方法

#include <string>

class Person
{
 public:
  Person() { lname_ = ""; fname_[0] = '\0'; }
  Person(const std::string &ln, const char *fn = "Heyyou");
  void Show() const; // "firstname lastname" format
  void FormalShow() const; // "lastname, firstname" format

 private:
  static const int kLimit_ = 25;
  std::string lname_;
  char fname_[kLimit_];
};
