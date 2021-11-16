#ifndef WINE_MI_H_
#define WINE_MI_H_

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

class Wine : private std::string,
             private Pair<std::valarray<int>, std::valarray<int>> {
 private:
  typedef std::valarray<int> ArrayInt;
  typedef Pair<ArrayInt, ArrayInt> PairArray;
 public:
  Wine();
  Wine(const char * l, int y, const int yr[], const int bot[]);
  Wine(const char * l, int y);
  void GetBottles();
  const std::string & Label() const;
  int sum() const;
  void Show() const;

 private:
  /* data */
  int years_;
};

#endif // WINE_MI_H_