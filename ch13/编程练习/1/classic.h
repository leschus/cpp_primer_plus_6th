#ifndef CLASSIC_H_
#define CLASSIC_H_

#include "cd.h"

class Classic : public Cd {
 public:
  Classic(const char * main_works, const char * performers,
          const char * label, int selections, double playtime);
  Classic(const char * main_works, const Cd & d);
  // 派生类构造函数需要用到new为数据成员分配内存
  // 因此需要显式提供拷贝构造函数和赋值运算符
  Classic(const Classic & cc);
  Classic();
  Classic & operator=(const Classic & cc);

  virtual void Report() const;
  virtual ~Classic();


 private:
  /* data */
  char *main_works_;
};

#endif // CLASSIC_H_