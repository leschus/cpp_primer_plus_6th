#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include <valarray> // 元素为数值类型的数组, 常用方法sum(), max(), min()等

class Student {
 private:
  /* private definitions */
  typedef std::valarray<double> ArrayDbl;
 public:
  Student() : name_("Null Student"), scores_() {};
  explicit Student(const std::string &name) : name_(name), scores_() {}
  explicit Student(int n) : name_("Nully"), scores_(n) {}
  Student(const std::string &name, int n) : name_(name), scores_(n) {}
  Student(const std::string &name, ArrayDbl scores)
      : name_(name), scores_(scores) {}
  Student(const char *str, const double *pd, int n)
      : name_(str), scores_(pd, n) {}
  ~Student() {}
  double Average() const;
  const std::string & Name() const;
  double & operator[](int i);
  double operator[](int i) const;
  // input
  friend std::istream & operator>>(std::istream &is, Student &stu); // 1 word
  friend std::istream & getline(std::istream &is, Student &stu);  // 1 line
  // output
  friend std::ostream & operator<<(std::ostream &os, const Student &stu);

 private:
  /* data */
  std::string name_;
  ArrayDbl scores_;
  /* private method */
  std::ostream &arr_out(std::ostream &os) const;
};

#endif // STUDENT_H_