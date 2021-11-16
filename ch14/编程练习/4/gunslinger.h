#ifndef GUNSLINGER_H_
#define GUNSLINGER_H_

#include <string>
#include "person.h"

class Gunslinger : virtual public Person {
 public:
  Gunslinger(const std::string &fname = "Unknown",
             const std::string &lname = "Unknown",
             int cracks = 0);
  explicit Gunslinger(const Person &person, int cracks = 0);
  double Draw() const;        // 返回枪手的拔枪时间(使用rand()实现)
  virtual void Show() const;

 protected:
  void Data() const;

 private:
  /* data */
  int cracks_;                // 枪身上的裂痕数
};

#endif // GUNSLINGER_H_