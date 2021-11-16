#ifndef PERSON_H_
#define PERSON_H_

#include <string>

class Person {
 public:
  Person(const std::string &fname = "unknown",
         const std::string &lname = "unknown");
  virtual ~Person();
  virtual void Show() const;

 protected:
  void Data() const;  // Data()只供本类和派生类使用, 不被外界使用, 因此为protected

 private:
  /* data */
  std::string firstname_;
  std::string lastname_;
};

#endif // PERSON_H_