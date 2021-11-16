// stack.h -- class definition for the stack ADT
#ifndef STACK_H_
#define STACK_H_

const int kLength = 35;

typedef struct customer {
  char fullname[kLength];
  double payment;
}Item;

class Stack
{
 private:
  enum {MAX = 10};    // constant specific to class
  Item items[MAX];    // holds stack items
  int top;            // index for top stack item
 public:
  Stack();
  bool isempty() const;
  bool isfull() const;
  // push() returns false if stack already is full, true otherwise
  // 这里的形参item可以不是引用类型, 因为item只承担着"传值"的作用
  bool push(const Item & item);   // add item to stack
  // pop() returns false if stack already is empty, true otherwise
  // 这里的形参item必须为引用类型, 因为外界需要用到pop()对item值的修改
  bool pop(Item & item);          // pop top into item
};
#endif
