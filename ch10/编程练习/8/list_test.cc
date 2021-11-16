#include <iostream>
#include "list.h"

using namespace std;

void print_value(Item &item) {
  cout << item << endl;
}

// 该函数将item的值增加1
void increment(Item &item) {
  item += 1;
}

int main() {
  List list1; // 空列表(最大容量为0的列表, 啥也装不了)
  cout << "list1 is full: " << list1.full() << endl;
  cout << "list1 is empty: " << list1.empty() << endl;
  cout << "try to append item to list1: " << list1.append(100) << endl;

  List list2(1); // 最大容量为1的列表
  cout << "list2 is full: " << list2.full() << endl;
  cout << "list2 is empty: " << list2.empty() << endl;
  cout << "try to append item to list2: " << list2.append(100) << endl;
  cout << "list2 is full: " << list2.full() << endl;
  cout << "list2 is empty: " << list2.empty() << endl;
  cout << "try to append item to list2: " << list2.append(200) << endl;

  List list3(3);
  list3.append(1);
  list3.append(22);
  list3.append(333);
  list3.visit(print_value);
  list3.visit(increment);
  list3.visit(print_value);

  // 下面的测试, 结果说明了List的默认赋值运算和拷贝构造函数执行的是浅拷贝
  // 浅拷贝很可能造成程序逻辑错误, 如要执行深拷贝, 需要手动重载赋值运算符
  // 并且提供显式的拷贝构造函数
  // List list4(4);
  // for (int i = 0; i < 4; i++) {
  //   list4.append(i * i);
  // }
  // cout << "list4:\n";
  // list4.visit(print_value);
  // // List list5 = list4;
  // {
  //   List list5;
  //   list5 = list4;
  //   cout << "list5:\n";
  //   list5.visit(print_value);
  // }
  // cout << "list4:\n";
  // list4.visit(print_value);
}