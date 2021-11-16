#include <iostream>
#include "my_complex.h"

Complex::Complex(double n1, double n2) {
  real_ = n1;
  imaginary_ = n2;
}

Complex::~Complex() {
  // Do nothing
}

Complex Complex::operator+(const Complex & b) const {
  return Complex(real_ + b.real_, imaginary_ + b.imaginary_);
}

Complex Complex::operator-(const Complex & b) const {
  return Complex(real_ - b.real_, imaginary_ - b.imaginary_);
}

Complex Complex::operator*(const Complex & b) const {
  return Complex(real_ * b.real_ - imaginary_ * b.imaginary_,
                 real_ * b.imaginary_ + imaginary_ * b.real_);
}

Complex Complex::operator*(double k) const {
  return Complex(real_ * k, imaginary_ * k);
}

Complex operator*(double k, const Complex & b) {
  return b * k;
}

Complex Complex::operator~() const {
  return Complex(real_, -imaginary_);
}

std::ostream & operator<<(std::ostream & os, const Complex & b) {
  os << "(" << b.real_ << ", " << b.imaginary_ << "i)";
  return os;
}

std::istream & operator>>(std::istream & is, Complex & b) {
  std::cout << "real: ";
  // 如果在输入real_的阶段就读到了'q', 则不需要再请求输入imaginary_
  if (is >> b.real_) {
    std::cout << "imaginary: ";
    is >> b.imaginary_;
  }
  return is;
}