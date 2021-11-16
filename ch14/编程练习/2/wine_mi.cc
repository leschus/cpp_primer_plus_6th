#include "wine_mi.h"

Wine::Wine()
    : std::string("none"), PairArray(ArrayInt(0), ArrayInt(0)), years_(0) {
  // Do nothing inside
}

Wine::Wine(const char * l, int y, const int yr[], const int bot[])
    : std::string(l), years_(y), PairArray(ArrayInt(yr, y), ArrayInt(bot, y)) {
  // Do nothing inside
}

Wine::Wine(const char * l, int y)
    : std::string(l), years_(y), PairArray(ArrayInt(y), ArrayInt(y)) {
  // Do nothing inside
}

void Wine::GetBottles() {
  using std::cout;
  using std::cin;
  std::string &label = (std::string &) *this;
  PairArray &yield = (PairArray &) *this;
  // std::string &label = (std::string) *this;  // 注意: 不加&是错的
  // PairArray &yield = (PairArray) *this;      // 注意: 不加&是错的
  cout << "Enter " << label << " data for "
            << years_ << " year(s):\n";
  for (int i = 0; i < years_; i++) {
    cout << "Enter year: ";
    cin >> yield.first()[i];
    cout << "Enter bottles for that year: ";
    cin >> yield.second()[i];
  }
}

const std::string & Wine::Label() const {
  return (const std::string &) *this;
}

int Wine::sum() const {
  return PairArray::second().sum();
}

void Wine::Show() const {
  using std::cout;
  using std::endl;
  cout << "Wine: " << (std::string &) *this << endl;
  cout << "    Year    Bottles\n";
  for (int i = 0; i < years_; i++) {
    cout << "    " << PairArray::first()[i]
         << "    " << PairArray::second()[i] << endl;
  }
}