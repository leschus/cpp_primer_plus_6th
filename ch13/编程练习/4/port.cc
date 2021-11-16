#include <iostream>
#include <cstring>
#include "port.h"

Port::Port(const char *brand, const char *style, int bottles) {
  brand_ = new char[strlen(brand) + 1];
  strcpy(brand_, brand);
  strncpy(style_, style, kStyleLen - 1);
  style_[kStyleLen - 1] = '\0';
  bottles_ = bottles;
}

Port::Port(const Port &p) {
  brand_ = new char[strlen(p.brand_) + 1];
  strcpy(brand_, p.brand_);
  strcpy(style_, p.style_); // p已是一个合法的Port对象, 因此这里不必要用strncpy()
  bottles_ = p.bottles_;
}

Port & Port::operator=(const Port &p) {
  if (this == &p)
    return *this;
  delete [] brand_;
  brand_ = new char[strlen(p.brand_) + 1];
  strcpy(brand_, p.brand_);
  strcpy(style_, p.style_);
  bottles_ = p.bottles_;
  return *this;
}

Port & Port::operator+=(int b) {
  if (b < 0) {
    std::cout << "Number of bottles cannot be negative. "
              << "Process cancelled.\n";
    return *this;
  }
  bottles_ += b;
  return *this;
}

Port & Port::operator-=(int b) {
  if (b < 0) {
    std::cout << "Number of bottles cannot be negative. "
              << "Process cancelled.\n";
    return *this;
  }
  bottles_ -= b;
  return *this;
}

void Port::Show() const {
  std::cout << "Brand: " << brand_ << "\nKind: " << style_
            << "\nBottles: " << bottles_ << std::endl;
}

std::ostream & operator<<(std::ostream &os, const Port &p) {
  os << p.brand_ << ", " << p.style_ << ", " << p.bottles_;
  return os;
}