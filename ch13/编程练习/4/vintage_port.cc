#include <iostream>
#include <cstring>
#include "vintage_port.h"

VintagePort::VintagePort() : Port("none", "vintage", 0) {
  // 注意: 不能通过成员初始化列表中添加nickname_("none")来初始化nickname_
  // 必须通过new为nickname_在堆中分配内存
  nickname_ = new char[5];
  strcpy(nickname_, "none");
  year_ = 0;
}

VintagePort::VintagePort(const char *brand, int bottles, const char *nickname,
                         int year) : Port(brand, "vintage", bottles) {
  nickname_ = new char[strlen(nickname) + 1];
  strcpy(nickname_, nickname);
  year_ = year;
}

VintagePort::VintagePort(const VintagePort &vp) : Port(vp) {
  // 使用Port类的拷贝构造函数初始化新VintagePort对象的基类部分
  // 因为: 基类对象引用可以指向派生类对象
  nickname_ = new char[strlen(vp.nickname_) + 1];
  strcpy(nickname_, vp.nickname_);
  year_ = vp.year_;
}

VintagePort & VintagePort::operator=(const VintagePort &vp) {
  if (this == &vp)
    return *this;
  // 使用基类的赋值运算符来将vp的基类部分赋给当前VintagePort对象的的基类部分
  Port::operator=(vp);
  delete [] nickname_;
  nickname_ = new char[strlen(vp.nickname_) + 1];
  strcpy(nickname_, vp.nickname_);
  year_ = vp.year_;
  return *this;
}

void VintagePort::Show() const {
  Port::Show();
  std::cout << "Nickname: " << nickname_ << "\nYear: " << year_ << std::endl;
}

std::ostream & operator<<(std::ostream &os, const VintagePort &vp) {
  os << (const Port &)vp;
  os << ", " << vp.nickname_ << ", " << vp.year_ ;
  return os;
}