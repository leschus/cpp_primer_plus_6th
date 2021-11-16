// Person.cc

#include <iostream>
#include <string>
#include <cstring>      // strncpy()
#include "person.h"

Person::Person(const std::string &ln, const char *fn) {
    lname_ = ln;
    strncpy(fname_, fn, kLimit_ - 1); // 需要留出一个字符用来存储'\0'
}

void Person::Show() const {
    using std::cout;
    using std::endl;
    cout << fname_ << " " << lname_ << endl;
}

void Person::FormalShow() const {
    using std::cout;
    using std::endl;
    cout << lname_ << ", " << fname_ << endl;
}