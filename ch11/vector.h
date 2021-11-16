#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

namespace VECTOR
{
  class Vector {
  public:
    /* public data */
    enum Mode {RECT, POL}; // 模式: RECT直角坐标系, POL极坐标系
    /* public methods */
    Vector();
    Vector(double n1, double n2, Mode m = RECT);
    void reset(double n1, double n2, Mode m = RECT);
    ~Vector();
    double xval() const { return x; }
    double yval() const { return y; }
    double magval() const { return mag; }
    double angval() const { return ang; }
    void polar_mode(); // set mode to POL
    void rect_mode();  // set mode to RECT
    // 运算符重载
    Vector operator+(const Vector & b) const;
    Vector operator-(const Vector & b) const; // 重载双目运算符-
    Vector operator-() const; // 重载单目运算符-, 用于反转向量的方向
    Vector operator*(double n) const; // 乘以一个放缩倍数
    // 友元函数
    friend Vector operator*(double n, const Vector & b);
    friend std::ostream & operator<<(std::ostream & os, const Vector & b);

  private:
    /* data */
    double x;         // 横坐标
    double y;         // 纵坐标
    double mag;  // 极径, magnitude
    double ang;     // 极角, angle
    Mode mode;        // 模式
    /* private methods for setting values */
    // 根据直角坐标值设置极径mag
    void set_mag();
    // 根据直角坐标值设置极角ang
    void set_ang();
    // 根据极坐标值设置横坐标x
    void set_x();
    // 根据极坐标值设置纵坐标y
    void set_y();
  };

} // namespace VECTOR

#endif // VECTOR_H_