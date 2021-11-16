#include <iostream>
#include <cstring>
#include "cd.h"

Cd::Cd() : performers_("Unkown"), label_("Unkown") {
  selections_ = 0;
  playtime_ = 0.0;
}

Cd::Cd(const char * performers, const char * label,
       int selections, double playtime) {
  // 注意: 无法使用成员初始化列表来将performers_/label_初始化为performers/label
  // 因此借助于strcpy()
  strcpy(performers_, performers);
  strcpy(label_, label);
  selections_ = selections;
  playtime_ = playtime;
}

Cd::~Cd() { // 注意: 在实现文件中提供虚函数的定义时, 函数头中不再需要virtual关键字
  // Do nothing
}

void Cd::Report() const {
  using std::cout;
  using std::endl;
  using std::ios_base;

  cout << "          Performers: " << performers_ << endl;
  cout << "               Label: " << label_ << endl;
  cout << "Number of selections: " << selections_ << endl;

  // save original format
  auto original_format = cout.setf(ios_base::fixed, ios_base::floatfield);
  auto original_percision = cout.precision(2);
  cout << "      Total playtime: " << playtime_ << endl;
  // restore float format
  cout.setf(original_format, ios_base::floatfield);
  cout.precision(original_percision);
}