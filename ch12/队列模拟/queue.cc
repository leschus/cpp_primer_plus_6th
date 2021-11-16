#include "queue.h"

namespace QUEUE
{
  Queue::Queue(int size) : size_(size) {
    front_ = rear_ = nullptr;
    num_of_items_ = 0;
  }

  Queue::~Queue() {
    Node *p_node;
    while (front_ != nullptr) {
      p_node = front_;        // save address of front item
      front_ = front_->next;  // reset front to next item
      delete p_node;          // delete former front
    }

  }

  bool Queue::empty() const {
    return num_of_items_ == 0;
  }

  bool Queue::full() const {
    return num_of_items_ == size_;
  }

  int Queue::count() const {
    return num_of_items_;
  }

  bool Queue::enqueue(const Item &item) {
    if (full())
      return false;
    Node *p_node = new Node;
    // on failure, new throws std::bad_alloc exception
    p_node->item = item;
    p_node->next = nullptr;
    if (empty()) {
      front_ = rear_ = p_node;
    }
    else {
      rear_->next = p_node;
      rear_ = p_node;
    }
    num_of_items_++;
    return true;
  }

  bool Queue::dequeue(Item &item) {
    if (empty())
      return false;
    Node *p_node = front_;
    front_ = front_->next;
    if (!front_)
      rear_ = nullptr;
    item = p_node->item;
    delete p_node;  // delete former first item
    num_of_items_--;
    return true;
  }

} // namespace QUEUE
