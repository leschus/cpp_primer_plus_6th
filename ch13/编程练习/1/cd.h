#ifndef CD_H_
#define CD_H_

class Cd { // represents a CD disk
 public:
  Cd(const char * performers, const char * label,
     int selections, double playtime);
  // Cd(const Cd & d);  // 基类不需要显式提供拷贝构造函数
  Cd();
  virtual ~Cd();
  virtual void Report() const;  // reports all CD data
  // Cd & operator=(const Cd & d);  // 基类不需要显式提供赋值运算符

 private:
  /* data */
  char performers_[50];
  char label_[20];
  int selections_;   // number of selections
  double playtime_;  // playing time in minutes

};

#endif // CD_H_