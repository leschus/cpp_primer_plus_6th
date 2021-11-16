#include <iostream>
#include "baddude.h"

BadDude::BadDude(const std::string &fname, const std::string &lname, int cracks)
    : Person(fname, lname),
      Gunslinger(fname, lname, cracks),
      PokerPlayer(fname, lname) {
  // std::cout << "BadDude constructor called.\n";
}

BadDude::BadDude(const Person &person , int cracks)
    : Person(person), Gunslinger(person, cracks), PokerPlayer(person) {}

BadDude::BadDude(const Gunslinger &gunslinger)
    : Person(gunslinger), Gunslinger(gunslinger), PokerPlayer(gunslinger) {}
// 用到的特性: 函数参数以基类对象引用作为形参时, 可以接受派生类对象的引用作为实参

BadDude::BadDude(const PokerPlayer &pokerplayer, int cracks)
    : Person(pokerplayer),
      Gunslinger(pokerplayer, cracks),
      PokerPlayer(pokerplayer) {}

double BadDude::Gdraw() const {
  return Gunslinger::Draw();
}

int BadDude::Cdraw() const {
  return PokerPlayer::Draw();
}

void BadDude::Show() const {
  std::cout << "Category: BadDude\n";
  Person::Data();
  Gunslinger::Data();
}