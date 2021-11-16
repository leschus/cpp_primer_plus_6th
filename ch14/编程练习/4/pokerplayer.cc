#include <ctime>
#include <cstdlib>
#include <iostream>
#include "pokerplayer.h"

PokerPlayer::PokerPlayer(const std::string &fname, const std::string &lname)
    : Person(fname, lname) {
  // std::cout << "PokerPlayer constructor called.\n";
}

PokerPlayer::PokerPlayer(const Person &person) : Person(person) {}

int PokerPlayer::Draw() const {
  srand(time(0));
  // 返回一个1到52之间的随机整数
  return rand() / 52 + 1;
}

void PokerPlayer::Show() const {
  std::cout << "Category: PokerPlayer\n";
  Person::Data();
}