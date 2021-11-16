#include <iostream>
#include <cstring>
#include "plorg.h"

Plorg::Plorg(const char *name) {
  strncpy(name_, name, MAX - 1);
  ci_ = DEFAULT_CI;
}

void Plorg::update(int ci) {
  ci_ = ci;
}

void Plorg::report() {
  using std::cout;
  using std::endl;
  cout << "Name: " << name_ << endl;
  cout << "CI: " << ci_ << endl;
}