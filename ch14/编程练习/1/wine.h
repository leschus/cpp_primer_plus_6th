#ifndef WINE_H_
#define WINE_H_

#include <iostream>
#include <string>
#include <valarray>

template <typename T1, typename T2>
class Pair {
 public:
  Pair(const T1 & a, const T2 & b) : a_(a), b_(b) {}
  Pair() {}
  T1 & first() { return a_; }
  T1 first() const { return a_; }
  T2 & second() { return b_; }
  T2 second() const { return b_; }

 private:
  T1 a_;
  T2 b_;
};

class Wine {
 private:
  /* private definitions */
  typedef std::valarray<int> ArrayInt;
  typedef Pair<ArrayInt, ArrayInt> PairArray;
 public:
  // default constructor
  Wine();
  // initialize label to l, number of years to y,
  // vintage years to yr[], bottles to bot[]
  Wine(const char * l, int y, const int yr[], const int bot[]);
  // initialize label to l, number of years to y,
  // create array objects of length y
  Wine(const char * l, int y);
  // ask for entering the vintage years and bottles
  void GetBottles();
  // return a conference of label_
  const std::string & Label() const;
  // return the sum of bottles in stored vintage years
  int sum() const;
  void Show() const;

 private:
  /* data */
  std::string label_;     // 葡萄酒名称
  int years_;              // 共保存了多少年的产量信息
  PairArray yield_;       // 产量
};

#endif // WINE_H_