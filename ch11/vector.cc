#include <cmath>
#include "vector.h"

namespace VECTOR
{
  // compute degrees in one radian
  const double RadianToDegree = 45.0 / atan(1.0);
  // should be about 57.2957795130823

  Vector::Vector() {
    x = y = mag = ang = 0.0;
    mode = RECT;
  }

  Vector::Vector(double n1, double n2, Mode m) {
    mode = m;
    if (mode == RECT) {
      x = n1;
      y = n2;
      set_mag();
      set_ang();
    }
    else if (mode == POL) {
      mag = n1;
      ang = n2 / RadianToDegree;
      set_x();
      set_y();
    }
    else {
      std::cout << "Incorrect 3rd argument to Vector() -- ";
      std::cout << "Vector set to 0\n";
      x = y = mag = ang = 0.0;
      mode = RECT;
    }
  }

    void Vector::reset(double n1, double n2, Mode m) {
    mode = m;
    if (mode == RECT) {
      x = n1;
      y = n2;
      set_mag();
      set_ang();
    }
    else if (mode == POL) {
      mag = n1;
      ang = n2 / RadianToDegree;
      set_x();
      set_y();
    }
    else {
      std::cout << "Incorrect 3rd argument to reset() -- ";
      std::cout << "Vector set to 0\n";
      x = y = mag = ang = 0.0;
      mode = RECT;
    }
  }

  Vector::~Vector() {
    // Do nothing
  }

  void Vector::polar_mode() {
    mode = POL;
  }

  void Vector::rect_mode() {
    mode = RECT;
  }

  Vector Vector::operator+(const Vector & b) const {
    return Vector(x + b.x, y + b.y); //进行运算时使用的是直角坐标系
  }

  Vector Vector::operator-(const Vector & b) const {
    return Vector(x - b.x, y - b.y);
  }

  Vector Vector::operator-() const {
    return Vector(-x, -y);
  }

  Vector Vector::operator*(double n) const {
    return Vector(n * x, n * y);
  }

  Vector operator*(double n, const Vector & b) {
    return b * n;
  }

  std::ostream & operator<<(std::ostream &os, const Vector & b) {
    if (b.mode == Vector::RECT) { // 注意这里需要使用作用域运算符::
      os << "(x, y) = (" << b.x << ", " << b.y << ")";
    }
    else if (b.mode == Vector::POL) {
      os << "(m, a) = (" << b.mag << ", " << b.ang << ")";
    }
    else {
      os << "Vector object mode is invalid";
    }
    return os;
  }

  void Vector::set_mag() {
    mag = sqrt(x * x + y * y);
  }

  void Vector::set_ang() {
    if (x == 0 && y == 0)
      ang = 0.0;
    else
      ang = atan2(y, x);
  }

  void Vector::set_x() {
    x = mag * cos(ang);
  }

  void Vector::set_y() {
    y = mag * sin(ang);
  }

} // namespace VECTOR
