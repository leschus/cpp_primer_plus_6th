#ifndef PORT_H_
#define PORT_H_

#include <iostream>

class Port {
 public:
  Port(const char *brand = "none", const char *style = "none", int bottles = 0);
  Port(const Port &p);
  virtual ~Port() { delete [] brand_; }
  Port & operator=(const Port &p);
  Port & operator+=(int b);
  Port & operator-=(int b);
  int BottleCount() const { return bottles_; }
  virtual void Show() const;
  friend std::ostream &operator<<(std::ostream &os, const Port &p);

 private:
  /* data */
  static const int kStyleLen = 20;
  char *brand_;
  char style_[kStyleLen];
  int bottles_;
};

#endif // PORT_H_