#ifndef QUEUE_H_
#define QUEUE_H_

#include "customer.h"

namespace QUEUE
{
  typedef Customer Item;

  class Queue {
   public:
    Queue(int size = Q_SIZE);
    ~Queue();
    bool empty() const;
    bool full() const;
    int count() const;              // 获取队列当前人数
    bool enqueue(const Item &item); // 入队
    bool dequeue(Item &item);       // 出队

   private:
    /* data */
    enum { Q_SIZE = 10 }; // 队列最大容量
    struct Node { Item item; Node *next; }; // 链表结点
    Node *front_;  // 队头指针
    Node *rear_;   // 队尾指针
    int num_of_items_;  // 队列中当前元素个数
    const int size_;    // 队列容量, 通过构造函数的成员初始化列表获得值
                        // C++11支持在类声明中初始化成员变量的值, 其效果和
                        // 在构造函数中使用成员初始化列表对其赋值一样
                        // 因此, 这里可以: const int size_ = Q_SIZE;
                        // 如果同时在类声明中和成员初始化列表中对同一变量初始化,
                        // 那么效果是成员初始化列表将覆盖类声明中所赋的值
    /* private funtions */
    // 显式提供拷贝构造函数并声明为私有类型
    // 可以避免测试代码调用拷贝构造函数
    // 对于一些目前尚未开发, 但编译器可能隐式提供默认函数定义的函数而言,
    // 可以通过将其声明为私有的空函数来避免编译器的这种行为
    Queue(const Queue & q): size_(0) {}
    // 显式提供赋值运算符的重载函数, 基于和显式提供拷贝构造函数相同的目的
    Queue & operator=(const Queue & q) { return *this; }

  };


} // namespace QUEUE

#endif // QUEUE_H_