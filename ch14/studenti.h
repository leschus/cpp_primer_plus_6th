// 重写Student类, 使用私有继承实现has-a关系

#ifndef STUDENTI_H_
#define STUDENTI_H_

#include <iostream>
#include <string>
#include <valarray>

class Student : private std::string, private std::valarray<double> {
 private:
  /* private definitions */
  typedef std::valarray<double> ArrayDbl;
 public:
  Student() : std::string("Null Student"), ArrayDbl() {}
  explicit Student(const std::string &name) : std::string(name), ArrayDbl() {}
  explicit Student(int n) : std::string("Nully"), ArrayDbl(n) {}
  Student(const std::string &name, int n) : std::string(name), ArrayDbl(n) {}
  Student(const std::string &name, const ArrayDbl &score)
      : std::string(name), ArrayDbl(score) {}
  Student(const std::string &name, const double &pd, int n)
      : std::string(name), ArrayDbl(pd, n) {}
  ~Student() {}
  double Average() const;
  const std::string &Name() const;
  double & operator[](int n);
  double operator[](int n) const;
  // input
  friend std::istream & operator>>(std::istream &is, Student &stu); // 1 word
  friend std::istream & getline(std::istream &is, Student &stu);  // 1 line
  // output
  friend std::ostream & operator<<(std::ostream &os, const Student &stu);

 private:
  /* private methods */
  std::ostream & arr_out(std::ostream &os) const;

};

#endif // STUDENTI_H_