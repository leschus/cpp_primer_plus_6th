#include <iostream>
#include <cstring>
#include "classic.h"

Classic::Classic() : Cd() {
  main_works_ = new char[1];
  main_works_[0] = '\0';
  // OR: main_works = nullptr;
}

Classic::Classic(const char * main_works, const char * performers,
                 const char * label, int selections, double playtime)
    : Cd(performers, label, selections, playtime) {
  int len = strlen(main_works);
  main_works_ = new char[len + 1];
  strcpy(main_works_, main_works);
}

Classic::Classic(const char * main_works, const Cd & d) : Cd(d) {
  // 此处成员初始化列表中调用基类的隐式拷贝构造函数来初始化派生类对象的基类部分.
  // 之所以可行, 是因为基类中的数据成员可以通过浅拷贝正确地生成副本
  int len = strlen(main_works);
  main_works_ = new char[len + 1];
  strcpy(main_works_, main_works);
}

Classic::Classic(const Classic & cc) : Cd(cc) {
  // 基类的隐式拷贝构造函数接收一个基类对象的引用, 而由于基类对象的引用可以引用
  // 派生类对象, 因此成员初始化列表中使用Cd(cc)来初始化派生类对象的基类部分是可
  // 行的
  int len = strlen(cc.main_works_);
  main_works_ = new char[len + 1];
  strcpy(main_works_, cc.main_works_);
}

Classic::~Classic() {
  delete [] main_works_;
}

Classic & Classic::operator=(const Classic & cc) {
  if (this == &cc)                    // 处理自我赋值的情况
    return *this;
  Cd::operator=(cc);                  // 对基类部分数据进行赋值!!!
  delete [] main_works_;              // 释放原有的main_works_内存
  int len = strlen(cc.main_works_);
  main_works_ = new char[len + 1];    // 重新为main_works_分配内存
  strcpy(main_works_, cc.main_works_);
  return *this;
}

void Classic::Report() const {
  Cd::Report();
  std::cout << "          Main works: " << main_works_ << std::endl;
}