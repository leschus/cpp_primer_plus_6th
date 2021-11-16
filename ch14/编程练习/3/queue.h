#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>

template <typename T>
class Queue {
 public:
  // 创建一个容量为qsize的队列
  Queue(int qsize = kQueueSize);
  // 析构函数: 销毁队列
  ~Queue();
  // 元素入队
  bool EnQueue(const T & item);
  // 元素出队
  bool DeQueue(T & item);
  // 判断队满
  bool full() const;
  // 判断队空
  bool empty() const;
  // 返回队列当前元素个数
  int count() const;

 private:
  /* private definitions */
  enum { kQueueSize = 10 };
  // 链表结点模板
  template <typename ItemType>
  struct Node { ItemType item; Node *next; };
  /* data */
  Node<T> *front_;             // 队头指针
  Node<T> *rear_;              // 队尾指针
  const int qsize_;         // 队列最大容量
  int count_;                // 队列当前元素个数
};

/*************************模板成员函数定义*************************/
// 不要在独立的实现文件中给出类模板成员函数定义, 原因在于:
// >>>模板不是函数, 无法单独编译, 模板必须与特定的模板实例化请求一起使用
// 因此, 通常的做法是, 将所有模板信息放在一个头文件中


template <typename T>
Queue<T>::Queue(int qsize) : qsize_(qsize) {
  front_ = rear_ = nullptr;
  count_ = 0;
}

template <typename T>
Queue<T>::~Queue() {
  Node<T> *p;
  while (front_ != nullptr) {
    p = front_;
    front_ = front_->next;
    delete p;
  }
}

template <typename T>
bool Queue<T>::EnQueue(const T & item) {
  if (full())
    return false;
  Node<T> *pnode = new Node<T>;
  pnode->item = item;
  pnode->next = nullptr;
  if (empty()) {
    front_ = rear_ = pnode;
  } else {
    rear_->next = pnode;
    rear_ = pnode;
  }
  count_++;
  return true;
}

template <typename T>
bool Queue<T>::DeQueue(T & item) {
  if (empty())
    return false;
  Node<T> *pnode = front_;
  item = pnode->item;
  front_ = front_->next;
  if (count_ == 1) {
    rear_ = front_;
  }
  delete pnode;
  count_--;
  return true;
}

template <typename T>
bool Queue<T>::full() const {
  return count_ == qsize_;
}

template <typename T>
bool Queue<T>::empty() const {
  return count_ == 0;
}

template <typename T>
int Queue<T>::count() const {
  return count_;
}

#endif // QUEUE_H_