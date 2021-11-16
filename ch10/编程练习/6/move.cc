#include <iostream>
#include "move.h"

Move::Move(double a, double b) {
  x = a, y = b;
}

void Move::showmove() const{
  std::cout << "x = " << x << ", y = " << y << ".\n";
}

Move Move::add(const Move &m) const {
  // return (x + m.x, y + m.y);
  // 上面的语句看似简洁, 但实际上无法达到效果. 编译器将其视为逗号表达式, 从而其等价于
  // return (y + m.y), 这虽然确实会调用构造函数, 但却只传递了第一个参数, 导致新对象
  // 的第二个参数被设置成了默认值0
  return Move(x + m.x, y + m.y); // 这样显式调用构造函数才是对的 :)
}