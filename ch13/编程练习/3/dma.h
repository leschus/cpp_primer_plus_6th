#ifndef DMA_H_
#define DMA_H_

#include <iostream>

class DmaAbc {
 public:
  DmaAbc(const char *label = "null", int rating = 0);
  DmaAbc(const DmaAbc &d); // 需要显式提供拷贝构造函数
  virtual ~DmaAbc();
  DmaAbc & operator=(const DmaAbc &d); // 需要显示提供赋值运算符重载
  virtual void View() const = 0;  // 纯虚函数, 继而使得DmaAbc类成为抽象基类
  friend std::ostream & operator<<(std::ostream &os, const DmaAbc &d);

 private:
  /* data */
  char *label_;
  int rating_;
};


class BaseDma : public DmaAbc {
 public:
  BaseDma(const char *label = "null", int rating = 0);
  BaseDma(const DmaAbc &d);
  // BaseDma(const BaseDma & bd); // 无需显式提供拷贝构造函数
  virtual ~BaseDma();
  // BaseDma & operator=(const BaseDma &bd); // 无需显示提供赋值运算符重载
  virtual void View() const;  // 需提供对纯虚函数View()的实现
  friend std::ostream & operator<<(std::ostream &os, const BaseDma &bd);

 private:
  /* data */
};


class LacksDma : public DmaAbc {
 public:
  LacksDma(const char *color = "black", const char *label = "null",
          int rating = 0);
  LacksDma(const char *color, const DmaAbc &d);
  virtual void View() const;
  friend std::ostream & operator<<(std::ostream &os, const LacksDma &ld);

 private:
  /* data */
  enum { COLOR_LEN = 40 };
  char color_[COLOR_LEN];
};


class HasDma : public DmaAbc {
 public:
  HasDma(const char *style = "none", const char *label = "null",
         int rating = 0);
  HasDma(const char *style, const DmaAbc &d);
  HasDma(const HasDma &hd); // 需要显式提供拷贝构造函数
  virtual ~HasDma();
  HasDma & operator=(const HasDma &hd); // 需要显示提供赋值运算符重载
  virtual void View() const;
  friend std::ostream & operator<<(std::ostream &os, const HasDma &hd);

 private:
  /* data */
  char *style_;
};

#endif // DMA_H_