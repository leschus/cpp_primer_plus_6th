#include <iostream>
#include <cstring>
#include "dma.h"

DmaAbc::DmaAbc(const char *label, int rating) {
  label_ = new char[strlen(label) + 1];
  strcpy(label_, label);
  rating_ = rating;
}

DmaAbc::DmaAbc(const DmaAbc &d) {
  label_ = new char[strlen(d.label_) + 1];
  strcpy(label_, d.label_);
  rating_ = d.rating_;
}

DmaAbc::~DmaAbc() {
  delete [] label_;
}

DmaAbc & DmaAbc::operator=(const DmaAbc &d) {
  if (this == &d)
    return *this;
  delete [] label_;
  label_ = new char[strlen(d.label_) + 1];
  strcpy(label_, d.label_);
  rating_ = d.rating_;
  return *this;
}

// 即使是纯虚函数, 也可以在实现文件中给出定义
void DmaAbc::View() const {
  std::cout << "Label: " << label_ << std::endl
            << "Rating: " << rating_ << std::endl;
}

std::ostream & operator<<(std::ostream &os, const DmaAbc &d) {
  os << "Label: " << d.label_ << std::endl
     << "Rating: " << d.rating_ << std::endl;
  return os;
}

BaseDma::BaseDma(const char *label, int rating) : DmaAbc(label, rating) {
  // Do nothing
}

BaseDma::BaseDma(const DmaAbc &d) : DmaAbc(d) {
  // Do nothing
}

BaseDma::~BaseDma() {
  // Do nothing
}

void BaseDma::View() const {
  DmaAbc::View();
}

std::ostream & operator<<(std::ostream &os, const BaseDma &bd) {
  os << (const DmaAbc &)bd;
  return os;
}

LacksDma::LacksDma(const char *color, const char *label, int rating)
    : DmaAbc(label, rating) {
  // 使用strncpy()而非strcpy()以避免数组溢出
  strncpy(color_, color, COLOR_LEN - 1);
  color_[COLOR_LEN - 1] = '\0';
}

LacksDma::LacksDma(const char *color, const DmaAbc &d) : DmaAbc(d) {
  strncpy(color_, color, COLOR_LEN - 1);
  color_[COLOR_LEN - 1] = '\0';
}

void LacksDma::View() const {
  DmaAbc::View();
  std::cout << "Color: " << color_ << std::endl;
}

std::ostream & operator<<(std::ostream &os, const LacksDma &ld) {
  os << (const DmaAbc &)ld;
  os << "Color: " << ld.color_ << std::endl;
  return os;
}

HasDma::HasDma(const char *style, const char *label, int rating)
    : DmaAbc(label, rating) {
  style_ = new char[strlen(style) + 1];
  strcpy(style_, style);
}

HasDma::HasDma(const char *style, const DmaAbc &d) : DmaAbc(d) {
  style_ = new char[strlen(style) + 1];
  strcpy(style_, style);
}

HasDma::HasDma(const HasDma &hd) : DmaAbc(hd) {
  // 成员初始化列表中使用基类的拷贝构造函数来初始化新派生类对象的基类部分
  // 由于基类拷贝构造函数接收一个基类的对象引用作为参数, 而基类对象的引用
  // 可以引用派生类的对象, 从而可以将hd作为基类拷贝构造函数的参数
  style_ = new char[strlen(hd.style_) + 1];
  strcpy(style_, hd.style_);
}

HasDma::~HasDma() {
  delete [] style_;
}

HasDma & HasDma::operator=(const HasDma &hd) {
  if (this == &hd)
    return *this;
  DmaAbc::operator=(hd); // 对基类部分进行赋值
  delete [] style_;
  style_ = new char[strlen(hd.style_) + 1];
  strcpy(style_, hd.style_);
  return *this;
}

void HasDma::View() const {
  DmaAbc::View();
  std::cout << "Style: " << style_ << std::endl;
}

std::ostream & operator<<(std::ostream &os, const HasDma &hd) {
  os << (const DmaAbc &)hd;
  os << "Style: " << hd.style_ << std::endl;
  return os;
}
