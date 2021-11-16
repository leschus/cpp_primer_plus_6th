#include "studenti.h"

double Student::Average() const {
  // 注意: 使用私有继承时只能使用类名和作用域解析运算符来调用方法
  if (ArrayDbl::size())
    return ArrayDbl::sum() / ArrayDbl::size();
  else
    return 0;
}

const std::string & Student::Name() const {
  // 注意: 使用私有继承时只能使用强制类型转换来访问基类对象
  return (const std::string &) *this;
}

double & Student::operator[](int n) {
  return ArrayDbl::operator[](n);
}

double Student::operator[](int n) const {
  return ArrayDbl::operator[](n);
}

std::istream & operator>>(std::istream &is, Student &stu) {
  is >> (std::string &)stu;
  return is;
}

std::istream & getline(std::istream &is, Student &stu) {
  getline(is, (std::string &)stu);
  return is;
}

std::ostream & operator<<(std::ostream &os, const Student &stu) {
  // 同样使用强制类型转换访问基类对象
  os << "Scores for " << (const std::string &)stu << ":\n";
  stu.arr_out(os);
  return os;
}

std::ostream & Student::arr_out(std::ostream &os) const {
  int i;
  int len = ArrayDbl::size();
  if (len) {
    for (i = 0; i < len; i++) {
      os << ArrayDbl::operator[](i) << " ";
      if (i % 5 == 4)
        os << std::endl;
    }
    if (i % 5 != 0)
      os << std::endl;
  }
  else {
    os << "Empty Array\n";
  }
  return os;
}