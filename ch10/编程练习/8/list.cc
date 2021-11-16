#include "list.h"
#include <iostream>

List::List(int size) {
  if (size == 0) {
    plist_ = nullptr;
  }
  else {
    plist_ = new Item[size];
  }
  size_ = size;
  current_idx = 0; // 初始化当前下标为0
}

List::~List() {
  // std::cout << "\"" << plist_ << "\" destructor called.\n";
  if (size_)
    delete[] plist_; // 释放动态数组的内存
}

bool List::append(const Item &item) {
  if(full())
    return false;
  plist_[current_idx++] = item;
  return true;
}

bool List::full() const {
  return current_idx == size_;
}

bool List::empty() const {
  return current_idx == 0;
}

void List::visit(void (*pf)(Item &item)) {
  for (int i = 0; i < current_idx; i++) {
    (*pf)(plist_[i]);
    // 也可使用`pf(plist_[i]);`
  }
}