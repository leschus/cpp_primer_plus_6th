#ifndef POKERPLAYER_H_
#define POKERPLAYER_H_

#include <string>
#include "person.h"

class PokerPlayer : virtual public Person {
 public:
  PokerPlayer(const std::string &fname = "Unknown",
              const std::string &lname = "Unknonw");
  explicit PokerPlayer(const Person &person);
  int Draw() const;
  virtual void Show() const;

 private:
  /* data */
};

#endif // POKERPLAYER_H_