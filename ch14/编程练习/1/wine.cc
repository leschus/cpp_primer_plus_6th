#include "wine.h"

using std::cout;
using std::cin;
using std::endl;

Wine::Wine()
    : label_("none"),
      years_(0),
      yield_(PairArray(ArrayInt(0), ArrayInt(0))) {
  // Do nothing inside
}

Wine::Wine(const char * l, int y, const int yr[], const int bot[])
    : label_(l),
      years_(y),
      yield_(PairArray(ArrayInt(yr, y), ArrayInt(bot, y))) {
  // Do nothing inside
}

Wine::Wine(const char * l, int y)
    : label_(l),
      years_(y),
      yield_(PairArray(ArrayInt(y), ArrayInt(y))) {
  // Do nothing inside
}

void Wine::GetBottles() {
  cout << "Enter " << label_ << " data for " << years_ << " year(s):\n";
  for (int i = 0; i < years_; i++) {
    cout << "Enter year: ";
    cin >> yield_.first()[i]; // 运算符优先级: ./()/[]优先级相同, 结合律从左至右
    cout << "Enter bottles for that year: ";
    cin >> yield_.second()[i];
  }
}

const std::string & Wine::Label() const {
  return label_;
}

int Wine::sum() const {
  // 调用valarray<int>类对象的sum()成员函数
  return yield_.second().sum();
}

void Wine::Show() const {
  cout << "Wine: " << label_ << endl;
  cout << "    Year    Bottles\n";
  for (int i = 0; i < years_; i++) {
    cout << "    " << yield_.first()[i] << "    " << yield_.second()[i] << endl;
  }
}
