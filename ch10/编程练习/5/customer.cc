#include <iostream>
#include "stack.h"

int main() {
  using std::cin;
  using std::cout;
  using std::endl;

  Stack s;
  int choice;
  char next;
  Item item;
  double total = 0.0;
  cout << ">>> Enter 1 to push, 0 to pop: ";
  // 事实上, 输入非数字也会导致循环结束
  while (cin >> choice) {
    if (choice == 1 && !s.isfull()) { // 栈未满才能push
      cout << ">>> Enter the fullname: ";
      cin.get(); // 丢弃缓冲区中由上一次读取choice值所残留下的换行符
      cin.get(item.fullname, kLength);
      do { // 丢弃缓冲区内可能存在的剩余字符
        cin.get(next);
      } while(next != '\n');
      cout << ">>> Enter the payment: ";
      cin >> item.payment;
      s.push(item);
    } else if (choice == 0 && !s.isempty()) { // 栈非空才能pop
      s.pop(item);
      total += item.payment;
      cout << item.fullname << " has been poped.\n"
          << "Current pryment in total: " << total << endl;
    } else {
      cout << "Invalid choice, please try again.\n";
    }
    cout << "-------------------------------------------\n";
    cout << ">>> Enter 1 to push, 0 to pop: ";
  }
  cout << "BYE!\n";
}