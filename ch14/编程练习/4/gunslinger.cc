#include <ctime>
#include <cstdlib>
#include <iostream>
#include "gunslinger.h"

Gunslinger::Gunslinger(const std::string &fname, const std::string &lname,
                       int cracks)
    : Person(fname, lname), cracks_(cracks) {
  // std::cout << "Gunslinger constructor called.\n";
}

Gunslinger::Gunslinger(const Person &person, int cracks)
    : Person(person), cracks_(cracks) {}  // 使用了Person类的默认拷贝构造函数

double Gunslinger::Draw() const {
  srand(time(0));
  // 返回一个0~1之间的随机浮点数
  return (rand() % 1001) * 0.001;
}

void Gunslinger::Data() const {
  std::cout << "Cracks: " << cracks_ << std::endl;
}

void Gunslinger::Show() const {
  std::cout << "Category: Gunslinger\n";
  Person::Data();
  Data();
}