#include "queue.h"

using QUEUE::Queue;

int main() {
  Queue q1(6);
  // Queue q2 = q1; // 尝试使用拷贝构造函数, 会有编译错误
  // error: 'QUEUE::Queue::Queue(const QUEUE::Queue&)' is private within this context
  Queue q3;
  // q3 = q1; // 尝试使用重载的赋值运算符, 会有编译错误
  // error: 'QUEUE::Queue& QUEUE::Queue::operator=(const QUEUE::Queue&)' is private within this context
}