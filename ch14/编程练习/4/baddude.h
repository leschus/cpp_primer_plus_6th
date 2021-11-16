#ifndef BADDUDE_H_
#define BADDUDE_H_

#include <string>
#include "gunslinger.h"
#include "pokerplayer.h"

class BadDude : public Gunslinger, public PokerPlayer {
 public:
  BadDude(const std::string &fname = "Unknown",
          const std::string &lname = "Unknown",
          int cracks = 0);
  explicit BadDude(const Person &person, int cracks = 0);
  explicit BadDude(const Gunslinger &gunslinger); // explicit避免隐式转换
  explicit BadDude(const PokerPlayer &pokerplayer, int cracks = 0);
  double Gdraw() const;
  int Cdraw() const;
  virtual void Show() const;

 private:
  /* data */
};

#endif // BADDUDE_H_