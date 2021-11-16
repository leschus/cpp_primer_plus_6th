#include <iostream>
#include "person.h"

Person::Person(const std::string &fname, const std::string &lname)
    : firstname_(fname), lastname_(lname) {
  // std::cout << "Person constructor called.\n";
}

Person::~Person() {}

void Person::Data() const {
  using std::cout;
  using std::endl;
  cout << "Name: " << firstname_ << " " << lastname_ << endl;
}

void Person::Show() const {
  std::cout << "Category: Person\n";
  Data();
}