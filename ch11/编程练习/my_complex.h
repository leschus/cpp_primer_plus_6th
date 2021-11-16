#include <iostream>

class Complex {
 public:
  Complex(double n1 = 0.0, double n2 = 0.0);
  ~Complex();
  // 重载运算符
  // 复数加法
  Complex operator+(const Complex & b) const;
  // 复数减法
  Complex operator-(const Complex & b) const;
  // 复数乘法
  Complex operator*(const Complex & b) const;
  // 复数的数乘运算, 支持`complex * k`形式
  Complex operator*(double k) const;
  // 复数的数乘运算, 支持`k * complex`形式, 声明为内联的友元函数
  // 将该函数声明为友元函数只是为了将其写在类体内(为了整齐),
  // 因为其没有使用到Complex的私有成员, 所以其实可以不用声明为友元函数
  friend Complex operator*(double k, const Complex & b);
  Complex operator~() const;
  // 重载<<, 声明为友元函数
  friend std::ostream & operator<<(std::ostream & os, const Complex & b);
  // 重载>>, 声明为友元函数
  friend std::istream & operator>>(std::istream & is, Complex & b);

 private:
  /* data */
  double real_;       // 复数实部
  double imaginary_;  // 复数虚部
};