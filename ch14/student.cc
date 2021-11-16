#include "student.h"

double Student::Average() const {
  if (scores_.size())
    return scores_.sum() / scores_.size();
  return 0;
}

const std::string & Student::Name() const {
  return name_;
}

double & Student::operator[](int i) {
  return scores_[i];
}

double Student::operator[](int i) const {
  return scores_[i];
}

std::istream & operator>>(std::istream &is, Student &stu) {
  is >> stu.name_;
  return is;
}

std::istream & getline(std::istream &is, Student &stu) {
  getline(is, stu.name_);
  return is;
}

std::ostream & operator<<(std::ostream &os, const Student &stu) {
  os << "Scores for " << stu.name_ << ":\n";
  stu.arr_out(os);
  return os;
}

std::ostream & Student::arr_out(std::ostream &os) const {
  int i;
  int len = scores_.size();
  if (len) {
    for (i = 0; i < len; i++) {
      os << scores_[i] << " ";
      if (i % 5 == 4)
        os << std::endl;
    }
    if (i % 5 != 0)
      os << std::endl;
  }
  else {
    os << " Empty array\n";
  }
  return os;
}